
#ifndef FONCTION_ROBOT
#define FONCTION_ROBOT


#include <msp430.h>

// Description : Fonction permettant d'initialiser du timer 0
//Inputs :
//        - void
//Outputs :
//         -void
//***********************************************************************************************

void Init_Timer0(void);

// Description : Fonction permettant d'initialiser du timer de la vitesse du robot
//Inputs :
//        - void
//Outputs :
//         -void
//***********************************************************************************************

void Init_PWM(void);

// Description : Fonction permettant d'initialiser les ports du utilisé par le robot. 

//Inputs :
//        - void
//Outputs :
//         -void
//***********************************************************************************************

void Init_Port(void);

// Description : Fonction permettant d'initialiser les ports pour le capteur IR.
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Init_capteur(void);

// Description : Fonctionn permettant d'initialiser une fonction timer
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Attente_Timer0(void);

// Description : Fonction permettant d'initialiser les sens des roues du moteur A du robot 
//Inputs :
//        - int sens : valeur prenant 1 ou 0
//Outputs :
//         -void
//****************************************************************************

void Sens_moteurA(int sens);

// Description : Fonction permettant d"initialiser les sens des roues du moteur B du robot
//Inputs :
//        - int sens : valeur prenant 1 ou 0
//         -void
//****************************************************************************

void Sens_moteurB(int sens);

// Description : Fonction permettant de faire avancer le robot
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Avancer_robot();


// Description : Fonction permettant de faire tourner le robot à gauche le robot
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Tourner_gauche(void);

// Description : Fonction permettant de faire tourner le robot à droite le robot
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Tourner_droite(void);


// Description : Fonction permettant de faire reculer le robot
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Reculer_robot(void);


// Description : Fonction permettant d'arreter le robot
//Inputs :
//        - void
//Outputs :
//         -void
//****************************************************************************

void Arret_robot(void);

// Description : Fonction permettant de détecter un obstacle 
//Inputs :
//        - void
//Outputs :
//         - Retourne 1 si un obstacle est détecté ou retourne si 0 aucun obstacle n'est détecté
//****************************************************************************

int capteur();


// Description : Fonction permettant de lire la valeur du capteur et converti cette valeur en décimale
//Inputs :
//        - int capt : valeur du port où le capteur est relié au robot
//Outputs :
//         - retourne la valeur tension : valeur lu par le capteur et converti en décimale
//****************************************************************************

int detection_distance(int capt);

#endif
