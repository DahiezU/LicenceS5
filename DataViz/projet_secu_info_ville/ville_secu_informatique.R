library(questionr)
library(jsonlite)

library(maps)
map(database="world")
library(dplyr)

villeSecuInfo <- read.csv("C:\\Users\\dahie\\Documents\\DataViz\\projet_secu_info_ville\\ville_secu_informatique.csv")


#plus la population de la ville est importante, plus le site est bien entretenu (version language à jour, pas de fail)

# Plus la position de la ville est dans le nord de la france, moins la sécurité est élevé ( à jours ou non)

#les villes ayant un site https sont les villes autours des métropoles,  car ce système est plus chère.



villeSecuInfoSup5000Nord <- filter(villeSecuInfo, Population > 5000  & Latitude > 46.3223 & Application != "Inconnue" & CatÃ.gorie != "Inconnue")
barplot(table(villeSecuInfoSup5000Nord$CatÃ.gorie, villeSecuInfoSup5000Nord$Application),
        col = c("green", "yellow", "orange", "red"),
        main = paste("les", nrow(villeSecuInfohttpssup5000Nord), "villes de plus de 5000 habitants du nord en fonction du l'aplication qu'elles utilisent"),
        ylab = "nombre de ville",
        las=3,
        legend.text = c("à jour" ,'Information masqué ',  'Niveau de sécurité incertain',"Pas à jour" ),
        args.legend = list(x = "topright"), xlim = c(0, 22)
)

villeSecuInfoSup5000Sud <- filter(villeSecuInfo, Population > 5000  & Latitude < 46.3223 & Application != "Inconnue" & CatÃ.gorie != "Inconnue")
barplot(table(villeSecuInfoSup5000Sud$CatÃ.gorie, villeSecuInfoSup5000Sud$Application),
        col = c("green", "yellow", "orange", "red"),
        main = paste("les", nrow(villeSecuInfohttpssup5000Sud), "villes de plus de 5000 habitants du sud en fonction du l'aplication qu'elles utilisent"),
        ylab = "nombre de ville",
        las=3,
        legend.text = c("à jour" ,'Information masqué ',  'Niveau de sécurité incertain',"Pas à jour" ),
        args.legend = list(x = "topright"), xlim = c(0, 22)
)




codeRegion <- substr(ville_secu_info$Code.Insee,0,2)

tablefrequence <- table(villeSecuInfo$https,codeRegion)

subset(villeSecuInfo, codeRegion == 51)




tapply(tablefrequence.Freq, tablefrequence.codeRegion, mean)

meanbp = function(vector) {
    
    for(moncode in vector){
        moncode
    }
    
}
t = meanbp(tablefrequence)
table(t)

meanbp(tablefrequence$Freq,100)


villeSecuInfohttpssup5000Nord <- filter(villeSecuInfo, Population > 5000  & Latitude > 46.3223)
barplot(table(villeSecuInfohttpssup5000Nord$https),
     col = c("red", "blue"),
     main = paste("les", nrow(villeSecuInfohttpssup5000Nord), "villes de plus de 5000 habitants du nord qui ont une adresse https"),
     ylim = c(0,2000),
     xlab = "https",
     ylab = "nombre de ville"
)
villeSecuInfohttpssup5000Sud <- filter(villeSecuInfo, Population > 5000  & Latitude < 46.3223)
barplot(table(villeSecuInfohttpssup5000Sud$https),
        col = c("red", "blue"),
        main = paste("les", nrow(villeSecuInfohttpssup5000Sud), "villes de plus de 5000 habitants du sud qui ont une adresse https"),
        ylim = c(0,2000),
        xlab = "https",
        ylab = "nombre de ville"
)
villeSecuInfohttpssup150000Nord <- filter(villeSecuInfo, Population > 150000  & Latitude > 46.3223)
barplot(table(villeSecuInfohttpssup150000Nord$https),
    col = c("red", "blue"),
    main = paste("les", nrow(villeSecuInfohttpssup150000Nord), "villes de plus de 150 000 habitants du nord qui ont une adresse https"),
    ylim = c(0,15),
    xlab = "https",
    ylab = "nombre de ville"
)
villeSecuInfohttpssup150000Sud <- filter(villeSecuInfo, Population > 150000  & Latitude < 46.3223)
barplot(table(villeSecuInfohttpssup150000Sud$https),
        col = c("red", "blue"),
        main = paste("les", nrow(villeSecuInfohttpssup150000Sud), "villes de plus de 150 000 habitants du sud qui ont une adresse https"),
        ylim = c(0,8),
        xlab = "https",
        ylab = "nombre de ville"
)

#est ce que la taille de la population de la ville influt sur la sécurité du site 

villeSecuInfohttpsnon <- filter(villeSecuInfo, Population > 25000 & https == "non" )
villeSecuInfohttpsoui <- filter(villeSecuInfo, Population > 25000 & https == "oui" )
map(database="france" )
symbols(villeSecuInfohttpsnon$Longitude,
        villeSecuInfohttpsnon$Latitude,
        bg="#e2373f",
        fg="#ffffff",
        lwd=0.5,
        circles=rep(0.2,
        length(villeSecuInfohttpsnon$Longitude)),
        inches=0.05, add=TRUE)

symbols(villeSecuInfohttpsoui$Longitude,
        villeSecuInfohttpsoui$Latitude,
        bg="#3235f0",
        fg="#ffffff",
        lwd=0.5,
        circles=rep(0.2,
        length(villeSecuInfohttpsoui$Longitude)),
        inches=0.05, add=TRUE)
legend(5, 51, legend=c("sans https", "avec https"),
       col=c("red", "blue"), lty=1:1, cex=0.8)
title(main = "position des villes de plus de 25 000 habitants ayant une adresse https")



