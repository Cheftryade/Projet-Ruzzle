int main ()
{
	//essai de la fonction int ecrireFichier(char mot[N], char nom_fichier[N])
	// Déclaration des variables
	const int N = 17;
	char nom_fichier[50]= "tecrireFichier.txt";
	//char mot[16] = "lire\0";


	// Corps de la fonction

	ecrireFichier("sucess", nom_fichier, N);

	return 0;
}
