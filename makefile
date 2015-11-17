PROG = prog
OBJ = ./fonctions/matrice.o ./fonctions/ruzzleDicoParMot.o ./fonctions/ruzzleEcrireFichier.o ./fonctions/search.o main.o
CC = gcc
CFLAGS = -g -Wall

prog : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o prog

ruzzleDicoParMot.o : ruzzleDicoParMot.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleDicoParMot.c

ruzzleEcrireFichier.o : ruzzleEcrireFichier.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleEcrireFichier.c

search.o : search.c
	${CC} ${CFLAGS} -c ./fonctions/search.c

main.o : main.c fonctions.h
	${CC} ${CFLAGS} main.c ./header/fonctions.h

#suppression des fichiers temporaires
clean :
	rm -i *.o

mrproper : clean
	rm -i prog