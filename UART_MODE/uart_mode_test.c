// main programm for testing the uart mode with the spi mode
// autor : Toan pham Tran
// date : 13/03/2018
//project : ISE-OC

// library use in this program
#include <msp430.h> 
#include "spi_mode_master.h"
#include "uart.h"
#include <string.h>
#include <stdio.h>

/*
 * main.c
 */
void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
    DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
    //InitUartPort();
    InitUART();
    initPortMaster();
    initMaster();

	__enable_interrupt();
	 while(1);
}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR()
{
	unsigned char choix;
	int i ;
	//unsigned char MST_data;
	char car [100];
	if (IFG2 & UCA0RXIFG)
	 {

	 choix = RXdata();
	 sprintf(car,"Veuillez entrez votre choix : %s","\r\n");
	 afficher_caract(car, strlen(car));
	 sprintf(car,"allumer une led sur le msp 2231-connection spi" : s %s","\r\n");
	 afficher_caract(car, strlen(car));


	 switch(choix)
	 {
	 	 case 's':
	 	 	 	 {
	 	 	 		 for( i =0; i<10; i++)
	 	 	 		 {
	 	 	 		P1OUT &=~BIT0;
	 	 	 		//P1OUT &=~ BIT4;
	 	 	 		//MST_data=choix;
	 	 	 		TX_SPI(choix);
	 	 	 		//P1OUT |=BIT4;
	 	 	 		 }
	 	 	 	}
	 	 	 	 break;

	 	 default:
	 		 break;
	 }

	 }


}
