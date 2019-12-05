#include <Adafruit_BMP085.h>
#include <Wire.h>
Adafruit_BMP085 bmp180;
int mostrador = 0;
   
void setup() 
{
  Serial.begin(9600);
  if (!bmp180.begin()) 
  {
    Serial.println("Sensor nao encontrado !!");
    while (1) {}
  }
}
   
void loop() {
  Serial.print("Temperatura : ");
   if ( bmp180.readTemperature() < 10){
     Serial.print(bmp180.readTemperature());
     Serial.println(" C");
   }else{
     Serial.print(bmp180.readTemperature(),1);
     Serial.println(" C");
   }
     Serial.print("Altitude : ");
     Serial.print(bmp180.readAltitude());
     Serial.println(" m");
     Serial.print("Pressao : ");
     float Pa = bmp180.readPressure();
     float atm = (Pa/101325);
     Serial.print(atm);
     Serial.println(" Atm");
     Serial.print("Pressao : ");
     Serial.print(Pa);
     Serial.println(" Pa");
     Serial.println("");
}
