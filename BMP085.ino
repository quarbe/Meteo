// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here

//END BMP085

BLYNK_READ(V4)
{
  //Calc here, we send less work to the sensor
  pressure = bmp.readPressure()/100;
  // pressure of 1013.25 millibar = 101325 Pascal
  // This command writes Arduino's Pressure in Pa to Virtual Pin (4)
  Blynk.virtualWrite(V4,pressure);

  if (pressure<minPressure)
  {
    minPressure = pressure;
    Blynk.virtualWrite(V14, minPressure);
  }

  if (pressure>maxPressure)
  {
    maxPressure = pressure;
    Blynk.virtualWrite(V15, maxPressure);
  }
  
  

}
