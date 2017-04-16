#include "file.h"
#include "test.h"
#include "morse.h"

#define MORSE_MAX_DUREE_POINT 10
#define MORSE_MIN_DUREE_PAUSE 30

/**
 * Caractère ASCII selon l'état actuel de la séquence morse.
 */
static unsigned char morseLettre = 0;
static unsigned char Lettre = 0;

/**
 * Liste les caractères morse.
 */
typedef enum {
    CARACTERE_LIGNE = '-',
    CARACTERE_POINT = '.',
    CARACTERE_PAUSE = ' '
} CaractereMorse;

/**
 * Rend le caractère ASCII correspondant à la séquence 
 * d'appels à morsePoint et morseLigne.
 * @return Le caractère ASCII. Un '?' si la séquence est inconnue.
 */
unsigned char morseDecodeSequence() {
// Remplace les caractères mémoire en '?' et retourne la valeur actuelle
switch (morseLettre) {
        case '_':
            morseLettre = '?';
            break;
        case '#':
            morseLettre = '?';
            break;
        case '%':
            morseLettre = '?';
            break;
        case '&':
            morseLettre = '?';
            break;
        default:
            
            break;
    }
    return morseLettre;

    
}

/**
 * Appelée si la pioche morse à marqué un point.
 */
void morsePoint() {
    // Implémentation du caractère en fonction de l'état précédent
    switch (morseLettre) {
        case 0:
            morseLettre = 'E';
            break;
        case 'A':
            morseLettre = 'R';
            break;
        case 'B':
            morseLettre = '6';
            break;
        case 'C':
            morseLettre = '?';
            break;
        case 'D':
            morseLettre = 'B';
            break;
        case 'E':
            morseLettre = 'I';
            break;
        case 'F':
            morseLettre = '?';
            break;
        case 'G':
            morseLettre = 'Z';
            break;
        case 'H':
            morseLettre = '5';
            break;
        case 'I':
            morseLettre = 'S';
            break;
        case 'J':
            morseLettre = '?';
            break;
        case 'K':
            morseLettre = 'C';
            break;
        case 'L':
            morseLettre = '?';
            break;
        case 'M':
            morseLettre = 'G';
            break;
        case 'N':
            morseLettre = 'D';
            break;
        case 'O':
            morseLettre = '%';
            break;
        case 'P':
            morseLettre = '?';
            break;
        case 'Q':
            morseLettre = '?';
            break;
        case 'R':
            morseLettre = 'L';
            break;
        case 'S':
            morseLettre = 'H';
            break;
        case 'T':
            morseLettre = 'N';
            break;
        case 'U':
            morseLettre = 'F';
            break;
        case 'V':
            morseLettre = '?';
            break;
        case 'W':
            morseLettre = 'P';
            break;
        case 'X':
            morseLettre = '/';
            break;
        case 'Y':
            morseLettre = '?';
            break;
        case 'Z':
            morseLettre = '7';
            break;
        case '*':
            morseLettre = '?';
            break;
        case '#':
            morseLettre = '+';
            break;
        case '%':
            morseLettre = '8';
            break;
        case '&':
            morseLettre = '9';
            break;
        case '0':
            morseLettre = '?';
            break;
        case '1':
            morseLettre = '?';
            break;
        case '2':
            morseLettre = '?';
            break;
        case '3':
            morseLettre = '?';
            break;
        case '4':
            morseLettre = '?';
            break;
        case '5':
            morseLettre = '?';
            break;
        case '6':
            morseLettre = '?';
            break;
        case '7':
            morseLettre = '?';
            break;
        case '8':
            morseLettre = '?';
            break;
        case '9':
            morseLettre = '?';
            break;
        case '+':
            morseLettre = '?';
            break;
        case '=':
            morseLettre = '?';
            break;
        case '/':
            morseLettre = '?';
            break;
        default: break;
    }
fileEnfile(CARACTERE_POINT);
}

/**
 * Appelée si la pioche morse a marqué une ligne.
 */
