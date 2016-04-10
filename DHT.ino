// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
/*
 * double Humidity = 0;
double TempDHT = 0;
double HeatIndex = 0;
 */
BLYNK_READ(12) //leave min 3 seconds between consult
{

  
  Humidity = dht.readHumidity();
//  TempDHT = dht.readTemperature(false);//Celsius, true for F
  // Check if any reads failed and exit early (to try again).
 // if (isnan(Humidity) || isnan(TempDHT)) {
 //   Serial.println("Failed to read from DHT sensor!");
 //   return;
 // }

  // Compute heat index in Celsius (isFahreheit = false)
  //HeatIndex = dht.computeHeatIndex(TempDHT, Humidity, false);

      Blynk.virtualWrite(12,Humidity);
    //  Blynk.virtualWrite(24,TempDHT);
      Blynk.virtualWrite(25,HeatIndex);
}
