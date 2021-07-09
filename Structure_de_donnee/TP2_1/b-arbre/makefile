test_b_arbre.exe : test_b_arbre.o p_b_arbre.o p_tableau_trie.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o
	gcc -o test_b_arbre.exe test_b_arbre.o p_b_arbre.o p_tableau_trie.o ../utilitaires/p_utilitaires.o ../element_string/p_element_string.o

test_b_arbre.o: test_b_arbre.c
	gcc -c test_b_arbre.c

p_b_arbre.o: p_b_arbre.c p_b_arbre.h
	gcc -c p_b_arbre.c

p_tableau_trie.o: p_tableau_trie.c p_tableau_trie.h
	gcc -c p_tableau_trie.c

../utilitaires/p_utilitaires.o: ../utilitaires/p_utilitaires.c ../utilitaires/p_utilitaires.h
	cd ../utilitaires && gcc -c p_utilitaires.c && ../p_b_arbre

../element_string/p_element_string.o: ../element_string/p_element_string.c ../element_string/p_element_string.h
	cd ../element_string/ && gcc -c p_element_string.h && ../p_b_arbre
