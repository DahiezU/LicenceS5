#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p_table_des_matieres.h"

/*
    projet S5 
    Burdy Simon 
    Dahiez Ulysse
    28/01/2021
*/

/*
la fonction suivante sert à créer un nouvelle entrée
*/

t_entree* nouvelle_entree(char* etiquette, a_entree pere, a_entree gd_frere){
    t_entree* new = (a_entree)malloc(sizeof(t_entree));
    
        new->l_etiquette = etiquette;
        new->le_pere = pere;
        new->le_frere_precedent = gd_frere;
        
    return new;  
    
}
/*
petite fonction simple pour afficher un nombre d'espace, qui servira prochainement
*/

void afficher_n_espaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

/*
affiche l'entrée. 
*/

void afficher_entree(a_entree ceci){
    if(ceci != NULL){
        printf("%s  \n", ceci->l_etiquette);
        
        if(ceci->le_pere != NULL){
            printf("%s  pere \n", ceci->le_pere->l_etiquette);
            }
   

        if(ceci->le_premier_fils != NULL){            
            printf("%s premier fils \n", ceci->le_premier_fils->l_etiquette); 
         }   
        if(ceci->le_dernier_fils != NULL){   
            printf("%s dernier fils \n", ceci->le_dernier_fils->l_etiquette);
                }     
        if(ceci->le_frere_suivant != NULL){
            printf("%s frere suivant \n", ceci->le_frere_suivant->l_etiquette);
            
            }  
        if(ceci->le_frere_precedent != NULL){
            printf("%s frere prec \n", ceci->le_frere_precedent->l_etiquette);
            
            }
    }
    return; 
    
}

/*
affiche la table 
*/


void afficher_table(t_table ceci, int decalage){

    if(ceci != TABLE_VIDE){
        if(ceci->l_etiquette){
            afficher_n_espaces(decalage);
            printf("%s \n",ceci->l_etiquette);
          
            if(ceci->le_premier_fils != NULL){ 
                
                afficher_table(ceci->le_premier_fils, decalage+1);  
            } 

            if(ceci->le_frere_suivant != NULL){    
                
                    afficher_table(ceci->le_frere_suivant, decalage);        
            }else{
                if(ceci->le_frere_suivant == ceci->le_dernier_fils  && ceci->le_frere_suivant != NULL ){
                
                    afficher_table(ceci->le_dernier_fils, decalage+1);    
                }
            }
            
        } 

    }
    
    return;
}

/*

*/

void creer_aine(t_table ceci, char* etiquette){
    if(ceci != TABLE_VIDE){
        if(ceci->le_premier_fils == NULL){
            ceci->le_premier_fils = nouvelle_entree(etiquette, ceci , NULL);
            ceci->le_dernier_fils  = ceci->le_premier_fils;
            return;
        }
        
        if(ceci->le_premier_fils == ceci->le_dernier_fils && ceci->le_premier_fils != NULL ){ 
            ceci->le_premier_fils = nouvelle_entree(etiquette, ceci , NULL);        
            ceci->le_premier_fils->le_frere_suivant  = ceci->le_dernier_fils;
            ceci->le_dernier_fils->le_frere_precedent = ceci->le_premier_fils;
            return;
        }else{
            t_entree* temp = ceci->le_premier_fils;
            ceci->le_premier_fils = nouvelle_entree(etiquette , ceci , NULL);
            ceci->le_premier_fils->le_frere_suivant = temp;
            ceci->le_premier_fils->le_frere_suivant->le_frere_precedent = ceci->le_premier_fils;
            return;
            
        }

    }
        return;
    
}


void creer_benjamin(a_entree ceci, char* etiquette){
    if(ceci != TABLE_VIDE){
        if(ceci->le_premier_fils == NULL){
            
            creer_aine(ceci , etiquette);
        }else{
            a_entree temp = ceci->le_dernier_fils;
           
            ceci->le_dernier_fils = nouvelle_entree(etiquette , ceci , ceci->le_dernier_fils );
            ceci->le_dernier_fils->le_frere_precedent = temp; 
            ceci->le_dernier_fils->le_frere_precedent->le_frere_suivant = ceci->le_dernier_fils;
        }

   
    }
    return;
}


