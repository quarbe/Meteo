// Keep this flag not to re-sync on every reconnection
bool isFirstConnect = true;

// This function will run every time Blynk connection is established
BLYNK_CONNECTED() {
  if (isFirstConnect) {
    // Request Blynk server to re-send latest values for all pins
    Blynk.syncAll();

    // You can also update an individual Virtual pin like this:
    //Blynk.syncVirtual(V0);

    isFirstConnect = false;
  }

  //Show Sync Time in LCD
  UpdateLCDClear();
  int syncTime = millis() / 1000;
  UpdateLCDline0("Sync Time: "); 
  UpdateLCDline1(String(syncTime, DEC));

}

//Variables to be synced
BLYNK_WRITE(V31)
{
  segundos = param.asInt();
  Serial.print("Seconds to sync: ");
  Serial.println(segundos);
}

BLYNK_WRITE(V30)
{
  minutos = param.asInt();
  Serial.print("Minutes to sync: ");
  Serial.println(minutos);
}

BLYNK_WRITE(V29)
{
  horas = param.asInt();
  Serial.print("Hours to sync: ");
  Serial.println(horas);
}

BLYNK_WRITE(V28)
{
  dias = param.asInt();
  Serial.print("Days to sync: ");
  Serial.println(dias);
}
