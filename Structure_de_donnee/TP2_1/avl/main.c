#include <stdio.h>
#include <stdlib.h>
#include "p_avl.h"

int main(){
    t_avl mon_avl = AVL_VIDE;
    afficher_avl(mon_avl,0);
    mon_avl = nouveau_noeud("d",
                            nouveau_noeud("b",
                                          nouveau_noeud("a", AVL_VIDE, AVL_VIDE),
                                          nouveau_noeud("c", AVL_VIDE, AVL_VIDE)),
                            nouveau_noeud("f",
                                          nouveau_noeud("e", AVL_VIDE, AVL_VIDE),
                                          nouveau_noeud("g", AVL_VIDE, AVL_VIDE)));

    afficher_avl(mon_avl, 0);
    rotation_gauche(&mon_avl);
    afficher_avl(mon_avl, 0);
    rotation_droite(&mon_avl);
    afficher_avl(mon_avl, 0);


    t_avl mon_avl_2 = AVL_VIDE;
    afficher_avl(mon_avl_2,0);
    printf("**************\n");

    inserer_avl("a", &mon_avl_2);
    afficher_avl(mon_avl_2,0);
    printf("**************\n");

    inserer_avl("b", &mon_avl_2);
    afficher_avl(mon_avl_2,0);
    inserer_avl("c", &mon_avl_2);
    afficher_avl(mon_avl_2,0);
    inserer_avl("d", &mon_avl_2);
    afficher_avl(mon_avl_2,0);
    inserer_avl("f", &mon_avl_2);
    afficher_avl(mon_avl_2,0);
    inserer_avl("g", &mon_avl_2);
    afficher_avl(mon_avl_2,0);


    return 0;
}
