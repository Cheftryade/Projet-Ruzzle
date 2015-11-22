/**
 @file matrice.c
 @brief Créer et affiche la matrice de caractères
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4 /**< Taille de la matrice */


/**
 * Permet l'affichage de la matrice dans le terminal
 * @param Mat Matrice générée
 */
void afficherMatrice(char Mat[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%c", Mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Renvoie un nombre aléatoire borné entre les deux paramètres de la fonction
 * @param  min Borne minimale
 * @param  max Borne maximale
 * @return     Retourne un nombre aléatoire compris entre min et max
 */
int rand_a_b(int min,int max){
    return rand()%(max-min)+min;
}


/**
 * Fonction permettant d'obtenir une lettre aléatoire, selon sa fréquence d'apparition dans la langue française
 * @param  nombreAleatoire Nombre préalablement généré grace à la fonction rand_a_b
 * @return                 Retourne une lettre tiré aléatoirement
 */
char getLettreRandom(int nombreAleatoire)
{
    int occurrences[] = {225947, 121895, 117110,115465,111103,108812,100500,96785,83668,
        82762,56269,50003,46335,45521,24975,20889,16351,13822,11298,
        8351,5928,4725,2093,745};
    char lettres[] = "esaitnrulodcpmvqfbghjxyzwk";
    int i, total;

    char retour = ' '; /* Valeur par défaut au cas où */
    for (i=0, total = 0; i < 36; i++)
     {
        if ( (nombreAleatoire > total) && (nombreAleatoire < total + occurrences[i]))
         {
            retour = lettres[i];
            break;
         }
        total += occurrences[i];
     }
    return retour;
}



/**
 * Permet de remplir la matrice de caractères générés aléatoirement
 * @param Mat Matrice de caractères comprenant les caractères générés ci-dessus
 */
void creaMatrice(char Mat[N][N]){
    int i,j, nbAleatoire;
    srand (time (NULL)); // Obligatoire
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            nbAleatoire = rand_a_b(0,1533628);
            Mat[i][j] = getLettreRandom(nbAleatoire);
        }
    }
    afficherMatrice(Mat);
}
