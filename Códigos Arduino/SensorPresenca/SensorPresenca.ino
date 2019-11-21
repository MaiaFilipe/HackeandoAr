#define PIR 7
#define LED 8
 
int iniciaSensor = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() {
  iniciaSensor = digitalRead(PIR);
  Serial.print("Valor do Sensor PIR: "); 
  Serial.println(iniciaSensor);
  if(iniciaSensor == 1){
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(500);
}
