/*
 * main.c
 *
 *  Created on: 16 mars 2018
 *      Author: t.phamtran.14
 */
#include <msp430.h>
#include "fct_manuel.h"

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
    DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
    Fonction_manuel();

}

