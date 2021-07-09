test_arbre_ordonne.exe : main.o p_arbre_binaire_ordonne.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o
	gcc -o test_arbre_ordonne.exe main.o p_arbre_binaire_ordonne.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o ../arbre_binaire/p_arbre_binaire.o

main.o : main.c
	gcc -c main.c

p_arbre_binaire_ordonne.o : p_arbre_binaire_ordonne.h p_arbre_binaire_ordonne.c
	gcc -c p_arbre_binaire_ordonne.c

../arbre_binaire/p_arbre_binaire.o :  ../arbre_binaire/p_arbre_binaire.c ../arbre_binaire/p_arbre_binaire.h
	cd ../arbre_binaire && gcc -c p_arbre_binaire.c && cd ../p_arbre_binaire_ordonne

../noeud/p_noeud.o : ../noeud/p_noeud.h ../noeud/p_noeud.c
	cd ../noeud && gcc -c p_noeud.c && cd ../p_arbre_binaire_ordonne

../utilitaires/p_utilitaires.o : ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h 
	cd ../utilitaires && gcc -c p_utilitaires.c && cd ../p_arbre_binaire_ordonne

../element_string/p_element_string.o : ../element_string/p_element_string.c ../element_string/p_element_string.h
	cd ../element_string && gcc -c ../element_string/p_element_string.c && cd ../p_arbre_binaire_ordonne
