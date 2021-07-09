test_arbre.exe : test_arbre.o p_arbre_binaire.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o
	gcc -o test_arbre.exe test_arbre.o p_arbre_binaire.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o

test_arbre.o : test_arbre.c
	gcc -c test_arbre.c

p_arbre_binaire.o : p_arbre_binaire.h p_arbre_binaire.c
	gcc -c p_arbre_binaire.c

../noeud/p_noeud.o : ../noeud/p_noeud.h ../noeud/p_noeud.c
	cd ../noeud && gcc -c p_noeud.c && cd ../arbre_binaire

../utilitaires/p_utilitaires.o : ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h 
	cd ../utilitaires && gcc -c p_utilitaires.c && cd ../arbre_binaire

../element_string/p_element_string.o : ../element_string/p_element_string.c ../element_string/p_element_string.h
	cd ../element_string && gcc -c ../element_string/p_element_string.c && cd ../arbre_binaire
