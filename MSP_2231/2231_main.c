#include <msp430.h> 
#include "spi_mode_slave.h"
#include "servo.h"

/*
 * main.c
 */
int main(void)
{
	//P1DIR  = BIT4 ;

	 WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	 BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
	 DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz


	 Init_Port();
	 Init_Slave();
	 Init_Servo();
	 Init_Timer();
    __enable_interrupt();
}

#pragma vector =USI_VECTOR
__interrupt void SPI_slave (void)
{
	unsigned char tamp ;
	tamp = RXSlaveSPI();
	//USICNT = 8;
	if ( 0x30 & tamp )
	{
		//while(1)

		{

		//__delay_cycles(500000);
		angle_0();          // Appel des fonctions de rotations de 45 a 135
		__delay_cycles(500000);
		angle_45();
		__delay_cycles(500000);
		angle_90();
		__delay_cycles(500000);
		angle_135();
		__delay_cycles(500000);
		angle_180();
		__delay_cycles(500000);

		P1OUT|=BIT0;
		}
	}
	else
	{
		P1OUT &=~BIT0;
	}
}
/*int main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer


 Init_Clock();               // Appel des fonctions d'initialisation
Init_Servo();
Init_Timer();
while(1){

    angle_0();          // Appel des fonctions de rotations de 45 a 135
    __delay_cycles(500000);
     angle_45();
    __delay_cycles(500000);
	angle_90();
	 __delay_cycles(500000);
	angle_135();
	 __delay_cycles(500000);
	angle_180();
	 __delay_cycles(500000);







}

}*/
