#include <stdlib.h>
#include <stdio.h>
#include "p_b_arbre.h"

void initialiser_noeud(a_noeud ceci){
    initialiser_tableau_trie(&(ceci->les_cles));
    for(int i = 0; i<NB_CLES_MAX+1 ; i++){
        ceci->les_fils[i] = NULL;
    }
}

a_noeud nouveau_noeud() {
    a_noeud nouv_noeud = malloc(sizeof(t_noeud));
    initialiser_noeud(nouv_noeud);
    return nouv_noeud;
}

a_noeud creer_racine(t_element quoi) {
    a_noeud racine = nouveau_noeud();
    inserer_tableau_trie(&(racine->les_cles), quoi);
    return racine;
}

void finaliser_noeud(a_noeud ceci){
    free(ceci);
}

void debugger_noeud(a_noeud ceci){
    if(ceci != NULL){
        afficher_tableau_trie(&(ceci->les_cles));
        
    }
}

void afficher_noeud(a_noeud ceci, int decalage){

    if(ceci != NULL){
        for(int i = 0; i< ceci->les_cles.le_nb_elements ; i++){
            
            afficher_noeud(&(ceci->les_fils[i]),  decalage + 1);
            afficher_n_espaces(decalage*2);
            afficher_element(ceci->les_cles.les_elements[i]);

        }
        afficher_noeud(ceci->les_fils,  decalage + 1);

    }
    return;
    
}

void ajouter_noeud(a_noeud ceci, t_element quoi, t_element* ejecte, a_noeud* fils_droit_ejecte, int pos){

    if(est_feuille(ceci->les_fils)){
        if( est_plein_noeud(ceci)){
            
        }else{
            inserer_tableau_trie(ceci, quoi);
        }
    }else{
        int posi = pos_insertion_tableau_trie(ceci, quoi);
        if(est_plein_noeud(ceci)){
           
        }else{
            
        }

    }
}



