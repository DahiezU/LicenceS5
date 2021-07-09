#include "p_noeud.h"
#include "../utilitaires/p_utilitaires.h"


int main(){

    afficher_message("+ Test +", "~ Noeud ~");

    a_noeud mon_noeud_1 = nouveau_feuille("Hello");
    a_noeud mon_noeud_2 = nouveau_noeud("Bonjour", mon_noeud_1, ARBRE_VIDE);

    afficher_noeud(mon_noeud_1);
    afficher_noeud(mon_noeud_2);

    if(est_arbre_vide(ARBRE_VIDE)){
        afficher_passe("Vide");
    }else{
        afficher_echoue("Vide");
    }
    if(est_arbre_vide(mon_noeud_2)){
        afficher_echoue("Non Vide");
    }else{
        afficher_passe("Non vide");
    }

    if(est_feuille(mon_noeud_1)){
        afficher_passe("Feuille");
    }else{
        afficher_echoue("Feuille");
    }
    if(est_feuille(mon_noeud_2)){
        afficher_echoue("Non Feuille");
    }else{
        afficher_passe("Non Feuille");
    }

    detruire_noeud(mon_noeud_1);
    finaliser_noeud(&mon_noeud_2);

    afficher_noeud(mon_noeud_1);
    afficher_noeud(mon_noeud_2);

    return 0;
}