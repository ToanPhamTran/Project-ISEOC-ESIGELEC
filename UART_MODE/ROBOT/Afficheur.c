
#include "msp430.h"
#include "Afficheur.h"

/********************************/
/*        Pin connection        */
/********************************/
/* Connection for MSP430G2452   */
/*    MSP430    |    Display	*/
/*     P1.4     |      SSN      */
/*     P1.6     |      SDI       */
/*     P1.5     |      SCK      */
/*..............................*/
/* Connection for MSP430G2553   */
/*    MSP430    |    Display    */
/*     P1.4     |      SSN      */
/*     P1.7     |      SDI       */
/*     P1.5     |      SCK      */
/*..............................*/


/*...................................................................................*/
/* void Init_USI_SPI()                                                               */
/*...................................................................................*/
/* Description : Initialisation of the SPI bus                                       */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Init_USI_SPI()
{
  #if defined __MSP430G2452__
    P1DIR |= BIT4; // CS output
    P1OUT |= BIT4; // CS high
    USICTL0 = 0;
    USICTL0 |= (0 | USIOE | USIGE | USIMST | USIPE5 | USIPE6);
    USICTL1 |= (0 );
    USICKCTL |= (0 | USISSEL1 | USIDIV1 | USIDIV0);
  #elif defined __MSP430G2553__
    UCB0CTL1 = UCSWRST;
    P1DIR |= BIT4; // CS output
    P1OUT |= BIT4; // CS high
    P1SEL |= BIT7 + BIT5;  // Enable SIMO + SCLK
    P1SEL2 |= BIT7 + BIT5; // Enable SIMO + SCLK
    UCB0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
    UCB0CTL1 |= UCSSEL_2; // SMCLK
    UCB0CTL1 &= ~UCSWRST;
  #endif
}

/*...................................................................................*/
/* void Send_char_SPI(unsigned char carac)                                           */
/*...................................................................................*/
/* Description : Send a char via SPI                                                 */
/* Inputs :                                                                          */
/*      - unsigned char carac : the char to send                                     */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Send_char_SPI(unsigned char carac)
{
  #if defined __MSP430G2452__
    P1OUT &= ~BIT4;
    USISRL = carac;
    USICNT = 8;
    while ((USICTL1 & USIIFG) == 0);
    P1OUT |= BIT4;
  #elif defined __MSP430G2553__
    P1OUT &= ~BIT4;  // CS low
    UCB0TXBUF = carac; // Put caracter in transmit buffer
    while (!(IFG2 & UCB0TXIFG)); // USCI_A0 TX buffer ready?
    P1OUT |= BIT4; // CS high
  #endif
}




/*...................................................................................*/
/* void Aff_4carac(unsigned char buffer[4])                                       */
/*...................................................................................*/
/* Description : Display four characters                                             */
/* Inputs :                                                                          */
/*      - unsigned char buffer[4] : characters to display                            */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_4carac(unsigned char buffer[4])
{
  Send_char_SPI(buffer[0]);
  Send_char_SPI(buffer[1]);
  Send_char_SPI(buffer[2]);
  Send_char_SPI(buffer[3]);
}


/*...................................................................................*/
/* void Aff_Points(unsigned char code)                                           */
/*...................................................................................*/
/* Description : Swicth on points on the display                                     */
/* Inputs :                                                                          */
/*      - unsigned char code :  points to switch on                                  */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_Points(unsigned char code)
{
  Send_char_SPI(0x77);
  Send_char_SPI(code);
}



/*...................................................................................*/
/* void Aff_Efface()                                     */
/*...................................................................................*/
/* Description : Clear the display                                                   */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_Efface()
{
  Send_char_SPI(0x76);
  Aff_Points(0x00);
}

/*...................................................................................*/
/* void Aff_Luminosite(unsigned char lum)                                     */
/*...................................................................................*/
/* Description : Change the luminosity of the display                                */
/* Inputs :                                                                          */
/*      - unsigned char lum : Value of the luminosity between 0 (min) and 255 (max)  */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_Luminosite(unsigned char lum)
{
  Send_char_SPI(0x7A);
  Send_char_SPI(lum);
}


