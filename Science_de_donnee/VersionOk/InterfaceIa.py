from tkinter import Frame,Label,N,W,E,S,Entry,Button,Radiobutton,IntVar,Tk
from tkinter.filedialog import askopenfilename,askopenfile
import TestClass
    


class Interface(Frame):
    
    """Notre fenêtre principale.
    Tous les widgets sont stockés comme attributs de cette fenêtre."""
    
    def __init__(self, fenetre, **kwargs):
        Frame.__init__(self, fenetre, width=0, height=0, **kwargs)
        #self.pack(fill=BOTH)

        
        #Creation Label

        LabelTitre = Label(fenetre, text="ALGORYTHME KNN")
        LabelTitre.grid(sticky = N,row=0, column = 1 , pady=(20,0))
        
        self.labelSelectFileTrain = Label(fenetre, text="Selectionner le fichier csv d'entrainnement")
        self.labelSelectFileTrain.grid(sticky = W,row=1, pady=(30,2) , padx=(5,0))

        self.labelSelectFileTest = Label(fenetre, text="Selectionner le fichier csv de Test")
        self.labelSelectFileTest.grid(sticky = W,row=2 , padx=(5,0))

        self.labelNbIndividus = Label(fenetre , text="Nb individus : ")
        self.labelNbIndividus.grid(sticky = W,row=3 , padx=(20,0) ,column = 0, pady=(20,0))

        self.labelNbIndividusRes = Label(fenetre , text="")
        self.labelNbIndividusRes.grid(sticky = W,row=3 ,column = 1 ,padx=(20,0) ,pady=(20,0))

        self.labelNbAttr = Label(fenetre , text="Nb attribus : ")
        self.labelNbAttr.grid(sticky = W,row=4 , padx=(20,0) ,column = 0, pady=(5,0))

        self.labelNbAttrRes = Label(fenetre , text="")
        self.labelNbAttrRes.grid(sticky = W,row=4 ,column = 1 ,padx=(20,0) ,pady=(5,0))

        self.labelSelectKVoisins = Label(fenetre, text="Saisir le nombre de K voisins")
        self.labelSelectKVoisins.grid(sticky = W,row=7 ,pady=(30,2) , padx=(5,0))

        self.labelSelectnbColonne = Label(fenetre, text="Saisir l'index de la  colonne à test :")
        self.labelSelectnbColonne.grid(sticky = W,row=8 , padx=(5,0))

        self.Res = Label(fenetre, text="Resultat :")
        self.Res.grid(sticky = W,row= 9 , padx=(20,0), pady=(10,10))
        
        # Création input
        #self.varTrainData = StringVar()
        self.inputFileNameTrain= Entry(fenetre, text="", width=110)
        self.inputFileNameTrain.grid(row=1, column =1 ,pady=(30,2) , padx=(20))

        #self.varTestData = StringVar()
        self.inputFileNameTest= Entry(fenetre, text ="", width=110)
        self.inputFileNameTest.grid(row=2, column =1 )

        #self.varKVoisins = IntVar()
        self.inputKVoisins= Entry(fenetre, text="", width=10)
        self.inputKVoisins.grid(sticky = W,row=7, column =1 ,pady=(30,2))

        #self.varNColonne = IntVar()
        self.inputNColonne= Entry(fenetre, text="", width=10)
        self.inputNColonne.grid(sticky = W,row=8, column =1)

        self.monres = ""
        
        self.inputRes= Entry(fenetre, text=self.monres, width=40)
        self.inputRes.grid(sticky = W,row=9, column =1 , pady=(10,10))
        self.inputRes.config(state='disabled')
        #Creation bouton
        

        self.boutonSelectFileTrain = Button(fenetre, text="Charger csv" , command=self.browsecsvTrain)
        self.boutonSelectFileTrain.grid(sticky = W ,row=1, column =2 ,pady=(30,2))

        self.boutonSelectFileTest = Button(fenetre, text="Charger csv" , command=self.browsecsvTest)
        self.boutonSelectFileTest.grid(sticky = W ,row=2, column =2)
        
        
        self.boutonLancer = Button(fenetre, text="Calculer" , command=self.FonctionFinale)
        self.boutonLancer.grid(sticky = N ,row=9, column =2)
 
        #Creation radio bouton
        self.var = IntVar()
        self.radioEucli = Radiobutton(fenetre, text="Division Euclidienne Classique", variable = self.var ,value=1 )
        self.radioEucli.grid(sticky = W ,row=6, column =0 , padx=(20,0) , pady=(30,0))
        self.var.set(1)
        
        self.radioEucliNormal = Radiobutton(fenetre, text="Division Euclidienne Nomalisée" ,variable = self.var , value=2)
        self.radioEucliNormal.grid(sticky = W ,row=6, column =1, padx=(20,0),pady=(30,0))
     
        
        
    
    def browsecsvTrain(self):
        self.inputFileNameTrain.delete(0,'end')
        Tk().withdraw() 
        filename = askopenfilename()
        self.inputFileNameTrain.insert(0, filename) 
    
    def browsecsvTest(self):
        self.inputFileNameTest.delete(0,'end')
        Tk().withdraw() 
        filename = askopenfilename()
        self.inputFileNameTest.insert(0, filename) 
    
    def TestDataType(self):
        extensionTrain = self.inputFileNameTrain.get().split('.')[-1]
        extensionTest = self.inputFileNameTest.get().split('.')[-1]
        if( extensionTrain != "csv"):
            self.inputFileNameTrain.delete(0, 'end')
            self.inputFileNameTrain.insert(0,"ERROR TYPE FICHIER")
              
            return False
        elif(extensionTest != "csv"):
            self.inputFileNameTest.delete(0, 'end')
            self.inputFileNameTest.insert(0,"ERROR TYPE FICHIER")
            return False
        else:
            return True

    def TestNum(self,test):
        numCol = self.inputNColonne.get()
        numVoisin = self.inputKVoisins.get()
        try:
            if(int(numCol) > len(test.testFileConvert)-1 or int(numCol) < 0 or numCol is None):
                self.inputNColonne.delete(0, 'end')
                self.inputNColonne.insert(0,"ERROR")
                return False
            elif(int(numVoisin) > len(test.trainFileConvert[0])-1 or int(numVoisin) <= 0 or numVoisin is None ):
                self.inputKVoisins.delete(0, 'end')
                self.inputKVoisins.insert(0,"ERROR")
                return False
                
        except :
            self.inputNColonne.delete(0, 'end')
            self.inputNColonne.insert(0,"ERROR")
            self.inputKVoisins.delete(0, 'end')
            self.inputKVoisins.insert(0,"ERROR")
            return False
        return True
    '''def TestNum(self,test):
        numCol = self.inputNColonne.get()
        numVoisin = self.inputKVoisins.get()
        try:
            if(int(numCol) > len(test.testFileConvert)-1 or int(numCol) < 0 or numCol is None):
                self.inputNColonne.delete(0, 'end')
                self.inputNColonne.insert(0,"ERROR")
                return False
            elif(int(numVoisin) > len(test.trainFileConvert[0])-1 or int(numVoisin) <= 0 or numVoisin is None ):
                self.inputKVoisins.delete(0, 'end')
                self.inputKVoisins.insert(0,"ERROR")
                return False
            else:
                return True
        except :
            self.inputNColonne.delete(0, 'end')
            self.inputNColonne.insert(0,"ERROR")
            self.inputKVoisins.delete(0, 'end')
            self.inputKVoisins.insert(0,"ERROR")
            return False'''

    def NbAtt(self,ia):
        self.labelNbIndividusRes['text'] = ''
        self.labelNbIndividusRes['text'] = len(ia.trainFileConvert)

        self.labelNbAttrRes['text'] = ''
        self.labelNbAttrRes['text'] = len(ia.trainFileConvert[0])


    def FonctionFinale(self):
        if(self.TestDataType()):
            self.inputRes.config(state='normal')
            self.inputRes.delete(0, 'end')
            montest = TestClass.MiniIa(self.inputFileNameTrain.get(),self.inputFileNameTest.get(),self.inputNColonne.get(), self.inputKVoisins.get())
            montest.OpenFile()
            montest.TableToFloatTrain()
            montest.TableToFloatTest()
            self.NbAtt(montest)
            print(self.TestNum(montest))
            if(self.TestNum(montest)):
                if(self.var == 2):
                    montest.MaxColonne()
                    montest.MinColonne()
                    montest.Euclidienne1()
                    montest.ClassementCroissantLigne()
                else:
                    montest.Euclidienne2()
                    montest.ClassementCroissantLigne()
                #self.monres = montest.CorrespondanceVoisin()
            else:
                self.inputRes.insert(0,"ERROR")
            self.inputRes.insert(0,"Classe :  " + montest.CorrespondanceVoisin())
        self.inputRes.config(state='disabled')

    
    
        
        

fenetre = Tk()
fenetre.geometry('1100x400')
fenetre.title('KNN')
fenetre.resizable(width=False, height=False)
interface = Interface(fenetre)
interface.destroy()
interface.mainloop()