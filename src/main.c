/**
 @file main.c
 @brief Programme principal
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */
#include <stdlib.h>
#include <stdio.h>
#include "./../include/fonctions.h"
#define N 4 /**< Taille de la matrice */

int main() {
    char Mat[N][N];
    creaMatrice(Mat);
    chercheMatrice(Mat);
    return 0;
}
