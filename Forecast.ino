/*

BLYNK_READ(16)
{
  Blynk.virtualWrite(16,forecast);
}


//Anounce: Forecast

void titleForecast() //linea0
{
  UpdateLCDline0("Forecast: "); //LCD AT V0 - Update every second
}

//Send update to LCD
void sendForecast() //Linea1
{
  UpdateLCDline1(weather[forecast]); //LCD AT V0 - Update every second
}

void calcForecast()
{
  forecast = sample(pressure);
}





 
/**********************************  sample  ***************************************
Input:   pressure 
Output:  an int containing the weather based on pressure
************************************************************************************/ 
/*

int sample(float pressure) {
 //Deben ser globales para que funcionen, pero no hay espacio para el array de samples, 
 //Crear otro algoritmo
 float pressureSamples[35]; //7x5 avg values, using minutos as variable
  int minuteCount = 0;
  bool firstRound = true;
  float pressureAvg[7];
  float dP_dt; 
 
  

  // Algorithm found here
  // http://www.freescale.com/files/sensors/doc/app_note/AN3914.pdf
  if (minuteCount > 180){
    minuteCount = 6;
  }
  pressureSamples[minuteCount] = pressure;
  //minuteCount++;
  minuteCount = minuteCount + 1;

  Serial.print("Minute Count: ");
  Serial.println(minuteCount);

  if (minuteCount == 5) {
    // Avg pressure in first 5 min, value averaged from 0 to 5 min.
    Serial.println("Avg pressure in first 5 min, value averaged from 0 to 5 min.");
    pressureAvg[0] = ((pressureSamples[1] + pressureSamples[2]
        + pressureSamples[3] + pressureSamples[4] + pressureSamples[5])
        / 5);
    Serial.print("Avg pressure in first 5 min: ");   
    Serial.println(pressureAvg[0]);
  } else if (minuteCount == 35) {
    // Avg pressure in 30 min, value averaged from 0 to 5 min.
    Serial.print("Avg pressure in 30 min, value averaged from 0 to 5 min."); 
    pressureAvg[1] = ((pressureSamples[30] + pressureSamples[31]
        + pressureSamples[32] + pressureSamples[33]
        + pressureSamples[34]) / 5);
    Serial.print("Avg pressure in 30 min: ");   
    Serial.println(pressureAvg[1]);
    float change = (pressureAvg[1] - pressureAvg[0]);
    if (firstRound) // first time initial 3 hour
      dP_dt = ((65.0 / 1023.0) * 2 * change); // note this is for t = 0.5hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 1.5); // divide by 1.5 as this is the difference in time from 0 value.
  } else if (minuteCount == 60) {
    // Avg pressure at end of the hour, value averaged from 0 to 5 min.
    pressureAvg[2] = ((pressureSamples[55] + pressureSamples[56]
        + pressureSamples[57] + pressureSamples[58]
        + pressureSamples[59]) / 5);
    float change = (pressureAvg[2] - pressureAvg[0]);
    if (firstRound) //first time initial 3 hour
      dP_dt = ((65.0 / 1023.0) * change); //note this is for t = 1 hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 2); //divide by 2 as this is the difference in time from 0 value
  } else if (minuteCount == 95) {
    // Avg pressure at end of the hour, value averaged from 0 to 5 min.
    Serial.println("Avg pressure at end of the hour, value averaged from 0 to 5 min.");
    pressureAvg[3] = ((pressureSamples[90] + pressureSamples[91]
        + pressureSamples[92] + pressureSamples[93]
        + pressureSamples[94]) / 5);
    float change = (pressureAvg[3] - pressureAvg[0]);
    if (firstRound) // first time initial 3 hour
      dP_dt = (((65.0 / 1023.0) * change) / 1.5); // note this is for t = 1.5 hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 2.5); // divide by 2.5 as this is the difference in time from 0 value
  } else if (minuteCount == 120) {
    // Avg pressure at end of the hour, value averaged from 0 to 5 min.
    Serial.println("Avg pressure at end of the hour, value averaged from 0 to 5 min.");
    pressureAvg[4] = ((pressureSamples[115] + pressureSamples[116]
        + pressureSamples[117] + pressureSamples[118]
        + pressureSamples[119]) / 5);
    float change = (pressureAvg[4] - pressureAvg[0]);
    if (firstRound) // first time initial 3 hour
      dP_dt = (((65.0 / 1023.0) * change) / 2); // note this is for t = 2 hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 3); // divide by 3 as this is the difference in time from 0 value
  } else if (minuteCount == 155) {
    // Avg pressure at end of the hour, value averaged from 0 to 5 min.
    Serial.println("Avg pressure at end of the hour, value averaged from 0 to 5 min.");
    pressureAvg[5] = ((pressureSamples[150] + pressureSamples[151]
        + pressureSamples[152] + pressureSamples[153]
        + pressureSamples[154]) / 5);
    float change = (pressureAvg[5] - pressureAvg[0]);
    if (firstRound) // first time initial 3 hour
      dP_dt = (((65.0 / 1023.0) * change) / 2.5); // note this is for t = 2.5 hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 3.5); // divide by 3.5 as this is the difference in time from 0 value
  } else if (minuteCount == 180) {
    // Avg pressure at end of the hour, value averaged from 0 to 5 min.
    Serial.println("Avg pressure at end of the hour, value averaged from 0 to 5 min.");
    pressureAvg[6] = ((pressureSamples[175] + pressureSamples[176]
        + pressureSamples[177] + pressureSamples[178]
        + pressureSamples[179]) / 5);
    float change = (pressureAvg[6] - pressureAvg[0]);
    if (firstRound) // first time initial 3 hour
      dP_dt = (((65.0 / 1023.0) * change) / 3); // note this is for t = 3 hour
    else
      dP_dt = (((65.0 / 1023.0) * change) / 4); // divide by 4 as this is the difference in time from 0 value
    pressureAvg[0] = pressureAvg[5]; // Equating the pressure at 0 to the pressure at 2 hour after 3 hours have past.
    firstRound = false; // flag to let you know that this is on the past 3 hour mark. Initialized to 0 outside main loop.
  }

  if (minuteCount < 35 && firstRound) //if time is less than 35 min on the first 3 hour interval.
    return 5; // Unknown, more time needed
  else if (dP_dt < (-0.25))
    return 4; // Quickly falling LP, Thunderstorm, not stable
  else if (dP_dt > 0.25)
    return 3; // Quickly rising HP, not stable weather
  else if ((dP_dt > (-0.25)) && (dP_dt < (-0.05)))
    return 2; // Slowly falling Low Pressure System, stable rainy weather
  else if ((dP_dt > 0.05) && (dP_dt < 0.25))
    return 1; // Slowly rising HP stable good weather
  else if ((dP_dt > (-0.05)) && (dP_dt < 0.05))
    return 0; // Stable weather
  else
    return 5; // Unknown
}


*/
