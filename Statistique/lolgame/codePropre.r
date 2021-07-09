library(questionr)
library(jsonlite)
library(dplyr)

install.packages("rjson")
player_team_lol_data <- read.csv("C:\\Users\\dahie\\Documents\\Statistique\\lolgame\\player_team_lol_data.csv", header=TRUE)
playerTeamLolData <- read.csv("C:\\Users\\dahie\\Documents\\Statistique\\lolgame\\player_team_lol_data.csv", header=TRUE)
champion <- read.csv("C:\\Users\\dahie\\Documents\\Statistique\\lolgame\\champion.csv", header=TRUE)
View(player_team_lol_data)

#Problematique 

library(dplyr)




moyenneKilsWin <- (mean(gameWin$kills1) + mean(gameWin$kills1) + mean(gameWin$kills1)
                        +mean(gameWin$kills1) + mean(gameWin$kills1))/5


moyenneKilsLoose <- (mean(gameLoose$kills1) + mean(gameLoose$kills1) + mean(gameLoose$kills1)
                   +mean(gameLoose$kills1) + mean(gameLoose$kills1))/5



kills <- table(c(gameWin$kills1 , gameWin$kills2 , gameWin$kills3 ,gameWin$kills4,gameWin$kills5))
win <- table(c(gameWin$winTeam1,gameWin$winTeam1,gameWin$winTeam1,gameWin$winTeam1,gameWin$winTeam1))


plot(c(player_team_lol_data$kills1,player_team_lol_data$kills2,
       player_team_lol_data$kills3,player_team_lol_data$kills4,
       player_team_lol_data$kills5))


#### Correlation heros jouer et victoire ####
# 
# plot(player_team_lol_data$championID1 , player_team_lol_data$kills1)
# 
# cor(player_team_lol_data$championID1 , player_team_lol_data$kills1)
# 
# boxplot(c(player_team_lol_data$championID1,player_team_lol_data$championID2,
#           player_team_lol_data$championID3,player_team_lol_data$championID4,
#           player_team_lol_data$championID5)
#         ~ c(player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
#             player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
#             player_team_lol_data$winTeam1))

#################################        Win / kils     ######################################
boxplot( c(player_team_lol_data$kills1,player_team_lol_data$kills2,
           player_team_lol_data$kills3,player_team_lol_data$kills4,
           player_team_lol_data$kills5)
~ c(player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
    player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
    player_team_lol_data$winTeam1) , ylim=c(0,17) , xlab = "Resultat de la partie" ,
    ylab = "Nombre de kills  " , 
    col = c("red" , "green"),
    main = "Graphique montrant le nombre de Kills des membre \n de l'equipe en fonction du resultat de la partie ")  


#################################        Win / Death     ######################################
boxplot( c(player_team_lol_data$deaths1,player_team_lol_data$deaths2,
           player_team_lol_data$deaths3,player_team_lol_data$deaths4,
           player_team_lol_data$deaths5)
         ~ c(player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
             player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
             player_team_lol_data$winTeam1),
         ylim=c(0,17) , xlab = "Resultat de la partie" ,
         ylab = "Nombre de deaths  " , 
         col = c("red" , "green"),
         main = "Graphique montrant le nombre de deaths des membre \n de l'equipe en fonction du resultat de la partie ")  

## Corelation Level et Victoire ####

boxplot(c(player_team_lol_data$championLevel1,player_team_lol_data$championLevel2,
          player_team_lol_data$championLevel3,player_team_lol_data$championLevel4,
          player_team_lol_data$championLevel5)
        ~ c(player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
            player_team_lol_data$winTeam1 , player_team_lol_data$winTeam1,
            player_team_lol_data$winTeam1),
        ylim=c(0,20) , xlab = "Resultat de la partie" ,
        ylab = "Level  " , 
        col = c("red" , "green"),
        main = "Graphique montrant le Level des membres \n de l'equipe en fonction du resultat de la partie ")  




### Corelation level et gold ####### 

plot(c(player_team_lol_data$championLevel1,player_team_lol_data$championLevel2,
       player_team_lol_data$championLevel3 ,player_team_lol_data$championLevel4,
       player_team_lol_data$championLevel5),
     c( player_team_lol_data$gold1, player_team_lol_data$gold2, player_team_lol_data$gold3
        , player_team_lol_data$gold4, player_team_lol_data$gold5) ,
      , xlab = "Levels" ,
     ylab = "Gold " , 
     main = "Graphique montrant le Level des membres \n de l'equipe en fonction des golds recupere ")  

