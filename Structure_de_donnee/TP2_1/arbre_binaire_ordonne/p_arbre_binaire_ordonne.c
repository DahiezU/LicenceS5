#include <stdio.h>
#include "p_arbre_binaire_ordonne.h"

void inserer_dans_abo(t_arbre_binaire_ordonnee* ceci, t_element quoi){;
    if (est_arbre_vide(*ceci)){
        *ceci = nouveau_feuille(quoi);
    }else if (est_inferieur_a((*ceci)->l_etiquette, quoi)){
        inserer_dans_abo(&((*ceci)->la_droite), quoi);
    }else{
        inserer_dans_abo(&((*ceci)->la_gauche), quoi);
    }
}

int extraire_plus_petit(t_arbre_binaire_ordonnee* ceci, t_element* dans){
    if(est_arbre_vide(*ceci)){
        return 0;
    }
    if(est_arbre_vide((*ceci)->la_gauche)){
        *dans = (*ceci)->l_etiquette;
        a_noeud tmp = (*ceci)->la_droite;
        /* finaliser_noeud(ceci);*/
        detruire_noeud(*ceci); /* l'un ou l'autre doit fonctionner */
        *ceci = tmp;
        return 1;
    }else{
        return extraire_plus_petit(&((*ceci)->la_gauche), dans);
    }
}

void remplir_abo(t_arbre_binaire_ordonnee* ceci, t_element* avec, int taille){
    for (int i = 0; i < taille; i++){
        inserer_dans_abo(ceci, avec[i]);
    }
}

void vider_abo(t_arbre_binaire_ordonnee* ceci, t_element* dans, int taille){
    for(int i = 0; i < taille; i++){
        if(!extraire_plus_petit(ceci, &(dans[i]))){
            printf("nb elements insuffisant !\n");
            return;
        }
    }
}

void trier(t_element* ceci, int taille) {
    t_arbre_binaire_ordonnee nouvel_arbre = ARBRE_VIDE;
    remplir_abo(&nouvel_arbre, ceci, taille);
    vider_abo(&nouvel_arbre, ceci, taille);
}
