
-- //////////////////////E X E R C I C E   1////////////////////////////////////

somme_foldl ::(Num a) => [a] -> a
somme_foldl l = foldl (+) 0 l

somme_foldr ::(Num a) => [a] -> a
somme_foldr l = foldr (+) 0 l

(+++) :: (Num a) => [a] -> [a] -> [a]
(+++) array1 array2 = foldr (:) array2 array1

concate ::  [[a]] -> [a]
concate l = foldr (++) [] l

map_fold::(a -> b) -> [a] -> [b]
map_fold f l = foldr (\x ac -> (f x) : ac) [] l

filter_fold :: (a -> bool) -> [a] -> [a]
filter_fold f l = foldr (\x ac -> if fx then x:ac else ac) [] l

-- //////////////////////E X E R C I C E   2////////////////////////////////////

{-

atSafe :: [a] -> Int -> Maybe a
atSafe l x 
        |lenght l > x = Just (l !! x)
        |otherwise = Nothing

tailSafe :: [a] -> Maybe [a]
tailSafe [] = Nothing
tailSafe l = Just (tail l)

minSafe :: Ord a => [a] -> Maybe a
minSafe [] = Nothing
minSafe [x] = Just x
minSafe (h1:h2:t)
            |h1 > h2 = minSafe (h2:t)
            |otherwise = minSafe (h1:t)

-}

-- //////////////////////E X E R C I C E   3////////////////////////////////////

data Pile a = Vide |  Value a (Pile a) 
        deriving (Show, Eq, Read)


b = Value "eee" ( Value "iii" (Vide))
d = Vide

estVide :: Pile a -> Bool
estVide Vide = True
estVide _ = False

sommet  :: Pile a -> Maybe a
sommet (Value a (_)) = Just a 
sommet Vide = Nothing
 
depiler :: Pile a -> Pile a
depiler Vide = Vide
depiler (Value _ (p)) = p 

empiler :: a -> Pile a -> Pile a 
empiler v (Vide) = Value v (Vide)
empiler v p = Value v (p)


empilerTout :: Ord a => [a] -> Pile a -> Pile a
empilerTout [] p = p
empilerTout (h : t) Vide = Value (last t) (empilerTout (reverse t) (empiler (h) Vide))
empilerTout (h : t) (Value v p) 
        | length (h:t) > 1 = Value (last t) (empilerTout (reverse t) (empiler (h) (Value v p)))
        | otherwise = Value v p

empilerToutCor :: [a] -> Pile a -> Pile a
empilerToutCor [] p = p
empilerToutCor (h:t) p = empilerToutCor t (empiler h p)

empilerToutF :: [a] -> Pile a -> Pile a 
empilerToutF l p = foldr empiler p (reverse l)

-- //////////////////////E X E R C I C E   4////////////////////////////////////

type File a = Pile a 

file = Value 3(Value 5 (Value 2 (Value 1 (Vide))))

estFileVide  :: File a -> Bool
estFileVide Vide = True
estFileVide _ = False


suivant  :: File a -> Maybe a
suivant Vide = Nothing
suivant (Value a Vide) = Just a
suivant (Value a f) = suivant f 

defiler :: File a -> File a 
defiler Vide = Vide 
defiler (Value a Vide) = Vide
defiler (Value x  f) = Value x (defiler f)

emfiler :: a -> Pile a -> Pile a 
emfiler v (Vide) = Value v (Vide)
emfiler v p = Value v (p)

emfilerToutCor :: [a] -> Pile a -> Pile a
emfilerToutCor [] p = p
emfilerToutCor (h:t) p = empilerToutCor t (empiler h p)

-- //////////////////////E X E R C I C E   4////////////////////////////////////

data ArbreBinaire a = Feuille | Noeud a (ArbreBinaire a) (ArbreBinaire a)
        deriving Show

ajouterValeur :: (Eq a, Ord a) => ArbreBinaire a -> a -> ArbreBinaire a
ajouterValeur Feuille x = Noeud x Feuille Feuille
ajouterValeur (Noeud a ag ad) x 
                | x < a = Noeud a (ajouterValeur ag x) ad
                | otherwise = Noeud a ag  (ajouterValeur ad x)

rechercherValeur :: (Eq a, Ord a) => ArbreBinaire a -> a -> Bool
rechercherValeur Feuille _ = False
rechercherValeur (Noeud a ag ad) x
                        | x == a = True
                        | x  < a = rechercherValeur ag x
                        | otherwise = rechercherValeur ad x

applatirArbre :: ArbreBinaire a -> [a] --liste doit être trié
applatirArbre Feuille = []
applatirArbre (Noeud a ag ad) = (applatirArbre ag) ++ [a] ++ (applatirArbre ad) 

--ajouterTout :: (Eq a, Ord a) =>ArbreBinaire a -> [a] ->ArbreBinaire a

--SupprimerValeur :: ArbreBinaire a -> a -> ArbreBinaire a

