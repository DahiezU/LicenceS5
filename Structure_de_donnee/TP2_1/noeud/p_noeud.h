/**
 * \file p_noeud.h
 * \brief Des outils sur les noeuds d'un arbre binaire.
 *
 * \author Weinberg Benjamin
 * \version 0.5
 * \date septembre 2019
 *
 */
#ifndef P_Noeud_H_INCLUDED
#define P_Noeud_H_INCLUDED
#include <stdlib.h>
#include "../utilitaires/p_utilitaires.h"
#include "../element_string/p_element_string.h"

#define ARBRE_VIDE NULL


/**
 * \brief le type permettant de stocker les informations relative à un noeud.
 * \struct t_noeud
 */
typedef struct s_noeud{
    t_element l_etiquette;
    struct s_noeud* la_gauche;
    struct s_noeud* la_droite;
}t_noeud;

/**
 * \brief Un pointeur sur un noeud.
 */
typedef t_noeud* a_noeud;

/**
 * \brief Cette fonction construit un nouveau noeud et le retourne.
 *
 * \param etiquette : t_element : La valeur stockée dans le Noeud
 * \param gauche : a_noeud : un pointeur vers un sous arbre gauche.
 * \param droite : a_noeud : un pointeur vers un sous arbre droit.
 * \return Le nouveau noeud construit.
 */
a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite);


/**
 * \brief Cette fonction construit un nouveau feuille et la retourne.
 *
 * \param etiquette : t_element : La valeur stockée dans la feuille.
 * \return a_noeud : Le nouveau noeud construit.
 */
a_noeud nouveau_feuille(t_element etiquette);

/**
 * \brief Libère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param ceci : a_noeud : Un pointeur vers le noeud à libérer.
 */
void detruire_noeud(a_noeud ceci);

/**
 * \brief Libère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param ceci : a_noeud* : Un pointeur vers un pointeur vers un noeud à libérer. *ceci vaut NULL après cette une appel à cette fonction.
 */
void finaliser_noeud(a_noeud* ceci);

/**
 * \brief Affiche le contenu d'un noeud pointé par ceci.
 * le sous-arbre gauche et le sous-arbre droit ne sont pas affichés.
 *
 * \param ceci : a_noeud : Un pointeur vers un noeud à afficher. Attention ceci ne doit pas être NULL.
 */
void afficher_noeud(a_noeud ceci);

/**
 * \brief indique si ceci est arbre vide.
 *
 * \param ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si ceci est vide.
 */
int est_arbre_vide(a_noeud ceci);


/**
 * \brief indique si ceci est une feuille.
 *
 * \param ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si ceci est une feuille.
 */
int est_feuille(a_noeud ceci);


#endif // P_Noeud_H_INCLUDED
