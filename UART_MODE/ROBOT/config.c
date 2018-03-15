#include <msp430.h>
#include "ADC.h"


void Avancer_robot(int vitesseA, int vitesseB)
{
	P2OUT &=~ BIT1; // sens avant moteur A
	P2OUT |=  BIT5; // sens avant moteur B

	TA1CCR1 = vitesseA; //vitesse de base de la roue gauche(A)
	TA1CCR2 = vitesseB; //vitesse de base de la roue droite(B)

}
void tourner_gauche()
{
	P2OUT |= ( BIT5 );
	P2OUT |= ( BIT1 );
}

void tourner_droite()
{
	P2OUT |= BIT1; 	// sens avant moteur A
	P2OUT |= BIT5; 	// inverse sens de moteur B
}

void Arret_robot()
{
	TA1CCR1=0 ; //vitesse de base de la roue gauche
	TA1CCR2=0; //vitesse de base de la roue droite
}


void init_capteur()
{
/// mesure avec le capteur
   P1DIR &= ~BIT1;
   P1DIR &= ~BIT5;
   ADC_init();

}
int detection_obstacle(int capt)
{
	int valeurIR;
	int obst =0;
	int valeurSeuilIR = 0x294;

	ADC_Demarrer_conversion(capt);
	valeurIR = ADC_Lire_resultat();
	if (valeurIR>valeurSeuilIR)
		{
			obst=1;

		}
	else
		{
			obst=0;
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

