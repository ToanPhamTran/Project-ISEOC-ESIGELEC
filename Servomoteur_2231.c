#include <msp430.h> 
//#include <Servomoteur_2231.h>


//**********************Rotation Servomoteur*********************************

//génération du signal PWM pour f=50Hz
void Init_Clock(){
	 BCSCTL1 = CALBC1_1MHZ; //horloge 1Mhz
	    DCOCTL = CALDCO_1MHZ;
}
void Init_Timer(){

    TACTL |= (TASSEL_2 | ID_0 | MC_1);
    TACCTL1 |= OUTMOD_7;
    TACCR0 = 19550;   // Correspond a 20ms
    TACTL &= ~TAIFG;
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
// rotation jusqu'a l'angle 90°
void Droit_135(){
	TACCR1 = 2000;
}
// rotation jusqu'a l'angle 0°
void Gauche_0(){
	TACCR1 = 1000;
}
// rotation jusqu'a l'angle 180°
//void Droit_180(){
//	TACCR1=2500;
}
int main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer


 Init_Clock();               // Appel des fonctions d'initialisation
Init_Servo();
Init_Timer();
while(1){

    Gauche_45();          // Appel des fonctions de rotations de 45 a 135
    __delay_cycles(500000);
     Droit_135();
    __delay_cycles(500000);
 






}

}