void creer_petit_frere(a_entree ceci, char* etiquette){
    if(ceci->le_frere_suivant == NULL){
   
        ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
        if(ceci->le_pere != NULL){
            ceci->le_pere->le_dernier_fils = ceci->le_frere_suivant;
        }
        
    }else{
        if(ceci->le_frere_suivant != NULL ){
            a_entree  temp = ceci->le_frere_suivant ; 
            ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
            ceci->le_frere_suivant->le_frere_suivant = temp;
            ceci->le_frere_suivant->le_frere_precedent = ceci;
          
        }else{
            ceci->le_frere_suivant->le_frere_suivant = NULL;
            ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
            ceci->le_frere_suivant->le_frere_precedent = ceci;
                    
        }
       
    }
    
    return;
}


void inserer_grand_frere(t_table* ceci, char* etiquette){
    if( ((*ceci)->le_frere_precedent  == NULL) && ((*ceci)->le_pere != NULL)){

        creer_aine((*ceci)->le_pere , etiquette);
        return;
    }
    if(((*ceci)->le_frere_precedent  == NULL) && ((*ceci)->le_pere == NULL)){
            (*ceci)->le_frere_precedent = nouvelle_entree(etiquette , NULL ,NULL);
            (*ceci)->le_frere_precedent->le_frere_suivant = (*ceci);
            *ceci = (*ceci)->le_frere_precedent;
            
            return;
    }else{
        creer_petit_frere((a_entree)(*ceci)->le_frere_precedent , etiquette);
        return;
    }

    return;
}



