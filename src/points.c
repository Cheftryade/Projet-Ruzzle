/**
 @file points.c
 @brief Compte les points d'un mot
 @author Biardeau Tristan Bussereau Keryann Tabot Alexandre
 @version v1.00
 @date 14/11/2015
 */


/**
 * Permet de donner un nombre de points pour un mot passé en paramètre
 * @param  mot Mot antérieurement trouvé
 * @return Retourne le nombre de points du mot
 */
int compte_points(char mot[]){
	int i = 0;
	int points = 0;
	for(i = 0 ; mot[i] != '\0' ; i++){
		switch(mot[i]){
			case 'a' : points += 1; break;
			case 'b' : points += 3; break;
			case 'c' : points += 2; break;
			case 'd' : points += 2; break;
			case 'e' : points += 1; break;
			case 'f' : points += 3; break;
			case 'g' : points += 3; break;
			case 'h' : points += 3; break;
			case 'i' : points += 1; break;
			case 'j' : points += 10; break;
			case 'k' : points += 12; break;
			case 'l' : points += 2; break;
			case 'm' : points += 2; break;
			case 'n' : points += 1; break;
			case 'o' : points += 2; break;
			case 'p' : points += 2; break;
			case 'q' : points += 6; break;
			case 'r' : points += 1; break;
			case 's' : points += 1; break;
			case 't' : points += 1; break;
			case 'u' : points += 2; break;
			case 'v' : points += 4; break;
			case 'w' : points += 15; break;
			case 'x' : points += 10; break;
			case 'y' : points += 10; break;
			case 'z' : points += 4; break;
		}

	}
	return points;
}
