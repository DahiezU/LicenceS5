#include "p_tableau_trie.h"
#include "../utilitaires/p_utilitaires.h"
#include <stdio.h>

void initialiser_tableau_trie(a_tableau_trie ceci) {
    ceci->le_nb_elements = 0;
}

void finaliser_tableau_trie(a_tableau_trie ceci) {

}

void afficher_tableau_trie(a_tableau_trie ceci) {
    for (int i = 0; i < ceci->le_nb_elements; i++)
    {
        afficher_element(ceci->les_elements[i]);
    }
    
}

int nb_elements_tableau_trie(const a_tableau_trie ceci) {
    return ceci->le_nb_elements;
}

int pos_insertion_tableau_trie(const a_tableau_trie ceci, t_element quoi) {
    for (int i = 0; i < ceci->le_nb_elements; i++)
    {
        if (est_inferieur_a(quoi, ceci->les_elements[i]))
        {
            return i;
        }
    }
    return ceci->le_nb_elements;
}

int est_plein_tableau_trie(const a_tableau_trie ceci) {
    return ceci->le_nb_elements == NB_CLES_MAX;
}

void inserer_tableau_naif(a_tableau_trie ceci, t_element quoi, int pos) {
    for (int i = ceci->le_nb_elements; i > pos; i--)
    {
        ceci->les_elements[i] = ceci->les_elements[i-1];
    }
    ceci->les_elements[pos] = quoi;
    ceci->le_nb_elements++;
}

int inserer_tableau_trie(a_tableau_trie ceci, t_element quoi) {
    if (est_plein_tableau_trie(ceci))
    {
        return 0;
    } else {
        inserer_tableau_naif(ceci, quoi, pos_insertion_tableau_trie(ceci, quoi));
        return 1;
    }
    
}

int supprimer_tableau_trie(a_tableau_trie ceci, t_element quoi){

    int posi = pos_insertion_tableau_trie(ceci, quoi);
    if( est_egal_a(quoi, ceci->les_elements[posi]) ){
        for(int i = posi; i< NB_CLES_MAX ; i++){
            ceci->les_elements[i] = ceci->les_elements[i+1];
        }
        return 1;
    }else{
        return 0;
    }
     
}

t_element valeur(a_tableau_trie ceci, int i){
    return ceci->les_elements[i];
}
