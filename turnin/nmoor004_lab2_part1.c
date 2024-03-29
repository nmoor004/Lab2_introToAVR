/*	Author: nmoor004
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab # 2 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	unsigned char temp_val = 0x00;
	    while (1) { 		// Set temp_val to the bits of PINA and check if it's first nibble is 0001.
		temp_val = PINA;

		if (temp_val == 0x01) {
			PORTB = temp_val;
		}
		else {
			PORTB = 0x00;
		}


    }
    return 1;
}
