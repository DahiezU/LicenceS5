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



    def max (tab):
        tableMax = []
        for carac in range(len(tab[0])):
            varMax = 0
            for ligne in range(len(tab)): 
                if(float(tab[ligne][carac]) > float(varMax)):
                    varMax = tab[ligne][carac]
            tableMax.append(varMax)
        print(tableMax)
        return  tableMax

    def min (tab):
        tableMin = []
        for carac in range(len(tab[0])):
            varMin = tab[0][0]
            for ligne in range(len(tab)): 
                if(float(tab[ligne][carac]) < float(varMin)):
                    varMin = tab[ligne][carac]
            tableMin.append(varMin)
        print(tableMin)
        return  tableMin


    def euclidienne (fic_test, fic_training):
 
        varmax = max(fic_training)
        varmin = min(fic_training)

        for val_test in fic_test:
            for ligne in fic_training:
            
            
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

    def strint(string):
        val = 0
        for st in string:
            val += float(ord(st))
        return val

    def allTabStrInt(fic_training):
        
        for val_test in fic_training:
            i = 0
            for ellement in val_test:
                try: 
                    val_test[i] = float(ellement)
                    i+= 1
                except:
                    val_test[i] = strint(ellement)
                    i += 1
        return fic_training


                


print(allTabStrInt(valeur_test))

    
#print(strint("pomme"))

#print(max(valeur_training))

#print(min(valeur_training))

#euclidienne(valeur_test, valeur_training)
#print(valeur_training)
#print(valeur_training)
