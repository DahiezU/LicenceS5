library(stats)
library(OneTwoSamples)
# Exo 1
x = c(10.1, 9.8, 10.2, 10.3, 10.4, 9.8, 9.9, 10.4, 10.2, 9.5, 10.4, 9.6)
t.test(x, mu = 10, alternative = "greater")$p.value

# Exo2
x = c(232, 277, 235, 245, 245, 250, 268, 256)
t.test(x, mu = 276)$p.value

# Exo 3 
prop.test(118, 400, 0.25)$p.value

# exo 4 
x1 = c(31.70, 31.98, 32.24, 32.35, 31.18, 32.19, 32.63, 31.19, 31.54, 31.89)
x2 = c(31.61, 31.10, 31.20, 31.11, 32.66, 31.15, 31.71, 31.22, 31.16, 31.21)
t.test(x1, x2, var.equal = T)$p.value


# Exo5
x1 = c(12.12, 12.03, 13.58, 13.38, 11.81, 15.92, 13.65)
x2 = c(14.81, 13.93, 14.91, 15.87, 15.62, 15.39)
t.test(x1, x2)$p.value


# exo6
prop.test(x = c(54, 110), n = c(230, 340), alternative = "less")$p.value


# exo7
A = matrix(c(61, 11, 2, 13), ncol = 2)
mcnemar.test(A)$p.values