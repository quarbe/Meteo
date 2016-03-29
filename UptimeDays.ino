BLYNK_READ(6)
{
  // This command writes Arduino's uptime in days to Virtual Pin (6)
  Blynk.virtualWrite(6, millis() /86400000);
}

