#include <stdio.h>
#include <stdlib.h>
#include "p_arbre_binaire.h"


int main(){

    t_arbre_binaire e = nouveau_arbre_binaire("E", ARBRE_VIDE, ARBRE_VIDE);
    t_arbre_binaire d = nouveau_arbre_binaire("D", e, ARBRE_VIDE);
    t_arbre_binaire c = nouveau_arbre_binaire("C", ARBRE_VIDE, ARBRE_VIDE);
    t_arbre_binaire b = nouveau_arbre_binaire("B", c, ARBRE_VIDE);
    t_arbre_binaire a = nouveau_arbre_binaire("A", b, d);

    afficher_arbre_binaire(a, 0);

}