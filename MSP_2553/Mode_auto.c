// main programm for testing the uart mode with the spi mode
// autor : Toan pham Tran
// date : 13/03/2018
//project : ISE-OC

// library use in this program
#include <msp430.h>
#include "spi_mode_master.h"
#include "uart.h"
#include <string.h>
#include <stdio.h>
#include"fct_robot.h"
/*
 * main.c
 */
void Mode_auto()
{


    int position;
    int distance;

    Init_UART();
    Init_PWM();
    Init_PortMaster();
    Init_Master();
    Init_Port();
    Init_capteur();


    do{
	   distance = detection_distance(3);
    	if(  distance != 614)
    	{

        	Balayage_servo('s');
        	position=capteur();
        	if (position == 0)
        	{
        		Avancer_robot();
        	}
        	if (position == 1 )
				{
        		Tourner_gauche();
				}

    	}

    }while(1);
}

