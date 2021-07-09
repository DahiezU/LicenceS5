/**
 * \file p_element_string.c
 * \brief Des outils pour manipuler des éléments.
 *
 * \author Weinberg Benjamin
 * \version 0.6
 * \date septembre 2020
 *
 */
#include <stdio.h>
#include "p_element_string.h"
#include "../utilitaires/p_utilitaires.h"

/**
 * \brief Affiche un élément.
 *
 * \param ceci : t_element : L'élément Affiché
 */
void afficher_element(t_element ceci){
    printf("%s", ceci);
}

/**
 * \brief Encapsule la comparaison des t_elements.
 *
 * \param ceci : t_element
 * \param cela : t_element
 * \return int : retourne Vrai si et seulement <ceci> est placé avant <cela> dans le dictionnaire.
 */
int est_inferieur_a(t_element ceci, t_element cela){
    return compare_chaine(ceci, cela) <= 0;
}

/**
 * \brief Teste l'égalité de deux t_elements.
 *
 * \param ceci : t_element : le premier élément comparé.
 * \param cela : t_element : le second élément comparé.
 * \return int : retourne Vrai si et seulement ceci et cela représente la même chaine de caractères.
 */
int est_egal_a(t_element ceci, t_element cela){
    return compare_chaine(ceci, cela) == 0;
}

/**
 * \brief Echange les valeurs pointées par les paramètres
 *
 * \param ceci : t_element* : le pointeur sur le premier élément échangé.
 * \param cela : t_element* : le pointeur sur second élément échangé.
 */
void echanger(t_element* ceci, t_element* cela){
    t_element tmp = *ceci;
    *ceci = *cela;
    *cela = tmp;
}