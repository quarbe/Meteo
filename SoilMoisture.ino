BLYNK_READ(V1)
  {
    //This command writes Soil mousture in % to Virtual Pin (1)
    //humidity ground: Analog value from 0 to 1023 (aprox).
    //0 = dry, 1023 = Full water
    soilMousture = map(analogRead(A1),0,1023,100,0);
  
    Blynk.virtualWrite(V1,soilMousture);

    /*/debugging
    Serial.println(" Valor analogico: ");
    Serial.println(analogRead(1));
    Serial.println(" Valor %: ");
    Serial.println(soilMousture);
  /*
    //Led
    if (LuxInPercent < 30) {
     led8.on();
     led9.off();
    }
    else
    {
       led8.off();
      led9.on();
    }  
    */
  }
