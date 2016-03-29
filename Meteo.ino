/**************************************************************
 **************************************************************
 * Output any data on LCD widget!
 *
 * App project setup:
 *   LCD widget, SIMPLE mode, in widget settings :
 *   - Select pin V0 for zero pin
 *   - Select pin V1 for first pin
 *   - Leave "Reading Frequency" on "1 sec" interval
 *   - Type into first edit field "/pin0/ seconds"
 *   - Type into second edit field "/pin1/ millis"
 *
 **************************************************************/
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <SimpleTimer.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "500663fc272e460eb5e7e2e49da34f14";

//Windgets
WidgetLCD lcd(V0);

// Mapeado
//const int BMP085_PIN = A4y5;


//Instances
SimpleTimer timer;
Adafruit_BMP085 bmp;

//Variables Global
int milisegundos;
int lastSeconds = 0;
int segundos;
float segundosAcu;
float minutos;
float horas;
float dias;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

  //Timers
  timer.setInterval(1000L, UpdateLCD); //LCD AT V0

  //
  //BMP085
  bmp.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
  Blynk.run();
  timer.run(); 

  segundos = millis()/1000;
  


  
}
