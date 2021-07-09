#include <stdio.h>
#include <string.h>
#include "p_arbre_binaire.h"

T_Arbre_Binaire Nouveau_Arbre_Binaire(t_element Etiquette, T_Arbre_Binaire Gauche, T_Arbre_Binaire Droite){
    T_Arbre_Binaire new = malloc(sizeof(a_noeud)); 
    new->L_Etiquette = Etiquette;
    new->La_Gauche = Gauche;
    new->La_Droite = Droite;
    //printf(" tmtc ca passe dedans");
    return new;
}

void Afficher_Arbre_Binaire(T_Arbre_Binaire Ceci, int Decalage){
    
    if(Ceci == ARBRE_VIDE){
        return;
    }
    else{
        Afficher_Arbre_Binaire(Ceci->La_Gauche, Decalage + 1);
        afficher_n_espaces(2*Decalage);
        afficher_element( Ceci->L_Etiquette);
        printf("\n");
        Afficher_Arbre_Binaire(Ceci->La_Droite, Decalage + 1);
    }
}