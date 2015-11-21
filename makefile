PROG = ./bin/ruzzleSolver
OBJ = ./fonctions/matrice.o ./fonctions/ruzzleDicoParMot.o ./fonctions/ruzzleEcrireFichier.o ./fonctions/search.o ./fonctions/points.o main.o
CC = gcc
CFLAGS = -g -Wall

${PROG} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${PROG}

matrice.o : ./fonctions/matrice.c
	${CC} ${CFLAGS} -c ./fonctions/matice.c
	
ruzzleDicoParMot.o : ./fonctions/ruzzleDicoParMot.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleDicoParMot.c

ruzzleEcrireFichier.o : ./fonctions/ruzzleEcrireFichier.c
	${CC} ${CFLAGS} -c ./fonctions/ruzzleEcrireFichier.c

points.o : ./fonctions/points.c
	${CC} ${CFLAGS} -c ./fonctions/points.c
	
search.o : ./fonctions/search.c ./header/foncSearch.h
	${CC} ${CFLAGS} -c ./fonctions/search.c ./header/foncSearch.h

main.o : main.c ./header/fonctions.h
	${CC} ${CFLAGS} -c main.c ./header/fonctions.h

#suppression des fichiers temporaires
clean :
	rm -i *.o
	rm -i ./fonctions/*.o
	rm -i ./header/*.gch
	
cleanforce :
	rm *.o
	rm ./fonctions/*.o
	rm ./header/*.gch

mrproper : clean
	rm -i Resultat.txt
	rm -i ./bin/ruzzleSolver
	rm -i ./bin/ruzzleSolver.exe
	
mrproperforce : cleanforce
	rm Resultat.txt
	rm ./bin/ruzzleSolver
	rm ./bin/ruzzleSolver.exe