int remonter(a_entree ceci){
    if(ceci->le_pere != NULL){
        a_entree temp = ceci->le_pere->le_frere_suivant;  
        a_entree monCeci  = ceci ;
        
        if(ceci->le_pere->le_dernier_fils == ceci){
            if(ceci->le_frere_precedent != NULL ){ 
                    ceci->le_pere->le_dernier_fils  = ceci->le_frere_precedent;
                   
            }else{
                if(ceci->le_frere_suivant != NULL){   
                        ceci->le_pere->le_premier_fils =  ceci->le_frere_suivant;
                }else{  
                     ceci->le_pere->le_premier_fils = NULL;
                }
            }
        }
        if(ceci->le_frere_suivant == NULL){
            if(ceci->le_frere_precedent != NULL){
                 ceci->le_frere_precedent->le_frere_suivant = NULL;
            }
           
        }else{
            if(ceci->le_frere_precedent != NULL){
                ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant;
                ceci->le_frere_suivant->le_frere_precedent = ceci->le_frere_precedent;
              
            }else{
                ceci->le_frere_suivant->le_frere_precedent = NULL;
                ceci->le_pere->le_premier_fils = ceci->le_frere_suivant; 
            
            }   
        }
        if(ceci->le_pere->le_frere_suivant == NULL){
            ceci->le_frere_suivant = NULL;
        }else{
            ceci->le_pere->le_frere_suivant->le_frere_precedent = ceci;
            ceci->le_frere_suivant = ceci->le_pere->le_frere_suivant;   
        }

        ceci->le_frere_precedent =  ceci->le_pere;
        ceci->le_frere_precedent->le_frere_suivant = ceci;

       
        if(ceci->le_pere->le_pere != NULL){
             ceci->le_pere = ceci->le_pere->le_pere;
        }else{
            ceci->le_pere = NULL;
        }#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p_table_des_matieres.h"

/*
    projet S5 
    Burdy Simon 
    Dahiez Ulysse
    28/01/2021
*/

/*
la fonction suivante sert à créer un nouvelle entrée
*/

t_entree* nouvelle_entree(char* etiquette, a_entree pere, a_entree gd_frere){
    t_entree* new = (a_entree)malloc(sizeof(t_entree));
    
        new->l_etiquette = etiquette;
        new->le_pere = pere;
        new->le_frere_precedent = gd_frere;
        
    return new;  
    
}
/*
petite fonction simple pour afficher un nombre d'espace, qui servira prochainement
*/

void afficher_n_espaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

/*
affiche l'entrée. 
*/

void afficher_entree(a_entree ceci){
    if(ceci != NULL){
        printf("%s  \n", ceci->l_etiquette);
        
        if(ceci->le_pere != NULL){
            printf("%s  pere \n", ceci->le_pere->l_etiquette);
            }
   

        if(ceci->le_premier_fils != NULL){            
            printf("%s premier fils \n", ceci->le_premier_fils->l_etiquette); 
         }   
        if(ceci->le_dernier_fils != NULL){   
            printf("%s dernier fils \n", ceci->le_dernier_fils->l_etiquette);
                }     
        if(ceci->le_frere_suivant != NULL){
            printf("%s frere suivant \n", ceci->le_frere_suivant->l_etiquette);
            
            }  
        if(ceci->le_frere_precedent != NULL){
            printf("%s frere prec \n", ceci->le_frere_precedent->l_etiquette);
            
            }
    }
    return; 
    
}

/*
affiche la table 
*/


void afficher_table(t_table ceci, int decalage){

    if(ceci != TABLE_VIDE){
        if(ceci->l_etiquette){
            afficher_n_espaces(decalage);
            printf("%s \n",ceci->l_etiquette);
          
            if(ceci->le_premier_fils != NULL){ 
                
                afficher_table(ceci->le_premier_fils, decalage+1);  
            } 

            if(ceci->le_frere_suivant != NULL){    
                
                    afficher_table(ceci->le_frere_suivant, decalage);        
            }else{
                if(ceci->le_frere_suivant == ceci->le_dernier_fils  && ceci->le_frere_suivant != NULL ){
                
                    afficher_table(ceci->le_dernier_fils, decalage+1);    
                }
            }
            
        } 

    }
    
    return;
}

/*

*/

void creer_aine(t_table ceci, char* etiquette){
    if(ceci != TABLE_VIDE){
        if(ceci->le_premier_fils == NULL){
            ceci->le_premier_fils = nouvelle_entree(etiquette, ceci , NULL);
            ceci->le_dernier_fils  = ceci->le_premier_fils;
            return;
        }
        
        if(ceci->le_premier_fils == ceci->le_dernier_fils && ceci->le_premier_fils != NULL ){ 
            ceci->le_premier_fils = nouvelle_entree(etiquette, ceci , NULL);        
            ceci->le_premier_fils->le_frere_suivant  = ceci->le_dernier_fils;
            ceci->le_dernier_fils->le_frere_precedent = ceci->le_premier_fils;
            return;
        }else{
            t_entree* temp = ceci->le_premier_fils;
            ceci->le_premier_fils = nouvelle_entree(etiquette , ceci , NULL);
            ceci->le_premier_fils->le_frere_suivant = temp;
            ceci->le_premier_fils->le_frere_suivant->le_frere_precedent = ceci->le_premier_fils;
            return;
            
        }

    }
        return;
    
}


void creer_benjamin(a_entree ceci, char* etiquette){
    if(ceci != TABLE_VIDE){
        if(ceci->le_premier_fils == NULL){
            
            creer_aine(ceci , etiquette);
        }else{
            a_entree temp = ceci->le_dernier_fils;
           
            ceci->le_dernier_fils = nouvelle_entree(etiquette , ceci , ceci->le_dernier_fils );
            ceci->le_dernier_fils->le_frere_precedent = temp; 
            ceci->le_dernier_fils->le_frere_precedent->le_frere_suivant = ceci->le_dernier_fils;
        }

   
    }
    return;
}


void creer_petit_frere(a_entree ceci, char* etiquette){
    if(ceci->le_frere_suivant == NULL){
   
        ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
        if(ceci->le_pere != NULL){
            ceci->le_pere->le_dernier_fils = ceci->le_frere_suivant;
        }  
        ceci->le_frere_suivant->le_frere_suivant = NULL;
        ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
        ceci->le_frere_suivant->le_frere_precedent = ceci;
        
    }else{
   
            a_entree  temp = ceci->le_frere_suivant ; 
            ceci->le_frere_suivant = nouvelle_entree(etiquette , ceci->le_pere , ceci);
            ceci->le_frere_suivant->le_frere_suivant = temp;
            ceci->le_frere_suivant->le_frere_precedent = ceci;
          

         
                    
        }
       
    
    
    return;
}


void inserer_grand_frere(t_table* ceci, char* etiquette){
    if( ((*ceci)->le_frere_precedent  == NULL) && ((*ceci)->le_pere != NULL)){

        creer_aine((*ceci)->le_pere , etiquette);
        return;
    }
    if(((*ceci)->le_frere_precedent  == NULL) && ((*ceci)->le_pere == NULL)){
            (*ceci)->le_frere_precedent = nouvelle_entree(etiquette , NULL ,NULL);
            (*ceci)->le_frere_precedent->le_frere_suivant = (*ceci);
            *ceci = (*ceci)->le_frere_precedent;
            
            return;
    }else{
        creer_petit_frere((a_entree)(*ceci)->le_frere_precedent , etiquette);
        return;
    }

    return;
}


int remonter(a_entree ceci){
    if(ceci->le_pere != NULL){
        a_entree temp = ceci->le_pere->le_frere_suivant;  
        a_entree monCeci  = ceci ;
        

        if(ceci->le_pere->le_dernier_fils == ceci){
            if(ceci->le_frere_precedent != NULL ){ 
                    ceci->le_pere->le_dernier_fils  = ceci->le_frere_precedent;
                   
            }else{
                if(ceci->le_frere_suivant != NULL){   
                        ceci->le_pere->le_premier_fils =  ceci->le_frere_suivant;
                }else{  
                     ceci->le_pere->le_premier_fils = NULL;
                }
                
            }
        }
       
        if(ceci->le_frere_suivant == NULL){
            if(ceci->le_frere_precedent != NULL){
                 ceci->le_frere_precedent->le_frere_suivant = NULL;
            }
           
        }else{
            if(ceci->le_frere_precedent != NULL){
                ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant;
                ceci->le_frere_suivant->le_frere_precedent = ceci->le_frere_precedent ;
              
            }else{
               
                ceci->le_frere_suivant->le_frere_precedent = NULL;
                ceci->le_pere->le_premier_fils = ceci->le_frere_suivant ;
               
            
            }
             
        }
   
           
        if(ceci->le_pere->le_frere_suivant == NULL){
            ceci->le_frere_suivant = NULL;
        }else{
        
        
            ceci->le_pere->le_frere_suivant->le_frere_precedent = ceci;
            ceci->le_frere_suivant = ceci->le_pere->le_frere_suivant;   
        }

       ceci->le_frere_precedent =  ceci->le_pere;
        ceci->le_frere_precedent->le_frere_suivant = ceci;
       
       
       if(ceci->le_pere->le_premier_fils == ceci){
           ceci->le_pere->le_premier_fils = NULL;
       }
        
       
        if(ceci->le_pere->le_pere != NULL){
             ceci->le_pere = ceci->le_pere->le_pere;
        }else{
            ceci->le_pere = NULL;
        }
       
        return 1;
    
    }
    return 0;
}




int descendre(a_entree ceci){
    if(ceci->le_frere_precedent != NULL){
        
      /*  printf(" 1 < -*----- \n");
        afficher_entree(ceci);*/
        if(ceci->le_frere_suivant !=  NULL ) {
           /// printf(" 2 < -*----- \n");
            ceci->le_frere_suivant->le_frere_precedent = ceci->le_frere_precedent;
            ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant ; 
           // afficher_entree(ceci);
        }else{
        //printf(" 3 < -*----- \n");
            ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant  ; 
           // afficher_entree(ceci);
        }
        
       
       if(ceci->le_frere_precedent->le_premier_fils != NULL){
            if(ceci->le_frere_precedent->le_dernier_fils != NULL){
                 //printf(" 4 < -*----- \n");
               
                ceci->le_pere = ceci->le_frere_precedent;
                ceci->le_frere_precedent = ceci->le_frere_precedent->le_dernier_fils;
                ceci->le_frere_precedent->le_frere_suivant = ceci; 
                
                ceci->le_frere_suivant = NULL;
                ceci->le_pere->le_dernier_fils = ceci;
                //afficher_entree(ceci);
          
                
            }else{
                //printf(" 5 < -*----- \n");
                ceci->le_frere_precedent->le_dernier_fils->le_frere_suivant = ceci;    
               // afficher_entree(ceci);
            }
            
        }else{
             /*printf(" 6 < -*----- \n");
               afficher_entree(ceci->le_frere_precedent->le_premier_fils);*/
            ceci->le_pere = ceci->le_frere_precedent;
            ceci->le_frere_precedent->le_premier_fils = ceci ;    
            //afficher_entree(ceci);
          
           
            
        }
        
     
        if(ceci->le_frere_precedent->le_dernier_fils != NULL ){
            ceci->le_frere_precedent->le_dernier_fils = ceci;
            ceci->le_pere = ceci->le_frere_precedent;
      /*  printf(" 7 < -*----- \n");
             afficher_entree(ceci);
       */
        }else{
        }
        
        ceci->le_frere_precedent = NULL; 
        
    ceci->le_frere_suivant = NULL;
    //afficher_entree(ceci);
    return 1;
}
return 0;
}

void supprimer_entree(a_entree* ceci){
    if (ceci != NULL){
        if((*ceci)->le_premier_fils != NULL ){
            while((*ceci)->le_premier_fils != NULL){
                remonter((*ceci)->le_dernier_fils); 
            }
            (*ceci)->le_dernier_fils = NULL;

            if((*ceci)->le_frere_precedent != NULL){
                (*ceci)->le_frere_precedent->le_frere_suivant = (*ceci)->le_frere_suivant; 
                
            }else{ 
                if((*ceci)->le_pere != NULL){
                   (*ceci)->le_pere->le_premier_fils = (*ceci)->le_frere_suivant;
                }else{
                   (*ceci) = (*ceci)->le_frere_suivant;
                }

                if((*ceci)->le_frere_suivant != NULL){
                    (*ceci)->le_frere_precedent = NULL;
                    (*ceci)->le_frere_suivant->le_frere_precedent = NULL;
                }

            }

            if((*ceci)->le_frere_suivant != NULL && (*ceci)->le_frere_precedent != NULL ){
                (*ceci)->le_frere_suivant->le_frere_precedent = (*ceci)->le_frere_precedent;
           
            }

            free((*ceci)->le_frere_precedent);

        }else{
            if((*ceci)->le_frere_suivant == NULL && (*ceci)->le_frere_precedent == NULL ){               
                (*ceci)->le_pere->le_premier_fils = NULL;                
           }
           if((*ceci)->le_frere_suivant !=NULL &&  (*ceci)->le_frere_precedent !=NULL){
              
                (*ceci)->le_frere_suivant->le_frere_precedent =  (*ceci)->le_frere_precedent;
                (*ceci)->le_frere_precedent->le_frere_suivant  = (*ceci)->le_frere_suivant ; 
                
           }else if((*ceci)->le_frere_precedent == NULL && (*ceci)->le_frere_suivant !=NULL  ){
                
                (*ceci)->le_frere_suivant->le_frere_precedent = NULL;
                
                if((*ceci)->le_pere != NULL){
                        
                    (*ceci)->le_pere->le_premier_fils = (*ceci)->le_frere_suivant;
                }

                a_entree temp = (*ceci);       
                (*ceci) = (*ceci)->le_frere_suivant;
                free(temp);
                  
           }else if((*ceci)->le_frere_precedent != NULL && (*ceci)->le_frere_suivant ==NULL  ){
               
               (*ceci)->le_frere_precedent->le_frere_suivant = NULL ;

               if((*ceci)->le_pere != NULL){
                   (*ceci)->le_pere->le_dernier_fils = (*ceci)->le_frere_precedent ;
               }
              
            }

        }

    }
}

/*
void detruire_table(t_table* ceci){
    if((*ceci)->le_frere_suivant != NULL){

        while((*ceci)->le_frere_suivant != NULL){

            
            while((*ceci)->le_premier_fils != NULL){
            
                supprimer_entree((*ceci));

            }
        }
    }else{
        if((*ceci)->le_premier_fils != NULL){
            if((*ceci)->le_premier_fils->le_frere_suivant != 0){
                supprimer_entree((*ceci)->le_premier_fils);

                detruire_table((*ceci)->le_premier_fils);
            }
        }else{
            supprimer_entree((*ceci));
        }
    }
    
}
*/

void sauver_table(t_table ceci, FILE* dans){
    if(ceci != TABLE_VIDE){
        int decalage = 0;
        if (dans != NULL){
            if(ceci->l_etiquette){     
            fprintf(dans,"%s \n",ceci->l_etiquette);
                
                if(ceci->le_premier_fils != NULL){ 
                    a_entree  temp = ceci;
                    int i =  0 ;
                    while(temp->le_pere !=NULL){
                        temp = temp->le_pere;
                        i++;
                    }
                    for(int a = 0 ; a <= i ; a++){
                        fprintf(dans , " ");
                    }
                    sauver_table(ceci->le_premier_fils,dans);  
                } 
                if(ceci->le_frere_suivant != NULL){
                    a_entree  temp = ceci;
                    int i =  -1 ;
                    while(temp->le_pere !=NULL){
                        temp = temp->le_pere;
                        i++;
                    }
                    for(int a = 0 ; a <= i ; a++){
                        fprintf(dans , " ");
                    }
                    sauver_table(ceci->le_frere_suivant, dans);        
                }
                if(ceci->le_frere_suivant == ceci->le_dernier_fils  && ceci->le_frere_suivant != NULL ){
                    sauver_table(ceci->le_dernier_fils, dans);    
                }
            }
        }else{
            printf("Impossible d'ouvrir le fichier test.txt");
        }
        
}
        
    
    return;
}
        return 1;
    }
    return 0;
}


