// Keep this flag not to re-sync on every reconnection
bool isFirstConnect = true;

// This function will run every time Blynk connection is established
BLYNK_CONNECTED() {
  if (isFirstConnect) {
    // Request Blynk server to re-send latest values for all pins
   // Blynk.syncAll();

    // You can also update an individual Virtual pin like this:
    //Blynk.syncVirtual(V0);

    isFirstConnect = false;
  }

  //Here is running a few miliseconds
  //Retrieve last value from Sync

}

