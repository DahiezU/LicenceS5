add :: Int -> Int -> Int
add a b = a + b

somme :: Num a => [a] -> a
somme [] = 0
somme (x:xs) = x + somme (xs)

dernier :: [t] -> t
dernier x = head (reverse x)

initial :: [t] -> [t]
initial l = reverse (drop 1 (reverse l))

prendre :: Int -> [a] -> [a]
prendre 0 _ =  []
prendre n (h:t) = h : (prendre (n-1) t)

miroir :: [a] -> [a]
miroir (h:t) = (miroir t) ++ [h]

compression :: Eq a => [a] -> [a]
compression [] = []
compression [x] = [x] 
compression (h1:h2:t) | h1 == h2 = (compression(h1:t))
                      | otherwise = h1 : (compression (h2:t))

applique :: (a -> a)->a-> Int -> [a]
applique f x a = [x]
applique f x n = x : (applique (fx) (n-1))

entier_0_a_n :: Int -> [Int]
entier_0_a_n = applique (\t -> t + 1) 0 n

un_sur_deux :: [a] -> [a]
un_sur_deux [] = []
un_sur_deux [x] = [x]
un_sur_deux (h1:h2:t) = (h1: un_sur_deux t)

combine :: (a -> b -> c) -> [a] -> [b] -> [c]
combine _ [] = []
combine _ _ [] = []
combine f (ha:ta) (hb:tb) = (f ha hb) : (combine f ta tb)