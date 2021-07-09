#include <stdio.h>
#include <string.h>
#include "p_arbre_binaire.h"

int main(){

    

    T_Arbre_Binaire e = Nouveau_Arbre_Binaire("E", ARBRE_VIDE, ARBRE_VIDE);
    T_Arbre_Binaire d = Nouveau_Arbre_Binaire("D", e, ARBRE_VIDE);
    T_Arbre_Binaire c = Nouveau_Arbre_Binaire("C", ARBRE_VIDE, ARBRE_VIDE);
    T_Arbre_Binaire b = Nouveau_Arbre_Binaire("B", c, ARBRE_VIDE);
    T_Arbre_Binaire a = Nouveau_Arbre_Binaire("A", b, c);

   
    Afficher_Arbre_Binaire(a, 0);


    return 0;
}