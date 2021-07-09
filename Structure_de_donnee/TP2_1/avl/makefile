test_avl.exe : main.o p_avl.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o
	gcc -o test_avl.exe main.o p_avl.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o

main.o : main.c
	gcc -c main.c

p_avl.o : p_avl.c p_avl.h
	gcc -c p_avl.c

../utilitaires/p_utilitaires.o : ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h 
	cd ../utilitaires && gcc -c p_utilitaires.c && cd ../p_arbre_binaire_ordonne

../element_string/p_element_string.o : ../element_string/p_element_string.c ../element_string/p_element_string.h
	cd ../element_string && gcc -c ../element_string/p_element_string.c && cd ../p_arbre_binaire_ordonne