/*...................................................................................*/
/* void Aff_Init()                                                               */
/*...................................................................................*/
/* Description :Initializing of the display                                       */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_Init()
{
  Init_USI_SPI();
  Aff_Efface();
  Aff_4carac("8888");
  Aff_Points(0x3F);
  Aff_Luminosite(255);
  __delay_cycles(1000000);
  Aff_Efface();
}


/*...................................................................................*/
/* void Aff_1carac( unsigned char num, unsigned char code)                        */
/*...................................................................................*/
/* Description : Display only one character                                          */
/* Inputs :                                                                          */
/*      - unsigned char num : number of the character (between 1 and 4 )             */
/*      - unsigned char code : segments to swicth on                                 */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_1carac(unsigned char num, unsigned char code)
{
  num %=5;
  num +=0x7A;
  Send_char_SPI(num);
  Send_char_SPI(code);
}

/*...................................................................................*/
/* void convert_digit(int value)                                                      */
/*...................................................................................*/
/* Description : Use for an other fonction                                           */
/* Inputs :                                                                          */
/*      - int value: value of the digit you want to convert in ASCII                       */
/*                                                                                   */
/* Output : int  : value of the ASCII code of the digit                                                                    */
/*...................................................................................*/

int convert_digit(int value)                       // fonction de conversion en hexadecimal
{
	int valTens=0;

	if(value<=9) valTens = value +0x30;          // pour les unités

    else valTens = value +0x37;                  // pour les nombres > 9

	return valTens;
}


/*...................................................................................*/
/* void convert_ASCII(int c, buffer)                                                         */
/*...................................................................................*/
/* Description : Convert the value of an int in ASCII                                          */
/* Inputs :                                                                          */
/*      - int c: value of the number you want to convert  (unsigned)                           */
/*      - buffer : adress of the ASCII buffer to put the results                                                                             */
/* Output : void                							*/
/*...................................................................................*/

void convert_ASCII(int c, unsigned char hexa[4])
{

	int digit1,digit2,digit3,digit4;

	digit4= c & ( 0x000F);                     //  décalage de bit selon le digit
	digit3=(c & ( 0x00F0))>>0x04;
	digit2=(c & ( 0x0F00))>>0x08;
	digit1=(c & ( 0xF000))>>0x0C;
	hexa[3]=convert_digit(digit4);		  // placement dans un tableau de 4 caractères + conversion
	hexa[2]=convert_digit(digit3);
	hexa[1]=convert_digit(digit2);
	hexa[0]=convert_digit(digit1);

}


/*...................................................................................*/
/* void convert_Hex_Dec(int valeur_hex)                                            */
/*...................................................................................*/
/* Description : Convert an hexadecimal to decimal                                   */
/* Inputs :                                                                          */
/*      - char toExtract[]: value of the number in hexadecimal you want to convert   */
/*                                                                                   */
/* Output : char                                                                     */
/*...................................................................................*/
int convert_Hex_Dec(int valeur_hex)
{
	unsigned char dec [4];
        int val_dec;
	dec[0]= valeur_hex / 0x03e8;
 	dec[1]= (valeur_hex % 0x03e8) / 0x64;
	dec[2]= (valeur_hex % 0x64) / 0x0A;
	dec[3]= (valeur_hex % 0x0A);
	val_dec= (dec[0]<<12) + (dec[1]<<8)+ (dec[2]<<4) + dec[3];
	return val_dec;


}


/*...................................................................................*/
/* void affiche_valeur(int av)                                                       */
/*...................................................................................*/
/* Description : Display a value without ASCII conversion                            */
/* Inputs :                                                                          */
/*      - int av: value of the number you want to display                            */
/*                                                                                   */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_valeur(int c)
{

	int digit1,digit2,digit3,digit4;
	unsigned char v[4];


	digit4= c & ( 0x000F);                     //  décalage de bit selon le digit
	digit3=(c & ( 0x00F0))>>0x04;
	digit2=(c & ( 0x0F00))>>0x08;
	digit1=(c & ( 0xF000))>>0x0C;
	v[3]=(digit4);			           // placement dans un tableau de 4 caractères + conversion
	v[2]=(digit3);
	v[1]=(digit2);
	v[0]=(digit1);
	Aff_4carac(v);                          // affichage du tableau

}
