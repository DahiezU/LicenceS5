#include <stdlib.h>
#include <stdio.h>
#include "../utilitaires/p_utilitaires.h"
#include "p_element_string.h"



int main(int argc, const char * argv[]) {

    afficher_element("Titi");
    printf("\n");
    afficher_passe("afficher_element");

    if(est_egal_a("titi", "titi")){
        afficher_passe("Egalite");
    }else{
        afficher_echoue("Egalite");
    }
    if(!est_egal_a("toto", "titi")){
        afficher_passe("Egalite");
    }else{
        afficher_echoue("Egalite");
    }

    if(est_inferieur_a("titi", "titi")){
        afficher_echoue("est_inferieur");
    }else{
        afficher_passe("est_inferieur");
    }
    if(est_inferieur_a("ti", "titi")){
        afficher_passe("est_inferieur");
    }else{
        afficher_echoue("est_inferieur");
    }
    if(est_inferieur_a("titam", "titi")){
        afficher_passe("est_inferieur");
    }else{
        afficher_echoue("est_inferieur");
    }
    if(est_inferieur_a("titom", "titi")){
        afficher_echoue("est_inferieur");
    }else{
        afficher_passe("est_inferieur");
    }

    return 0;
}


