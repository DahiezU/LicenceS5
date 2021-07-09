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
typedef struct S_Noeud{
    t_element L_Etiquette;
    struct S_Noeud* La_Gauche;
    struct S_Noeud* La_Droite;
}t_noeud;

/**
 * \brief Un pointeur sur un noeud.
 */
typedef t_noeud* a_noeud;

/**
 * \brief Cette fonction construit un nouveau noeud et le retourne.
 *
 * \param Etiquette : t_element : La valeur stockée dans le Noeud
 * \param Gauche : a_noeud : un pointeur vers un sous arbre gauche.
 * \param Droite : a_noeud : un pointeur vers un sous arbre droit.
 * \return Le nouveau noeud construit.
 */
a_noeud Nouveau_Noeud(t_element Etiquette, a_noeud Gauche, a_noeud Droite);


/**
 * \brief Cette fonction construit un nouveau feuille et la retourne.
 *
 * \param Etiquette : t_element : La valeur stockée dans la feuille.
 * \return a_noeud : Le nouveau noeud construit.
 */
a_noeud Nouveau_Feuille(t_element Etiquette);

/**
 * \brief Librère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param Ceci : a_noeud : Un pointeur vers le noeud à libérer.
 */
void Detruire_Noeud(a_noeud Ceci);

/**
 * \brief Librère la mémoire pour un seul noeud
 * (le sous-arbre gauche et le sous-arbre droit sont toujours alloués).
 * Attention au fuite de mémoire.
 *
 * \param Ceci : a_noeud* : Un pointeur vers un pointeur vers un noeud à libérer. *Ceci vaut NULL après cette une appel à cette fonction.
 */
void Finaliser_Noeud(a_noeud* Ceci);

/**
 * \brief Affiche le contenu d'un noeud pointé par Ceci.
 * le sous-arbre gauche et le sous-arbre droit ne sont pas affichés.
 *
 * \param Ceci : a_noeud : Un pointeur vers un noeud à afficher. Attention Ceci ne doit pas être NULL.
 */
void Afficher_Noeud(a_noeud Ceci);

/**
 * \brief indique si Ceci est arbre vide.
 *
 * \param Ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si Ceci est vide.
 */
int Est_Arbre_Vide(a_noeud Ceci);


/**
 * \brief indique si Ceci est une feuille.
 *
 * \param Ceci : a_noeud : l'arbre testé.
 * \return int : Vrai si et seulement si Ceci est une feuille.
 */
int Est_Feuille(a_noeud Ceci);


#endif // P_Noeud_H_INCLUDED
