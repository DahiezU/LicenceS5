test_noeud.exe : test_noeud.o p_noeud.o ../utilitaires/p_utilitaires.o
	gcc -o test_noeud.exe test_noeud.o p_noeud.o ../utilitaires/p_utilitaires.o

test_noeud.o : test_noeud.c
	gcc -c test_noeud.c

p_noeud.o : p_noeud.h p_noeud.c
	gcc -c p_noeud.c

../utilitaires/p_utilitaires.o : ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h 
	cd ../utilitaires
	gcc -c p_utilitaires.c
	cd ../noeud

