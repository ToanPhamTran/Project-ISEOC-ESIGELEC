/*
 * uart.h
 *
 *  Created on: 8 mars 2018
 *  Author: t.phamtran.14
 */
#ifndef UART
#define UART
typedef unsigned char UCHAR;
typedef char CHAR;



//Librairie utilise dans ce programme
#include <msp430.h>

// Description : Fonction permettant d'initialiser les registres qui seront utilises par le mode UART
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************************************

void Init_UART(void);

// Description : Fonction permettant de transmettre un caractere via UART
//Inputs :
//        - unsigned char c : le caractere transmis
//Outputs :
//         -void
//****************************************************************************

void TXdata (UCHAR c);

// Description : Fonction permettant de recevoir un caractre via UART
//Inputs :
//        - unsigned char c : le caractere reçu
//Outputs :
//         -void
//*************************************************************************

UCHAR RXdata(void);

// Description : Fonction permettant d'afficher une chaine de caractere
//Inputs :
//        - unsigned char *point : caractere de type de pointeur
//		  - int taille : valeur de la taille de la chaine de caractere saisi
//Outputs :
//         -void
//*****************************************************************************

void afficher_caract(CHAR *point, int taille);

#endif
