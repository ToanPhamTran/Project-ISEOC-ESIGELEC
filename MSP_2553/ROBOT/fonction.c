#include <msp430.h>
#include "config.h"
#include "ADC.h"




void init_Timer()
{

	TA1CCR0 |= 1000;
	TA1CCTL2 |= OUTMOD_7;
	TA1CCR2=0;
	TA1CTL |= TASSEL_2 + MC_1;

	TA1CCR0 |= 1000;
	TA1CCTL1 |= OUTMOD_7;
	TA1CCR1=0; 
	TA1CTL |= TASSEL_2 + MC_1;

	TA1CCR1 = 100;
	TA1CCR2 = 100;


}


void initPort()
{
	//Mesure vitesse moteur A bit 0
	P2DIR &=~BIT0;
	P2SEL |=BIT0;
	P2SEL2 &=~BIT0;

	//sens moteur A sur le bit 1
	P2DIR |=BIT1;
	P2SEL &=~ BIT1;
	P2SEL2 &=~ BIT1;
	//bit2
	P2DIR |= BIT2;
	P2SEL |= BIT2;
	//Mesure vitesse moteur B bit 3
	P2DIR &=~BIT3;
	P2SEL |=BIT3;
	P2SEL2 &=~BIT3;

	//bit4
	P2DIR |= BIT4;
	P2SEL |= BIT4;
	//sens moteur B sur le bit 5
	P2DIR  |= BIT5;
	P2SEL &=~ BIT5;
	P2SEL2 &=~ BIT5;
}



void fonctionRobot()
{
	/*
	 * Initialisation des variables
	 *  */
		int capt;
		int tension;
		int vitesseA;
		int vitesseB;

	_delay_cycles(2000000);
	initPort();
	init_Timer();
	init_capteur();

	do
	{
		vitesseA=192;
		vitesseB=200;
		Avancer_robot(vitesseA,vitesseB);

	capt=detection_obstacle(5); //regarde valeur capteur
	tension=detection_distance(5);

	}while(tension!=327);

	if(tension == 327)//tension pour une distance à 8cm
		{
		Arret_robot();
		_delay_cycles(400000);
		}

		do
		{
			vitesseA=192;
			vitesseB=200;
			Avancer_robot(vitesseA,vitesseB);
			capt=detection_obstacle(5); //regarde valeur capteur
			tension=detection_distance(5);
		}while(tension!=614);

	 if(tension == 614) //tension pour une distance à 4cm
			{
				Arret_robot();
				TA1CCR0 = 0;
				_delay_cycles(400000);
			}

}
