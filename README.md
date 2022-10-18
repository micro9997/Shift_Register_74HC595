# Shift_Register_74HC595
Shift register (74HC595) library for ATMega328P with 16MHz crystal

&nbsp;

![image_1](https://github.com/micro9997/Shift_Register_74HC595/blob/master/images/image_1.gif)

&nbsp;

&nbsp;

### Test code

&nbsp;

```c
#define F_CPU 16000000

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "src/shiftReg.hpp"

using namespace mohan;

int main(void) {
    // Create an object
    ShiftReg firstSR(PORTD, 4, 6, 5);
    
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
```

&nbsp;
