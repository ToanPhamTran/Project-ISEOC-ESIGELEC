/*
 * spi_mode_slave.h
 *
 *  Created on: 8 mars 2018
 *      Author: t.phamtran.14
 */
#include "msp430.h"

// Description : Fonction qui permet d'initialiser les lignes du Port 1 correspondant au protocole du SPI mode
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************
void initPort();

// Description : fonction permettant d'initialiser les ports et les registres du slave
//Inputs :
//        - unsigned char c : le caractere transmis
//Outputs :
//         -void
//****************************************************************************
void initSlave();

// Description : fonction permet de recevoir le caractere envoye par le maitre
//Inputs :
//        - unsigned char c : le caractere transmis
//Outputs :
//         -void
//****************************************************************************

unsigned char RXSlaveSPI ();




