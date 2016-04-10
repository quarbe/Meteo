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
WidgetLCD lcd(V27);

// Mapeado
//const int BMP085_PIN = A4y5;
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

//Instances
SimpleTimer timer;
Adafruit_BMP085 bmp;
DHT dht(DHTPIN, DHTTYPE);

//Variables Global
//----- Uptime ----------
long ms;
double ms_before = 0;  
int segundos = 0;
int minutos = 0;
int horas = 0;
int dias = 0;
//----- BMP085 ----------
int pressure = 0;
int minPressure = 1013.25;
int maxPressure = -1;
double Temperature = 0;
double maxTemperature = 0;
double minTemperature = 0;
//----- Soil Mousture ------
int soilMousture = 0;
//DHT
double Humidity = 0;
double TempDHT = 0;
double HeatIndex = 0;


//----- Forecast  -------
//int forecast = 4;
//char* weather[] = {"stable","sunny","cloudy","unstable","thunderstorm","unknown"};

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

  //Timers
 // timer.setInterval(1000L, UpdateLCD); //LCD AT V0 - Update every second
 //UpdateLCD(); //Wellcome
//timer.setInterval(60000L, calcForecast); //calculate forecast every Minute
//timer.setInterval(60001L, titleForecast); //To line 0 - Update every Minute
//timer.setInterval(60002L, sendForecast); //To line 1 - Update every Minute
 

  //BMP085
  Serial.println("Starting BMP085...");
  bmp.begin();
 /* if (!bmp.begin()) 
  {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    Serial.println("Program will not work");
    while (true) {//wait forever}
  }
  */

  //DHT
  dht.begin();

/*  
  Serial.println("GREETINGS PROFESSOR FALKEN");
  Serial.println(" ");
  Serial.println("HELLO");
  Serial.println(" ");
  Serial.println("A STRANGE GAME.");
  Serial.println("THE ONLY WINNING MOVE IS");
  Serial.println("NOT TO PLAY.");
  Serial.println(" ");
  */
}

void loop() {
  // put your main code here, to run repeatedly: 
  Blynk.run();
 // timer.run(); 
  ms = millis(); //Always counting
  uptime();

  
}
