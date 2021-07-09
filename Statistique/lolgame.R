library(questionr)
library(jsonlite)
library(dplyr)

install.packages("rjson")
playerTeamLolData <- read.csv("C:\\Users\\dahie\\Documents\\Statistique\\LOL_java_project\\files\\data\\player_team_lol_data.csv")
#View(player_team_lol_data)



#game <- read_json("~/Statistique/lolgame/lolgamefic.json", header=FALSE)
#timeline <- read_json("~/Statistique/lolgame/timeline.json", header=FALSE)
#champion<- read_json("~/Statistique/lolgame/champion.json", header=FALSE)



#table1 <- (game$)

#Si Les Levels d'une équipe sont superieurs à l'équipe adverse, elle l'emporte :


#Problématique : nous allons analyser les meilleurs compositions de héros ainsi que leurs placements optimaux sur les maps lors de victoires 

# Si une équipe a détruit le plus de tours, elle gagne :
# Si l'équipe qui est le mieux dispercée sur la carte gagne :
#l'équipe qui a le plus de kills l'emporte :
#ptld <- player_team_lol_data
#View(ptld)
tableKill <- table(
                  c(playerTeamLolData$kills1, 
                    playerTeamLolData$kills2,
                    playerTeamLolData$kills3, 
                    playerTeamLolData$kills4, 
                    playerTeamLolData$kills5, 
                    playerTeamLolData$kills6))
                     
tabledeath <- table(c(playerTeamLolData$death1, 
                      playerTeamLolData$death2,
                      playerTeamLolData$death3, 
                      playerTeamLolData$death4, 
                      playerTeamLolData$death5, 
                      playerTeamLolData$death6))


tablelane <- table(c(playerTeamLolData$lane1, 
                     playerTeamLolData$lane2,
                     playerTeamLolData$lane3, 
                     playerTeamLolData$lane4, 
                     playerTeamLolData$lane5, 
                     playerTeamLolData$lane6))


barplot(table(( c(playerTeamLolData$lane1,
                  playerTeamLolData$lane2,
                  playerTeamLolData$lane3,
                  playerTeamLolData$lane4,
                  playerTeamLolData$lane5)),
               c(playerTeamLolData$kills1,
                 playerTeamLolData$kills2,
                 playerTeamLolData$kills3,
                 playerTeamLolData$kills4,
                 playerTeamLolData$kills5)
               ),
        col = c("red", "green", "blue", "white", "yellow"),
        legend.text = c('BOTTOM' , 'JUNGLE', 'MIDDLE', 'NONE', 'TOP'),
        args.legend = list(x = "topright"), xlim = c(0, 22),
      main = "graphique des Kill en fonction de lane",
      xlab = "nombre de lane", ylab = "nombre de kill")




# l'équipe qui à fait le plus de pentakill l'emporte :
tableMinion <- table(c(playerTeamLolData$minionsKill1, 
                        playerTeamLolData$minionsKill2,
                        playerTeamLolData$minionsKill3, 
                        playerTeamLolData$minionsKill4, 
                        playerTeamLolData$minionsKill5))

plot(table(tableMinion, playerTeamLolData$winTeam1))

# l'équipe du joueur qui fait le first kill gagne :

tableIDBTTeam1 <- table(c( playerTeamLolData$inhibitorKillsTeam1,
                           playerTeamLolData$dragonKillsTeam1,
                           playerTeamLolData$baronKillsTeam1,
                           playerTeamLolData$towerKillsTeams1))

tableTeam1Lane <- table(playerTeamLolData$lane1,
                       playerTeamLolData$lane2,
                       playerTeamLolData$lane3,
                       playerTeamLolData$lane4,
                       playerTeamLolData$lane5,
                       playerTeamLolData$lane6,
                       playerTeamLolData$lane7,
                       playerTeamLolData$lane8,
                       playerTeamLolData$lane9,
                       playerTeamLolData$lane10)

tableTeamTowerKill <- table( c(tableTeam1Lane , playerTeamLolData$lane1))


barplot(table( playerTeamLolData$inhibitorKillsTeam1,
               playerTeamLolData$dragonKillsTeam1,
               playerTeamLolData$baronKillsTeam1,
               playerTeamLolData$towerKillsTeams1))
table()

plot(playerTeamLolData$lane1, playerTeamLolData$towerKillsTeams1)

plot(playerTeamLolData$towerKillsTeams1, playerTeamLolData$winTeam1)

#l'équipe qui débloque le plus de dragons gagne :
#quel est le meilleur champion :
#quelle est la meilleure composition pour gagner:
# quel est le héro le plus ban :





















