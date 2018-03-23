#include <msp430.h>
#include "ADC.h"


void Init_Timer0()
{

	TA0CTL |= ( TASSEL_2 | ID_0 | MC_1);
	TA0CCR0 = 25000;
	TA0CTL &= ~TAIFG;
}

void Init_PWM ()
{

	TA1CTL |= ( TASSEL_2 | ID_0 | MC_1);
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_7;
	TA1CCR0 = 1000;
	TA1CCR1 = 0;
	TA0CCR2 = 0;
}

void Init_Port()
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

void Init_capteur()
{
/// mesure avec le capteur
   P1DIR &= ~BIT1;
   P1DIR &= ~BIT3;
   ADC_init();

}

void Attente_Timer0()
{
	Init_Timer0();
	while( !(TA0CTL & TAIFG));
	TA0CTL &= ~TAIFG;
}

void Sens_moteurA(int sens)
{
	if (sens == 0)
	{
		P2OUT &=~ BIT1; // sens avant moteur A
	}
	else
	{
		P2OUT |= ( BIT1 );
	}
}

void Sens_moteurB(int sens)
{
	if (sens == 0)
	{
		P2OUT &=~ BIT5;
	}
	else
	{
		P2OUT |=  BIT5;
	}
}
void Avancer_robot()
{

	Sens_moteurA(0); // sens avant moteur A


	Sens_moteurB(1); // sens avant moteur B

	TA1CCR1 = 600; //vitesse de base de la roue gauche(A)
	TA1CCR2 = 600; //vitesse de base de la roue droite(B)

}


void Tourner_gauche()
{
	int i;
	//Sens_moteurA(1);
	P2OUT |= ( BIT1 );

	//Sens_moteurB(1);
	P2OUT |=  BIT5;

	for(i=22; i>0; i--) //timer pour tourner à gauche (90°)
		{
			Attente_Timer0();
		}
	Arret_robot();
}

void Tourner_droite()
{
	int i;

	//P2OUT &=~ BIT1;
	Sens_moteurA(0) ; // sens avant moteur A
	//P2OUT &=~ BIT5;
	Sens_moteurB(0); // inverse sens de moteur B
	for(i=18; i>0; i--) //timer pour tourner à droite (90°)
	{
		Attente_Timer0();
	}
	Arret_robot();
}

void Arret_robot()
{
	TA1CCR1=0 ; //vitesse de base de la roue gauche
	TA1CCR2=0; //vitesse de base de la roue droite
}


void Reculer_robot()
{
	Sens_moteurA(1); // sens avant moteur A
	Sens_moteurB(0); // sens avant moteur B

	TA1CCR1 = 200; //vitesse de base de la roue gauche(A)
	TA1CCR2 = 200; //vitesse de base de la roue droite(B)

}

int capteur()
{
	int tension ;
	int obst;
	tension=detection_distance(3);
	if(tension ==614)
		{
			//Arret_robot();
			obst=1;
		}
		else
		{
			obst =0;
		}

		return obst;
}

int detection_distance(int distance_capt)
{
	int tension;
	ADC_Demarrer_conversion(distance_capt);
	tension=ADC_Lire_resultat();
	return tension;
}




