 /* BLYNK_WRITE(V31)
  {
    lastSeconds = param.asInt();
  }
*/
void uptime(){
  //TODO: Program a clock :)
  //Then show only variables

  if (ms > (ms_before + 999)) 
  {
    ms_before = ms;
    segundos = segundos +1;
    Blynk.virtualWrite(V31,segundos); //Push mode, set up a Value Display with push mode read. Remember not send more than 10 values per second
  }

  if (segundos >= 59) 
  {
    segundos = 0; 
    minutos = minutos + 1;
    // This command writes Arduino's uptime in minutes to Virtual Pin (30)
    Blynk.virtualWrite(V30,minutos);
     
  }

  if (minutos >= 59)
  {
    minutos = 0;
    horas = horas + 1;
    Blynk.virtualWrite(V29,horas);
  }
  
  if (horas >= 23)
  {
    horas = 0;
    dias = dias + 1;
    Blynk.virtualWrite(V28,dias);
  }
}

/*
//Segundos
BLYNK_READ(V31)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (31)
  //lastSeconds = 0;
  
  Blynk.virtualWrite(V31,segundos);
 
}


//Minutes
BLYNK_READ(V30)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (30)
  Blynk.virtualWrite(V30,minutos);
  
}

//Horas
BLYNK_READ(V29)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (29)
  Blynk.virtualWrite(V29,horas);
}

//Dias
BLYNK_READ(V28)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (28)
  Blynk.virtualWrite(V28,dias);
}

*/
