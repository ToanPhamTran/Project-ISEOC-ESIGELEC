/*
 * Servomoteur_2231.h
 *
 *  Created on: 8 mars 2018
 *      Author: q.blazejewski.14
 */





//...................................................................................
// void Init_Timer(Vr)
//...................................................................................
// Description : Initialisation du signal PWM
// Inputs :
//      - int Vr : The value of TACCR1
// Output :
//      - void
//...................................................................................

void Init_Timer(Vr);

//...................................................................................
// void Init_Servo()
//...................................................................................
// Description : Initialisation of the Servomoteur
// Inputs :
//      - void
// Output :
//      - void
//...................................................................................

void Init_Servo();

//...................................................................................
// void Stop()
//...................................................................................
// Description : Stop the motor
// Inputs :
//      - void
// Output :
//      - void
//...................................................................................

void Stop();



