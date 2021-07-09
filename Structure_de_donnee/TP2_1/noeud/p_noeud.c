/**
 * \file p_noeud.h
 * \brief Des outils sur les noeuds d'un arbre binaire.
 *
 * \author Weinberg Benjamin
 * \version 0.5
 * \date septembre 2019
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include "p_noeud.h"


/**
 * \brief Cette fonction construit un nouveau noeud et le retourne.
 *
 * \param etiquette : t_element : La valeur stockée dans le Noeud
 * \param gauche : a_noeud : un pointeur vers un sous arbre gauche.
 * \param droite : a_noeud : un pointeur vers un sous arbre droit.
 * \return Le nouveau noeud construit.
 */
a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite){
    a_noeud res = (a_noeud)malloc(sizeof(t_noeud));
    res->l_etiquette = etiquette;
    res->la_gauche = gauche;
    res->la_droite = droite;
    return res;
}

/**
 * \brief Cette fonction construit un nouveau feuille et la retourne.
 *
 * \param etiquette : t_element : La valeur stockée dans la feuille.
 * \return a_noeud : Le nouveau noeud construit.
 */
a_noeud nouveau_feuille(t_element etiquette){
    return nouveau_noeud(etiquette, ARBRE_VIDE, ARBRE_VIDE);
}

/**
 * \brief Librère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param ceci : a_noeud : Un pointeur vers le noeud à libérer.
 */
void detruire_noeud(a_noeud ceci){
    free(ceci);
}

/**
 * \brief Librère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param ceci : a_noeud* : Un pointeur vers un pointeur vers un noeud à libérer. *ceci vaut NULL après cette une appel à cette fonction.
 */
void finaliser_noeud(a_noeud* ceci){
    detruire_noeud(*ceci);
    *ceci = NULL;
}

/**
 * \brief Affiche le contenu d'un noeud pointé par ceci.
 * le sous-arbre gauche et le sous-arbre droit ne sont pas affichés.
 *
 * \param ceci : a_noeud : Un pointeur vers un noeud à afficher. Attention ceci ne doit pas être NULL.
 */
void afficher_noeud(a_noeud ceci){
    if(est_arbre_vide(ceci)){
        printf("x\n");    
    }else{
        printf("%x : [", ceci);
        afficher_element(ceci->l_etiquette);
        printf(", %x, %x]\n", ceci->la_gauche, ceci->la_droite);
    }
}

/**
 * \brief indique si ceci est arbre vide.
 *
 * \param ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si ceci est vide.
 */
int est_arbre_vide(a_noeud ceci){
    return ceci == ARBRE_VIDE;
}


/**
 * \brief indique si ceci est une feuille.
 *
 * \param ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si ceci est une feuille.
 */
int est_feuille(a_noeud ceci){
    if (ceci == ARBRE_VIDE){
        return 0;
    }
    return ceci->la_droite == ARBRE_VIDE && ceci->la_gauche == ARBRE_VIDE;
}

