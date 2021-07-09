#include <stdio.h>
#include "p_utilitaires.h"

int main(int argc, char* argv){

    printf("**");
    afficher_n_espaces(3);
    printf("**\n");
    afficher_message("Bonjour", "[ OK ]");
    afficher_passe("Bon travail !");
    afficher_echoue("encore un effort !");
    if(compare_chaine("titi", "titi") == 0){
        afficher_passe("Egalite");
    }else{
        afficher_echoue("Egalite");
    }
    if(compare_chaine("tati", "titi") < 0){
        afficher_passe("Inferieur");
    }else{
        afficher_echoue("Inferieur");
    }
    if(compare_chaine("ti", "titi") < 0){
        afficher_passe("Inferieur");
    }else{
        afficher_echoue("Inferieur");
    }
    if(compare_chaine("titi", "ti") > 0){
        afficher_passe("Superieur");
    }else{
        afficher_echoue("Superieur");
    }
    if(compare_chaine("titom", "titi") > 0){
        afficher_passe("Superieur");
    }else{
        afficher_echoue("Superieur");
    }
    return 0;
}