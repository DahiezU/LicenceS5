import csv
import math

class MiniIa:
    
    def __init__(self, trainFile , testFile,numCollonne,kVoisins):
        #Colonne à chercher
        self.numCollonne = numCollonne
        
        #KVoisins
        self.kVoisins = kVoisins

        #Fichier csv pur
        self.trainFile = trainFile
        self.testFile = testFile
        
         #Fichier csv lisible
        self.trainFileConvert = []
        self.testFileConvert = []
        
        #Noms values à rechercher
        self.valuesName = []

        #Min et Max Collonnes
        self.listMax = []
        self.listMin = []

        #Tableau des calculs
        self.tableCalculs = []

        #Moyenn Medianne
        self.moyenne = []
        self.medianne = []
    

    def OpenFile(self):
        fileTrain = open(self.trainFile)
        fileTest = open(self.testFile)

        csvTrain = csv.reader(fileTrain, delimiter=',', quotechar='|')
        csvTest = csv.reader(fileTest, delimiter=',', quotechar='|')
       
        next(csvTrain)
        next(csvTest)
        
        for rowTrain in csvTrain:
            self.trainFileConvert.append(rowTrain)
         
        for rowTest in csvTest:
            self.testFileConvert.append(rowTest)


    def StringToInt(self,texte):
        val = 0.0
        for c in texte:
            val += float(ord(c)) 
        return val
    
    
    def TableToFloatTrain(self):
        for ligne in range(len(self.trainFileConvert)):   
            for carac in range(len(self.trainFileConvert[ligne])):            
                try:
                    self.trainFileConvert[ligne][carac] = float(self.trainFileConvert[ligne][carac])
                except:
                    self.valuesName.append((self.trainFileConvert[ligne][len(self.trainFileConvert[ligne])-1],self.StringToInt(self.trainFileConvert[ligne][len(self.trainFileConvert[ligne])-1])))     
                    self.trainFileConvert[ligne][carac] = self.StringToInt(self.trainFileConvert[ligne][carac])
        self.valuesName = list(set(self.valuesName))
        

    def TableToFloatTest(self):
        for ligne in range(len(self.testFileConvert)):
            for carac in range(len(self.testFileConvert[ligne])) :
                try: 
                    self.testFileConvert[ligne][carac] = float(self.testFileConvert[ligne][carac])
                except:
                    self.testFileConvert[ligne][carac] = self.StringToInt(self.testFileConvert[ligne][carac])

    def MaxColonne(self):
        for carac in range(len(self.trainFileConvert[0])):
            varMax = 0
            for ligne in range(len(self.trainFileConvert)): 
                if(float(self.trainFileConvert[ligne][carac]) > float(varMax)):
                    varMax = self.trainFileConvert[ligne][carac]
            self.listMax.append(varMax)
       
    def MinColonne(self):
        for carac in range(len(self.trainFileConvert[0])):
            varMin = self.trainFileConvert[0][0]
            for ligne in range(len(self.trainFileConvert)): 
                if(float(self.trainFileConvert[ligne][carac]) < float(varMin)):
                    varMin = self.trainFileConvert[ligne][carac]
            self.listMin.append(varMin)
       
    def Euclidienne1(self):
        var = self.trainFileConvert
        intermediaire = []   
        for ligneTraining in  var:
            formule = 0
            i = 0
            for caracTest,caracTraining in zip(self.testFileConvert[int(self.numCollonne)],ligneTraining):   
                if(self.listMax[i] == self.listMin[i]):         
                        self.listMax[i] +=1
                formule += pow((float(caracTraining)-float(caracTest))/(float(self.listMax[i])-float(self.listMin[i])), 2)   
                i +=1               
            intermediaire.append(math.sqrt(formule))        
        self.tableCalculs.append(intermediaire)
      
     
    def Euclidienne2(self):
        var = self.trainFileConvert       
        intermediaire = []      
        for ligneTraining in  var:
            formule = 0
            i = 0
            for caracTest,caracTraining in zip(self.testFileConvert[int(self.numCollonne)],ligneTraining):            
                formule += pow((float(caracTraining)-float(caracTest)), 2)   
                i +=1             
            intermediaire.append(math.sqrt(formule))         
        self.tableCalculs.append(intermediaire)
      

    def Moyenne(self):
        moyenne = 0
        for ligne in self.tableCalculs:
            inc = 0
            for valeur in ligne:
                moyenne += valeur
                inc+=1
            moyenne /= len(self.tableCalculs[0])
            self.moyenne.append(moyenne) 

    def MoyenneLigne(self):
        moyenne = 0
        for ligne in self.tableCalculs:
            inc = 0
            for valeur in ligne:
                moyenne += valeur
                inc+=1
            moyenne /= len(self.tableCalculs[0])
            self.moyenne.append(moyenne) 
       

    def ClassementCroissantLigne(self):
        listSorted  = self.tableCalculs  
        listSorted = sorted(listSorted[0])
        return listSorted

    def FindVoisins(self):
        listeVoisin = []
        i=0
        for  i in range(int(self.kVoisins)):
            listeVoisin.append(self.ClassementCroissantLigne()[i])
        valeurIndex = []        
        for voisin in listeVoisin:
            for valeur in self.tableCalculs[0]:
                    if(float(voisin) == float(valeur)):                    
                        valeurIndex.append(self.tableCalculs[0].index(valeur))
        return sorted(valeurIndex)

    def ValeurVoisins(self):
        liste = self.FindVoisins()
        valeur  = []
        for indexVoisin in liste:
            valeur.append(self.trainFileConvert[indexVoisin][len(self.trainFileConvert[0])-1])
        return valeur
    
    def CorrespondanceVoisin(self):
        dictValeur = {i:self.ValeurVoisins().count(i) for i in  self.ValeurVoisins()}
        {k: v for k, v in sorted(dictValeur.items(), key=lambda item: item[1])}
        voisinVal = (list({k: v for k, v in sorted(dictValeur.items(), key=lambda item: item[1])}.items())[-1])[0]
        for Val in self.valuesName:
            if(Val[1] == voisinVal ):
                print("Champi de nb colone : " , self.numCollonne ," est " , Val[0] , " \n")
                return Val[0]