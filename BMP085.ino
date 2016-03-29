// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here
float lastPressure = -1;
int lastForecast = -1;
char* weather[] = {"stable","sunny","cloudy","unstable","thunderstorm","unknown"};
int minutes;
float pressureSamples[180];
int minuteCount = 0;
bool firstRound = true;
float pressureAvg[7];
float dP_dt;
int forecast;
int minPressure = 1013.25;
int maxPressure = 0;
//END BMP085

BLYNK_READ(4)
{
  
  // pressure of 1013.25 millibar = 101325 Pascal
  // This command writes Arduino's Pressure in Pa to Virtual Pin (4)
  Blynk.virtualWrite(4,bmp.readPressure()/100);

  if ((bmp.readPressure()/100)<minPressure)
  {
    minPressure = (bmp.readPressure()/100);
  }

  if ((bmp.readPressure()/100)>maxPressure)
  {
    maxPressure = (bmp.readPressure()/100);
  }
  Blynk.virtualWrite(14, minPressure);
  Blynk.virtualWrite(15, maxPressure);

}
