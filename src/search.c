/**
 @file search.c
 @brief Ecris dans un fichier les mots trouvés dans la grille présent dans le dico
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./../include/foncSearch.h"
#define N 4 /**< Taille de la matrice */
#define M 8

/*
 * ON considère pour chercheDico :
 * rien = pas un début de mot ni un mot complet
 * mot = un mot mais pas de début d'un autre mot
 * deb = début d'un mot mais pas de mot complet
 * mdeb = mot complet + début d'un mot
*/


/**
 * Réinitialise le tableau pour la recherche de mot pour pouvoir réutiliser le même tableau pour tout les mots trouvés
 * @param tab Mot trouvé 
 */
void init_tab(char tab[M]) {
    int i;
    for(i=0;i<N+1;i++)
        tab[i]='\0';
}

/**
 * Concatène le mot avec un espace puis le nombre de points
 * @param T Mot
 * @param k [description]
 */
void concat(char T[M], int k) {
    char a[2];
    int nbpts;
    T[k+1]=' ';
    nbpts=compte_points(T);
    sprintf(a, "%d", nbpts);
    strcat(T, a);
    ecrireFichier(T);
}

/**
 * Recherche de mot verticalement et horizontalement
 * @param Matrice Matrice de caractère générée
 */
void chercheMatrice(char Matrice[N][N]) {
    int rien=0;
    //int deb=1;
    int mot=2;
    int mdeb=3;
    char T[M];
    int i, j, k;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            /* Recherche de mot à la verticale vers le bas */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N;k++) {
                T[k]=Matrice[i+k][j];
                if(i+k<N && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }

            /* Recherche de mot à la verticale vers le haut */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T)!= mot && i-k>0;k++){
                T[k]=Matrice[i-k][j];
                if(i-k>0 && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }

            /* Recherche de mot à l'horizontale vers la droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && j+k<N;k++) {
                T[k]=Matrice[i][j+k];
                if(j+k<N && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }

            /* Recherche de mot à l'horizontale vers la gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T)!= mot && j-k>0;k++){
                T[k]=Matrice[i][j-k];
                if(j-k>0 && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }

            /* Recherche de mot à la diagonale vers le bas à droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N && j+k<N;k++) {
                T[k]=Matrice[i+k][j+k];
                if((i+k<N || j+k<N) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }
            /* Recherche de mot à la diagonale vers le haut à gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i-k>0 && j-k>0;k++) {
                T[k]=Matrice[i-k][j-k];
                if((i-k>0 || j-k>0) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }
            /* Recherche de mot à la diagonale vers le haut à droite */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i-k>0 && j+k<N;k++) {
                T[k]=Matrice[i-k][j+k];
                if((i-k>0 || j+k<N) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }
            /* Recherche de mot à la diagonale vers le bas à gauche */
            init_tab(T);
            T[0]=Matrice[i][j];
            for(k=1;chercheDico(T)!= rien && chercheDico(T) != mot && i+k<N && j-k>0;k++) {
                T[k]=Matrice[i+k][j-k];
                if((i+k<N || j-k>0) && (chercheDico(T)==mot || chercheDico(T)==mdeb))
                    concat(T, k);
            }
        }
    }
}
