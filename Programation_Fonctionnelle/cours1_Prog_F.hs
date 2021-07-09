--

--Exercice 1

--1- [char]
--2- (Char, Char, Char, Char)
--3- [(Bool, Int)]
--4- Erreur, impossible d'avoir une liste de tyope different 
--5- ([Char], [Int])
--6- Erreur, impossible,les types sont different dans les deux tuples et il n'y a pas le meme nombre de paramettre
--7- ([Int], Int)
--8- Erreur
--9- [ [t] -> [t] ]
--10- ([t] -> [t], [t] -> [t], [t] -> [t])
--11- [t] -> [t] Take prends les premiers caractère indiqué d'une liste

--Exercice 2

--1- second :: [t] -> t
--second l = head (tail l)

--2- swapp :: (t2, t1) -> (t1, t2)
--swap(a, b) = (b, a)

--3- first :: (t1, t2) ->t1
--first (a, b) = a

--4- triple :: Num t => t  (mettre => quand il y a une class de fonction avant)
--Triple a = a * 3

--5- pairing :: t1 -> t2 -> (t1, t2)
--pairing a b = (a, b)

--6- palindrome :: Eq t => [t] -> Bool
--Palindrome l = (reverse l) == l

--7- Applique_deux_fois :: (t -> t) -> t -> t
--appliquer_deux_fois f x = f (f x)

--Exercice 3

--1- f1 :: (t1 -> t2 -> t3) -> t1 -> t2 -> t3

--2- f2 :: (a -> (b -> c)) -> a  -> b -> c

--3- f3 :: (t2 -> t3) -> (t1 -> t2) -> t1 -> t3
