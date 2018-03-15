/*
 * spi_mode_master.c
 *
 *  Created on: 8 mars 2018
 *      Author: t.phamtran.14
 */
#include <msp430.h>
#include "spi_mode_master.h"

void initPortMaster()
{
	  //initialisation des ports
	  //*******************************

	  P1DIR |= BIT0 ;
	  P1DIR |=BIT4;
	  P1SEL |= (BIT6 + BIT7 + BIT5);
	  P1SEL2 |= (BIT6 + BIT7 + BIT5);

}
void initMaster()
{
	  //*****************************
	  // initialisation des registres
	  // la polarité et la phase est configuré par le registre UCCKPL
	  // Initialalisation des registres à 1
	  // UCMSB on configure le sens de direction de l'envoie ici MSB en premier
	  //UCMST : on selectionne le mode maitre à 1, 0 pour le l'esclave.
	  //UCSYNC synchronous mode

	  UCB0CTL0 |= UCCKPL + UCMSB + UCMST + UCSYNC;  // 3-pin, 8-bit SPI master


	  UCB0CTL1 |= UCSSEL_2;                     // Mode SMCLK
	  UCB0BR0 |= 0x02;                          // diviser par 2
	  UCB0BR1 = 0;                              //
	  //UCB0MCTL = 0;                             // No modulation
	  UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	  IE2 |= UCB0RXIE;                          // Enable USCI0 RX interrupt

}

void TX_SPI(unsigned char c)
{
	 while (!(IFG2 & UCB0TXIFG)); // USCI_B0 TX buffer ready?
	 UCB0TXBUF = c;
}

void RX_SPI(unsigned char c)
{
	 while (!(IFG2 & UCB0RXIFG)); // USCI_B0 RX buffer ready?
	 UCB0RXBUF = c;
}


