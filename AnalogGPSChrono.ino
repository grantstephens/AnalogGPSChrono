#include "NMEAGPS.h"
#include <SoftwareSerial.h>

SoftwareSerial ss(0, 30);
NMEAGPS gps;

void setup()
{
  ss.begin(9600);
  pinMode(1, OUTPUT);
  squareWave(200);
  delay(2500);
  squareWave(0);
}


void loop()
{
  if (gps.available( ss )) {
    const gps_fix & fix = gps.read();
    if (fix.valid.speed)
      speedProcess( fix.spd.whole ); // knots
  }
}

