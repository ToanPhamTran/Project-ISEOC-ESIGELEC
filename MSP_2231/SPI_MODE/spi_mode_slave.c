/*
 * spi_mode_slave.c
 *
 *  Created on: 8 mars 2018
 *      Author: Toam Pham Tram, Blazejewski Quentin
 */
#include <msp430.h>
#include "spi_mode_slave.h"

 void initPort()
 {
	 P1DIR |= BIT0 ;
	 P1OUT &=~ BIT0;
	
	 P1SEL |= BIT6 + BIT7 + BIT5;
	 P1SEL2 = BIT6 + BIT7 + BIT5;
 }
void initSlave()
{
	 USICTL0 |= USIPE7 + USIPE6 + USIPE5 + USIOE; // Port, SPI slave
	 USICTL1 |= USIIE;                     // Counter interrupt, flag remains set
	 USICTL0 &= ~USISWRST;                 // USI released for operation
	 USISRL = 0x23;                        // init-load data
	 USICNT = 8;                           // init-load counter
}

unsigned char  RXSlaveSPI()
{
	return USISRL;
}