int descendre(a_entree ceci){
    if(ceci->le_frere_precedent != NULL){
      
        if(ceci->le_frere_suivant !=  NULL ) {
            
            ceci->le_frere_suivant->le_frere_precedent = ceci->le_frere_precedent;
            ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant ; 
        }else{
           
            ceci->le_frere_precedent->le_frere_suivant = ceci->le_frere_suivant  ; 
        }
        
       
       if(ceci->le_frere_precedent->le_premier_fils != NULL){
            if(ceci->le_frere_precedent->le_dernier_fils != NULL){
                
                ceci->le_pere = ceci->le_frere_precedent;
                ceci->le_frere_precedent = ceci->le_frere_precedent->le_dernier_fils;
                ceci->le_frere_precedent->le_frere_suivant = ceci; 
                
                ceci->le_frere_suivant = NULL;
                ceci->le_pere->le_dernier_fils = ceci;
                
            }else{
               
                ceci->le_frere_precedent->le_dernier_fils->le_frere_suivant = ceci;    
            }
            
        }else{
   
            ceci->le_frere_precedent->le_premier_fils = ceci ;    
            ceci->le_frere_suivant = NULL;
       
        }
        
     
        if(ceci->le_frere_precedent->le_dernier_fils != NULL ){
            ceci->le_frere_precedent->le_dernier_fils = ceci;
            ceci->le_pere = ceci->le_frere_precedent; 
            ceci->le_frere_precedent = NULL;
            ceci->le_pere = ceci->le_frere_precedent;
   
        }else{
        }
 
    return 1;
}
return 0;
}

