// Alexandre TABOT L2 SPI Université du Mans 2015-2016
// Date : 15 nov 2015
// inclusion des bibliothèques
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Déclaration des fonction

void lecture_fin_ligne_fichier(FILE * pointeur_fichier)
{
	//Renvoie : place le pointeur à la fin de la ligne courante du fichier.

	// déclaration des variables
	char caractere_courant_lu = 'a';

	// corps de la fonction
	while ((caractere_courant_lu !='\n') && (!feof(pointeur_fichier))) {
		// déplacement pointeur de fichier par lecture jusqu a saut de ligne ou fin de fichier
		fscanf (pointeur_fichier, "%c", &caractere_courant_lu);

	}
}

int dico(char mot[])
{
	//Renvoie : La fonction renvoie
	//				0 si la fonction ne trouve pas de début de mot avec le mot passé en paramètre, dans le fichier texte dico
	//				1 si la fonction trouve un début de mot avec le mot passé en paramètre dans le fichier texte dico
	//				2 si la fonction trouve le mot passé en paramètre dans le fichier texte dico mais pas d'autres mots possibles
	//				3 si la fonction trouve le mot passé en paramètre dans le fichier texte dico et qui est aussi le début
	//				d'autres mots possibles du dico.
	//				5 si la fonction se trouve en cas d'erreur.
	// La longueur maximale du mot passé en paramètres est de 4 caracteres.
	//
 	//Le nom du fichier dico est en dur dans la fonction . son nom et chemin d'accès sont : "./ressources/dico-ref-ascii-sans-accent.txt"
	// Cas d'erreur : Si un mot du dico depasse la taille du tableau tampon mot_lu_dico[]


	// Déclaration et initialisation des variables
	int i = 0;
	int longueur_mot_max =3; 	/*longueur maximale des mots possibles - 1 */
	int retour = 5;
	FILE * pointeur_fichier;

	char mot_lu[50]="a";
	char cara_ap_fin_mot ='a';
	int taille_tab_mot = strlen(mot) - 1;

	// corps de la procédure
	/* ouverture du fichier : */

	pointeur_fichier =fopen("./dico-ref-ascii-sans-accent.txt", "r");

	if (pointeur_fichier==NULL)	/* gestion d'erreur */

	{

		printf("erreur d'ouverture de fichier : \n ");

		printf("Fichier inexistant ou permissions insuffisantes. \n");

		exit(1);	/*termine le programme avec code d'erreur */

	}

	//
 	//
	i = 0;
	while ((!feof(pointeur_fichier)) && (retour > 3) ) {			/*feof : atteinte de la fin du fichier*/
		// entree dans la boucle maitresse
		// boucle comparaison mot de 4 caractère, caractere par caractere avec condition de sortie : fin de fichier ou valeur de retour
		// attendue
		fscanf(pointeur_fichier, "%c", &mot_lu[i]);
		// lecture du caractère courant pointé
		// choix en fonction du caractère lu

		if (mot[i]<mot_lu[i]) {
			printf("\nligne 78");

			// lettre lu dans dico supérieure en alphabet à lettre de mot . Exemple e> d donc si on a lu "la" puis "le" dans le dico
			// on sait que "ld" n'est pas dans le dico.
			//printf("\npremier retour 1955 le compteur est : %i, la taille du mot cherché est : %i", i, strlen(mot));
			retour = 0;
		}
		else if (mot[i]==mot_lu[i]) {
			if (taille_tab_mot == i) {
				printf("\nligne 87");
				// choix quand on se trouve sur le dernier caratere du mot a trouvé passé en parametre.

				// lecture du caratere venant apres dans le dico
				fscanf(pointeur_fichier, "%c", &cara_ap_fin_mot);
					if(cara_ap_fin_mot !='\n') {
						// choix si caractere suivant fin du mot est une lettre dans dico
						if( i<longueur_mot_max) {
							// cas reste des lettre suplémentaire possible donc mot est un début de mot du dico
							retour = 1;
						}
						if ( i == longueur_mot_max) {
							// cas pas de possibilité de lettre suplémentaire et mot pas entier, mot absent du dico
							// second cas de retour valeur 0
							retour = 0;
						}
					else	{
						// choix si caractere suivant fin du mot fin de ligne dans dico
						if( i<longueur_mot_max) {
							// cas reste des lettre suplémentaire possible donc mot est un début de mot du dico
							retour = 3;
						}
						if ( i == longueur_mot_max) {
							// cas pas de possibilité de lettre suplémentaire et mot pas entier, mot absent du dico
							// second cas de retour valeur 0
							retour = 2;
						}						

	
					}
					if (taille_tab_mot > i) {
						// lecture quand i n'a pas atteint taille mot entier
						// choix quand on se trouve sur un caratere non-dernier du mot a trouvé passé en parametre
						i++;
					}
				}
				else if (mot[i]>mot_lu[i]) {
					printf("\n ligne 107 : lettre < lettre lu");
					// lettre lu inférieur en alphabet à lettre de mot donc on passe à la ligne suivante du dico
					// appel fonction lecture_fin_ligne_fichier(FILE *fichier_pointeur)
					lecture_fin_ligne_fichier(pointeur_fichier);
					// effacement de mot_lu

					// mise compteur tableau a 0 en debut de mot.
					i = 0;
				}
				else {		// cas des caractères de fin de ligne non déterminés
					printf("\nligne 117 : derniere caractere de mot comparé à fin de ligne");
					// cas mot entier lu dans dico puisque passage à la ligne
					// le compteur i peut etre varié pour cette position.
					// choix de valeur de retour de la fonction
			
					if (i<longueur_mot_max) {
						// cas mot identique avec possible mots supplémentaires avec plus de lettres
						retour = 3;
						printf("\n code ligne 117");
					}
					if  (i==longueur_mot_max) {
						// cas mot trouvé dans dico sans possibilites d'ajout de lettres
						retour = 2;
					}
				}

			} // fin lecture choix

		}
	}
	fclose(pointeur_fichier);	/*fermeture du fichier */
	return retour;
}

int main ()
{
	//essai de la fonction int ecrireFichier(char mot[N], char nom_fichier[N])
	// Déclaration des variables
	char motTest[50] ="abri";
	int retour = 4;

	// Corps de la fonction
	printf("\nvaleur de depart : retour = %i , mot test = %s \n", retour, motTest);
	retour = dico(motTest) ;
	printf("\nvaleur apres appel fonction : retour = %i , mot test = %s \n", retour, motTest);
	if (retour == 0) {
		printf("\n la fonction retourne 0, ");
		printf("elle ne trouve pas de mot, ou début de mot avec le mot passé en paramètre, dans le fichier texte dico\n");
	}
	if (retour==1) {
		printf("\n la fonction retourne 1, elle trouve un début de mot avec le mot passé en paramètre dans le fichier texte dico \n");
	}
	if (retour ==2) {
		printf("\n la fonction retourne 2 trouve le mot passé en paramètre dans le fichier texte dico mais pas d'autres mots possible \n");
	}
	if (retour==3) {
		printf("\n la fonction retourne 3, ");
		printf(" trouve le mot passé en paramètre dans le fichier texte dico et qui est aussi le début d'autres mots \n");
	}
	if (retour > 3) {
		printf("\n cas d'erreur pour la fonction \n");
	}

	return 0;
}