void morseLigne() {
    //  Implémentation du caractère en fonction de l'état précédent
    switch (morseLettre) {
        case 0:
            morseLettre = 'T';
            break;
        case 'A':
            morseLettre = 'W';
            break;
        case 'B':
            morseLettre = '=';
            break;
        case 'C':
            morseLettre = '?';
            break;
        case 'D':
            morseLettre = 'X';
            break;
        case 'E':
            morseLettre = 'A';
            break;
        case 'F':
            morseLettre = '?';
            break;
        case 'G':
            morseLettre = 'Q';
            break;
        case 'H':
            morseLettre = '4';
            break;
        case 'I':
            morseLettre = 'U';
            break;
        case 'J':
            morseLettre = '1';
            break;
        case 'K':
            morseLettre = 'Y';
            break;
        case 'L':
            morseLettre = '?';
            break;
        case 'M':
            morseLettre = 'O';
            break;
        case 'N':
            morseLettre = 'K';
            break;
        case 'O':
            morseLettre = '&';
            break;
        case 'P':
            morseLettre = '?';
            break;
        case 'Q':
            morseLettre = '?';
            break;
        case 'R':
            morseLettre = '#';
            break;
        case 'S':
            morseLettre = 'V';
            break;
        case 'T':
            morseLettre = 'M';
            break;
        case 'U':
            morseLettre = '_';
            break;
        case 'V':
            morseLettre = '3';
            break;
        case 'W':
            morseLettre = 'J';
            break;
        case 'X':
            morseLettre = '?';
            break;
        case 'Y':
            morseLettre = '?';
            break;
        case 'Z':
            morseLettre = '?';
            break;
        case '_':
            morseLettre = '2';
            break;
        case '#':
            morseLettre = '?';
            break;
        case '%':
            morseLettre = '?';
            break;
        case '&':
            morseLettre = '0';
            break;
        case '0':
            morseLettre = '?';
            break;
        case '1':
            morseLettre = '?';
            break;
        case '2':
            morseLettre = '?';
            break;
        case '3':
            morseLettre = '?';
            break;
        case '4':
            morseLettre = '?';
            break;
        case '5':
            morseLettre = '?';
            break;
        case '6':
            morseLettre = '?';
            break;
        case '7':
            morseLettre = '?';
            break;
        case '8':
            morseLettre = '?';
            break;
        case '9':
            morseLettre = '?';
            break;
        case '+':
            morseLettre = '?';
            break;
        case '=':
            morseLettre = '?';
            break;
        case '/':
            morseLettre = '?';
            break;
        default: break;
    }
fileEnfile(CARACTERE_LIGNE);
}

/**
 * Appelée si la pioche morse à marqué une pause.
 */
unsigned char morsePause() {
    // À implémenter.
    if (morseLettre != 0){ // si la valeur est différente de 0 
    morseDecodeSequence(); //alors on appel le décode 
    Lettre = morseLettre;
    fileEnfile(CARACTERE_PAUSE); //Envoi le caractère pause dans la file
    fileEnfile(Lettre);         // Envoi le caractère dans la file
    fileEnfile('\r');
    fileEnfile('\n');
    morseLettre = 0;            // Remet à zéro la variable mémoire
    return Lettre;              
    }
    return 0;
}

/**
 * Réinitialise le décodeur morse.
 */
void morseReinitialise() {
    // Remet à zéro les variables mémoire
    morseLettre = 0;
    Lettre = 0;

}

/**
 * Décrit les états possibles de la pioche morse.
 */
typedef enum {
    PIOCHE_LIBRE,
    PIOCHE_ENFONCEE
} EtatPiocheMorse;

/** État de la pioche morse. */
static EtatPiocheMorse etatPiocheMorse = PIOCHE_LIBRE;

/** Compte le temps que la pioche reste dans un même état. */
static int compteurDeTemps = 0;

/**
 * Reçoit la notification que la pioche a été enfoncée.
 */
void morseEnfoncePioche() {
    // À implémenter.
    etatPiocheMorse = PIOCHE_ENFONCEE;              // Passe l'état en pioche enfoncée
    compteurDeTemps = 0;                            // remise à zéro du compteur de temps

}

/**
 * Reçoit la notification que la pioche a été libéré.
 */
