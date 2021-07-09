import csv
import math
file = open("C:\\Users\\dahie\\Documents\\Science_de_donnee\\citron_tp\\detecteur_citrons_training.csv")
monCsv = csv.reader(file)
next(monCsv)
valeur_training = []
for row in monCsv:
    valeur_training.append(row)

file2 = open("C:\\Users\\dahie\\Documents\\Science_de_donnee\\citron_tp\\detecteur_citrons_test.csv")
monCsv2 = csv.reader(file2)
next(monCsv2)
valeur_test = []
for row2 in monCsv2:
    valeur_test.append(row2)


class mes:

    def __init__(self, fic_test, fic_training):
        self.test = fic_test
        self.training = fic_training

        self.training_sort = []


    def strint(self, string):
        val = 0
        for st in string:
            val += float(ord(st))
        return val

    def allTabStrInt(self):
        
        for val_test in self.training:
            i = 0
            for ellement in val_test:
                try: 
                    val_test[i] = float(ellement)
                    i+= 1
                except:
                    val_test[i] = self.strint(ellement)
                    i += 1
        return self.training

    
    def max (self):
        
        tableMax = []
        for carac in range(len(self.training[0])):
            varMax = 0
            for ligne in range(len(self.training)): 
                if(float(self.training[ligne][carac]) > float(varMax)):
                    varMax = self.training[ligne][carac]
            tableMax.append(varMax)
        print(tableMax)
        return  tableMax

    def min (self):
        
        tableMin = []
        for carac in range(len(self.training[0])):
            varMin = self.training[0][0]
            for ligne in range(len(self.training)): 
                if(float(self.training[ligne][carac]) < float(varMin)):
                    varMin = self.training[ligne][carac]
            tableMin.append(varMin)
        print(tableMin)
        return  tableMin

    def euclidienne (self):
 
        varmax = max(self.training)
        varmin = min(self.training)

        for val_test in self.test:
            for ligne in self.training:
            
            
                inter = 0.0
                res_eucli = 0.0
                i = 0
                minmax = 0.0
                for ma_val in val_test:
                    
                    minmax = (float(varmin[i]) - float(varmax[i]))

                    inter += pow(((float(ma_val) - float(ligne[i]))/minmax),2)
                    res_eucli = math.sqrt(inter)
                    i += 1
                
                ligne.append(res_eucli)


        

         
    



test = mes(valeur_test, valeur_training)
test.allTabStrInt()

#test.euclidienne()

print(test.training_sort)


