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

  // Let's write your hardware uptime to Virtual Pin 2
  int value = millis() / 1000;
  Blynk.virtualWrite(V2, value);
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Blynk.virtualWrite(V2, value);
}
