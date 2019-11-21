#include <Thermistor.h>

Thermistor temp(A0); 
void setup() {
Serial.begin(9600);
}
void loop() {
int temperature = temp.getTemp();
Serial.print("Temperatura: ");
Serial.print(temperature);
Serial.println("°C");
delay(1000);
}
