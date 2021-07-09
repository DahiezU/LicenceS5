#include <stdio.h>
#include "p_arbre_binaire.h"

t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite){
    return nouveau_noeud(etiquette, gauche, droite);
}

/**
 * \brief affiche un arbre avec un décalage.
 *
 * \param ceci : t_arbre_binaire : l'arbre à afficher.
 * \param decalage : int : Le nombre d'intentation de l'arbre. Plus l'indentation est élevée pour l'arbre est un sous-arbre rangé profondément dans un autre arbre.
 */
void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage){

    if(ceci != ARBRE_VIDE){
        afficher_arbre_binaire(ceci->la_gauche, decalage + 1);
        afficher_n_espaces(2*decalage);
        afficher_element(ceci->l_etiquette);
        printf("\n");
        afficher_arbre_binaire(ceci->la_droite, decalage + 1);
    }
}

int hauteur_arbre_binaire(t_arbre_binaire ceci) {
    int hauteur = 0;
    if (est_arbre_vide(ceci)) {
        return hauteur;
    } else {
        return MAX(hauteur_arbre_binaire(ceci->la_droite), hauteur_arbre_binaire(ceci->la_gauche))+1;
    }
}

int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci){
    int g, h;
    if(est_arbre_vide(ceci)){
        return 0;
    }else{

        g = hauteur_equilibre_arbre_binaire(ceci->la_gauche);
        h = hauteur_equilibre_arbre_binaire(ceci->la_droite);

        if((g == -1)||(h == -1)){
            return -1;
        }if(h == g){
            return h + 1;
        }else{
            return -1;
        }    
    }
}

int est_parfaitement_equilibre(t_arbre_binaire ceci){
    return -1 != hauteur_equilibre_arbre_binaire(ceci);
}

int nb_elements_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)){
        return 0;
    }
    return 1 + nb_elements_arbre_binaire(ceci->la_gauche) + nb_elements_arbre_binaire(ceci->la_droite);

}

void detruire_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)){
        return 0;
    }else{
        detruire_arbre_binaire(ceci->la_gauche);
        detruire_arbre_binaire(ceci->la_droite);
        free(ceci);
    }
}

void finaliser_arbre_binaire(t_arbre_binaire* ceci){
    detruire_arbre_binaire(*ceci);
    *ceci = ARBRE_VIDE;
}

int est_present_arbre_binaire(t_element quoi, t_arbre_binaire dans){
    if(est_arbre_vide(dans)){
        return 0;
    }
    if(est_egal_a(quoi, dans->l_etiquette)){
        return 1;
    }
    return est_present_arbre_binaire(quoi, dans->la_gauche) || est_present_arbre_binaire(quoi, dans->la_droite);
}

int nb_occurences_arbre_binaire(t_element quoi, t_arbre_binaire dans){
    if(est_arbre_vide(dans)){
        return 0;
    }
    return est_egal_a(quoi, dans->l_etiquette)
            + nb_occurences_arbre_binaire(quoi, dans->la_droite)
            + nb_occurences_arbre_binaire(quoi, dans->la_gauche);
}

int desequilibre(t_arbre_binaire ceci){
    if(ceci != ARBRE_VIDE){
        return hauteur_arbre_binaire (ceci->la_gauche) - hauteur_arbre_binaire(ceci->la_droite);
    }
    return 0;
}

t_arbre_binaire clone(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)){
        return ARBRE_VIDE;
    }
    
}


