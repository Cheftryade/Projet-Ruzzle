#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void afficherMatrice(char * mat[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int rand_a_b(int min,int max){
    return rand()%(max-min)+min;
}

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




void creaMatrice(char * Mat[N][N]){
    // char mat[N][N];
    char Random;
    int i,j, nbAleatoire, nb;
    //char voyelle[6] = "AEIOUY";
    int indice;
    srand (time (NULL)); // Obligatoire
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            nbAleatoire = rand_a_b(0,1533628);
            Mat[i][j] = getLettreRandom(nbAleatoire);
        }
    }
    afficherMatrice(Mat);
}
