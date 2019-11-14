// Programa : Sensor de presenca com modulo PIR
// Autor : Arduino e Cia

int pinopir = 3;  //Pino ligado ao sensor PIR
int acionamento;  //Variavel para guardar valor do sensor

void setup()
{
  pinMode(pinopir, INPUT);   //Define pino sensor como entrada
  Serial.begin(9600);
}

void loop()
{
 acionamento = digitalRead(pinopir);
 if (acionamento == LOW){
  Serial.println("Sem movimento");
 } else {
  Serial.println("Com movimento");
 }
 delay(500);
}