cor(c(player_team_lol_data$championLevel1,player_team_lol_data$championLevel2,
      player_team_lol_data$championLevel3 ,player_team_lol_data$championLevel4,
      player_team_lol_data$championLevel5),
    c( player_team_lol_data$gold1, player_team_lol_data$gold2, player_team_lol_data$gold3
       , player_team_lol_data$gold4, player_team_lol_data$gold5))

##Cor de 0.88

### Corelation level et baron kills 



plot(c(player_team_lol_data$championLevel1,player_team_lol_data$championLevel2,
       player_team_lol_data$championLevel3,player_team_lol_data$championLevel4,
       player_team_lol_data$championLevel5),
     c (player_team_lol_data$baronKillsTeam1, player_team_lol_data$baronKillsTeam1,
        player_team_lol_data$baronKillsTeam1,player_team_lol_data$baronKillsTeam1,
        player_team_lol_data$baronKillsTeam1 ),
     xlab = "Levels" ,
     ylab = "Barons Kill" , 
     main = "Graphique montrant le nombre de Baron Kill \n de l'equipe en fonction des levels")  

cor(c(player_team_lol_data$championLevel1,player_team_lol_data$championLevel2,
      player_team_lol_data$championLevel3,player_team_lol_data$championLevel4,
      player_team_lol_data$championLevel5),
    c (player_team_lol_data$baronKillsTeam1, player_team_lol_data$baronKillsTeam1,
       player_team_lol_data$baronKillsTeam1,player_team_lol_data$baronKillsTeam1,
       player_team_lol_data$baronKillsTeam1 ))


#Cor de 0.39 

#################################Correlation Dragon deaths enemi  ######################################
plot(c(player_team_lol_data$dragonKillsTeam1,player_team_lol_data$dragonKillsTeam1,
       player_team_lol_data$dragonKillsTeam1,player_team_lol_data$dragonKillsTeam1,
       player_team_lol_data$dragonKillsTeam1),c(player_team_lol_data$deaths6,
                                                player_team_lol_data$deaths7,
                                                player_team_lol_data$deaths8,
                                                player_team_lol_data$deaths9,
                                                player_team_lol_data$deaths10))


cor(c(player_team_lol_data$dragonKillsTeam1,player_team_lol_data$dragonKillsTeam1,
      player_team_lol_data$dragonKillsTeam1,player_team_lol_data$dragonKillsTeam1,
      player_team_lol_data$dragonKillsTeam1),c(player_team_lol_data$deaths6,
                                               player_team_lol_data$deaths7,
                                               player_team_lol_data$deaths8,
                                               player_team_lol_data$deaths9,
                                               player_team_lol_data$deaths10))

##Cor de 0.27 



### Corrrelation Minions kills ###


plot(player_team_lol_data$kills1 , player_team_lol_data$minionsKill1)
cor(player_team_lol_data$kills1 , player_team_lol_data$minionsKill1)

## Cpr de 0.25




### Corellation baronskills / win ### 

cor(player_team_lol_data$baronKillsTeam1 , player_team_lol_data$baronKillsTeam2)
boxplot(player_team_lol_data$baronKillsTeam1 ~  player_team_lol_data$winTeam1 , ylim = c(0,1.3))




#barplot(mean(player_team_lol_data$championLevel1) , mean(player_team_lol_data$baronKillsTeam1))


### Corelation  level et kills 
cor(player_team_lol_data$kills1 , player_team_lol_data$assists1)



#### Calcul qantile kills #### 
gameDurationTrue <- filter (player_team_lol_data  , gameDuration > 300 )
quantkills25 <- quantile(gameDurationTrue$kills1 , prob = 0.25) #2
quantkills50 <- quantile(gameDurationTrue$kills1 , prob = 0.50) #4
quantkills75 <- quantile(gameDurationTrue$kills1 , prob = 0.75) #7

quantAssits25 <- quantile(gameDurationTrue$assists1 , prob = 0.25) #4
quantAssits50 <- quantile(gameDurationTrue$assists1 , prob = 0.50) #7
quantAssits75 <- quantile(gameDurationTrue$assists1 , prob = 0.75) # 12



############################          MVP           ###########################################
mvp <- filter (player_team_lol_data , kills1 > 7  ,lane1 != " NONE" , gameDuration > 300 )
laneWinMvp <- table(mvp$lane1 , mvp$winTeam1)

player_team_lol_data$gameDuration

lprop(laneWinMvp)
cprop(laneWinMvp)

# On observe que la lane dans laquelles  un joueur faisant plus de 10 kills joue importe peu sur la victoire de son equipe
#. Si il fait plus de 10 kills  o? qu'il soit , sont ?quipe ? une plus grande chance de gagner  .



