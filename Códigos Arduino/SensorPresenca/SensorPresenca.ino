#define PIR 6
#define PIRterra 7
#define PIR5v 5

int iniciaSensor = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(PIRterra, OUTPUT);
  digitalWrite(PIRterra, LOW);
  pinMode(PIR5v, OUTPUT);
  digitalWrite(PIR5v, HIGH);
}
void loop() {
  iniciaSensor = digitalRead(PIR);
  Serial.println(iniciaSensor);
  if(iniciaSensor == 1){
    Serial.println("TRUE");
  } else {
    Serial.println("FALSE");
  }
  delay(500);
}
