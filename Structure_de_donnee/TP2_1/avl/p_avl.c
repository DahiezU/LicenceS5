#include <stdlib.h>
#include <stdio.h>
#include "p_avl.h"

a_noeud_avl nouveau_noeud(t_element etiquette, t_avl gauche, t_avl droite){
    a_noeud_avl n_noeud = malloc(sizeof(t_noeud_avl));
    n_noeud->l_etiquette = etiquette;
    n_noeud->la_gauche = gauche;
    n_noeud->la_droite = droite;
    mettre_a_jour_hauteur((t_avl)n_noeud);
    return n_noeud;

}

void mettre_a_jour_hauteur(t_avl ceci){
    ceci->la_hauteur = 1 + MAX(hauteur_avl(ceci->la_gauche), hauteur_avl(ceci->la_droite));
}

int hauteur_avl(t_avl ceci){
    if(ceci == AVL_VIDE){
        return 0;
    }else{
        return ceci->la_hauteur;
    }
}

void afficher_avl(t_avl ceci, int decalage){
    if(! est_avl_vide(ceci)){
        afficher_avl(ceci->la_gauche, decalage+1);
        afficher_n_espaces(2*decalage);
        afficher_element(ceci->l_etiquette);
        printf("| hauteur : %d\n", ceci->la_hauteur);
        afficher_avl(ceci->la_droite, decalage+1);
    }
}


int est_avl_vide(t_avl ceci){
    return ceci == NULL;
}

int desequilibre(t_avl ceci){
    if(est_avl_vide(ceci)){
        return 0;
    }
    return hauteur_avl(ceci->la_gauche) - hauteur_avl(ceci->la_droite);
}

void rotation_gauche(t_avl* ceci){
    t_avl tmp = *ceci;
    *ceci = (*ceci)->la_droite;
    tmp->la_droite = (*ceci)->la_gauche;
    (*ceci)->la_gauche = tmp;
    mettre_a_jour_hauteur((*ceci)->la_gauche);
    mettre_a_jour_hauteur(*ceci);
}

void rotation_droite(t_avl* ceci){
    t_avl tmp = *ceci;
    *ceci = (*ceci)->la_gauche;
    tmp->la_gauche = (*ceci)->la_droite;
    (*ceci)->la_droite = tmp;
    mettre_a_jour_hauteur((*ceci)->la_droite);
    mettre_a_jour_hauteur(*ceci);
}

void rotation_droite_gauche(t_avl* ceci){
    rotation_droite(&((*ceci)->la_droite));
    rotation_gauche(ceci);
}

void rotation_gauche_droite(t_avl* ceci){
    rotation_droite(&((*ceci)->la_gauche));
    rotation_gauche(ceci);
}


void inserer_avl(t_element quoi, t_avl* dans){
    if(est_avl_vide(*dans)){
        *dans = nouveau_noeud(quoi, AVL_VIDE, AVL_VIDE);
    }else if(est_inferieur_a((*dans)->l_etiquette, quoi)){
        inserer_avl(quoi, &((*dans)->la_droite));
        if(desequilibre(*dans) == -2){
            if(desequilibre((*dans)->la_droite) == -1){
                rotation_gauche(dans);
            }else{
                rotation_droite_gauche(dans);
            }
        }
    }else{
         inserer_avl(quoi, &((*dans)->la_gauche));
        if(desequilibre(*dans) == -2){
            if(desequilibre((*dans)->la_gauche) == -1){
                rotation_droite(dans);
            }else{
                rotation_gauche_droite(dans);
            }
       }
}
