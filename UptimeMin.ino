BLYNK_READ(18)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (18)
  Blynk.virtualWrite(18, millis() /60000);
}

