#include <msp430.h> 
#include "Servomoteur_2231.h"


//**********************Rotation Servomoteur*********************************

//génération du signal PWM pour f=50Hz
void Init_Timer(int Vr){
	BCSCTL1 = CALBC1_1MHZ; //horloge 1Mhz
	DCOCTL = CALDCO_1MHZ;
	TACTL |= (TASSEL_2 | ID_0 | MC_1);
	TACCTL1 |= OUTMOD_7;
	TACCR0 = 20000;   // Correspond a 20ms
	TACCR1 = Vr;     // Permet de gérer le rapport cyclique
	//TACTL &= ~TAIFG;
}
void Init_Servo(){

P1DIR |=BIT2;   // Reception du signal de commande sur la ligne du Timer
P1SEL |=BIT2;


}
// A utiliser pour stopper le signal
void Stop(){
	P1DIR |= BIT2;
	P1SEL &= ~BIT2;

}

int main(void) {

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	Init_Servo();
    while(1){                       // boucle permettant de répéter deux balayages
	    Init_Timer(500);           // Position 0°
		__delay_cycles(525000);
		Init_Timer(1500);        // Position 90°
		__delay_cycles(1550000);
		Init_Timer(2500);              // Position 180°
		__delay_cycles(525000);
		 Init_Timer(500);
		__delay_cycles(435000);        // Retour a la position 0°


	}

}
