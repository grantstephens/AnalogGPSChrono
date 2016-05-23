void speedProcess(float currentSpeed, bool valid)
{
  if (!valid) 
  {
    squareWave(100);
  }
  else
  {
    if (round(currentSpeed) != round(lastSpeed))
    {
      lastSpeed = currentSpeed;
      speedHz(currentSpeed);
      smartDelay(0);
    }
  }
}

void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}


void speedHz (float speedMPH)
{
  float iHz;
  if (speedMPH < 11) iHz = 0;
  else if (speedMPH > 40) iHz = 200;
  else iHz = map(speedMPH, 11, 40, 14, 200);
  squareWave(int(round(iHz)));
//  squareWave(speedMPH);
}



