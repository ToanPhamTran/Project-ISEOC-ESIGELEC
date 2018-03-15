

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
void Init_USI_SPI();

/*...................................................................................*/
/* void Send_char_SPI(unsigned char carac)                                           */
/*...................................................................................*/
/* Description : Send a char via SPI                                                 */
/* Inputs :                                                                          */
/*      - unsigned char carac : the char to send                                     */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Send_char_SPI(unsigned char carac);





/*...................................................................................*/
/* void Aff_4carac(unsigned char buffer[4])                                       */
/*...................................................................................*/
/* Description : Display four characters                                             */
/* Inputs :                                                                          */
/*      - unsigned char buffer[4] : characters to display                            */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_4carac(unsigned char buffer[4]);



/*...................................................................................*/
/* void Aff_Points(unsigned char code)                                           */
/*...................................................................................*/
/* Description : Swicth on points on the display                                     */
/* Inputs :                                                                          */
/*      - unsigned char code :  points to switch on                                  */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_Points(unsigned char code);




/*...................................................................................*/
/* void Aff_Efface()                                     */
/*...................................................................................*/
/* Description : Clear the display                                                   */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_Efface();


/*...................................................................................*/
/* void Aff_Luminosite(unsigned char lum)                                     */
/*...................................................................................*/
/* Description : Change the luminosity of the display                                */
/* Inputs :                                                                          */
/*      - unsigned char lum : Value of the luminosity between 0 (min) and 255 (max)  */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_Luminosite(unsigned char lum);



/*...................................................................................*/
/* void Aff_Init()                                                               */
/*...................................................................................*/
/* Description :Initializing of the display                                       */
/* Inputs :                                                                          */
/*      - void                                                                       */
/* Output :                                                                          */
/*      - void                                                                       */
/*...................................................................................*/
void Aff_Init();



/*...................................................................................*/
/* void Aff_1carac( unsigned char num, unsigned char code)                        */
/*...................................................................................*/
/* Description : Display only one character                                          */
/* Inputs :                                                                          */
/*      - unsigned char num : number of the character (between 1 and 4 )             */
/*      - unsigned char code : segments to swicth on                                 */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_1carac(unsigned char num, unsigned char code);


/*...................................................................................*/
/* void convert_digit(int value)                                                      */
/*...................................................................................*/
/* Description : Use for an other fonction                                           */
/* Inputs :                                                                          */
/*      - int value: value of the digit you want to convert in ASCII                       */
/*                                                                                   */
/* Output : int  : value of the ASCII code of the digit                                                                    */
/*...................................................................................*/

int convert_digit(int value);                       // fonction de conversion en hexadecimal



/*...................................................................................*/
/* void convert_ASCII(int c, buffer)                                                         */
/*...................................................................................*/
/* Description : Convert the value of an int in ASCII                                          */
/* Inputs :                                                                          */
/*      - int c: value of the number you want to convert  (unsigned)                           */
/*      - buffer : adress of the ASCII buffer to put the results                                                                             */
/* Output : void                							*/
/*...................................................................................*/

void convert_ASCII(int c, unsigned char hexa[4]);



/*...................................................................................*/
/* void convert_Hex_Dec(int valeur_hex)                                            */
/*...................................................................................*/
/* Description : Convert an hexadecimal to decimal                                   */
/* Inputs :                                                                          */
/*      - char toExtract[]: value of the number in hexadecimal you want to convert   */
/*                                                                                   */
/* Output : char                                                                     */
/*...................................................................................*/
int convert_Hex_Dec(int valeur_hex);



/*...................................................................................*/
/* void affiche_valeur(int c)                                                       */
/*...................................................................................*/
/* Description : Display a value without ASCII conversion                            */
/* Inputs :                                                                          */
/*      - int c: value of the number you want to display                            */
/*                                                                                   */
/* Output : void                                                                     */
/*...................................................................................*/
void Aff_valeur(int c);
