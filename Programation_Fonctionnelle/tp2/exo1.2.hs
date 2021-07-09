add :: Num a => [a] -> a
add [] = 0
add (h:t) = h + add t

dernier :: [a] -> a
dernier [] = error "erreur"
dernier h = head(reverse h) 

initial :: [a] -> [a]
initial [] = error "erreur"
initial h = reverse(tail (reverse h))

elementplace :: (Num a) => Int -> [a] -> [a]
elementplace  _ [] = error "erreur" 
elementplace n l = take 1 (drop (n-1) l)


concat :: [a] -> [a] -> [a]
concat [] [] = error "erreur"
concat n (h : t) = n ++ (h : t)


prendre :: Int -> [a] -> [a]
prendre 0 _ = []
prendre _ [] = []
prendre v (h : t) = h : (prendre (v-1) t)

miroir :: [a] -> [a]
miroir [] = []
miroir (h : t) =  miroir(t) ++ [h]
