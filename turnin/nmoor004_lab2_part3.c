/*	Author: nmoor004
 *  Partner(s) Name: none
 *	Lab Section:
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
	DDRA = 0x00; PORTA = 0xFF;  // Set PORTA as input pins.
	DDRC = 0xFF; PORTC = 0x00; //Set PORTC as output pins.
    /* Insert your solution below */
	unsigned char temp_val = 0x00;    // Stores the value of PINA
	//unsigned char check_val = 0x01;  // Value which is used to check the first bit
	unsigned char cntavail = 0x04;  // How many spaces are available
	int num_parked = 0;

	    while (1) {
		temp_val = PINA;

		while (temp_val != 0x00) {	// Inner while loop which checks bit 0 of temp_val and
					       // right shifts temp_val so that the next bit can be checked;
					      // then it increments num_parked if bit 0 is 1.	
			if ((temp_val & 0x01) == 0x01) {
			   num_parked++;
			}
			temp_val = temp_val >> 1;
		}
		
		
		 if (num_parked == 1) { // Check the number of cars parked and assign cntavail!
			cntavail = 0x03;
		}
		else if (num_parked == 2) {
			cntavail = 0x02;
		}
		else if (num_parked == 3) {
			cntavail = 0x01;
		}
		else if (num_parked == 4) {
			cntavail = 0x00;
			cntavail = cntavail | 0x90; //By using ORing cntavail with 0x90, we set PC7 to 1, thus
						   // indicating a full parking lot.
		}
		else {
			cntavail = 0x04;
		}

		num_parked = 0x00; //Reset for the while loop
		PORTC = cntavail;


    }
    return 1;
}
