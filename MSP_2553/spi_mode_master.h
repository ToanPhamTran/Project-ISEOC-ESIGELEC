/*
 * spi_mode_master.h
 *
 *  Created on: 8 mars 2018
 *      Author: t.phamtran.14
 */
#ifndef SPI_2553
#define SPI_2553

#include "msp430.h"

// Description : Fonction permettant d'initialiser les ports qui seront utilises pour le mode SPI du maitre
//Inputs :
//        - void
//Outputs :
//         -void
//***********************************************************************************************
void initPortMaster();

// Description : Fonction permettant d'initialiser les registres qui seront utilises par le mode UART du maitre
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************************************

void initMaster();


// Description : Fonction permettant de transmettre un caractere via SPI du maitre
//Inputs :
//        - unsigned char c : le caractere transmis
//Outputs :
//         -void
//****************************************************************************

void TX_SPI(unsigned char c);

// Description : Fonction permettant de recevoir un caractre via UART
//Inputs :
//        - unsigned char c : le caractere reçu
//Outputs :
//         -void
//*************************************************************************

void RX_SPI(unsigned char c);

#endif