#################################         WVP       ######################################

wvp <- filter (player_team_lol_data , kills1 <=2  ,lane1 != " NONE")
laneWinWvp <- table(wvp$lane1 , wvp$winTeam1)


lprop(laneWinWvp)
cprop(laneWinWvp)
# On  remarque que si un joueur  ayant un score de kills  >= 2  se trouvant  dans la lane  jungle  , son ?quipe est ? 7.1 % de victoire 
#alors que si  il se trouve dans la la bottom , son ?quipe est ? 60 % de victoire 


#################################         assist     ######################################

assist <- filter(player_team_lol_data , kills1 <2 , assists1 > 12  ,lane1 != " NONE")
laneWinAssist <- table(assist$lane1 , assist$winTeam1)


lprop(laneWinAssist)
cprop(laneWinAssist)
# On  remarque que si un joueur  ayant un score de kills  <= 2   mais plus de 12 assist joue dans le middle ou top son ?quipe ?  100 % de chance de win


#################################       Moyenne kilss det victoire    ######################################


gameWin <- filter(player_team_lol_data, winTeam1 == " Win")
gameLoose <- filter(player_team_lol_data, winTeam1 == " Fail")



gameLooseKills <- c(mean(gameLoose$kills1),
                    mean(gameLoose$kills2),
                    mean(gameLoose$kills3),
                    mean(gameLoose$kills4),
                    mean(gameLoose$kills5))

gameWinKills <- c(mean(gameWin$kills1),
                  mean(gameWin$kills2),
                  mean(gameWin$kills3),
                  mean(gameWin$kills4),
                  mean(gameWin$kills5))



kills <- c(gameWin$kills1,
          gameWin$kills2,
           gameWin$kills3,
           gameWin$kills4,
           gameWin$kills5)

death <- c(gameWin$deaths1,
           gameWin$deaths2,
           gameWin$deaths3,
           gameWin$deaths4,
           gameWin$deaths5)




plot(kills , death)

tab<-rbind(gameLooseKills,gameWinKills)

b<-barplot(tab,
           ,axisnames=TRUE,beside=TRUE , names.arg = c("J1" , "J2","J3","J4","J5")
           , ylim = c(0,7) , col = c("red","green","red","green","red","green","red","green","red","green") , xlab = "Num?ro de Joeurs et r?sultat (gagnants ou perdant)" , ylab= "moyenne Nb Kills" ,
           main = "Graphique montrant la moyenne des kills de chaque joueur en fonction de la vicoire ou défaite ")

legend('topleft', cex=1,  c('Loose' , 'Win'), fill=c('red', 'green'))




Win <-  filter(player_team_lol_data, winTeam1 == " Win")
Loose <- filter(player_team_lol_data, winTeam2 == " Fail")



barplot(table(( c(player_team_lol_data$lane1,
                  player_team_lol_data$lane2,
                  player_team_lol_data$lane3,
                  player_team_lol_data$lane4,
                  player_team_lol_data$lane5)),
              c(player_team_lol_data$kills1,
                player_team_lol_data$kills2,
                player_team_lol_data$kills3,
                player_team_lol_data$kills4,
                player_team_lol_data$kills5)
),
col = c("red", "green", "blue", "purple", "brown"),
legend.text = c('BOTTOM' , 'JUNGLE', 'MIDDLE', 'NONE', 'TOP'),
args.legend = list(x = "topright") , xlim=c(0,22))
#, c(mean(Win$towerKillsTeams1),mean(Loose$towerKillsTeams2))
# l'équipe du joueur qui fait le first kill gagne :
#l'équipe qui débloque le plus de dragons gagne :
#quel est le meilleur champion :
#quelle est la meilleure composition pour gagner:
# quel est le héro le plus ban 



###### Noms des heros # ######
champion <- read.csv("C:\\Users\\sburd\\Desktop\\CoursSDNL3S1\\stats\\stat_LOL\\champion.csv", header=TRUE)



functionPourcentagePerso<-function(typeChampionKey , testChampionId){
    conteur <- 0
   for (i in 1:length(typeChampionKey)) {
    b <-typeChampionKey[i]
    for(j in 1:length(testChampionId)){
      c <- testChampionId[j]
      if(b == c ){
        conteur<- conteur + 1
      }
    }
   }
    return ((conteur/length(testChampionId))*100)
}


barplot(table(champion$data__.__tags__001))


####Champions composition moyenne victoire #######

