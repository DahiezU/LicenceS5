type Resultat a = Maybe (a, String)

data Parseur a = Cons (String -> Resultat a)

parser :: Parseur a -> String -> Resultat a
parser (Cons f) chaine = f chaine

lireCaractere :: Parseur Char
lireCaractere = Cons f
    where f [] = Nothing
          f (h:t) = Just (h, t)

(<.>) :: Parseur a -> (a -> Parseur b) -> Parseur b
(<.>) parseur1 parseur2 = Cons (\chaine -> case parser parseur1 chaine of
                                    Nothing      -> Nothing
                                    Just (resultat, reste) -> parser (parseur2 resultat) reste)

lireCaractereSi :: (Char -> Bool) -> Parseur Char
lireCaractereSi condition = lireCaractere <.> (\caractere -> 
                                    case condition caractere of
                                        False -> echouer
                                        True  -> retourner caractere
                                )


isDigit :: Char -> Bool
isDigit caractere = caractere >= '0' && caractere <= '9'

lireChiffre :: Parseur Char
lireChiffre = lireCaractereSi isDigit

(<|>) :: Parseur a -> Parseur a -> Parseur a
(<|>) parseur1 parseur2 = Cons (\chaine -> case parser parseur1 chaine of
                                    Nothing  -> parser parseur2 chaine
                                    resultat -> resultat
                                )

unOuPlus :: Parseur a -> Parseur [a]
unOuPlus un_parseur = un_parseur <.> \res ->
                      (unOuPlus un_parseur <|> retourner []) <.> \res2 ->
                      retourner (res:res2)    

zeroOuPlus :: Parseur a -> Parseur [a]
zeroOuPlus un_parseur = unOuPlus un_parseur <|> retourner []

charToInt :: Char -> Int
charToInt c = read [c]

stringToInt :: String -> Int
stringToInt c = read c

lireNombre :: Parseur Int
lireNombre = unOuPlus lireChiffre <.> \res ->
             retourner (stringToInt res)

             
-- //////////////////////////// R E G E X //////////////////////////////////////////

--Question 1
data Regex = Mot String | UnCarQuelconque | ZeroOuUn Regex | UnOuPlus Regex | ZeroOuPlus Regex | Ou Regex Regex | Et Regex Regex deriving Show

--Question 2
isLetter :: Char -> Bool
isLetter caractere = (caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')

lireLettre :: Parseur Char
lireLettre = lireCaractereSi isLetter

mot :: Parseur Regex
mot = unOuPlus lireLettre <.> \res ->
             retourner (Mot res)



--Question 3

isCaractereSpe :: Char -> Bool
isCaractereSpe caractere = caractere == '.'

lireCaractereSpe :: Parseur Char
lireCaractereSpe = lireCaractereSi isCaractereSpe 

unCarQuelconque :: Parseur Regex
unCarQuelconque = unOuPlus lireCaractereSpe <.> \res ->
            retourner (UnCarQuelconque)

--Question 4, 7, 10 et 12


regexSimple :: Parseur Regex
regexSimple = ou <|> mot <|> unCarQuelconque  <|> repetition <|> exprParenthesee


--Question 5

regex :: Parseur Regex
regex = unOuPlus regexSimple <.> \res ->
    retourner (foldl1 Et res)

--Question 6


exprParenthesee :: Parseur Regex
exprParenthesee = (lireCaractereSi (\par -> par == '(')) <.> \res ->
                  regex <.> \res1 ->
                  (lireCaractereSi (\par -> par == ')')) <.> \res2 ->
                  retourner res1





-- Question 8

zeroOuUnRegex :: Parseur Regex
zeroOuUnRegex  = exprParenthesee  <.> \res ->
    lireCaractereSi (\par -> par == '?') <.> \res2 ->         
    retourner (ZeroOuUn res )


zeroOuPlusRegex :: Parseur Regex
zeroOuPlusRegex = exprParenthesee  <.> \res ->
    (lireCaractereSi (\par -> par == '*')) <.> \res2 ->         
    retourner (ZeroOuPlus res)


unOuPlusRegex :: Parseur Regex
unOuPlusRegex = exprParenthesee  <.> \res ->
    (lireCaractereSi (\par -> par == '+')) <.> \res2 ->         
    retourner (UnOuPlus res)

-- Question 9

repetition :: Parseur Regex 
repetition = zeroOuUnRegex <|> zeroOuPlusRegex <|> unOuPlusRegex 

-- Question 11

ou:: Parseur Regex
ou  = exprParenthesee  <.> \res ->
    (lireCaractereSi (\par -> par == '|')) <.> \res1 ->  
    exprParenthesee  <.> \res2 ->       
    retourner (Ou res res2)    

-- ///////////////////////Evaluation d’une expression régulière///////////////////////////


lireMotExact :: [Char] -> Parseur [Char]
lireMotExact "" = retourner ""
lireMotExact (h:t) = lireCaractereSi (\x -> x == h) <.> \_ ->
            lireMotExact t <.> \_ ->
            retourner (h:t)

-- Question 12


echouer :: Parseur a
echouer = Cons (\_ -> Nothing)

retourner :: a -> Parseur a
retourner valeur = Cons (\chaine -> Just (valeur, chaine))


match :: Regex -> Parseur ()                
match (Mot x) =     lireMotExact x <.> \_ -> 
                    retourner ()
match (Ou x y ) =   match x  <|> match y <.> \_ ->
                    retourner ()
match (Et x y) =    match x  <.>  \_ -> 
                    match y <.>  \_ -> 
                    retourner ()
match UnCarQuelconque =  match  UnCarQuelconque <.> \_ -> 
                        retourner ()                             
match (ZeroOuUn x)  =    match x  <|>  retourner ()   <.> \_ -> 
                        retourner ()              
match  (UnOuPlus x) =    unOuPlus (match x) <.> \_ -> 
                        retourner ()
match (ZeroOuPlus x) =  zeroOuPlus (match x)  <.> \_ -> 
                        retourner () 


fromJusty :: Maybe a -> a
fromJusty (Just x) = x 



isNothing :: Maybe a -> Bool
isNothing Nothing = True
isNothing _ = False

pregMatch :: String -> String -> Bool 
pregMatch reg exp   | isNothing (parser (match (fst (fromJusty (parser regex reg)))) exp ) == True = False
                    | ((fst (fromJusty (parser (match (fst (fromJusty (parser regex reg)))) exp ))) == ()  &&  (snd (fromJusty (parser (match (fst (fromJusty (parser regex reg)))) exp ))) == "" )= True
                    |  otherwise = False
                    


