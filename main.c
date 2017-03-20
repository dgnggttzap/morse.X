#include <xc.h>
#include <stdio.h>
#include <pic18f25k22.h>
#include "test.h"
#include "file.h"
#include "morse.h"
#include "uart.h"

/**
 * Bits de configuration:
 */
#pragma config FOSC = INTIO67  // Osc. interne, A6 et A7 comme IO.
#pragma config IESO = OFF      // Pas d'osc. au démarrage.
#pragma config FCMEN = OFF     // Pas de monitorage de l'oscillateur.

// Nécessaires pour ICSP / ICD:
#pragma config MCLRE = EXTMCLR // RE3 est actif comme master reset.
#pragma config WDTEN = OFF     // Watchdog inactif.
#pragma config LVP = OFF       // Single Supply Enable bits off.

#define CAPTURE_FLANC_MONTANT 1
#define CAPTURE_FLANC_DESCENDANT 0

#ifndef TEST

void low_priority interrupt bassePriorite() {

    if (INTCON3bits.INT1F) {
        INTCON3bits.INT1F = 0;
        if (PORTBbits.RB1) {
            INTCON2bits.INTEDG1 = CAPTURE_FLANC_DESCENDANT;
            morseLiberePioche();
        } else {
            INTCON2bits.INTEDG1 = CAPTURE_FLANC_MONTANT;
            morseEnfoncePioche();
        }
    }
    
    if (PIR1bits.TMR1IF) {
        TMR1 = 60535;
        PIR1bits.TMR1IF = 0;
        morseTicTac();
    }
}

/**
 * Initialise les périphériques.
 */
void initialiseHardware() {
    
    initialiseUART1();
    
    // ...
    // À faire.
    // ...
}

/**
 * Point d'entrée du programme.
 */
void main(void) {
    initialiseHardware();
    morseReinitialise();
    fileReinitialise();
    
    // Affiche les caractères de la file.
    
    while(1) {
        if (!fileEstVide()) {
            putch(fileDefile());
        }
    }
}
#endif

#ifdef TEST

/**
 * Point d'entrée des tests unitaires.
 */
void main() {
    
    initialiseTests();
    
    testFile();
    testMorse();
    
    finaliseTests();
    
    while(1);
}
#endif
