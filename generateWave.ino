void squareWave( uint16_t frequency )
{
  if (frequency == 0)
    TCCR1 = 0x90; // stop the counter
  else
  {
    uint32_t ocr           = F_CPU / frequency / 2;
    uint8_t  prescalarBits = 1;

    while (ocr > 255)
    {
      prescalarBits++;
      ocr /= 2;
    }
    TCCR1 = 0x90 | prescalarBits;
    OCR1C = ocr - 1; // Set the OCR
    bitWrite(TIMSK, OCIE1A, 1); // enable interrupt
  }
}

ISR(TIMER1_COMPA_vect)
{
}
