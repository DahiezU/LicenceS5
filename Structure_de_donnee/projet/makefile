test_table.exe : test_table.o p_table_des_matieres.o 
	gcc -o test_table.exe test_table.o p_table_des_matieres.o 


test_table.o : test_table.c
	gcc -c test_table.c

p_table_des_matieres.o : p_table_des_matieres.c p_table_des_matieres.h
	gcc -c p_table_des_matieres.c