void morseLiberePioche() {
    // À implémenter.
    etatPiocheMorse = PIOCHE_LIBRE;                 // Passe l'état en pioche libre
    if (compteurDeTemps <= MORSE_MAX_DUREE_POINT) { // Si le temps est inférieur 
        morsePoint();                               // Appel de la fonction pour gérer le point
    } else {
        morseLigne();                               // sinon appel la fonction pour gérer un trait
    }
    compteurDeTemps = 0;                            // remise à zéro du compteur de temps

}

/**
 * Est appelée régulièrement, toutes les 20 ms.
 */
void morseTicTac() {
    // À implémenter.
    compteurDeTemps++;                              // Implémentation du compteur à chaque fois qu'on appel la fonction
    if (compteurDeTemps >= MORSE_MIN_DUREE_PAUSE) { // Si le temps est supérieur
        morsePause();                               // Appel de la fonction pour gérer la pause
        compteurDeTemps = 0;                        // remise à zéro du compteur de temps
    }
}

#ifdef TEST

void testMorsePoint() {
    morseReinitialise();
    morsePoint();
    testeEgaliteChars("MPO", morseDecodeSequence(), 'E');
}

void testMorseLigne() {
    morseReinitialise();
    morseLigne();
    testeEgaliteChars("MLI", morseDecodeSequence(), 'T');
}

void testMorsePause() {
    morseReinitialise();
    morsePoint();
    morseLigne();
    testeEgaliteChars("MO-AA", morsePause(), 'A');
    morseLigne();
    morsePoint();
    morseLigne();
    testeEgaliteChars("MO-KK", morsePause(), 'K');
}

void testMorseDecodeLettreInconnue() {
    morseReinitialise();
    morsePoint();
    morseLigne();
    morsePoint();
    morseLigne();
    testeEgaliteChars("MO-IN", morsePause(), '?');
}

unsigned char testMorseDecode(const char *sequence) {
    unsigned char n = 0;

    morseReinitialise();
    do {
        switch (sequence[n++]) {
            case '-':
                morseLigne();
                break;
            case '.':
                morsePoint();
                break;
        }
    } while (sequence[n] != 0);

    return morsePause();
}

void testMorseDecodeToutAlphabet() {
    testeEgaliteChars("MO-A", testMorseDecode(".-"), 'A');
    testeEgaliteChars("MO-B", testMorseDecode("-..."), 'B');
    testeEgaliteChars("MO-C", testMorseDecode("-.-."), 'C');
    testeEgaliteChars("MO-D", testMorseDecode("-.."), 'D');
    testeEgaliteChars("MO-E", testMorseDecode("."), 'E');
    testeEgaliteChars("MO-F", testMorseDecode("..-."), 'F');
    testeEgaliteChars("MO-G", testMorseDecode("--."), 'G');
    testeEgaliteChars("MO-H", testMorseDecode("...."), 'H');
    testeEgaliteChars("MO-I", testMorseDecode(".."), 'I');
    testeEgaliteChars("MO-J", testMorseDecode(".---"), 'J');
    testeEgaliteChars("MO-K", testMorseDecode("-.-"), 'K');
    testeEgaliteChars("MO-L", testMorseDecode(".-.."), 'L');
    testeEgaliteChars("MO-M", testMorseDecode("--"), 'M');
    testeEgaliteChars("MO-N", testMorseDecode("-."), 'N');
    testeEgaliteChars("MO-O", testMorseDecode("---"), 'O');
    testeEgaliteChars("MO-P", testMorseDecode(".--."), 'P');
    testeEgaliteChars("MO-Q", testMorseDecode("--.-"), 'Q');
    testeEgaliteChars("MO-R", testMorseDecode(".-."), 'R');
    testeEgaliteChars("MO-S", testMorseDecode("..."), 'S');
    testeEgaliteChars("MO-T", testMorseDecode("-"), 'T');
    testeEgaliteChars("MO-U", testMorseDecode("..-"), 'U');
    testeEgaliteChars("MO-V", testMorseDecode("...-"), 'V');
    testeEgaliteChars("MO-X", testMorseDecode("-..-"), 'X');
    testeEgaliteChars("MO-Y", testMorseDecode("-.--"), 'Y');
    testeEgaliteChars("MO-Z", testMorseDecode("--.."), 'Z');

    testeEgaliteChars("MO-0", testMorseDecode("-----"), '0');
    testeEgaliteChars("MO-1", testMorseDecode(".----"), '1');
    testeEgaliteChars("MO-2", testMorseDecode("..---"), '2');
    testeEgaliteChars("MO-3", testMorseDecode("...--"), '3');
    testeEgaliteChars("MO-4", testMorseDecode("....-"), '4');
    testeEgaliteChars("MO-5", testMorseDecode("....."), '5');
    testeEgaliteChars("MO-6", testMorseDecode("-...."), '6');
    testeEgaliteChars("MO-7", testMorseDecode("--..."), '7');
    testeEgaliteChars("MO-8", testMorseDecode("---.."), '8');
    testeEgaliteChars("MO-9", testMorseDecode("----."), '9');
}

