#include <msp430.h>
#include "voiture.h"

void Init_Timer0(){
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	TA0CTL |= ( TASSEL_2 | ID_0 | MC_1);
	TA0CCR0 = 25000;
	TA0CTL &= ~TAIFG;
}

void Attente_Timer0(){
	Init_Timer0();
	while( !(TA0CTL & TAIFG));
	TA0CTL &= ~TAIFG;
}

void Init_Timer1 (unsigned int vM, unsigned int vA, unsigned int vB){
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	TA1CTL |= ( TASSEL_2 | ID_0 | MC_1);
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL2 |= OUTMOD_7;
		TA1CCR0 = vM;
		TA1CCR1 = vA;
		TA0CCR2 = vB;
}

void Init_moteur(){
	P2DIR |= ( BIT1 | BIT2 | BIT4 | BIT5);
	P2SEL |= ( BIT2 | BIT4 );
	P2SEL &= ~( BIT1 | BIT5);
	P2SEL2 &= ~( BIT1 | BIT2 | BIT4 | BIT5);

}

void Avancer(unsigned int vM, unsigned int vA, unsigned int time, unsigned int vB){
	int i;
	Init_Timer1(vM, vA, vB);
	//Init_moteur();
	P2OUT |= ( BIT5 );
	P2OUT &= ~( BIT1 );
	for(i=0; i<time; i++){
		Attente_Timer0();
	}

}

void Tourner_gauche(unsigned int vM, unsigned int vA){
	Init_Timer1(vM, vA, vA);
	Init_moteur();
	P2OUT |= ( BIT5 );
	P2OUT |= ( BIT1 );
	Attente_Timer0();

}

void Tourner_droite(unsigned int vM, unsigned int vA){
	Init_Timer1(vM, vA, vA);
		Init_moteur();
		P2OUT &= ~( BIT5 );
		P2OUT &= ~( BIT1 );
		Attente_Timer0();
	}

void Tourner_90_D(){
	int i;
	for (i=0; i<12; i++){
		Tourner_droite(10,2);
	}
}

void Tourner_90_G(){
	int i;
	for (i=0; i<12; i++){
		Tourner_gauche(10,2);
	}
}

void Reculer(unsigned int vM, unsigned int vA){
	Init_Timer1(vM, vA, vA);
			Init_moteur();
			P2OUT &= ~( BIT5 );
			P2OUT |= ( BIT1 );
			Attente_Timer0();
}

void Stop_voiture(){
	int i;
	Init_Timer1(10, 0, 0);
	Init_moteur();
	for (i=0; i<50; i++){
		Attente_Timer0();

}

}
