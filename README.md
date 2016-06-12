# AnalogGPSChrono

This is a piece of Arduino/ATTiny85 code for pulling the GPS speed of a standard serial and displaying it on a tachometer that is placed in a chronometer.

# Basics

Demo and description given on [youtube](https://www.youtube.com/watch?v=pP-rwahyP9g)

Essentially the ublox6 gives the ATtiny85 the GPS speed which the ATTiny85 translates to a square wave which the tachometer needs.

Tacho that I used is this one: [DX](http://www.dx.com/p/iztoss-b714-universal-motorcycle-modified-retro-led-backlight-tachometer-speedometer-tacho-gauge-420110#.V12kf0p97_h)- Has to run off 12V with a square wave signal centered around 0 and at least a 4V peak to peak swing.
GPS Chip: [DX](http://www.dx.com/p/gps-module-w-ceramic-passive-antenna-for-raspberry-pi-arduino-red-384916#.V12knEp97_h)- Runs perfectly off the ATTiny85

# Basic Code Stuff

The code uses the following 3 libraries:
1. [TinyGPS++](http://arduiniana.org/libraries/tinygpsplus/)
2. [TrinketTone](http://w8bh.net/avr/TrinketTone.pdf)*
3. [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore)
* Note that this was modified to be used in the program

The ATTiny85 had to use a crystal (16MHz) to keep the timing for the serial accurate. One pin goes to the signal line (via a capacitor and resistor- to get signal centered around 0) of the tachometer. The other pin is the RX from the GPS.

Also note that it is possible to program your ATTiny85 using your Arduino as the ISP- shown [here](http://highlowtech.org/?p=1695)

# TODO

There are a number of little odds and ends I would still like to do.
1. Possible filter over the output, just to smooth it a little, however this will cause a larger delay.
2. Make the speedo show the number of satellites it has found until it has a lock.
3. Cooler startup sequence.

# Finally

Any comments and contributions are most welcome.
