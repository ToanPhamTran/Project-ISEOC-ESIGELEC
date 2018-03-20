/* librairy program robots
 * function forward and stop
 */
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

// Description : Fonction permettant d'initialiser les ports utilisés pour le capteur IR et initatilise les registres de l'ADC

//Inputs :
//        - void
//Outputs :
//         -void
//***********************************************************************************************

void Init_Port(void);

void Init_capteur(void);

void Attente_Timer0(void);

void Sens_moteurA(int sens);

void Sens_moteurB(int sens);

void Avancer_robot();

void Tourner_gauche(void);

void Tourner_droite(void);

void Reculer_robot(void);

void Arret_robot(void);

int detection_obstacle(int capt);

int capteur();

int detection_distance(int tension);


