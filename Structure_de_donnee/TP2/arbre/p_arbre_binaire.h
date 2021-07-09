#ifndef P_ARBRE_BINAIRE_H_INCLUDED
#define P_ARBRE_BINAIRE_H_INCLUDED
#include <stdlib.h>
#include "../utilitaires/p_utilitaires.h"
#include "../noeud/p_noeud.h"


/**
 * \file p_arbre_binaire.h
 * \brief fichier contenant les outils sur les arbres binaire.
 *
 * \author Weinberg Benjamin
 * \version 0.5
 * \date septembre 2019
 *
 * \warning ATTENTION CETTE BIBLIOTHEQUE MANIPULE DES POINTEURS.
    Il faut faire attention qu'on libère correctement la mémoire
    On veuillera également à ne pas utiliser pas un pointeur qui pointe sur zone mémoire non allouée (ou qui n'est plus alloué).

 * \warning Dans ce TP, on ne mettra pas en place tous les mecanismes permettant de garantir l'intégrité des processus.
    En effet, le langage C fournit trop de moyen de détourner les securités qu'on vourdrait mettre en place.
*/


/**
 * \typedef T_Arbre_Binaire
 * \brief Un arbre est un Pointeur sur un Noeud
 */
typedef a_noeud T_Arbre_Binaire;


/**
 * \brief Assemble un arbre avec une étiquette et deux sous-arbres.
 *
 * \param Etiquette : T_Element : La valeur inscrite dans l'arbre.
 * \param Gauche : T_Arbre_Binaire : ce qui sera le sous-arbre gauche de l'arbre construit.
 * \param Droite: T_Arbre_Binaire : ce qui sera le sous-arbre droit de l'arbre construit.
 */
T_Arbre_Binaire Nouveau_Arbre_Binaire(t_element Etiquette, T_Arbre_Binaire Gauche, T_Arbre_Binaire Droite);


/**
 * \brief affiche un arbre avec un décalage.
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre à afficher.
 * \param Decalage : int : Le nombre d'intentation de l'arbre. Plus l'indentation est élevée pour l'arbre est un sous-arbre rangé profondément dans un autre arbre.
 */
void Afficher_Arbre_Binaire(T_Arbre_Binaire Ceci, int Decalage);


/**
 * \brief retourne la hauteur de l'arbre (i.e. la longueur de la plus grande branche de l'arbre).
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre dont on cherche la hauteur.
 * \return int : la hauteur de Ceci.
 */
int Hauteur_Arbre_Binaire(T_Arbre_Binaire Ceci);


/**
 * \brief retourne la hauteur de Ceci si Ceci est équilibré; -1 sinon.
 *
 * \param Ceci : T_Arbre_Binaire :
 * \return int : la hauteur de Ceci si Ceci est équilibré; -1 sinon.
 */
int Hauteur_Equilibre_Arbre_Binaire(T_Arbre_Binaire Ceci);


/**
 * \brief retourne Vrai si et seulement si l'arbre est parfaitement équilibré
 * (i.e. Toutes les branches font exactement la même longueur).
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre dont on veut savoir si il est équilibré.
 * \return int : 0 si Ceci n'est pas équilibré ; une valeur non nulle sinon.
 */
int Est_Parfaitement_Equilibre(T_Arbre_Binaire Ceci);

/**
 * \brief retourne le nombre d'éléments du paramètre.
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre dont on cherche le nombre d'éléments.
 * \return int : le nombre d'éléments.
 */
int Nb_Elements_Arbre_Binaire(T_Arbre_Binaire Ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres.
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre qu'on souhaite détruire.
 */
void Detruire_Arbre_Binaire(T_Arbre_Binaire Ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres et Ceci pointe maintenant vers l'arbre vide.
 *
 * \param Ceci : T_Arbre_Binaire* : un pointeur vers un arbre qu'on souhaite détruire.
 */
void Finaliser_Arbre_Binaire(T_Arbre_Binaire* Ceci);

/**
 * \brief Detruit tous les noeuds de l'arbres et Ceci pointe maintenant vers l'arbre vide.
 *
 * \param Quoi : T_Element : un élément qu'on cherche dans Dans.
 * \param Dans : T_Arbre_Binaire : un arbre où on cherche Quoi.
 * \return int : 0 si Quoi n'est pas un élément de Dans, une valeur non nulle sinon.
 */
int Est_Present_Arbre_Binaire(t_element Quoi, T_Arbre_Binaire Dans);


/**
 * \brief Detruit tous les noeuds de l'arbres et Ceci pointe maintenant vers l'arbre vide.
 *
 * \param Quoi : T_Element : un élément qu'on cherche dans Dans.
 * \param Dans : T_Arbre_Binaire : un arbre où on cherche Quoi.
 * \return int : le nombre d'occurences de Quoi dans Dans.
 */
int Nb_Occurences_Present_Arbre_Binaire(t_element Quoi, T_Arbre_Binaire Dans);

/**
 * \brief Cette fonction calcule le déséquilibre d'un arbre.
 * le déséquilibre d'un arbre est la différence entre la hauteur du sous arbre doit et
 * la hauteur du sous arbre gauche.
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre sur lequel cette fonction calcule le déséquilibre.
 */
int Desequilibre(T_Arbre_Binaire Ceci);

/**
 * \brief Cette fonction duplique la structure des l'arbre Ceci
 *
 * \param Ceci : T_Arbre_Binaire : l'arbre qui est clone par la fonction.
 * \return T_Arbre_Binaire : le clone de l'arbre Ceci.
 */
T_Arbre_Binaire Clone(T_Arbre_Binaire Ceci);


/** 2020 - 2021 */


/**
 * \brief retourne la hauteur de <Ceci> si <Ceci> est tassé; -1 sinon.
 *
 * \param Ceci : T_Arbre_Binaire :
 * \return int : la hauteur de <Ceci> si <Ceci> est tassé; -1 sinon.
 */
int Hauteur_Tasse(T_Arbre_Binaire Ceci);

/**
 * \brief Ajoute <Quoi> à <*Ceci>. On suppose que <*Ceci> est tassé.
 * L'élément ajouter est ajouter comme une feuille de l'arbre <*Ceci>,
 * de sorte que <*Ceci> conserve la propriété d'être Tassé.
 *
 * \param Ceci : T_Arbre_Binaire* : l'arbre tassé dans lequel ajouter <Quoi>.
 * \param Quoi : T_Element : l'élément à ajouter à *Ceci.
 * \return void : rien.
 */
void Entasser(T_Arbre_Binaire* Ceci, t_element Quoi);


#endif // P_ARBRE_H_INCLUDED
