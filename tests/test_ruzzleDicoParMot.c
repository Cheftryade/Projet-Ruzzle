#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ()
{
	//essai de la fonction int dico
	// D�claration des variables

	char motTest[50] ="abri";
	int retour = 4;

	// Corps de la fonction
	printf("\nvaleur de depart : retour = %i , mot test = %s \n", retour, motTest);
	retour = dico(motTest) ;
	printf("\nvaleur apres appel fonction : retour = %i , mot test = %s \n", retour, motTest);
	if (retour == 0) {
		printf("\n la fonction retourne 0, ");
		printf("elle ne trouve pas de mot, ou d�but de mot avec le mot pass� en param�tre, dans le fichier texte dico\n");
	}
	if (retour==1) {
		printf("\n la fonction retourne 1, elle trouve un d�but de mot avec le mot pass� en param�tre dans le fichier texte dico \n");
	}
	if (retour ==2) {
		printf("\n la fonction retourne 2 trouve le mot pass� en param�tre dans le fichier texte dico mais pas d'autres mots possible \n");
	}
	if (retour==3) {
		printf("\n la fonction retourne 3, ");
		printf(" trouve le mot pass� en param�tre dans le fichier texte dico et qui est aussi le d�but d'autres mots \n");
	}
	if (retour > 3) {
		printf("\n cas d'erreur pour la fonction \n");
	}

	return 0;
}
