/**
 @file ruzzleEcrireFichier.c
 @brief Ecris dans un fichier les mots trouvés dans la grille présent dans le dico
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */ 

// Inclusion des bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 /**
  * Ecris dans le fichier Resultat.txt le mot passé en paramètre
  * @param  mot Mot trouvé dans la grille et présent dans le dico
  * @return     Retourne le nombre d'éléments écrit
  */
int ecrireFichier(char mot[])
{
	// Renvoie : la fonction écrit le mot passé en paramètre dans le fichier Resultat.txt
	// Déclaration des variables
	int i = 0;
	FILE * pointeur_fichier;

	// corps de la procédure
	/* ouverture du fichier : */

	pointeur_fichier =fopen("./lib/Resultat.txt", "a+");

	if (pointeur_fichier ==NULL)	/* gestion d'erreur */

	{

		printf("erreur d'ouverture de fichier : \n ");

		printf("Fichier inexistant ou permissions insuffisantes. \n");

		exit(1);	/*termine le programme avec code d'erreur */

	}

	// on peut mettre des appels de fonctions comme fscanf dans une condition. Ici, fscanf retourne 1 en cas de
 	//succès

	for (i=0; i < strlen(mot); i++) {			/*strlen calcule longueur de mot et a besoin de l'inclusion de string.h */
		fprintf(pointeur_fichier, "%c", mot[i]);


	}
	// écriture de l'élement de séparation entre les mots du fichier

	fprintf(pointeur_fichier, "\n");

	fclose(pointeur_fichier);	/*fermeture du fichier */

	return i;	/* on retourne le nombre d'éléments écrit */

}

