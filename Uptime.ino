 /* BLYNK_WRITE(V31)
  {
    lastSeconds = param.asInt();
  }
*/
void uptime(){
  //TODO: Program a clock :)
  //Then show only variables
  }

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
  minutos = (milisegundos/60000) + (segundos/60);
  Blynk.virtualWrite(V30,minutos);
  
}

//Horas
BLYNK_READ(V29)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (29)
  horas = (milisegundos/60000) + (minutos/60);
  Blynk.virtualWrite(V29,horas);
  
}

//Dias
BLYNK_READ(V28)
{
  // This command writes Arduino's uptime in minutes to Virtual Pin (28)
  dias = (milisegundos/60000) + (horas/24);
  Blynk.virtualWrite(V28,dias);
  
}
