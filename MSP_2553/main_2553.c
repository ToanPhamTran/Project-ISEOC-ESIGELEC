#include <msp430.h> 
#include "uart.h"
#include "fct_robot.h"
#include <string.h>
#include <stdio.h>
#include "Mode_auto.h"
//**********************************
// main.c 
//************************************
void main()
{

	
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
	DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
	//**********************************
	// Initialisation des registres et des ports pour l'UART & pour le robot
	//************************************
        Init_Port();
        Init_PWM();
	Init_UART();

	__enable_interrupt();
	while(1);
}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR_Manuel()
{
	unsigned char choix; // variable permettant de stocker le choix choisi par l'utilisateur
	char car [100]; //variable permettant de stocker les caractères saisis par l'utilisateur
	sprintf(car,"Bienvenue dans le mode manuel du Robot: %s","\r\n");
	afficher_caract(car, strlen(car));
	if (IFG2 & UCA0RXIFG) // verifie si le buffer UCA0RXIFG est prêt
	{
		 choix = RXdata(); //le choix choisi par l'utilisateur est stocké dans la varibale "choix"
		 //l'utilisateur choisi les différentes fonction du mode manuel ou le mode autonome
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
			//Fonction avancer du robot du mode manuel
		 	 case 'a':
		 	 	 {
		 	 		 Avancer_robot();
		 	 	 }
		 	 	 break;
			//Fonction  tourner à droite du robot en mode manuel
		 	 case 'd':
		 	 	 {
		 	 		 Tourner_droite();
		 	 	 }
		 	 	 break;
			//Fonction tourner à gauche du robot en mode manuel
		 	 case 'g':
		 	 	 {
		 	 		 Tourner_gauche();
		 	 	 }
		 	 	 break;
			//Fonction reculer du robot en mode manuel
		 	 case 'r':
		 	 	 {
		 	 		 Reculer_robot();
		 	 	 }
		 	 	 break;
			//Fonction Arret du robot en mode manuel
		 	 case 's':
		 	 	 {
		 	 		 Arret_robot();
		 	 	 }
		 	 	 break;
			//selection du mode autonome du robot
		 	 case 'm':
		 	 {
		 		 Mode_auto();
		 	 }
		 	 default :
		 		 break;
		 }
	}
}

