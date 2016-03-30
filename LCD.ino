/**************************************************************
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
 
void UpdateLCD() //Just for test porpouses
{
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Hola! que pasa "); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(4, 1, "Calabaza");
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
}

void UpdateLCDline0(char* line0)
{
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, line0); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
}

void UpdateLCDline1(char* line1)
{
  //lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 1, line1); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
}
