PROG = ./bin/ruzzleSolver
OBJ = ./src/matrice.o ./src/ruzzleDicoParMot.o ./src/ruzzleEcrireFichier.o ./src/search.o ./src/points.o ./src/main.o
CC = gcc
CFLAGS = -g -Wall

${PROG} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${PROG}

matrice.o : ./src/matrice.c
	${CC} ${CFLAGS} -c ./src/matice.c
	
ruzzleDicoParMot.o : ./src/ruzzleDicoParMot.c
	${CC} ${CFLAGS} -c ./src/ruzzleDicoParMot.c

ruzzleEcrireFichier.o : ./src/ruzzleEcrireFichier.c
	${CC} ${CFLAGS} -c ./src/ruzzleEcrireFichier.c

points.o : ./src/points.c
	${CC} ${CFLAGS} -c ./src/points.c
	
search.o : ./src/search.c ./include/foncSearch.h
	${CC} ${CFLAGS} -c ./src/search.c ./include/foncSearch.h

main.o : ./src/main.c ./include/fonctions.h
	${CC} ${CFLAGS} -c ./src/main.c ./include/fonctions.h

#suppression des fichiers temporaires
clean :
	rm -i ./src/*.o
	
cleanforce :
	rm ./src/*.o

mrproper : clean
	rm -i ./lib/Resultat.txt
	rm -i ./bin/ruzzleSolver
	
mrproperforce : cleanforce
	rm ./lib/Resultat.txt
	rm ./bin/ruzzleSolver
