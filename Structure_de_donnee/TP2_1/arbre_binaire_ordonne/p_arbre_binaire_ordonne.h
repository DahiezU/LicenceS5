#ifndef P_ARBRE_BINAIRE_ORDONNEE_H_INCLUDED
#define P_ARBRE_BINAIRE_ORDONNEE_H_INCLUDED

#include "../arbre_binaire/p_arbre_binaire.h"

/**
 * \file p_arbre_binaire_ordonnee.h
 *
 *
 * \brief les éléments sont des chaines de caractères.
 *   on dispose d'une relation d'ordre sur les chaines : l'ordre lexicographique.
 *   il s'agit de l'ordre du dictionnaire (appelé de manière impropre l'ordre alphabétiques).
 *   on pourra utiliser :
 *       - soit la fonction compare_chaine faite en tp de remise en route.
 *       - soit la fonction strcmp disponible dans la bibliothèque string.h
 *
 * \author weinberg benjamin
 * \version 0.5
 * \date septembre 2019

 * \warning attention cette bibliotheque manipule des pointeurs.
    il faut faire attention qu'on libère correctement la mémoire
    on veuillera également à ne pas utiliser pas un pointeur qui pointe sur zone mémoire non allouée (ou qui n'est plus alloué).

 * \warning dans ce tp, on ne mettra pas en place tous les mecanismes permettant de garantir l'intégrité des processus.
    en effet, le langage c fournit trop de moyen de détourner les securités qu'on vourdrait mettre en place.

 */

/**
 * \typedef t_arbre_binaire t_arbre_binaire_ordonnee
 */
typedef t_arbre_binaire t_arbre_binaire_ordonnee;

/**
 * \brief cette fonction ajoute quoi à *ceci en respectant la structure d'abo.
 *
 * \param ceci : t_arbre_binaire_ordonnee* : un pointeur vers un abo.
 * \param quoi : t_element : l'élément ajouté à ceci.
 */
void inserer_dans_abo(t_arbre_binaire_ordonnee* ceci, t_element quoi);


/**
 * \brief cette fonction supprime le plus petit élément de *ceci et place la valeur dans dans.
 *
 * \param ceci : t_arbre_binaire_ordonnee* : un pointeur vers un abo.
 * \param quoi : t_element* : un pointeur vers un élément permettant de recevoir la valeur supprimée.
 * \return int : 0 si *ceci est vide;
 * \return int : 1 sinon.
 */
int extraire_plus_petit(t_arbre_binaire_ordonnee* ceci, t_element* dans);

/**
 * \brief cette fonction ajoute toutes les éléments de avec à *ceci.
 *
 * \param ceci : t_arbre_binaire_ordonnee* : un pointeur vers un abo.
 * \param avec : t_element* : un tableau d'éléments à ajouter.
 * \param taille : int : la taille du tableau avec.
 */
void remplir_abo(t_arbre_binaire_ordonnee* ceci, t_element* avec, int taille);

/**
 * \brief cette fonction supprime taille plus petits éléments de *ceci
 * et les ajoute à dans.
 * si il n'y a pas assez d'éléments dans *ceci alors un message apparait.
 *
 * \param ceci : t_arbre_binaire_ordonnee* : un pointeur vers un abo.
 * \param dans : t_element* : un tableau d'éléments à récupérer.
 * \param taille : int : la taille du tableau avec.
 */
void vider_abo(t_arbre_binaire_ordonnee* ceci, t_element* dans, int taille);

/**
 * \brief ce fonction trie le tableaux ceci.
 *
 * \param ceci : t_element* : un tableau d'éléments.
 * \param taille : int : la taille du tableau ceci.
 */
void trier(t_element* ceci, int taille);


#endif // p_arbre_binaire_ordonnee_h_included
