#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <math.h>

int pos = 0;
float lastSpeed = 0;

TinyGPSPlus gps;
SoftwareSerial ss(0, 30);

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
  speedProcess(gps.speed.mph(), gps.speed.isValid());
  smartDelay(10);
}
