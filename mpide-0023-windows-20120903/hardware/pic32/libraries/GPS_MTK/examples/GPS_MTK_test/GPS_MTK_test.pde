/*
  Example of GPS MTK library.
  Code by Jordi Mu�oz and Jose Julio. DIYDrones.com

  Works with Ardupilot Mega Hardware (GPS on Serial Port1)
  and with standard ATMega168 and ATMega328 on Serial Port 0
*/

#include <GPS_MTK.h> // UBLOX GPS Library

void setup()
{
  Serial.begin(38400);
  Serial.println("GPS MTK library test");
  GPS.Init();   // GPS Initialization
  delay(1000);
}
void loop()
{
  GPS.Read();
  if (GPS.NewData)  // New GPS data?
    {
    Serial.print("GPS:");
    Serial.print(" Lat:");
    Serial.print(GPS.Lattitude);
    Serial.print(" Lon:");
    Serial.print(GPS.Longitude);
    Serial.print(" Alt:");
    Serial.print((float)GPS.Altitude/100.0);
    Serial.print(" GSP:");
    Serial.print((float)GPS.Ground_Speed/100.0);
    Serial.print(" COG:");
    Serial.print(GPS.Ground_Course/1000000);
    Serial.print(" SAT:");
    Serial.print((int)GPS.NumSats);
    Serial.print(" FIX:");
    Serial.print((int)GPS.Fix);
    Serial.print(" TIM:");
    Serial.print(GPS.Time);
    Serial.println();
    GPS.NewData = 0; // We have readed the data
    }
  delay(20);
}
