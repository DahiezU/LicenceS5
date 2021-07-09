#Exercice 1


library(questionr)
data("hdv2003")
d <- hdv2003
table(d$qualif, d$clso)

#qualif est la variable independante

table1 <- table(d$qualif, d$clso)
lprop(table1)
cprop(table1)
# d'apres le tableau ce sont principalalment les employés qu croient en l'existance des classes sociale 

chisq.test(table1)

mosaicplot(table1, shade = TRUE)


#Exercie 2

table2 <- table(d$occup, d$heures.tv)
boxplot(d$occup, d$heures.tv)
tapply(d$heures.tv, d$occup, mean)

#Exercice 3

library(questionr)
data(rp2012)
d2 <- rp2012
plot(d2$dipl_aucun, d2$proprio)

