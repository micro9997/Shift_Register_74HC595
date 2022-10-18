
avr-g++ -mmcu=atmega328p libraryTest.cpp src/shiftReg.cpp
avr-objcopy -O ihex a.out out.hex

rm a.out
