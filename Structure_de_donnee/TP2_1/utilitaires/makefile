utilitaires_test.exe: utilitaires_test.o p_utilitaires.o
	gcc -o utilitaires_test.exe utilitaires_test.o p_utilitaires.o

utilitaires_test.o: utilitaires_test.c
	gcc -c utilitaires_test.c

p_utilitaires.o: p_utilitaires.c p_utilitaires.h
	gcc -c p_utilitaires.c

clean:
	rm -f *.o
	rm -f *.exe
