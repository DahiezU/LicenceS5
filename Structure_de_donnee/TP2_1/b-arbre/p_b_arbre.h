#ifndef p_b_arbre_h_included
#define p_b_arbre_h_included

#include "p_tableau_trie.h"

typedef struct s_noeud{
    t_tableau_trie les_cles;
    struct s_noeud* les_fils[NB_CLES_MAX+1];
}t_noeud;

typedef t_noeud* a_noeud;

void initialiser_noeud(a_noeud ceci);

/* alloue et retourne un nouveau noeud vide */
a_noeud nouveau_noeud();

/* alloue et retourne un B-arbre contenant l'élément <quoi> */
a_noeud creer_racine(t_element quoi);

/* libere un noeud pointé par <ceci> */
void finaliser_noeud(a_noeud ceci);

/* affiche le contenu d'un seul noeud */
void debugger_noeud(a_noeud ceci);


/* affiche tout le sous-arbre pointé par <ceci> décalé 2* <decalage> espace */
void afficher_noeud(a_noeud ceci, int decalage);

/* indique si le noeud pointé par <ceci> est plein */
int est_plein_noeud(a_noeud ceci);


/* ajouter <quoi> à la racine d'un B-arbre pointé par *ceci */
void ajouter_racine(a_noeud* ceci, t_element quoi);

/* ajouter <quoi> dans le noeud pointé par <ceci> à la position <pos>
    Si le noeud est plein alors il est dédoublé et indique ce dédoublement en placent le noeud créé dans *<fils_droit ejecte>. */
void ajouter_noeud(a_noeud ceci, t_element quoi, t_element* ejecte, a_noeud* fils_droit_ejecte, int pos);

/* inserer <quoi> dans le noeud pointé par <ceci> à la position <pos>
    On suppose que *<ceci> n'est pas plein */
void inserer_valeur_non_plein(a_noeud ceci, t_element quoi, a_noeud fils_droit);

/* inserer <quoi> dans le noeud pointé par <ceci> à la position <pos>
    On suppose que *<ceci> est plein */
void inserer_valeur_plein(a_noeud ceci, t_element quoi, a_noeud fils_droit, t_element* ejecte, a_noeud* fils_droit_ejecte);


/* Pour les deux fonction suivant cf inserer_valeur en supposant que les positions d'insertion sont déjà calculé et fournit par le paramètre pos */
void inserer_valeur_non_plein2(a_noeud ceci, t_element quoi, a_noeud fils_droit, int pos);
void inserer_valeur_plein2(a_noeud ceci, t_element quoi, a_noeud fils_droit, t_element* ejecte, a_noeud* fils_droit_ejecte, int pos);

#endif // p_b_arbre_h_included