# championSupport <- filter(champion ,data__.__tags__001 == "Support" | data__.__tags__002 == "Support" )
# championAssassin <- filter(champion ,data__.__tags__001 == "Assassin" | data__.__tags__002 == "Assassin" )
# championFighter <- filter(champion ,data__.__tags__001 == "Fighter" | data__.__tags__002 == "Fighter" )
# championMage <- filter(champion ,data__.__tags__001 == "Mage" | data__.__tags__002 == "Mage" )
# championTank <- filter(champion ,data__.__tags__001 == "Tank" | data__.__tags__002 == "Tank" )
# championMarksman <- filter(champion ,data__.__tags__001 == "Marksman" | data__.__tags__002 == "Marksman" )
# 
# 
# support <- functionPourcentagePerso(championSupport$data__.__key,Win$championID1) # 26.00
# assassin <- functionPourcentagePerso(championAssassin$data__.__key,Win$championID1) # 30.00
# fighter <- functionPourcentagePerso(championFighter$data__.__key,Win$championID1)# 37.00
# mage <- functionPourcentagePerso(championMage$data__.__key,Win$championID1) # 37
# tank<- functionPourcentagePerso(championTank$data__.__key,Win$championID1) # 17 
# marksman <- functionPourcentagePerso(championMarksman$data__.__key,Win$championID1) # 22 




championSupport <- filter(champion ,data__.__tags__001 == "Support" )
championAssassin <- filter(champion ,data__.__tags__001 == "Assassin")
championFighter <- filter(champion ,data__.__tags__001 == "Fighter" )
championMage <- filter(champion ,data__.__tags__001 == "Mage"  )
championTank <- filter(champion ,data__.__tags__001 == "Tank" )
championMarksman <- filter(champion ,data__.__tags__001 == "Marksman"  )


supportWin <- functionPourcentagePerso(championSupport$data__.__key,gameWin$championID1) # 14.00
assassinWin <- functionPourcentagePerso(championAssassin$data__.__key,gameWin$championID1) # 12.00
fighterWin <- functionPourcentagePerso(championFighter$data__.__key,gameWin$championID1)# 27.00
mageWin <- functionPourcentagePerso(championMage$data__.__key,gameWin$championID1) # 17
tankWin<- functionPourcentagePerso(championTank$data__.__key,gameWin$championID1) # 6.25
marksmanWin <- functionPourcentagePerso(championMarksman$data__.__key,gameWin$championID1) # 21




slices <-c(14,12,27,17,6.25,21)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportWin,assassinWin,fighterWin,mageWin,tankWin,marksmanWin) , labels = lbls ,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe victorieuse")



###### heros composition moyenne defaite ######




supportLoose <- functionPourcentagePerso(championSupport$data__.__key,gameLoose$championID1) # 10.55
assassinLoose <- functionPourcentagePerso(championAssassin$data__.__key,gameLoose$championID1) # 14.88
fighterLoose <- functionPourcentagePerso(championFighter$data__.__key,gameLoose$championID1)# 23.52
mageLoose <- functionPourcentagePerso(championMage$data__.__key,gameLoose$championID1) # 17.27
tankLoose<- functionPourcentagePerso(championTank$data__.__key,gameLoose$championID1) # 9.92
marksmanLoose <- functionPourcentagePerso(championMarksman$data__.__key,gameLoose$championID1) # 23




slices <-c(10.55,14.88,23.52,17.27,9.92,23)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportLoose,assassinLoose,fighterLoose,mageLoose,tankLoose,marksmanLoose) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe perdante")




##### Heros les pluis joué Win  ######

