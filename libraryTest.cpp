
#define F_CPU 16000000

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "src/shiftReg.hpp"

#define dataPin 4
#define clockPin 6
#define latchPin 5

using namespace mohan;

int main(void) {
    // Create an object
    ShiftReg firstSR(PORTD, dataPin, clockPin, latchPin);

    // Then use it
    while(1) {
        for(int i = 0; i < 8; i++) {
            uint8_t data = 1 << i;
            firstSR.shiftOut(LSBFIRST, data);
            _delay_ms(25);
        }
        for(int i = 6; i >= 1; i--) {
            uint8_t data = 1 << i;
            firstSR.shiftOut(LSBFIRST, data);
            _delay_ms(25);
        }
    }
    
    return 0;
}
