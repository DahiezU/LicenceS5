#ifndef P_arbre_binaire_H_INCLUDED
#define P_arbre_binaire_H_INCLUDED
#include "../noeud/p_noeud.h"

/**
 * \file p_arbre_binaire.h
 * \brief fichier contenant les outils sur les arbres binaire.
 *
 * \author Weinberg Benjamin
 * \version 0.6
 * \date septembre 2020
 *
 * \warning ATTENTION CETTE BIBLIOTHEQUE MANIPULE DES POINTEURS.
    Il faut faire attention qu'on libère correctement la mémoire
    On veuillera également à ne pas utiliser pas un pointeur qui pointe sur zone mémoire non allouée (ou qui n'est plus alloué).

 * \warning Dans ce TP, on ne mettra pas en place tous les mecanismes permettant de garantir l'intégrité des processus.
    En effet, le langage C fournit trop de moyen de détourner les securités qu'on vourdrait mettre en place.
*/


/**
 * \typedef t_arbre_binaire
 * \brief Un arbre est un Pointeur sur un Noeud
 */
typedef a_noeud t_arbre_binaire;


/**
 * \brief Assemble un arbre avec une étiquette et deux sous-arbres.
 *
 * \param etiquette : t_element : La valeur inscrite dans l'arbre.
 * \param gauche : t_arbre_binaire : ce qui sera le sous-arbre gauche de l'arbre construit.
 * \param droite: t_arbre_binaire : ce qui sera le sous-arbre droit de l'arbre construit.
 */
t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite);


/**
 * \brief affiche un arbre avec un décalage.
 *
 * \param ceci : t_arbre_binaire : l'arbre à afficher.
 * \param decalage : int : Le nombre d'intentation de l'arbre. Plus l'indentation est élevée pour l'arbre est un sous-arbre rangé profondément dans un autre arbre.
 */
void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage);


/**
 * \brief retourne la hauteur de l'arbre (i.e. la longueur de la plus grande branche de l'arbre).
 *
 * \param ceci : t_arbre_binaire : l'arbre dont on cherche la hauteur.
 * \return int : la hauteur de ceci.
 */
int hauteur_arbre_binaire(t_arbre_binaire ceci);


/**
 * \brief retourne la hauteur de ceci si ceci est équilibré; -1 sinon.
 *
 * \param ceci : t_arbre_binaire :
 * \return int : la hauteur de ceci si ceci est équilibré; -1 sinon.
 */
int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci);


/**
 * \brief retourne Vrai si et seulement si l'arbre est parfaitement équilibré
 * (i.e. Toutes les branches font exactement la même longueur).
 *
 * \param ceci : t_arbre_binaire : l'arbre dont on veut savoir si il est équilibré.
 * \return int : 0 si ceci n'est pas équilibré ; une valeur non nulle sinon.
 */
int est_parfaitement_equilibre(t_arbre_binaire ceci);

/**
 * \brief retourne le nombre d'éléments du paramètre.
 *
 * \param ceci : t_arbre_binaire : l'arbre dont on cherche le nombre d'éléments.
 * \return int : le nombre d'éléments.
 */
int nb_elements_arbre_binaire(t_arbre_binaire ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres.
 *
 * \param ceci : t_arbre_binaire : l'arbre qu'on souhaite détruire.
 */
void detruire_arbre_binaire(t_arbre_binaire ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres et ceci pointe maintenant vers l'arbre vide.
 *
 * \param ceci : t_arbre_binaire* : un pointeur vers un arbre qu'on souhaite détruire.
 */
void finaliser_arbre_binaire(t_arbre_binaire* ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres et ceci pointe maintenant vers l'arbre vide.
 *
 * \param quoi : t_element : un élément qu'on cherche dans Dans.
 * \param dans : t_arbre_binaire : un arbre où on cherche Quoi.
 * \return int : 0 si Quoi n'est pas un élément de Dans, une valeur non nulle sinon.
 */
int est_present_arbre_binaire(t_element quoi, t_arbre_binaire dans);


/**
 * \brief Detruit tous les noeuds de l'arbres et ceci pointe maintenant vers l'arbre vide.
 *
 * \param quoi : t_element : un élément qu'on cherche dans Dans.
 * \param dans : t_arbre_binaire : un arbre où on cherche Quoi.
 * \return int : le nombre d'occurences de Quoi dans Dans.
 */
int nb_occurences_arbre_binaire(t_element quoi, t_arbre_binaire dans);

/**
 * \brief Cette fonction calcule le déséquilibre d'un arbre.
 * le déséquilibre d'un arbre est la différence entre la hauteur du sous arbre doit et
 * la hauteur du sous arbre gauche.
 *
 * \param ceci : t_arbre_binaire : l'arbre sur lequel cette fonction calcule le déséquilibre.
 */
int desequilibre(t_arbre_binaire ceci);

/**
 * \brief Cette fonction duplique la structure des l'arbre ceci
 *
 * \param ceci : t_arbre_binaire : l'arbre qui est clone par la fonction.
 * \return t_arbre_binaire : le clone de l'arbre ceci.
 */
t_arbre_binaire clone(t_arbre_binaire ceci);


/** 2020 - 2021 */


/**
 * \brief retourne la hauteur de <ceci> si <ceci> est tassé; -1 sinon.
 *
 * \param ceci : t_arbre_binaire :
 * \return int : la hauteur de <ceci> si <ceci> est tassé; -1 sinon.
 */
int hauteur_tasse(t_arbre_binaire ceci);

/**
 * \brief Ajoute <Quoi> à <*ceci>. On suppose que <*ceci> est tassé.
 * L'élément ajouter est ajouter comme une feuille de l'arbre <*ceci>,
 * de sorte que <*ceci> conserve la propriété d'être Tassé.
 *
 * \param ceci : t_arbre_binaire* : l'arbre tassé dans lequel ajouter <Quoi>.
 * \param quoi : t_element : l'élément à ajouter à *ceci.
 * \return void : rien.
 */
void entasser(t_arbre_binaire* ceci, t_element Quoi);


#endif // P_arbre_H_INCLUDED
