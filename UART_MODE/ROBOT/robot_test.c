#include <msp430.h>
#include "config.h"
#include "ADC.h"
#include "fonction.h"

void Init_Timer0()
{

	TA0CTL |= ( TASSEL_2 | ID_0 | MC_1);
	TA0CCR0 = 25000;
	TA0CTL &= ~TAIFG;
}

void Attente_Timer0(){
	Init_Timer0();
	while( !(TA0CTL & TAIFG));
	TA0CTL &= ~TAIFG;
}
void Init_Timer1 ()
{

	TA1CTL |= ( TASSEL_2 | ID_0 | MC_1);
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL2 |= OUTMOD_7;
		TA1CCR0 = 1000;
		TA1CCR1 = 100;
		TA0CCR2 = 100;
}

int main (void)
{
	 int vitesseA;
	 int vitesseB;
	 int i;

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	initPort();
	//init_Timer();
	Init_Timer1();
	//init_capteur();
	vitesseA=600;
	vitesseB=600;
	Avancer_robot(vitesseA,vitesseB);
	for(i=0; i<50; i++){
			Attente_Timer0();
		}

	tourner_gauche();
	for(i=0; i<22; i++) //timer pour tourner à 90° gauche --> 22
	{
				Attente_Timer0();
			}

	Avancer_robot(vitesseA,vitesseB);
	//Arret_robot();



//fonctionRobot(); //focntion robot parcourt 1


}
