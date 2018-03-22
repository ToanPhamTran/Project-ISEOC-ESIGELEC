#include <msp430.h> 
#include "uart.h"
#include "fct_robot.h"
#include <string.h>
#include <stdio.h>
#include "Mode_auto.h"
//
// main.c
void main()
{

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
	DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
    Init_Port();
    Init_PWM();
	Init_UART();
	Arret_robot();


	__enable_interrupt();
	while(1);
}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR_Manuel()
{
	unsigned char choix;
	char car [100];
	sprintf(car,"Bienvenue dans le mode manuel du Robot: %s","\r\n");
	afficher_caract(car, strlen(car));
	if (IFG2 & UCA0RXIFG)
	{
		 choix = RXdata();
		 sprintf(car,"Veuillez entrez votre choix : %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"1. Avancer le robot en mode manuel, veuillez saisir a %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"2. Tourner a droite le robot en mode manuel, veuillez saisir d %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"3. Tourner a gauche le robot en mode manuel, veuillez saisir g %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"4. Reculer le robot en mode manuel, veuillez saisir r %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"5. Stoper le robot en mode manuel, veuillez saisir s %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"6. Activer le mode autonome, veuillez saisir m %s","\r\n");
		 afficher_caract(car, strlen(car));
		 switch(choix)
		 {
		 	 case 'a':
		 	 	 {
		 	 		 Avancer_robot();
		 	 	 }
		 	 	 break;

		 	 case 'd':
		 	 	 {
		 	 		 Tourner_droite();
		 	 	 }
		 	 	 break;
		 	 case 'g':
		 	 	 {
		 	 		 Tourner_gauche();
		 	 	 }
		 	 	 break;
		 	 case 'r':
		 	 	 {
		 	 		 Reculer_robot();
		 	 	 }
		 	 	 break;
		 	 case 's':
		 	 	 {
		 	 		 Arret_robot();
		 	 	 }
		 	 	 break;
		 	 case 'm':
		 	 {
		 		 Mode_auto();
		 	 }
		 	 default :
		 		 break;
		 }
	}
}

