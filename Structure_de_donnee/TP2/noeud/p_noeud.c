#include <stdio.h>
#include <string.h>
#include "p_noeud.h"

a_noeud Nouveau_Noeud(t_element Etiquette, a_noeud Gauche, a_noeud Droite){
    a_noeud new = malloc(sizeof(a_noeud)); 
    new->L_Etiquette = Etiquette;
    new->La_Gauche = Gauche;
    new->La_Droite = Droite;
    printf("noeud tmtc ca passe dedans");
    return new;
}

a_noeud Nouveau_Feuille(t_element Etiquette){ 
    Nouveau_Noeud(Etiquette, NULL, NULL);

}

void Detruire_Noeud(a_noeud Ceci){
    free(&(Ceci->L_Etiquette));
    printf(" \n \n bonjours je passe dans le detruire_noeud \n \n");
}

void Finaliser_Noeud(a_noeud* Ceci){
    free(Ceci);
 
}

void Afficher_Noeud(a_noeud Ceci){
    printf("%p", Ceci);
    afficher_element(Ceci->L_Etiquette);
    printf("%p,", Ceci->La_Gauche);
    printf("%p ] \n", Ceci->La_Droite);
}

int Est_Arbre_Vide(a_noeud Ceci){
    return Ceci == ARBRE_VIDE;
}

int Est_Feuille(a_noeud Ceci){
    return Ceci->La_Droite == ARBRE_VIDE && Ceci->La_Gauche == ARBRE_VIDE;
}


int main () {
    /*
    t_noeud test;
    t_noeud testg;
    t_noeud testd;
    test.L_Etiquette = "noeud tmtc";
    testg.L_Etiquette = "noeud de gauche";
    testd.L_Etiquette = "noeud de droite";
   
    Nouveau_Noeud(test.L_Etiquette, &testg, &testd);
    */
    //Nouveau_Feuille("Bonjour");
    

    Detruire_Noeud(Nouveau_Feuille("Bonjour"));
    //Finaliser_Noeud(Nouveau_Feuille("Bonjour"));
    
    



}