#include <stdio.h>
#include <string.h>

#define LARGEUR_ECRAN 80

void afficher_n_espaces(int n) {
    for (int i = 0; i <= n; i++) {
        printf(" ");
    }
}

int longueur_chaine(char* chaine) {
    int i = 0;
    while (chaine[i] != '\0') {
        i++;
    }
    return i;
}

int compare_chaine(char* gauche, char* droite) {
    if (longueur_chaine(gauche) != 0) {
        if(gauche[0] < droite[0]) {
            return -1;
        }
        else if(gauche[0] > droite[0]) {
            return 1;
        }
        return  compare_chaine(&gauche[1], &droite[1]);
    }
    return 0;
}


//int compare_chaine(char* gauche, char* droite) {
//    int left_string = longueur_chaine(gauche);
//    int i;
//    for(i = 0; i < left_string; i++) {
//        if(gauche[i] < droite[i]) {
//            return -1;
//        }
//        else if(gauche[i] > droite[i]) {
//            return 1;
//        }
//    }
//    return -droite[i];
//}

void afficher_message(char* message, char* complement) {
    printf("%s", message);
    afficher_n_espaces(LARGEUR_ECRAN -longueur_chaine(message));
    printf("%s \n", complement);
}

void afficher_passe(char* message) {
    afficher_message(message, "[ OK ]");
}

void afficher_echoue(char* message) {
    afficher_message(message, "[FAIL]");
}
