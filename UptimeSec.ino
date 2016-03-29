BLYNK_READ(17)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (17)
  Blynk.virtualWrite(17, millis() /1000);
}

