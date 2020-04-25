/*	Author: Sana
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 5 Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

//Demo: https://drive.google.com/open?id=1tDtH40fvo9NRRloB6JTVYbzRWTpfmMR4

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, off, change, waitFall, waitRise} state;

      unsigned char tmpA;
      unsigned char flag = 0x00;

void Tick() {
	switch(state) {
		case start:
			state = off;
			break;
		case off:
			PORTB = 0x00;
			if (tmpA == 0x01) state = change;
			else		  state = off;
			break;
		case change:
			state = waitFall;
			break;
		case waitFall:
			if (tmpA == 0x01) state = waitFall;
			else		  state = waitRise;
			break;
		case waitRise:
			if (tmpA == 0x00) state = waitRise;
			else 		  state = change;
			break;
		default:
			PORTB = 0x00;
			state = start;
			break;
	};
	switch(state) {
		case off:					break;
		case change:
			if (flag == 0) {
				if (PORTB == 0x00) PORTB = 0x01;
				else if (PORTB == 0x01) PORTB = 0x03;
				else if (PORTB == 0x03) PORTB = 0x07;
				else if (PORTB == 0x07) PORTB = 0x0F;
				else if (PORTB == 0x0F) PORTB = 0x1F;
				else if (PORTB == 0x1F) PORTB = 0x3F;
				else if (PORTB == 0x3F) {PORTB = 0x00; flag = 0x01;}
			}
			else {
                                if (PORTB == 0x00) PORTB = 0x20;
                                else if (PORTB == 0x20) PORTB = 0x30;
                                else if (PORTB == 0x30) PORTB = 0x38;
                                else if (PORTB == 0x38) PORTB = 0x3C;
                                else if (PORTB == 0x3C) PORTB = 0x3E;
                                else if (PORTB == 0x3E) PORTB = 0x3F;
				else if (PORTB == 0x3F) {PORTB = 0x00; flag = 0x00;}
			}
			break;
		case waitFall:					break;
		case waitRise:					break;
		default:					break;
	};
}

int main(void) { 
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //PORTA = input
	DDRB = 0xFF; PORTB = 0x00; //PORTB = output

	flag = 0x00;
	state = start;

	while (1) {
		tmpA = ~PINA & 0x01;
		Tick();
	}
}
