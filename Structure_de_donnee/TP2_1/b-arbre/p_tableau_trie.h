#ifndef P_TABLEAU_TRIE_H_INCLUDED
#define P_TABLEAU_TRIE_H_INCLUDED

#include "../utilitaires/p_utilitaires.h"
#include "../element_string/p_element_string.h"

#define ORDRE 3
#define NB_CLES_MAX 2*ORDRE

typedef struct s_tableau_trie{
    t_element les_elements[NB_CLES_MAX];
    int le_nb_elements;
} t_tableau_trie;

typedef t_tableau_trie* a_tableau_trie;

/** a appeler apres la déclaration d'une variable de type t_tableau_trie.
    pour régler le champs le_nb_elements */
void initialiser_tableau_trie(a_tableau_trie ceci);

/** sert à rien */
void finaliser_tableau_trie(a_tableau_trie ceci);

/** afficher un t_tableau_trie */
void afficher_tableau_trie(a_tableau_trie ceci);

/** retourne le nombre d'éléments de ceci */
int nb_elements_tableau_trie(const a_tableau_trie ceci);

/** fournit la position où <quoi> serait inséré */
int pos_insertion_tableau_trie(const a_tableau_trie ceci, t_element quoi);

/** indique si ceci est plein */
int est_plein_tableau_trie(const a_tableau_trie ceci);

/** ajoute un élément à quoi.
    si ceci était déjà plein alors l'élément n'est pas insérer et la fonction retourne 0.
    en cas de succés (le tableau n'etait pas encore plein la fonction retourne 1 */
int inserer_tableau_trie(a_tableau_trie ceci, t_element quoi);

/** réalise l'insertion ceci à la position demandée et en supposant que n'est pas plein */
void inserer_tableau_naif(a_tableau_trie ceci, t_element quoi, int pos);

/** supprime l'élément de ceci
    cette fonction retourne 1 si la suppression s'est bien passée et 0 si élément été absent */
int supprimer_tableau_trie(a_tableau_trie ceci, t_element quoi);

/** retourne l'élément d'indice i*/
t_element valeur(a_tableau_trie ceci, int i);

#endif // p_base_h_included