void supprimer_entree(a_entree* ceci){
    if (ceci != NULL){
        if((*ceci)->le_premier_fils != NULL ){
            
            while((*ceci)->le_premier_fils != NULL){
                remonter((*ceci)->le_dernier_fils); 
            }

            if((*ceci)->le_frere_precedent != NULL){
              
               
                (*ceci)->le_frere_precedent->le_frere_suivant = (*ceci)->le_frere_suivant; 
                
            }else{
               
                (*ceci)->le_pere->le_premier_fils = (*ceci)->le_frere_suivant;
                
                if((*ceci)->le_frere_suivant != NULL){
                   
                    (*ceci)->le_frere_precedent = NULL;
                }

            }

            if((*ceci)->le_frere_suivant != NULL && (*ceci)->le_frere_precedent != NULL ){
                (*ceci)->le_frere_suivant->le_frere_precedent = (*ceci)->le_frere_precedent;
            }

            free((*ceci)->le_frere_precedent);

        }else{

            if((*ceci)->le_frere_suivant == NULL && (*ceci)->le_frere_precedent == NULL ){

                (*ceci)->le_pere->le_premier_fils = NULL;
                
           }
           if((*ceci)->le_frere_suivant !=NULL &&  (*ceci)->le_frere_precedent !=NULL){

                (*ceci)->le_frere_suivant->le_frere_precedent =  (*ceci)->le_frere_precedent;
                (*ceci)->le_frere_precedent->le_frere_suivant  = (*ceci)->le_frere_suivant ; 
           }else if((*ceci)->le_frere_precedent == NULL && (*ceci)->le_frere_suivant !=NULL  ){
                (*ceci)->le_frere_suivant->le_frere_precedent = NULL;
                if((*ceci)->le_pere != NULL){

                    (*ceci)->le_pere->le_premier_fils = (*ceci)->le_frere_suivant;
                }
                a_entree temp = (*ceci);       
                (*ceci) = (*ceci)->le_frere_suivant;
                free(temp);
                
           }else if((*ceci)->le_frere_precedent != NULL && (*ceci)->le_frere_suivant ==NULL  ){
               
               afficher_entree((*ceci)->le_pere);
               (*ceci)->le_frere_precedent->le_frere_suivant = NULL ;

               if((*ceci)->le_pere != NULL){
                   (*ceci)->le_pere->le_dernier_fils = (*ceci)->le_frere_precedent ;
               }
             

               }
               //free((*ceci)->le_frere_suivant);

           }

        }
    }


