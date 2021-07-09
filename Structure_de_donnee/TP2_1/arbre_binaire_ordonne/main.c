#include <stdio.h>
#include <stdlib.h>
#include "p_arbre_binaire_ordonne.h"

int main(){
    t_arbre_binaire_ordonnee mon_arbre = ARBRE_VIDE;

    afficher_arbre_binaire(mon_arbre, 0);
    printf("***************\n");

    
    inserer_dans_abo(&mon_arbre, "bla");
    afficher_arbre_binaire(mon_arbre, 0);
    printf("***************\n");
    inserer_dans_abo(&mon_arbre, "a");
    afficher_arbre_binaire(mon_arbre, 0);
    printf("***************\n");
    inserer_dans_abo(&mon_arbre, "cf");
    afficher_arbre_binaire(mon_arbre, 0);
    printf("***************\n");
    inserer_dans_abo(&mon_arbre, "aa");
    afficher_arbre_binaire(mon_arbre, 0);
    printf("***************\n");



    char* mon_mot;
    if(extraire_plus_petit(&mon_arbre, &mon_mot)){
        printf("mot extrait : %s\n", mon_mot);
    }
    int i;
    char* mes_mots[4];
    for(i = 0; i < 4; i++){
        mes_mots[i] = NULL;
    }
/*
    vider_abo(&mon_arbre, mes_mots, 4);
    
    for(i = 0; i < 4; i++){
        if(mes_mots[i]){
            printf("mot %i : %s\n", i, mes_mots[i]);
        }else{
            printf("mot %i : inexistant\n", i);
        }
    }

    char* des_mots[6] = {"bonjour", "le", "monde", "comment", "ca", "va"};
    trier(des_mots, 6);
    for(i=0;i<6;i ++){
        printf("%s\n", des_mots[i]);
    }*/
    return 0;
}
