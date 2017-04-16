#include "test.h"

#define FILE_TAILLE 10

/** Espace de mémoire pour stoquer la file. */
static char file[FILE_TAILLE];

/** Pointeur d'entrée de la file. */
static unsigned char fileEntree = 0;

/** Pointeur de sortie de la file. */
static unsigned char fileSortie = 0;

/** Indique si la file est vide. */
static char fileVide = 255;  // La file est initialement vide.

/** Indique si la file est pleine. */
static char filePleine = 0;  // La file est initialement vide.

/**
 * Si il y a de la place dans la file, enfile un caractère.
 * @param c Le caractère.
 */

/**
 * Indique si la file est vide.
 */
char fileEstVide() {
    // Si la pointeur de sortie est égal u pointeur d'entrée et que le pointeur plein vaut 0, on renvoir 255 sinon 0
    return ((fileSortie==fileEntree) && filePleine == 0) ? 255 : 0 ; 
}
/**
 * Indique si la file est pleine.
 */
char fileEstPleine() {
         
   return (filePleine == 255) ? 255 : 0; // Si le pointeur filePleine vaut 255 on renvoie 255 sinon 0
        
}

void fileEnfile(char c) {
    
    if (!fileEstPleine()){ // test pour savoir s'il y a de la place
        file[fileEntree]=c;// attribution du caractère à l'adresse pointeur
        filePleine = (fileEntree == FILE_TAILLE-1) ? 255 : 0; //Si le pointeur entrée est égal à la taille-1 (on commence les adresses à 0), plein vaut 255 sinon 0
        fileEntree=((fileEntree+1)%FILE_TAILLE); // On incrémente le pointeur d'entrée
    }
}

/**
 * Si la file n'est pas vide, défile un caractère.
 * @return Le caractère défilé, ou 0 si la file est vide.
 */
char fileDefile() {
    char data;
    if (!fileEstVide()){            //On vérifie que la file n'est pas vide
        data=file[fileSortie];      //On renvoie la valeur stockée à l'adresse du pointeur
                fileSortie=((fileSortie+1)%FILE_TAILLE);       //On incrémente le pointeur de sortie
                if (filePleine == 255) { // Si la file est pleine ...
            filePleine = 0;                //... elle ne l'est plus
        }
                return data;       
    }else{
        return 0;
    }
}  



/**
 * Vide et réinitialise la file.
 */
void fileReinitialise() {
    
    fileEntree = 0; //On remet les pointeurs à 0: résultat la file est vide
    fileSortie = 0; //On remet les pointeurs à 0: résultat la file est vide
    filePleine = 0; //On remet les pointeurs à 0: résultat la file est vide
}

#ifdef TEST
void testEnfileEtDefile() {
    fileReinitialise();
    
    testeEgaliteEntiers("FIL01", fileEstVide(), 255);    
    testeEgaliteEntiers("FIL02", fileDefile(), 0);
    testeEgaliteEntiers("FIL03", fileDefile(), 0);

    fileEnfile(10);
    fileEnfile(20);

    testeEgaliteEntiers("FIL04", fileEstVide(), 0);
    testeEgaliteEntiers("FIL05", fileDefile(), 10);
    testeEgaliteEntiers("FIL06", fileDefile(), 20);
    testeEgaliteEntiers("FIL07", fileEstVide(), 255);
    testeEgaliteEntiers("FIL08", fileDefile(), 0);
}

void testEnfileEtDefileBeaucoupDeCaracteres() {
    int n = 0;
    char c = 0;
    
    fileReinitialise();

    for (n = 0; n < FILE_TAILLE * 4; n++) {
        fileEnfile(c);
        if (testeEgaliteEntiers("FBC001", fileDefile(), c)) {
            return;
        }
        c++;
    }
}

void testDebordePuisRecupereLesCaracteres() {
    fileReinitialise();

    char c = 1;
    while(!fileEstPleine()) {
        fileEnfile(c++);
    }

    testeEgaliteEntiers("FDB001", fileDefile(), 1);
    testeEgaliteEntiers("FDB002", fileDefile(), 2);
    
    while(!fileEstVide()) {
        c = fileDefile();
    }
    fileEnfile(1);      // Ces caractères sont ignorés...
    fileEnfile(1);      // ... car la file est pleine.

    testeEgaliteEntiers("FDB003", c, FILE_TAILLE);
}

int testFile() {
    testEnfileEtDefile();
    testEnfileEtDefileBeaucoupDeCaracteres();
    testDebordePuisRecupereLesCaracteres();
}
#endif
