library(questionr)
data("hdv2003")
d<-hdv2003

boxplot(d$freres.soeurs, outline = FALSE, horizontal = TRUE)


barplot(table(d$freres.soeurs), border = "red", density = 10, col = "blue", angle = 45, ylim = c(0,500),  xlab = "frequence", ylab = "Nombre de freres et soeurs")

hist(d$age, ylab = "Effectif", xlab = "âges [Années]", col = "purple", labels = TRUE, xlim = c(0, 100), ylim = c(0,250), border = "white")

hist(d$age, ylab = "Effectif", xlab = "âges [Années]", col = "purple", labels = TRUE, xlim = c(0, 100), ylim = c(0,250), border = "white", breaks = 5)


pie(table(d$sexe), col = c("green", "blue"), main = "Pourcentage homme femme")

#H

slices <- table(d$sexe)
lbls <- c("Homme", "Femme")
pct <- freq(d$sexe)[,2]
lbls <- paste(lbls, pct)
lbls <- paste(lbls,"%",sep="")
pie(slices, labels = lbls, col = c("green", "blue"), main = "Proportion du nombre d'hommes et de femmes")



barplot(table(d$occup),  las=2)

# Exercice 7

#il y a 51020 observations et 10 variables 

## 'data.frame': 51020 obs. of 10 variables: 
## $ id : num 1 2 3 4 5 6 7 8 9 10 ... 
## $ happy : Factor w/ 3 levels "not too happy",..: 1 1 2 1 2 2 1 1 2 2 ... Qualitif 
## $ year : num 1972 1972 1972 1972 1972 ... Quantitatif
## $ age : num 23 70 48 27 61 26 28 27 21 30 ... Qauntitatif
## $ sex : Factor w/ 2 levels "male","female": 2 1 2 2 2 1 1 1 2 2 ... Qualitatif
## $ marital: Factor w/ 5 levels "married","never married",..: 2 1 1 1 1 2 3 2 2 1 ... Qalitatif
## $ degree : Factor w/ 5 levels "lt high school",..: 4 1 2 4 2 2 2 4 2 2 ... Qalitatif
## $ finrela: Factor w/ 5 levels "far below average",..: 3 4 3 3 4 4 4 3 3 2 ...Qualitatif
## $ health : Factor w/ 4 levels "poor","fair",..: 3 2 4 3 3 3 4 3 4 2 ... Qualitif
## $ wtssall: num 0.445 0.889 0.889 0.889 0.889 ... Quantitatif

# Qualitatif ; parti politique ; droite, gauche, centre, extreme droite, extreme gauche. et c'est tout 


h <- happy



