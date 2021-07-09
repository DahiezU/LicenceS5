import Graphics.Gloss
 

-- //////////////////// Un module de tortue ! ////////////////////////////////////


type EtatTortue =   ((Float, Float), Float)

avance :: Float -> EtatTortue -> EtatTortue
avance  dist ((ab,ord),angle) = ((ab + dist*cos((angle*pi)/180), ord + dist* sin((angle*pi)/180)) ,angle )


ajouterPoint :: Path -> EtatTortue -> Path
ajouterPoint p ((x, y), s) =  p ++ [(x, y)] 

tournerAGauche :: Float -> EtatTortue -> EtatTortue
tournerAGauche f ((x, y), s) = ((x, y),(s + f))

tournerADroite :: Float -> EtatTortue -> EtatTortue
tournerADroite f ((x, y), s) = ((x, y),(s - f))

-- //////////////////// Les L-Systèmes ////////////////////////////////////

type Symbole = Char
type Mot = [Symbole]
type Axiome = Mot
type Regles = Symbole -> Mot
type LSysteme = [Mot]


reglesVonKoch :: Regles
reglesVonKoch '+' =  ['+']
reglesVonKoch '-' =  ['-'] 
reglesVonKoch 'F' = "F-F++F-F"




motSuivant :: Regles -> Mot -> Mot
motSuivant _ [] = []
motSuivant regle (h : t) = regle h ++  motSuivant regle t 




lSysteme :: Axiome -> Regles -> LSysteme
lSysteme [] _ = []
lSysteme axiome regle =  [axiome] ++ lSysteme  (motSuivant regle axiome ) regle 



r =  motSuivant reglesVonKoch (motSuivant reglesVonKoch ['F'])


type Config = (EtatTortue, -- Etat initial de la tortue
                Float,      -- Longueur de déplacement
                Float)      -- Angle de rotation de la tortue

etatInitial :: Config -> EtatTortue
etatInitial (e, _, _) = e

longueurPas :: Config -> Float
longueurPas (_, l, _) = l

angleRotation :: Config -> Float
angleRotation ( _ , _,a) = a


type EtatDessin = (EtatTortue, Path)

interpreteSymbole :: Config -> EtatDessin -> Symbole -> EtatDessin
interpreteSymbole (etatTConf, long , angle) (etatTDessin, path) symbole 
                                        | symbole  == '+' =  (tournerAGauche 60 etatTDessin,  ajouterPoint path etatTDessin)
                                        | symbole == '-' = (tournerADroite 60 etatTDessin,  ajouterPoint path etatTDessin)
                                        | symbole == 'F' = (avance long etatTDessin,  ajouterPoint path (avance long etatTDessin))
        



interpreteMot :: Config -> EtatDessin -> Mot -> EtatDessin
interpreteMot config etatDessin (h : t)   | length (h:t) == 0 = etatDessin
                            | length (h:t) == 1 = interpreteSymbole config etatDessin h
                            | otherwise = interpreteMot  config (interpreteSymbole config etatDessin h) t 


cheminLSysteme :: Config -> LSysteme -> Int -> Path
cheminLSysteme conf lys iter  = snd (interpreteMot conf (etatInitial conf, []) (lys !! iter))





 -- ///////////////////////////////////etat de configuration /////////////////////////////////////////////

vonKoch = (((-15,0),0),10,60)


flocon = cheminLSysteme vonKoch (lSysteme ['F'] reglesVonKoch ) 4



main = display (InWindow "Tortue" (600, 400) (0, 0)) white (Line flocon)