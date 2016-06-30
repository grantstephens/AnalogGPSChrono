static const uint16_t MIN_KNOTS =  10; // ~11 mph
static const uint16_t MAX_KNOTS =  35; // ~40 mph
static const uint16_t MIN_HZ    =  14;
static const uint16_t MAX_HZ    = 200;

void speedProcess( uint16_t knots )
{
  if (knots < MIN_KNOTS)
    knots = MIN_KNOTS;
  else if (knots > MAX_KNOTS)
    knots = MAX_KNOTS;

  // Simple Low-Pass filter with a window of 4 samples
  static uint16_t averageKnots = 0;
  averageKnots = (averageKnots * 3) / 4  + knots;
  knots = averageKnots / 4;

  // Map the 10-35 knots onto 14-200 Hz
  uint16_t iHz =
    ((knots - MIN_KNOTS) * (MAX_HZ-MIN_HZ)) / (MAX_KNOTS-MIN_KNOTS) + MIN_HZ;

  squareWave(iHz);
}

