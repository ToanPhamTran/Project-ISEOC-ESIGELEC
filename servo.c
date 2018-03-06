#include <msp430.h> 

/*
 * main.c
 */
unsigned char flag;
void initport()
{

	P1DIR &=~ BIT1; // on set le cable rouge en entree
	P1SEL |= BIT1;

	P1DIR &=~ BIT2; // on set le cable noir en entree
	P1SEL |= BIT2;

	P1DIR |= BIT3; // on set le cable jaune en sortie
	P1SEL |=BIT3;

	P1IES |= BIT3; // on force le bit num�ro 3 � z�ro. Qui permet de d�tecter le front descendant
	P1IFG &= (~BIT3); // v�rifie que le flag est � z�ro

}

void initTimer()
{

	TA0CTL |= TASSEL_2 + MC_1 + ID_0;
	TA0CCR0 = 20000;
	//TA0CCR1= 20000;


}
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    BCSCTL1= CALBC1_1MHZ;
      DCOCTL = CALDCO_1MHZ;
	initport();
	 __enable_interrupt();
	 do
	 {
		 if (flag==1)
		 {
			 initTimer();
			 TA0CCR1=1500;
			 __delay_cycles(100000);
			 TA0CCR1=10000;
			 __delay_cycles(100000);

		 }
		 else
			 TA0CCR1=500;

	 }while(1)
}

#pragma vector = PORT vector
__interupt void servo(void)
{

}