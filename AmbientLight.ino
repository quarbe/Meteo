BLYNK_READ(0) //A0
  {
    //This command writes Arduino's Ambient Light in % to Virtual Pin (0)
    //Lux: Analog value from 0 to 470 (aprox).
    //0 = Full Light, 470 = Full Dark
    int LuxInPercent = map(analogRead(0),470,0,0,100);
  
    Blynk.virtualWrite(0,LuxInPercent);
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
