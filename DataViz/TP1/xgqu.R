library(questionr)
data("rp2012")
str(rp2012)

rp <- rp2012
library(dplyr)

rp <- filter(rp, code_departement==59)
table(rp$pop_cl)


barplot(table(rp$pop_cl))
rp <- filter(rp, pop_cl=="10 001-50 000")

t <- rp$commune
rp <- rp[,c("pop_chom","pop_agric", "pop_indep","pop_cadres", "pop_interm","pop_empl","pop_ouvr")]
row.names(rp) <- t
stars(rp, cex=0.4, flip.labels=FALSE, key.loc = c(18, 1.5))

rp4 <- rp2012
rp4 <- filter(rp4, code_departement=="02")
rp4 <- filter(rp4, pop_cl=="5 001-50 000")
t4 <- rp4$commune
rp4 <- rp4[,c("pop_dipl_aucun","pop_dipl_bepc", "pop_dipl_capbep","pop_dipl_bac", "pop_dipl_bac2","pop_dipl_sup")]
row.names(rp4) <- t4
stars(rp4, cex=0.4, flip.labels=FALSE, key.loc = c(18, 1.5))