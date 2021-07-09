#include <stdio.h>

/**
 * \brief affiche n espaces.
 *
 * \param n : int :le nombre de paires d'espaces affichées.
 */
void afficher_n_espaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

/**
 * \brief retourne le nombre de caractères de <chaine>.
 *
 * \param chaine : char* : La chaine de caractères dont on veut connaitre la longueur.
 * \return : int : le nombre de caractères de <chaine>.
 */
int longueur_chaine(char* chaine){
    int i = 0;
    while(chaine[i] != '\0'){
        i += 1; /*i++ ou i = i + 1 */
    }
    return i;
}

/**
 * \brief Encapsule la comparaison deux chaines de caractères.
 *
 * \param gauche : char* : La premier chaine de caractères comparées.
 * \param droite : char* : La seconde chaine de caractères comparées.
 * \return un nombre négatif si Gauche arrive avant Droite dans le dictionnaire.
 * \return un nombre positif si Droite arrive avant Gauche dans le dictionnaire.
 * \return 0 si <gauche> et <droite> représente la même chaine de caractères.
 */
int compare_chaine(char* gauche, char* droite){
    int left_string = longueur_chaine(gauche);
    int iter;
    for(iter = 0; iter < left_string; iter++){
        if (gauche[iter] < droite[iter]){
            return -1;
        }
        if (gauche[iter] > droite[iter]){
            return 1;
        }
    }
    return -droite[iter];
}

#define LARGEUR_ECRAN 80

/**
 * \brief Affiche <message> aligné à gauche et <complement> aligné à droite.
 * \param message : char* : La chaine alignée à gauche.
 * \param complement : char* : La chaine alignée à droite.
 */
void afficher_message(char* message, char* complement){
    int n = LARGEUR_ECRAN - longueur_chaine(message) - longueur_chaine(complement);
    printf("%s", message);
    afficher_n_espaces(n);
    printf("%s\n", complement);
}

/**
 * \brief Affiche un message indiquant un succès (message à gauche suivit de [ OK ] à droite).
 */
void afficher_passe(char* message){
    afficher_message(message, "[ OK ]");
}

/**
 * \brief Affiche un message indiquant un échec (message à gauche suivit de [FAIL] à droite).
 */
void afficher_echoue(char* message){
    afficher_message(message, "[FAIL]");
}

