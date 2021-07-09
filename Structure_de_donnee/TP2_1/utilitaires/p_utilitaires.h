/**
 * \file p_utils.h
 * \brief Des outils pour manipuler des éléments.
 *
 * \author Weinberg Benjamin
 * \version 0.6
 * \date septembre 2020
 *
 */

#ifndef P_UTILS_H_INCLUDED
#define P_UTILS_H_INCLUDED
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/**
 * \brief affiche n espaces.
 *
 * \param n : int :le nombre de paires d'espaces affichées.
 */
void afficher_n_espaces(int n);

/**
 * \brief retourne le nombre de caractères de <chaine>.
 *
 * \param chaine : char* : La chaine de caractères dont on veut connaitre la longueur.
 * \return : int : le nombre de caractères de <chaine>.
 */
int longueur_chaine(char* chaine);

/**
 * \brief Encapsule la comparaison deux chaines de caractères.
 *
 * \param gauche : char* : La premier chaine de caractères comparées.
 * \param droite : char* : La seconde chaine de caractères comparées.
 * \return un nombre négatif si Gauche arrive avant Droite dans le dictionnaire.
 * \return un nombre positif si Droite arrive avant Gauche dans le dictionnaire.
 * \return 0 si <gauche> et <droite> représente la même chaine de caractères.
 */
int compare_chaine(char* gauche, char* droite);

/**
 * \brief Affiche <message> aligné à gauche et <complement> aligné à droite.
 * \param message : char* : La chaine alignée à gauche.
 * \param complement : char* : La chaine alignée à droite.
 */
void afficher_message(char* message, char* complement);

/**
 * \brief Affiche un message indiquant un succès (message à gauche suivit de [ OK ] à droite).
 */
void afficher_passe(char* message);

/**
 * \brief Affiche un message indiquant un échec (message à gauche suivit de [FAIL] à droite).
 */
void afficher_echoue(char* message);



#endif // P_UTILS_H_INCLUDED
