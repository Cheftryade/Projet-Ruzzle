// Alexandre TABOT L2 SPI Université du Mans 2015-2016
// Date : 27 oct 2015
// inclusion des bibliothèques
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Déclaration des fonction

int dico(char mot[])
{
	//Renvoie : La fonction renvoie 1 si la fonction trouve le mot passé en paramètre dans le fichier texte dico dont le nom est
 	//en dur dans la fonction . son nom et chemin d'accès sont : "./ressources/dico-ref-ascii-sans-accent.txt"
	// Cas d'erreur : Si un mot du dico depasse la taille du tableau tampon mot_lu_dico[]


	// Déclaration et initialisation des variables
	int taille_mot = strlen(mot);
	FILE * pointeur_fichier;
	int retour = 1;
	char mot_lu[50];
	int longueur_mot_max =4;

	// corps de la procédure
	/* ouverture du fichier : */

	pointeur_fichier =fopen("./ressource/dico-ref-ascii-sans-accent.txt", "r");

	if (pointeur_fichier==NULL)	/* gestion d'erreur */

	{

		printf("erreur d'ouverture de fichier : \n ");

		printf("Fichier inexistant ou permissions insuffisantes. \n");

		exit(1);	/*termine le programme avec code d'erreur */

	}

	//
 	//

	while ((!feof(pointeur_fichier))&& (retour<2)) {			/*feof : atteinte de la fin du fichier*/
		fscanf(pointeur_fichier, "%s", mot_lu);

		if (strcmp(mot , mot_lu) ==0) {
			// trouve que mot est un mot entier du dico
			if( taille_mot<longueur_mot_max) {
				// cas reste des lettre suplémentaire possible donc mot est un mot présent et le début de mot du dico
				retour = 3;
			}
			if ( taille_mot == longueur_mot_max) {
				// cas pas de possibilité de lettre suplémentaire et mot entier, donc mot entier et unique du dico
				retour = 2;
			}
		}
 		else {
 			// trouve que mot n'est pas entier dans dico
 			if( taille_mot<longueur_mot_max) {
				// cas reste des lettre suplémentaire possible donc mot est le début de mot possible du dico
				retour = 1;
			}
			if ( taille_mot == longueur_mot_max) {
				// cas pas de possibilité de lettre suplémentaire et mot entier, donc mot absent du dico
				retour = 0;
			}
		}
	}


	fclose(pointeur_fichier);	/*fermeture du fichier */
	return retour;	/* on retourne 1 si mot trouvé , 0 sinon */

}


