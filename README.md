# Shift_Register_74HC595
Shift register (74HC595) library for ATMega328P with 16MHz crystal oscillator.

*It's a simple C++ library to access the 74HC595 shift register by Atmel ATMega328P. It's created using the Object-Oriented Programming concept. So, anyone can create as many objects as they need and use them easily.*

*What is special here is that we can realize the features of C++ by understanding this. That's why it is written simply.*

```c
// Create an object
ShiftReg firstSR(PORTD, dataPin, clockPin, latchPin);

// Then access it easily
firstSR.shiftOut(LSBFIRST, data);
```

*'ShiftReg' is like a blueprint of the object. 'firstSR' is an object that is created by using that blueprint. So, we can create many objects by using this blueprint.*

&nbsp;

### On test

![image_1](https://github.com/micro9997/Shift_Register_74HC595/blob/master/images/image_1.gif)

&nbsp;

### Test code

```c
#define F_CPU 16000000

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "src/shiftReg.hpp"

#define dataPin     4
#define clockPin    6
#define latchPin    5

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
```

&nbsp;
