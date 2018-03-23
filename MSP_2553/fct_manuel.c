#include <msp430.h> 
#include "uart.h"
#include "fct_robot.h"
#include <string.h>
#include <stdio.h>

/*
 * main.c
 * test for mode manu
 */
void Fonction_manuel()
{
    Init_Port();
    Init_PWM();
	Init_UART();
	Arret_robot();


	__enable_interrupt();
	while(1);
}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR()
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
		 sprintf(car,"1. Avancer le robot, veuillez saisir a %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"2. Tourner à droite le robot, veuillez saisir d %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"3. Tourner à gauche le robot, veuillez saisir g %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"4. Reculer le robot, veuillez saisir r %s","\r\n");
		 afficher_caract(car, strlen(car));
		 sprintf(car,"5. Stoper le robot, veuillez saisir s %s","\r\n");
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
		 	 default :
		 		 break;
		 }
	}
}
