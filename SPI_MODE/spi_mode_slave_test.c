#include <msp430.h> 
#include "spi_mode_slave.h"

/*
 * main.c
 */
int main(void)
{
	//P1DIR  = BIT4 ;
	P1DIR |= BIT0;
	P1OUT &=~BIT0;
	 WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
	    DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
	    USICTL0 |= USISWRST;
    initSlave();
  /* if(BIT4 & USISRL)
    	{
    		P1OUT |= BIT0;
    	}
    	else
    	{
    		P1OUT &= ~BIT0;
    	}
    	  USISRL = P1IN;
    	  USICNT = 8;  */                        // re-load counter
    __enable_interrupt();
}

#pragma vector =USI_VECTOR
__interrupt void SPI_slave (void)
{
	unsigned char tamp ;
	tamp = RXSlaveSPI();
	USICNT = 8;
	if ( 0x30 & tamp )
	{
		P1OUT |=BIT0;
	}
	else
	{
		P1OUT &=~BIT0;
	}
}