void attendTicTac(int nTicTac) {
    unsigned char n;
    for (n = 0; n < nTicTac; n++) {
        morseTicTac();
    }
}

void testMorseDetecteImpulsionsU() {
    morseReinitialise();
    fileReinitialise();

    morseEnfoncePioche();
    attendTicTac(1);
    morseLiberePioche();
    testeEgaliteChars("MDIU01", fileDefile(), CARACTERE_POINT);

    morseEnfoncePioche();
    attendTicTac(MORSE_MAX_DUREE_POINT);
    morseLiberePioche();
    testeEgaliteChars("MDIU02", fileDefile(), CARACTERE_POINT);

    attendTicTac(MORSE_MIN_DUREE_PAUSE - 1);

    morseEnfoncePioche();
    attendTicTac(MORSE_MAX_DUREE_POINT + 1);
    morseLiberePioche();
    testeEgaliteChars("MDIU03", fileDefile(), CARACTERE_LIGNE);

    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteChars("MDIU04", fileDefile(), CARACTERE_PAUSE);
    testeEgaliteChars("MDIU05", fileDefile(), 'U');
    testeEgaliteChars("MDIU06", fileDefile(), '\r');
    testeEgaliteChars("MDIU07", fileDefile(), '\n');
}

void testMorseDetecteImpulsionsET() {
    morseReinitialise();
    fileReinitialise();

    morseEnfoncePioche();
    attendTicTac(1);
    morseLiberePioche();
    testeEgaliteChars("MDIET01", fileDefile(), CARACTERE_POINT);

    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteChars("MDIET02", fileDefile(), CARACTERE_PAUSE);
    testeEgaliteChars("MDIET03", fileDefile(), 'E');
    testeEgaliteChars("MDIET04", fileDefile(), '\r');
    testeEgaliteChars("MDIET05", fileDefile(), '\n');

    morseEnfoncePioche();
    attendTicTac(MORSE_MAX_DUREE_POINT + 1);
    morseLiberePioche();
    testeEgaliteChars("MDIET06", fileDefile(), CARACTERE_LIGNE);

    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteChars("MDIET07", fileDefile(), CARACTERE_PAUSE);
    testeEgaliteChars("MDIET08", fileDefile(), 'T');
    testeEgaliteChars("MDIET09", fileDefile(), '\r');
    testeEgaliteChars("MDIET10", fileDefile(), '\n');

    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteEntiers("MDIET11", fileEstVide(), 255);
    attendTicTac(MORSE_MIN_DUREE_PAUSE * 2);
    testeEgaliteEntiers("MDIET12", fileEstVide(), 255);
}

void testMorseIgnorePauseInitiale() {
    morseReinitialise();
    fileReinitialise();

    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteEntiers("IPI01", fileEstVide(), 255);
    attendTicTac(MORSE_MIN_DUREE_PAUSE);
    testeEgaliteEntiers("IPI02", fileEstVide(), 255);
}

void testMorse() {
    testMorsePoint();
    testMorseLigne();
    testMorsePause();

    testMorseDecodeLettreInconnue();
    testMorseDecodeToutAlphabet();

    testMorseDetecteImpulsionsU();
    testMorseDetecteImpulsionsET();
    testMorseIgnorePauseInitiale();
}

#endif