/**
 @file fonctions.h
 @brief Prototype fonction matrices
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */

#define N 4 /**< Taille de la matrice */

/**
 * Permet de remplir la matrice de caractères générés aléatoirement
 * @param Mat Matrice de caractères comprenant les caractères générés ci-dessus
 */
void creaMatrice(char Mat[N][N]);

/**
 * Recherche de mot verticalement et horizontalement
 * @param Matrice Matrice de caractère générée
 */
void chercheMatrice(char Mat[N][N]);
