conjoint1 <- c(1200, 1180, 1750, 2100)
conjoint2 <- c(1450, 1870, 1690, 0)
nb_personnes <- c(4, 2, 3, 2)

  
  moy = (conjoint1+conjoint2)
  
  res = moy / nb_personnes

  
#///////////////////////////////////////exo univarié////////////////////////////////////////////////

#EXERCICE 1
  
  nbVoit = c(1:12)
  nbObs = c(2, 8, 14, 20, 19, 15, 9, 6, 2, 3, 1, 1)
  
  barplot(nbObs)
  moyenne
  mean(nbObs)
  #Ecart type
  sd(nbObs)
  
#EXERCICE 3  
  
library(questionr) 
data(hdv2003)
t <- hdv2003

#tabHTv <- filter(hdv2003, heures.tv != na.rm = t)

min(t$heures.tv, na.rm = T)
min(t$heures.tv, na.rm = T)
mean(t$heures.tv, na.rm = T)

#médiane (donne un peu tout)
summary(t$heures.tv, na.rm = T)

#écart-type
sd(t$heures.tv, na.rm = T)

#EXERCICE 4

table(t$trav.imp)

effectifs <- table(t$trav.imp)
prop.table(effectifs) * 100


#///////////////////////////////////////exo bivarié////////////////////////////////////////////////


#EXERCICE 1 

monTab = table(t$clso, t$qualif)

#Variable indépendante  = les métiers
#Variable dépendante = Oui / Non / Ne sait pas

effectifsMetiers <- monTab
cprop(effectifsMetiers)
lprop(effectifsMetiers)
#test X2
chisq.test(monTab)
# On rejète l'hypothèse d'indépence, les deux variables t$clso, t$qualif ne sont pas indépendante

mosaicplot(monTab, shade = TRUE)

# Plus c'est rouge, moins il y a d'effectif, donc moins c'est significatif.

#EXERCICE 2

boxplot(t$heures.tv, t$occup)

tapply(t$heures.tv, t$occup,na.rm = T, mean)



#EXERCICE 3




data(rp2012)
data(rp2012)
d <- rp2012

plot(d$dipl_aucun, d$pop_cadres)
cor(d$dipl_aucun, d$pop_cadres)

#EXERCICE 4


plot(d$dipl_aucun, d$proprio)


#///////////////////////////////////////Les probabilités et les distributions de probabilités////////////////////////////////////////////////

library(prob)


#Question 1 :




#Question 2 :




#Question 3 :



#Question 4 :

#///////////////////////////////////////Test Hipothèse////////////////////////////////////////////////


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






















