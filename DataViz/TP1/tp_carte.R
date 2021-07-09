install.packages('maps')
library(maps)
map(database="world")


#carte du monde avec des ronds 

costcos <- read.csv("http://book.flowingdata.com/ch08/geocode/costcos-geocoded.csv", sep=",")
map(database="world", col="gray")
symbols(costcos$Longitude, costcos$Latitude, circles=rep(2, nrow(costcos)), inches=0.05, add=TRUE)

#carte des etats unis

map(database="state", col="gray")
symbols(costcos$Longitude, costcos$Latitude, bg="red", fg="white", circles=rep(2, nrow(costcos)))
        
        map(database="france")