villeSecuInfoNord <- filter(villeSecuInfo, Population > 150000 & Latitude > 46.3223)
pie(table(villeSecuInfoNord$https),
        col = c("red", "blue"),
        main = paste("les", nrow(villeSecuInfoNord), "villes de plus de 150 000 habitants qui ont une adresse https dans le nord"),
       
        xlab = "https",
        ylab = "nombre de ville"
)

villeSecuInfoSud <- filter(villeSecuInfo, Population > 150000 & Latitude < 46.3223)
pie(table(villeSecuInfoSud$https),
        col = c("red", "blue"),
        main = paste("les", nrow(villeSecuInfoSud), "villes de plus de 150 000 habitants qui ont une adresse https dans le sud"),
        
        xlab = "https",
        ylab = "nombre de ville"
)

villeSecuInfoAppache  <- filter(villeSecuInfo, Population > 25000 & Serveur == "Apache")
villeSecuInfoDiffAp  <- filter(villeSecuInfo, Population > 25000 & Serveur != "Apache")

map(database="france" )
symbols(villeSecuInfoAppache$Longitude,
        villeSecuInfoAppache$Latitude,
        bg="#e2373f",
        fg="#ffffff",
        lwd=0.5,
        circles=rep(0.2,
                    length(villeSecuInfoAppache$Longitude)),
        inches=0.05, add=TRUE)

symbols(villeSecuInfoDiffAp$Longitude,
        villeSecuInfoDiffAp$Latitude,
        bg="#3235f0",
        fg="#ffffff",
        lwd=0.5,
        circles=rep(0.2,
                    length(villeSecuInfoDiffAp$Longitude)),
        inches=0.05, add=TRUE)
legend(5, 51, legend=c("Avec", "Sans"),
       col=c("red", "blue"), lty=1:1, cex=0.8)
title(main = "Ville de plus de 25 000 habitants Utilisant Appache")


villeSecuInfoCategorie <- filter(villeSecuInfo, CatÃ.gorie != "Inconnue")
barplot(table( villeSecuInfoCategorie$CatÃ.gorie ,villeSecuInfo$Serveur),
        col = c("green", "yellow", "orange", "red"),
        main = paste("Niveau de mise à jours des", nrow(villeSecuInfo), " serveurs des sites de ville"),
        ylim = c(0,12000),
        legend.text = c("à jour" ,'Information masqué ',  'Niveau de sécurité incertain',"Pas à jour" ),
        args.legend = list(x = "topright"), xlim = c(0, 22)
)


#par(las=2) # make label text perpendicular to axis
#par(mar=c(5,8,8,2))
par (mgp = c(1, 2, 0))

codeRegion <- substr(villeSecuInfo$`Code.Insee`,0,2)
villeSecuInfoRegionhttps <- filter(villeSecuInfo)
barplot(table(villeSecuInfo$https, codeRegion), 
        main = paste("Les", nrow(villeSecuInfohttpssup5000Nord),
                     "villes de plus de 5000 habitants du nord \n qui ont une adresse https"),
        ylim = c(0,400),
        col = c("red", "blue"),
        legend.text = c("sans https", "avec https"),
        args.legend = list(x = "topright"), xlim = c(0, 100) , las = 3
)








parDep<-function(nDep){
    codeRegionDep <- filter(villeSecuInfo, substr(Code.Insee, 0,2) == nDep)

    count <- table(unlist(codeRegionDep["https"]))
    perc <- 100*count/sum(count)
    result <- data.frame(code = sprintf('%10s', names(count)), 
                        count = as.integer(count), perc = as.numeric(perc))
      
    
    return(result)
}
test <- substr(villeSecuInfo$Code.Insee, 0,2)

listDesDep = c('01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31', '32', '33', '34', '35', '36', '37', '38', '39', '40', '41', '42', '43', '44', '45', '46', '47', '48', '49', '50', '51', '52', '53', '54', '55', '56', '57', '58', '59', '60', '61', '62', '63', '64', '65', '66', '67', '68', '69', '70', '71', '72', '73', '74', '75', '76', '77', '78', '79', '80', '81', '82', '83', '84', '85', '86', '87', '88', '89', '90', '91', '92', '93', '94', '95', '2A', '2B', '971', '972', '973', '974', '975', '976')


prcDep<-function(listDep){
    maListPerc <- list()
    maListCode <- list()
    for ( i in 1:length(listDep)){
        maListPerc <- c( maListPerc, parDep(listDep[i])$perc[1])
        maListCode   <- c( maListCode , listDep[i])
        
    }
    
    final <- do.call(rbind, Map(data.frame, code=maListCode, perc=maListPerc))
    
    
    
    
    return(final)
}
ey <- filter(prcDep(listDesDep), perc < 98)

barplot(ey$perc, 
        main = paste("les ", nrow(ey),
                     "départements \n avec le meilleur ratio de site sécurisé"),
        ylim = c(0,105),
        col = "blue",
        las = 3,
        names.arg = ey$code,
        space = 2
        
)

villeSecuInfohttpsnon <- filter(ey, )

map(database="france" )
symbols(villeSecuInfohttpsnon$Longitude,
        villeSecuInfohttpsnon$Latitude,
        bg="#e2373f",
        fg="#ffffff",
        lwd=0.5,
        circles=rep(0.2,
                    length(villeSecuInfohttpsnon$Longitude)),
        inches=0.05, add=TRUE)






#map(database="world", col="gray")
#symbols(villeSecuInfo$Longitude, villeSecuInfo$Latitude, circles=rep(2, nrow(costcos)), inches=0.05, add=TRUE)



# Plus la version du serveur est élevé, plus il est à jour

# bar plot de tout les serveurs possible, avec leurs fréquence d'utilisé