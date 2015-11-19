PROG = ruzzle
OBJ = ./fonctions/matrice.o ./fonctions/ruzzleDicoParMot.o ./fonctions/ruzzleEcrireFichier.o ./fonctions/search.o main.o
CC = gcc
CFLAGS = -g -Wall

${PROG} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${PROG} -lm

ruzzleDicoParMot.o : ruzzleDicoParMot.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleDicoParMot.c

ruzzleEcrireFichier.o : ruzzleEcrireFichier.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleEcrireFichier.c

search.o : search.c foncSearch.h
	${CC} ${CFLAGS} -c ./fonctions/search.c ./header/foncSearch.h

main.o : main.c fonctions.h
	${CC} ${CFLAGS} main.c ./header/fonctions.h

#suppression des fichiers temporaires
clean :
	rm -i *.o
	./fonctions/rm -i *.o

mrproper : clean
	rm -i prog