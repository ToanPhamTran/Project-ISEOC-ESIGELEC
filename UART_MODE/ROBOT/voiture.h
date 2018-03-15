/*
 * voiture.h
 *
 *  Created on: 9 mars 2018
 *      Author: q.blazejewski.14
 */

/*...................................................................................*/
/* void Init_Timer0()                                                               */
/*...................................................................................*/
/* Description : Initialisation Timer0                                     */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Init_Timer0();

/*...................................................................................*/
/* void Attente_Timer0()                                                            */
/*...................................................................................*/
/* Description : Tempo                                    */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Attente_Timer0();

/*...................................................................................*/
/* void Init_Timer1(unsigned int vM, unsigned int vA, unsigned int vB)                                                              */
/*...................................................................................*/
/* Description : Initialisation Timer1 vitesse robot                                 */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Init_Timer1(unsigned int vM, unsigned int vA, unsigned int vB);

/*...................................................................................*/
/* void Init_moteur()                                                               */
/*...................................................................................*/
/* Description : Initialisation du moteur                                       */
/* Inputs :                                                                          */
/*      - unsigned int vM, unsigned int vA, unsigned int vB                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Init_moteur();

/*...................................................................................*/
/* void Avancer(unsigned int vM, unsigned int vA, unsigned int time)                                                                  */
/*...................................................................................*/
/* Description : Permet au v�hicule d'avancer                                     */
/* Inputs :                                                                          */
/*      - unsigned int vM, unsigned int vA, unsigned int time                                                                  */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Avancer(unsigned int vM, unsigned int vA, unsigned int time, unsigned vB);

/*...................................................................................*/
/* void Tourner_gauche(unsigned int vM, unsigned int vA)                                                              */
/*...................................................................................*/
/* Description : Permet au robot de tourner a gauche                                      */
/* Inputs :                                                                          */
/*      - unsigned int vM, unsigned int vA                                                                     */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Tourner_gauche(unsigned int vM, unsigned int vA);

/*...................................................................................*/
/* void Tourner_droite(unsigned int vM, unsigned int vA)                                                            */
/*...................................................................................*/
/* Description : Permet azu robot de tourner � droite                                     */
/* Inputs :                                                                          */
/*      - unsigned int vM, unsigned int vA                                                                */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Tourner_droite(unsigned int vM, unsigned int vA);

/*...................................................................................*/
/* void Tourner_90_D()                                                               */
/*...................................................................................*/
/* Description : Rotation de 90� a droite du robot                                 */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Tourner_90_D();

/*...................................................................................*/
/* void Tourner_90_G()                                                              */
/*...................................................................................*/
/* Description : Rotation de 90� a gauche du robot                                      */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Tourner_90_G();

/*...................................................................................*/
/* void Reculer(unsigned int vM, unsigned int vA)                                                              */
/*...................................................................................*/
/* Description : Permet au robot de reculer                                     */
/* Inputs :                                                                          */
/*      - unsigned int vM, unsigned int vA                                                                     */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Reculer(unsigned int vM, unsigned int vA);

/*...................................................................................*/
/* void Stop_voiture()                                                               */
/*...................................................................................*/
/* Description : Permet au robot de s'arr�ter                                      */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Stop_voiture();

/*...................................................................................*/
/* void UART()
 * .............................................................................*/
/* Description : Etablir connection UART                                      */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void UART();

/*...................................................................................*/
/* void SPI()                                                               */
/*...................................................................................*/
/* Description : Etablir connection SPI                                       */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void SPI();

/*...................................................................................*/
/* void Detection_obstacle()                                                               */
/*...................................................................................*/
/* Description : Detecter les obstacles en fonction du signal Infrarouge                                     */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/

void Detection_obstacle();
