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


    '''def StringToInt(self,texte):
        val = 0.0
        for c in texte:
            val += float(ord(c))
        return val'''
    
    def strint(self, string):
        val = 0
        for st in string:
            val += float(ord(st))
        return val

    def allTabStrInt(self):
        for val_test in self.trainFile:
            print(val_test)
            i = 0
            for ellement in val_test:
                try: 
                    val_test[i] = float(ellement)
                    i+= 1
                except:
                    val_test[i] = self.strint(ellement)
                    i += 1
        print(self.trainFile)
        return self.trainFile


    
    '''def TableToFloat(self):
        for ligne in range(len(self.trainFileConvert)):
            for carac in range(len(self.trainFileConvert[ligne])) :
                try: 
                    self.trainFileConvert[ligne][carac] = float(self.trainFileConvert[ligne][carac])
                except:
                    if(((self.trainFileConvert[ligne][carac],self.StringToInt(self.trainFileConvert[ligne][carac])) in self.valuesName) == False):
                        self.valuesName.append((self.trainFileConvert[ligne][len(self.trainFileConvert[ligne])-1],self.StringToInt(self.trainFileConvert[ligne][len(self.trainFileConvert[ligne])-1])))
                        
                    self.trainFileConvert[ligne][carac] = self.StringToInt(self.trainFileConvert[ligne][carac])
        
       
        
        for ligne in range(len(self.testFileConvert)):
            for carac in range(len(self.testFileConvert[ligne])) :
                try: 
                    self.testFileConvert[ligne][carac] = float(self.testFileConvert[ligne][carac])
                except:
                    self.testFileConvert[ligne][carac] = self.StringToInt(self.testFileConvert[ligne][carac])
        print(self.trainFileConvert)'''


    '''def MaxColonne(self):
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
        print("fini")'''
       
    '''def Euclidienne1(self):
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
        u =  0  
        for ligneTraining in  var:
            formule = 0
            i = 0
            for caracTest,caracTraining in zip(self.testFileConvert[int(self.numCollonne)],ligneTraining):            
                formule += pow((float(caracTraining)-float(caracTest)), 2)   
                i +=1       
                u += 1      
            intermediaire.append(math.sqrt(formule))         
        self.tableCalculs.append(intermediaire) 
        print(self.tableCalculs)
        print( u )
      
    def Euclidienne3(self):
        compt = 0
        print(self.testFileConvert)
        for val_test in self.testFileConvert:
            for ligne in self.trainFileConvert: 
                inter = 0.0
                res_eucli = 0.0
                i = 0 
                for ma_val in range(len(val_test)-1):     
                    inter += pow((float(val_test[ma_val]) - float(ligne[ma_val])),2)
                    res_eucli = math.sqrt(inter)
                    i += 1             
                    compt+=1 
                ligne.append(res_eucli)
        print(res_eucli)
        print("\nMon res \n")
        print(compt)


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
                return Val[0]'''



pathTrain = "C:\\Users\\sburd\\Desktop\\CoursSDNL3S1\\science_données\\Projet_champi\\csv\\detecteur_citrons_training.csv"
pathTest = "C:\\Users\\sburd\\Desktop\\CoursSDNL3S1\\science_données\\Projet_champi\\csv\\detecteur_citrons_test.csv"

pathChampiTrain = "C:\\Users\\sburd\\Desktop\\CoursSDNL3S1\\science_données\\Projet_champi\\csv\\tp_mushrooms_dataset_5000.csv"
pathChampiTest = "C:\\Users\\sburd\\Desktop\\CoursSDNL3S1\\science_données\\Projet_champi\\csv\\tp_mushrooms_eval_etu_id.csv"


test = MiniIa(pathChampiTrain,pathChampiTest,0,2)
test.OpenFile()
test.allTabStrInt()
'''test.TableToFloat()
test.MaxColonne()
test.MinColonne()
test.Euclidienne3()'''


            


