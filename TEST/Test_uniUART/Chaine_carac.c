#include <msp430.h>

void InitUartPort()
{
    /*
     * Comunnication UART is located on P1.1 or P1.2
     */
    P1SEL |= (BIT1 + BIT2);                 // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= (BIT1 + BIT2);                // P1.1 = RXD, P1.2=TXD
}
void InitUART()
    {     P1DIR |= BIT0;
    /*
         * Comunnication UART is located on P1.1 or P1.2
         */
        P1SEL |= (BIT1 + BIT2);                 // P1.1 = RXD, P1.2=TXD
        P1SEL2 |= (BIT1 + BIT2);                // P1.1 = RXD, P1.2=TXD
        /*
         *  2 parameter for the connection UCA0CTL1 & UCACTL0
         *  UCSSEL_2 USCI clk Source
         */
        UCA0CTL1 |= UCSSEL_2;                   // SMCLK

        /*
         * Register UCAxBRx : register for CLK =F/dÈbit
         * UCA0BR0 is initialized
         */
        UCA0BR0 = 104;                          // frequency = 1MHz,  baud = 9600
        UCA0BR1 = 0;                            // 1MHz, 9600

        /*
         * UCPEN : Parity enable
         * UCPAR : Parity select
         * UCMSB : MSB first (MSB : " Most Significant Bit")
         */
        UCA0CTL0 &= ~UCPEN & ~UCPAR & ~UCMSB;
        /*
         * UC7BIT : Character Length
         * UCSPB : Stop Bit select
         * UCMODEx : USCI mode
         */
        UCA0CTL0 &= ~UC7BIT & ~UCSPB & ~UCMODE1;
        /*
         * UCMODEx : USCI mode
         * UCSYNC : Synchronous Mode Enable
         */
        UCA0CTL0 &= ~UCMODE0 & ~UCSYNC;
        /*
         * UCSWRST : Software Reset Enable
         */
        UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
        /*
         *
         */
        IE2 |= UCA0RXIE;                        // Enable USCI_A0 RX interrupt
    }


void afficher_caract(char *point, int taille)
{
    int i=0;
    for (i=0;i<taille;i++)
    {
        TXdata((unsigned char)point[i]);
    }
}


void main(){

        // Stop watchdog timer to prevent time out reset
        WDTCTL = WDTPW | WDTHOLD;

        if(CALBC1_1MHZ==0xFF || CALDCO_1MHZ==0xFF)
        {
            __bis_SR_register(LPM4_bits); // Low Power Mode #trap on Error
        }
        else
        {
            // Factory parameters
            BCSCTL1 = CALBC1_1MHZ;
            DCOCTL = CALDCO_1MHZ;
        }
InitUART();

        afficher_caract("Ceci est un test", 16);

while(1);

}