void detruire_table(t_table* ceci){
    if((*ceci)->le_frere_suivant != NULL){

        while((*ceci)->le_frere_suivant != NULL){

            
            while((*ceci)->le_premier_fils != NULL){
            
                supprimer_entree((*ceci));

            }
        }
    }else{
        if((*ceci)->le_premier_fils != NULL){
            if((*ceci)->le_premier_fils->le_frere_suivant != 0){
                supprimer_entree((*ceci)->le_premier_fils);

                detruire_table((*ceci)->le_premier_fils);
            }
        }else{
            supprimer_entree((*ceci));
        }
    }
    
}


void sauver_table(t_table ceci, FILE* dans){
    if(ceci != TABLE_VIDE){
        int decalage = 0;
        if (dans != NULL){
            if(ceci->l_etiquette){     
            fprintf(dans,"%s \n",ceci->l_etiquette);
                
                if(ceci->le_premier_fils != NULL){ 
                    a_entree  temp = ceci;
                    int i =  0 ;
                    while(temp->le_pere !=NULL){
                        temp = temp->le_pere;
                        i++;
                    }
                    for(int a = 0 ; a <= i ; a++){
                        fprintf(dans , " ");
                    }
                    sauver_table(ceci->le_premier_fils,dans);  
                } 
                if(ceci->le_frere_suivant != NULL){
                    a_entree  temp = ceci;
                    int i =  -1 ;
                    while(temp->le_pere !=NULL){
                        temp = temp->le_pere;
                        i++;
                    }
                    for(int a = 0 ; a <= i ; a++){
                        fprintf(dans , " ");
                    }
                    sauver_table(ceci->le_frere_suivant, dans);        
                }
                if(ceci->le_frere_suivant == ceci->le_dernier_fils  && ceci->le_frere_suivant != NULL ){
                    sauver_table(ceci->le_dernier_fils, dans);    
                }
            }
        }else{
            printf("Impossible d'ouvrir le fichier test.txt");
        }
        
}
        
    
    return;
}

