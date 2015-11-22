/**
 @file foncSearch.h
 @brief Prototype fonction reserche
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */


/**
 * Cherche dans le dico un mot
 * @param  mot Mot préalablement trouvé dans la grille
 * @return     1 si mot trouvé, 0 sinon
 */
int chercheDico(char mot[]);

 /**
  * Ecris dans le fichier Resultat.txt le mot passé en paramètre
  * @param  mot Mot trouvé dans la grille et présent dans le dico
  * @return     Retourne le nombre d'éléments écrit
  */
void ecrireFichier(char mot[]);

/**
 * Permet de donner un nombre de points pour un mot passé en paramètre
 * @param  mot_trouve Mot antérieurement trouvé
 * @return            Retourne le nombre de points du mot
 */
int compte_points(char mot[]);
