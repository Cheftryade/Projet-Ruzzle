#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 4

/*
** ON considère pour chercheDico :
 * rien = pas un début de mot ni un mot complet
 * mot = un mot mais pas de début d'un autre mot
 * deb = début d'un mot mais pas de mot complet
 * mdeb = mot complet + début d'un mot
*/

char Matrice[N][N];

void init_tab(char tab[N+1]) {
    int i;
    for(i=0;i<N+1;i++)
        tab[i]='\0';
}

void chercheMatrice() {
    int rien=0;
    int mot=1;
    int deb=2;
    int mdeb=3;
    char T[N+1];
    int i, j, k;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            /* Recherche de mot à la verticale vers le bas */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N;k++) {
                strcat(T, Matrice[i+k][j]);
                if(i+k<N && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à la verticale vers le haut */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T)!= mot && i-k>0;k++){
                strcat(T, Matrice[i-k][j]);
                if(i-k>0 && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à l'horizontale vers la droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && j+k<N;k++) {
                strcat(T, Matrice[i][j+k]);
                if(j+k<N && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à l'horizontale vers la gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T)!= mot && j-k>0;k++){
                strcat(T, Matrice[i][j-k]);
                if(j-k>0 && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à la diagonale vers le bas à droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N && j+k<N;k++) {
                strcat(T, Matrice[i+k][j+k]);
                if((i+k<N || j+k<N) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à la diagonale vers le haut à gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i-k>0 && j-k>0;k++) {
                strcat(T, Matrice[i-k][j-k]);
                if((i-k>0 || j-k>0) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à la diagonale vers le haut à droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i-k>0 && j+k<N;k++) {
                strcat(T, Matrice[i-k][j+k]);
                if((i-k>0 || j+k<N) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
            /* Recherche de mot à la diagonale vers le bas à gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N && j-k>0;k++) {
                strcat(T, Matrice[i+k][j-k]);
                if((i+k<N || j-k>0) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    ecrireFichier(T);
            }
        }
    }
}
