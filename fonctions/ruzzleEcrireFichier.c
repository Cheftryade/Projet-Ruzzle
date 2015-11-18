// Alexandre TABOT L2 SPI Universit� du Mans 2015-2016
// Date :
// Compilation : exemple :alexandre@alexandre-tabot7:~/Documents/pbc$ gcc affiche var ex001.c -o afficheEx001 -wall
// Execution :
//
// Inclusion des biblioth�ques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ecrireFichier(char mot[], int N)
{
	// Renvoie : la fonction �crit le mot pass� en param�tre dans le fichier dont le nom est pass� en parametre
	// D�claration des variables
	int i = 0;
	FILE * pointeur_fichier;

	// corps de la proc�dure
	/* ouverture du fichier : */

	pointeur_fichier =fopen("./../Resultat.txt", "a+");

	if (pointeur_fichier ==NULL)	/* gestion d'erreur */

	{

		printf("erreur d'ouverture de fichier : \n ");

		printf("Fichier inexistant ou permissions insuffisantes. \n");

		exit(1);	/*termine le programme avec code d'erreur */

	}

	// on peut mettre des appels de fonctions comme fscanf dans une condition. Ici, fscanf retourne 1 en cas de
 	//succ�s

	for (i=0; i < strlen(mot); i++) {			/*strlen calcule longueur de mot et a besoin de l'inclusion de string.h */
		fprintf(pointeur_fichier, "%c", mot[i]);


	}
	// �criture de l'�lement de s�paration entre les mots du fichier

	fprintf(pointeur_fichier, "\n");

	fclose(pointeur_fichier);	/*fermeture du fichier */

	return i;	/* on retourne le nombre d'�l�ments �crit */

}

