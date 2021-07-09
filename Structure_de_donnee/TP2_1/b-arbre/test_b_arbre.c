#include <stdio.h>
#include "p_tableau_trie.h"
#include "p_b_arbre.h"

int mon_out;
t_tableau_trie mon_tableau;

void tester_insertion(t_element elt){
    mon_out = inserer_tableau_trie(&mon_tableau, elt);
    afficher_tableau_trie(&mon_tableau);
    printf("%d*\n\n", mon_out);
}

void tester_tableau(){
    initialiser_tableau_trie(&mon_tableau);
    afficher_tableau_trie(&mon_tableau);

    tester_insertion("d");
    tester_insertion("e");
    tester_insertion("a");
    tester_insertion("h");
    tester_insertion("c");
    tester_insertion("b");
    tester_insertion("f");
    tester_insertion("g");

    finaliser_tableau_trie(&mon_tableau);
}

void tester_noeud(){
    a_noeud mon_arbre = nouveau_noeud();
    a_noeud mon_frere;
    t_element mon_milieu;
    t_element ma_val;
    afficher_noeud(mon_arbre, 1);

    ajouter_noeud(mon_arbre, ma_val, &mon_frere, &mon_milieu, 5);
    printf("zz\n");
    afficher_tableau_trie(&(mon_arbre->les_cles));
    printf("zz\n");
    printf("za\n");
    afficher_noeud(mon_arbre, 1);
    printf("aa\n");

    finaliser_noeud(mon_arbre);
}
/*
void test_noeud_1(){
    a_noeud mon_arbre = nouveau_noeud();
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 5, (a_noeud)10);
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 15, (a_noeud)11);
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 7, (a_noeud)12);
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 1, (a_noeud)13);
    debugger_noeud(mon_arbre);

    inserer_valeur_non_plein(mon_arbre, 4, (a_noeud)14);
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 12, (a_noeud)15);
    debugger_noeud(mon_arbre);
    inserer_valeur_non_plein(mon_arbre, 24, (a_noeud)16);
    debugger_noeud(mon_arbre);

    t_element mon_elt_out;
    a_noeud mon_fils_droit_out;
    //inserer_valeur_plein(mon_arbre, 3, 20, &mon_elt_out, &mon_fils_droit_out);
    //inserer_valeur_plein(mon_arbre, 0, 20, &mon_elt_out, &mon_fils_droit_out);
    //inserer_valeur_plein(mon_arbre, 6, 20, &mon_elt_out, &mon_fils_droit_out);
    inserer_valeur_plein(mon_arbre, 8, (a_noeud)20, &mon_elt_out, &mon_fils_droit_out);
    printf("out : [%d] {%d}\n", mon_elt_out, (int)mon_fils_droit_out);
    debugger_noeud(mon_arbre);
    debugger_noeud(mon_fils_droit_out);


    finaliser_noeud(mon_arbre);
}

void test_noeud_2(){
    a_noeud mon_arbre = null;
    ajouter_racine(&mon_arbre, 5);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 1);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 7);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 10);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, -1);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 1);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 6);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 8);
    debugger_noeud(mon_arbre);

        debugger_noeud(mon_arbre->les_fils[0]);
        debugger_noeud(mon_arbre->les_fils[1]);

    finaliser_noeud(mon_arbre);
}

void test_noeud_3(){
    a_noeud mon_arbre = null;
    mon_arbre = creer_racine(5);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 8);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, -1);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 13);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 9);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 18);
    debugger_noeud(mon_arbre);

    ajouter_racine(&mon_arbre, 7);
    debugger_noeud(mon_arbre);

    a_noeud mon_arbre_2 = creer_racine(29);
    debugger_noeud(mon_arbre_2);

//    ajouter_racine(&mon_arbre, 29);
//    debugger_noeud(mon_arbre);

//    ajouter_racine(&mon_arbre, 6);
//    debugger_noeud(mon_arbre);

//        debugger_noeud(mon_arbre->les_fils[0]);
//        debugger_noeud(mon_arbre->les_fils[1]);

    finaliser_noeud(mon_arbre);
}

*/

int main(){
    tester_tableau();
    //test_noeud_1();
    //test_noeud_2();
    //tester_noeud();
    //test_noeud_3();
    return 0;
}
