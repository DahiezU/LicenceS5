element_test.exe : element_test.o p_element_string.o ../utilitaires/p_utilitaires.o
	gcc -o element_test.exe element_test.o p_element_string.o ../utilitaires/p_utilitaires.o

../utilitaires/p_utilitaires.o: ../utilitaires/p_utilitaires.c
	cd ../utilitaires/
	gcc -c p_utilitaires.c
	cd ../element_string

element_test.o: element_test.c p_element_string.h
	gcc -c element_test.c

p_element_string.o: p_element_string.c p_element_string.h
	gcc -c p_element_string.c

clean :
	rm *.o
	rm *.exe