test_arbre.exe : test_arbre.o p_arbre_binaire.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o
	gcc -o test_noeud.exe test_noeud.o p_arbre_binaire.o ../noeud/p_noeud.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o

test_noeud.o : test_noeud.c
	gcc -c test_noeud.c

p_arbre_binaire.o : p_arbre_binaire.h p_arbre_binaire.c
	gcc -c p_arbre_binaire.c

../noeud/p_noeud.o : ../noeud/p_noeud.h ../noeud/p_noeud.c
	cd ../noeud && gcc -c p_noeud.c && cd ../noeud

../utilitaires/p_utilitaires.o : ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h 
	cd ../utilitaires && gcc -c p_utilitaires.c && cd ../noeud

../element_string/p_element_string.o : ../element_string/p_element_string.c ../element_string/p_element_string.h
	cd ../element_string && gcc -c ../element_string/p_element_string.c && cd ../noeud
