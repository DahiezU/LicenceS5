-- Ulysse dahiez
-- Programation Fonctionnelle
-- TP tri



-- /////////////////////E X E R C I C E   1//////////////////////////////////////////


f1 :: Ord a => [a] -> [a]
f1 [] = []
f1 [a] = [a]
f1 (h : h1 : t) | h > h1 = h1 : f1 (h : t)
            | otherwise = h : f1 (h1 : t)
            



tri_a_bulles :: Ord a => [a] -> [a]
tri_a_bulles [] = []
tri_a_bulles [a] = [a]
tri_a_bulles l | l == f1 l = l
                |otherwise = tri_a_bulles (f1 l)


-- /////////////////////E X E R C I C E   2//////////////////////////////////////////

         
h2 :: (Ord a) => a -> [a] -> [a]
h2 n [] = [n]
h2 n (h: t) 
        | n <= h = n : (h : t)
        | otherwise = h : h2 n t

            
            

tri_insertion :: Ord a => [a] -> [a]
tri_insertion [] = []
tri_insertion [a] = [a]
tri_insertion (h : t) = h2 h (tri_insertion t)


-- /////////////////////E X E R C I C E   3//////////////////////////////////////////


minimum1 :: (Ord a) => [a] -> a
minimum1 [x] = x
minimum1 (h : h1 : t) 
                | h <= h1 = minimum1(h:t)
                | otherwise = minimum1(h1:t)

suppr :: Ord a => a -> [a] -> [a]
suppr a [] = []
suppr x (h:t)
        | x == h = t
        |otherwise = h:(suppr x t)



tri_selection :: Ord a => [a] -> [a]
tri_selection [] = []
tri_selection  xs = let  x = minimum1 xs  
                in x : tri_selection (suppr x xs)


-- /////////////////////E X E R C I C E   4//////////////////////////////////////////


fusion :: Ord a => [a] -> [a] -> [a]
fusion xs [] = xs
fusion [] ys = ys
fusion (x:xs) (y:ys) | x <= y    = x:fusion xs (y:ys)
                     | otherwise = y:fusion (x:xs) ys
                
tri_fusion :: Ord a => [a] -> [a]
tri_fusion [] = []
tri_fusion [a] = [a]
tri_fusion l = fusion (tri_fusion (moitier1 l)) (tri_fusion (moitier2 l))
                                    
moitier1  l = let { n = length l } in take (div n 2) l
moitier2 l = let { n = length l } in drop (div n 2) l
                

-- /////////////////////E X E R C I C E   5//////////////////////////////////////////

tri_rapide :: (Ord a) => [a] -> [a] 
tri_rapide [] = []
tri_rapide (h:t) = (tri_rapide moins) ++ [h] ++ (tri_rapide plus)
        where
        moins = filter (< h) t
        plus = filter (>= h) t