count <- table(unlist(gameWin$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiers <- result[order(-perc),]

detach(result)

premier5 <-premiers[1:5,]



functionCorrespondanceKeyNom <- 
  function(key){
    championNom <- filter(champion , data__.__key == key)
    return (championNom[,4])
  }


functionListeKeyNom <- 
  function(listeKey){
    liste <- list(length(listeKey))
    for( i in 1:length(listeKey)){
      liste[[i]] <- functionCorrespondanceKeyNom(listeKey[i])
    }
    return(liste)
  
  }





bestHero <- barplot(premier10$perc , ylim=c(0,5) , names.arg = c(functionCorrespondanceKeyNom(051) , 
        functionCorrespondanceKeyNom(236),functionCorrespondanceKeyNom(022),
        functionCorrespondanceKeyNom(040), functionCorrespondanceKeyNom(432)),
        xlab = " Noms des Personnages" , ylab="Présence des heros lors de victoire (%)",
        main = "Graphique montrant les 5 héros les plus joués lors de Victoire  ",
        col = c("red","orange","yellow","blue","green"))


percValeurs<-as.matrix(premier10$perc)

text(bestHero,percValeurs+0.3,labels=as.character(paste(round(percValeurs,3),"%")) )




##### Heros les pluis joué Loose  ######


count <- table(unlist(gameLoose$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiersLoose <- result[order(-perc),]

detach(result)

premier5Loose <-premiersLoose[1:5,]


worstHero <- barplot(premier5Loose$perc , ylim=c(0,5) , 
                    names.arg = c(functionCorrespondanceKeyNom(022) , 
                                  functionCorrespondanceKeyNom(236),functionCorrespondanceKeyNom(104),
                                  functionCorrespondanceKeyNom(084),functionCorrespondanceKeyNom(202)),
                    xlab = " Noms des Personnages" , ylab="Présence des heros lors de defaite(%)",
                    main = "Graphique montrant les 5 héros les plus joué lors de defaite  ",
                    col = c("red","orange","yellow","blue","green"))


percValeurs<-as.matrix(premier5Loose$perc)

text(worstHero,percValeurs+0.3,labels=as.character(paste(round(percValeurs,3),"%")) )


###### Heros par lane ############

bottomWin <- filter(gameWin , gameDuration > 300 , lane1 == " BOTTOM")
TopWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")
jungleWin<- filter(gameWin , gameDuration > 300 , lane1 == " JUNGLE")
middleWin <- filter(gameWin , gameDuration > 300 , lane1 == " MIDDLE")

bottom <- filter(player_team_lol_data, gameDuration > 300 , lane1 == " BOTTOM")



count <- table(unlist(bottomWin$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiersBottomWin <- result[order(-perc),]

detach(result)

premier5BottomWin <-premiersBottomWin[1:5,]


bestHeroBottomWin <- barplot(premier5BottomWin$perc , ylim=c(0,10) , 
                     names.arg = c(functionCorrespondanceKeyNom(022), 
                     functionCorrespondanceKeyNom(051),functionCorrespondanceKeyNom(040),
                     functionCorrespondanceKeyNom(080),functionCorrespondanceKeyNom(432)),
                     xlab = " Noms des Personnages" , ylab="Présence des heros lors de Victoire(%)",
                     main = "Graphique montrant les 5 héros les plus joué lors de Victoire \n
                     a la lane Bottom",
                     col = c("red","orange","yellow","blue","green"))

percValeurs<-as.matrix(premier5BottomWin$perc)

text(bestHeroBottomWin,percValeurs+0.3,labels=as.character(paste(round(percValeurs,3),"%")) )


###### TOP #######


count <- table(unlist(topWin$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiersTopWin <- result[order(-perc),]

detach(result)

premier5TopWin <-premiersTopWin[1:5,]


bestHeroTopWin <- barplot(premier5TopWin$perc , ylim=c(0,10) , 
                             names.arg = c(functionCorrespondanceKeyNom(022), 
                                           functionCorrespondanceKeyNom(051),functionCorrespondanceKeyNom(040),
                                           functionCorrespondanceKeyNom(080),functionCorrespondanceKeyNom(432)),
                             xlab = " Noms des Personnages" , ylab="Présence des heros lors de Victoire(%)",
                             main = "Graphique montrant les 5 héros les plus joué lors de Victoire \n
                     a la lane Top",
                             col = c("red","orange","yellow","blue","green"))

percValeurs<-as.matrix(premier5TopWin$perc)

text(bestHeroTopWin,percValeurs+0.3,labels=as.character(paste(round(percValeurs,3),"%")) )


####### Jungle ######


count <- table(unlist(jungleWin$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiersJungleWin <- result[order(-perc),]

detach(result)

premier5JungleWin <-premiersJungleWin[1:5,]


bestHeroJungleWin <- barplot(premier5JungleWin$perc , ylim=c(0,18) , 
                          names.arg = c(functionCorrespondanceKeyNom(064), 
                                        functionCorrespondanceKeyNom(120),functionCorrespondanceKeyNom(076),
                                        functionCorrespondanceKeyNom(104),functionCorrespondanceKeyNom(876)),
                          xlab = " Noms des Personnages" , ylab="Présence des heros lors de Victoire(%)",
                          main = "Graphique montrant les 5 héros les plus joué lors de Victoire \n
                     a la lane Jungle",
                          col = c("red","orange","yellow","blue","green"))

percValeurs<-as.matrix(premier5JungleWin$perc)

text(bestHeroJungleWin,percValeurs+0.5,labels=as.character(paste(round(percValeurs,3),"%")) )



####### MIDDLE ###########

count <- table(unlist(middleWin$championID1))
perc <- 100*count/sum(count)
result <- data.frame(code = sprintf("%03d", as.integer(names(count))), 
                     count = as.integer(count), perc = as.numeric(perc)) 



attach(result) 
premiersMiddleWin <- result[order(-perc),]

detach(result)

premier5MiddleWin <-premiersMiddleWin[1:5,]


bestHeroMiddleWin <- barplot(premier5MiddleWin$perc , ylim=c(0,12) , 
                             names.arg = c(functionCorrespondanceKeyNom(236), 
                                           functionCorrespondanceKeyNom(084),functionCorrespondanceKeyNom(134),
                                           functionCorrespondanceKeyNom(777),functionCorrespondanceKeyNom(061)),
                             xlab = " Noms des Personnages" , ylab="Présence des heros lors de Victoire(%)",
                             main = "Graphique montrant les 5 héros les plus joué lors de Victoire \n
                     a la lane Middle",
                             col = c("red","orange","yellow","blue","green"))

percValeurs<-as.matrix(premier5MiddleWin$perc)

text(bestHeroMiddleWin,percValeurs+0.5,labels=as.character(paste(round(percValeurs,3),"%")) )



###### Classe Win Par Lane #######


championSupport <- filter(champion ,data__.__tags__001 == "Support")
championAssassin <- filter(champion ,data__.__tags__001 == "Assassin" )
championFighter <- filter(champion ,data__.__tags__001 == "Fighter"  )
championMage <- filter(champion ,data__.__tags__001 == "Mage"    )
championTank <- filter(champion ,data__.__tags__001 == "Tank"  )
championMarksman <- filter(champion ,data__.__tags__001 == "Marksman"  )








# 
# supportLoose<- functionPourcentagePerso(championSupport$data__.__key,bottomLoose$championID1) # 31.93
# assassinLoose  <- functionPourcentagePerso(championAssassin$data__.__key,bottomLoose$championID1) # 1.68
# fighterLoose  <- functionPourcentagePerso(championFighter$data__.__key,bottomLoose$championID1)# 9.24
# mageLoose  <- functionPourcentagePerso(championMage$data__.__key,bottomWLoose$championID1) # 13.44
# tankLoose <- functionPourcentagePerso(championTank$data__.__key,bottomLoose$championID1) # 6.72
# marksmanLoose  <- functionPourcentagePerso(championMarksman$data__.__key,bottomLoose$championID1) # 36




######### BOTTOM ######

#############Win###############


bottomWin <- filter(gameWin , gameDuration > 300 , lane1 == " BOTTOM")


supportWinBottom <- functionPourcentagePerso(championSupport$data__.__key,bottomWin$championID1) # 31.93
assassinWinBottom <- functionPourcentagePerso(championAssassin$data__.__key,bottomWin$championID1) # 1.68
fighterWinBottom <- functionPourcentagePerso(championFighter$data__.__key,bottomWin$championID1)# 9.24
mageWinBottom <- functionPourcentagePerso(championMage$data__.__key,bottomWin$championID1) # 13.44
tankWinBottom<- functionPourcentagePerso(championTank$data__.__key,bottomWin$championID1) # 6.72
marksmanWinBottom <- functionPourcentagePerso(championMarksman$data__.__key,bottomWin$championID1) # 36





slices <-c(31.93,1.68,9.24,13.24,6.72,36)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportWinBottom,assassinWinBottom,fighterWinBottom,mageWinBottom,tankWinBottom,marksmanWinBottom) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe gagnante en Bottom ")


#############Loose #############


bottomLoose <- filter(gameLoose, gameDuration > 300 , lane1 == " BOTTOM")
topLoose <- filter(gameLoose, gameDuration > 300 , lane1 == " TOP")
jungleLoose<- filter(gameLoose , gameDuration > 300 , lane1 == " JUNGLE")
middleLoose <- filter(gameLoose , gameDuration > 300 , lane1 == " MIDDLE")


supportLooseBottom <- functionPourcentagePerso(championSupport$data__.__key,bottomLoose$championID1) # 28.67
assassinLooseBottom <- functionPourcentagePerso(championAssassin$data__.__key,bottomLoose$championID1) # 2.09
fighterLooseBottom <- functionPourcentagePerso(championFighter$data__.__key,bottomLoose$championID1)# 7.69
mageLooseBottom <- functionPourcentagePerso(championMage$data__.__key,bottomLoose$championID1) # 14.68
tankLooseBottom<- functionPourcentagePerso(championTank$data__.__key,bottomLoose$championID1) # 6.29
marksmanLooseBottom <- functionPourcentagePerso(championMarksman$data__.__key,bottomLoose$championID1) # 40

supportLooseBottom 
assassinLooseBottom 
fighterLooseBottom 
mageLooseBottom 
tankLooseBottom
marksmanLooseBottom 





slices <-c(28.67,2.09,7.69,14.68,6.29,40)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportLooseBottom,assassinLooseBottom,fighterLooseBottom,mageLooseBottom,tankLooseBottom,marksmanLooseBottom) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe Perdante en Bottom ")





######### TOP ######

bottomWin <- filter(gameWin , gameDuration > 300 , lane1 == " BOTTOM")
TopWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")
jungleWin<- filter(gameWin , gameDuration > 300 , lane1 == " JUNGLE")
middleWin <- filter(gameWin , gameDuration > 300 , lane1 == " MIDDLE")

#############Win###############

topWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")



supportWinTop <- functionPourcentagePerso(championSupport$data__.__key,topWin$championID1) # 4.39
assassinWinTop<- functionPourcentagePerso(championAssassin$data__.__key,topWin$championID1) # 7.62
fighterWinTop <- functionPourcentagePerso(championFighter$data__.__key,topWin$championID1)# 53.85
mageWinTop <- functionPourcentagePerso(championMage$data__.__key,topWin$championID1) # 12.08
tankWinTop<- functionPourcentagePerso(championTank$data__.__key,topWin$championID1) # 15.38
marksmanWinTop <- functionPourcentagePerso(championMarksman$data__.__key,topWin$championID1) # 6.59

supportWinTop
assassinWinTop
fighterWinTop
tankWinTop
mageWinTop
marksmanWinTop

slices <-c(4.39,7.62,53.85,12.08,15.38,6.59)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportWinTop,assassinWinTop,fighterWinTop,mageWinTop,tankWinTop,marksmanWinTop) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe gagnante en Top ")


#############Loose #############



supportLooseTop <- functionPourcentagePerso(championSupport$data__.__key,topLoose$championID1) # 0
assassinLooseTop <- functionPourcentagePerso(championAssassin$data__.__key,topLoose$championID1) # 7.36
fighterLooseTop <- functionPourcentagePerso(championFighter$data__.__key,topLoose$championID1)# 50.52
mageLooseTop <- functionPourcentagePerso(championMage$data__.__key,topLoose$championID1) # 10.52
tankLooseTop<- functionPourcentagePerso(championTank$data__.__key,topLoose$championID1) # 22.10
marksmanLooseTop<- functionPourcentagePerso(championMarksman$data__.__key,topLoose$championID1) # 9.47

supportLooseTop
assassinLooseTop
fighterLooseTop
mageLooseTop
tankLooseTop
marksmanLooseTop





slices <-c(supportLooseTop,
           assassinLooseTop,
           fighterLooseTop,
           mageLooseTop,
           tankLooseTop,
           marksmanLooseTop,
)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("assassin","fighter","mage","tank","marksman")
pie(c(supportLooseTop,assassinLooseTop,fighterLooseTop,mageLooseTop,tankLooseTop,marksmanLooseTop) , labels = lbls,  col =c("White","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe Perdante en Top ")





######### Jungle #####

bottomWin <- filter(gameWin , gameDuration > 300 , lane1 == " BOTTOM")
TopWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")
jungleWin<- filter(gameWin , gameDuration > 300 , lane1 == " JUNGLE")
middleWin <- filter(gameWin , gameDuration > 300 , lane1 == " MIDDLE")

#############Win###############

jungleWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")



supportWinJungle <- functionPourcentagePerso(championSupport$data__.__key,jungleWin$championID1) # 4.39
assassinWinJungle<- functionPourcentagePerso(championAssassin$data__.__key,jungleWin$championID1) # 7.62
fighterWinJungle <- functionPourcentagePerso(championFighter$data__.__key,jungleWin$championID1)# 53.85
mageWinJungle <- functionPourcentagePerso(championMage$data__.__key,jungleWin$championID1) # 12.08
tankWinJungle<- functionPourcentagePerso(championTank$data__.__key,jungleWin$championID1) # 15.38
marksmanWinJungle <- functionPourcentagePerso(championMarksman$data__.__key,jungleWin$championID1) # 6.59

supportWinJungle
assassinWinJungle
fighterWinJungle
tankWinJungle
mageWinJungle
marksmanWinJungle

slices <-c(2.89,21.73,50.72,2.89,10.14,11.59)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportWinJungle,assassinWinJungle,fighterWinJungle,mageWinJungle,tankWinJungle,marksmanWinJungle) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe gagnante en Jungle ")


#############Loose #############


supportLooseJungle <- functionPourcentagePerso(championSupport$data__.__key,jungleLoose$championID1) # 4.39
assassinLooseJungle<- functionPourcentagePerso(championAssassin$data__.__key,jungleLoose$championID1) # 7.62
fighterLooseJungle <- functionPourcentagePerso(championFighter$data__.__key,jungleLoose$championID1)# 53.85
mageLooseJungle <- functionPourcentagePerso(championMage$data__.__key,jungleLoose$championID1) # 12.08
tankLooseJungle<- functionPourcentagePerso(championTank$data__.__key,jungleLoose$championID1) # 15.38
marksmanLooseJungle <- functionPourcentagePerso(championMarksman$data__.__key,jungleLoose$championID1) # 6.59



slices <-c(supportLooseJungle,
assassinLooseJungle,
fighterLooseJungle,
tankLooseJungle,
mageLooseJungle,
marksmanLooseJungle)


lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(supportLooseJungle,
      assassinLooseJungle,
      fighterLooseJungle,
      tankLooseJungle,
      mageLooseJungle,
      marksmanLooseJungle) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe perdante en Jungle ")



######## Middle ######



bottomWin <- filter(gameWin , gameDuration > 300 , lane1 == " BOTTOM")
TopWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")
jungleWin<- filter(gameWin , gameDuration > 300 , lane1 == " JUNGLE")
middleWin <- filter(gameWin , gameDuration > 300 , lane1 == " MIDDLE")

#############Win###############

jungleWin <- filter(gameWin , gameDuration > 300 , lane1 == " TOP")



supportWinMiddle <- functionPourcentagePerso(championSupport$data__.__key,middleWin$championID1) # 4.39
assassinWinMiddle <- functionPourcentagePerso(championAssassin$data__.__key,middleWin$championID1) # 7.62
fighterWinMiddle  <- functionPourcentagePerso(championFighter$data__.__key,middleWin$championID1)# 53.85
mageWinMiddle  <- functionPourcentagePerso(championMage$data__.__key,middleWin$championID1) # 12.08
tankWinMiddle <- functionPourcentagePerso(championTank$data__.__key,middleWin$championID1) # 15.38
marksmanWinMiddle  <- functionPourcentagePerso(championMarksman$data__.__key,middleWin$championID1) # 6.59

supportWinMiddle
assassinWinMiddle
fighterWinMiddle
tankWinMiddle
mageWinMiddle
marksmanWinMiddle

slices <-c(
  supportWinMiddle,
  assassinWinMiddle,
  fighterWinMiddle,
  tankWinMiddle,
  mageWinMiddle,
  marksmanWinMiddle)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(
  supportWinMiddle,
  assassinWinMiddle,
  fighterWinMiddle,
  tankWinMiddle,
  mageWinMiddle,
  marksmanWinMiddle) , labels = lbls,  col =c("white","black","red","blue","brown","green")
    ,main="Graphique représentant la compisition moyenne d'une équipe gagnante en Middle ")


#############Loose #############

supportLooseMiddle <- functionPourcentagePerso(championSupport$data__.__key,middleLoose$championID1) # 4.39
assassinLooseMiddle <- functionPourcentagePerso(championAssassin$data__.__key,middleLoose$championID1) # 7.62
fighterLooseMiddle  <- functionPourcentagePerso(championFighter$data__.__key,middleLoose$championID1)# 53.85
mageLooseMiddle  <- functionPourcentagePerso(championMage$data__.__key,middleLoose$championID1) # 12.08
tankLooseMiddle <- functionPourcentagePerso(championTank$data__.__key,middleLoose$championID1) # 15.38
marksmanLooseMiddle  <- functionPourcentagePerso(championMarksman$data__.__key,middleLoose$championID1) # 6.59

supportLooseMiddle
assassinLooseMiddle
fighterLooseMiddle
tankLooseMiddle
mageLooseMiddle
marksmanLooseMiddle

slices <-c(supportLooseMiddle,
           assassinLooseMiddle,
           fighterLooseMiddle,
           tankLooseMiddle,
           mageLooseMiddle,
           marksmanLooseMiddle
)
lbls <- c("Support","Assassin","Fighter","Mage","Tank","Marksman")
pct <- pct <- round(slices/sum(slices)*100)
lbls <- paste(lbls, pct) # add percents to labels
lbls <- paste(lbls,"%",sep="") # ad % to labels

championsNames = c("support","assassin","fighter","mage","tank","marksman")
pie(c(
  supportLooseMiddle,
  assassinLooseMiddle,
  fighterLooseMiddle,
  tankLooseMiddle,
  mageLooseMiddle,
  marksmanLooseMiddle
) , labels = lbls,  col =c("white","black","red","blue","brown","green")
  ,main="Graphique représentant la compisition moyenne d'une équipe perdante en Middle ")

