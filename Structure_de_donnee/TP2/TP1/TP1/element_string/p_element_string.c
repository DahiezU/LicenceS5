#include <stdio.h>
#include "../utilitaires/p_utilitaires.h"
typedef char* t_element;

void afficher_element(t_element ceci) {
    printf("%s" , ceci);
}

int est_inferieur_a(t_element ceci, t_element cela) {
    return compare_chaine(ceci,cela) < 0;
}
int est_egal_a(t_element ceci, t_element cela) {
    return compare_chaine(ceci, cela) == 0;
}
void echanger(t_element* ceci, t_element* cela) {
    t_element* poub = ceci;
    ceci = cela;
    cela = poub;
}
