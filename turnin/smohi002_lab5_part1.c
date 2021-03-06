/*	Author: Sana
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 5 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

//Demo link: https://drive.google.com/open?id=1tqnwOTxXG0Tx4HW4N-f5frwu5mH4r67y

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //Configure A's 8 pins as outputs, initialize to 0s
	DDRC = 0xFF; PORTC = 0x00; //Configure C's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	//Read input	

	tmpA = ~PINA & 0x0F;
	tmpC = 0x40;

	if ((tmpA == 0x01) || (tmpA == 0x02))
		tmpC = 0x60;
	else if ((tmpA == 0x03) || (tmpA == 0x04))
                tmpC = 0x70;
	else if ((tmpA == 0x05) || (tmpA == 0x06))
                tmpC = 0x38;
	else if ((tmpA == 0x07) || (tmpA == 0x08) || (tmpA == 0x09))
                tmpC = 0x3C;
	else if ((tmpA == 0x0A) || (tmpA == 0x0B) || (tmpA == 0x0C))
                tmpC = 0x3E;
	else if ((tmpA == 0x0D) || (tmpA == 0x0E) || (tmpA == 0x0F))
                tmpC = 0x3F;

	PORTC = tmpC;

    }
    return 1;
}
