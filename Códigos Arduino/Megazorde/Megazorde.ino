//Definições do Emissor IR
// 3 reservado para o IR
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
IRsend irsend;
int terraIR = 4;
int khz = 38;

//Definições da pinagenm do PIR - Sensor de presença
#define PIR 6
#define PIRterra 7
#define PIR5v 5
int iniciaSensor = 0;
int tempoInativo = 0;

//Definições da pinagem do BMP180 - Sensor temperatura
#include <Adafruit_BMP085.h>
#include <Wire.h>
Adafruit_BMP085 bmp180;

//Definições dos s de controle
int ledRed = 9;
int ledBlu = 10;
int ledWhi = 11;
int terraledRed = 8;
int terraledBlu = 12;
int terraledWhi = 13;

//Definições ar-condicionado
boolean arLigado = false;

//Definições do ledBluetooth

void setup() {
  //PIR
  Serial.begin(9600);
  pinMode(PIRterra, OUTPUT);
  digitalWrite(PIRterra, LOW);
  pinMode(PIR5v, OUTPUT);
  digitalWrite(PIR5v, HIGH);

  //IR
  pinMode(terraIR, OUTPUT);
  digitalWrite(terraIR, LOW);
  
  //Terra dos 
  pinMode(terraledRed, OUTPUT);
  digitalWrite(terraledRed, LOW);
  pinMode(terraledBlu, OUTPUT);
  digitalWrite(terraledBlu, LOW);
  pinMode(terraledWhi, OUTPUT);
  digitalWrite(terraledWhi, LOW);
  Serial.println("Terra dos LEDs");
  
  //BMP180
  //if (!bmp180.begin()) {
  //  Serial.println("Sensor nao encontrado !!");
    //ledWhile (1){}
  //}
  
  //Liga  vermelho
  analogWrite(ledRed, 128);
  analogWrite(ledBlu, 128);
  analogWrite(ledWhi, 80);
  delay(2000);
  analogWrite(ledBlu, 0);
  analogWrite(ledWhi, 0);
  
  //Liga o ar-condicionado
  LigaAr();
}

//Função que retorna o valor do PIR
boolean Presenca() {
  iniciaSensor = digitalRead(PIR);
  if(iniciaSensor == 1){
    Serial.println("TRUE");
    return true;
  } else {
    Serial.println("FALSE");
    return false;
  }
}

//Função que retorna os valores do BMP180
float TempPres(){
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

//Função Ligar ar-condicionado
void LigaAr(){
  if(arLigado == false){
  unsigned int irSignal[] = {4452, 4240, 536, 1628, 536, 552, 560, 1604, 532, 1632, 588, 500, 560, 524, 584, 1580, 560, 528, 588, 496, 584, 1580, 560, 528, 584, 500, 616, 1548, 560, 1604, 560, 528, 584, 1580, 584, 500, 588, 500, 584, 500, 584, 1580, 564, 1600, 560, 1604, 560, 1604, 560, 1608, 556, 1604, 560, 1604, 560, 1604, 612, 476, 560, 524, 560, 528, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 1604, 560, 1608, 560, 1604, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 528, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 1604, 560, 1604, 476, 5236, 4292, 4396, 560, 1604, 560, 528, 556, 1604, 560, 1608, 556, 528, 560, 528, 556, 1604, 560, 528, 556, 532, 556, 1604, 560, 528, 556, 528, 560, 1604, 560, 1604, 560, 528, 556, 1608, 556, 528, 560, 528, 556, 528, 560, 1604, 560, 1604, 556, 1608, 560, 1604, 556, 1608, 556, 1608, 556, 1608, 556, 1608, 556, 528, 560, 528, 556, 528, 560, 528, 556, 532, 552, 532, 556, 1604, 560, 1604, 560, 1604, 560, 1604, 556, 532, 556, 528, 556, 532, 552, 1608, 560, 528, 556, 528, 556, 532, 556, 528, 556, 1608, 556, 1608, 556, 1608, 552};
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
    Serial.println("Ar Ligado!");
    arLigado = true;
    ledAzul(true);
  }
}

//Funçao Desligar ar-condicionado
void DesligaAr(){
  if(arLigado){
  unsigned int irSignal[] = {4428, 4264, 560, 1604, 504, 584, 560, 1604, 556, 1608, 584, 500, 612, 476, 612, 1552, 584, 504, 584, 500, 584, 1580, 612, 472, 588, 500, 612, 1552, 584, 1576, 588, 500, 612, 1556, 580, 504, 584, 1580, 608, 1556, 608, 1556, 608, 1556, 584, 500, 612, 1552, 612, 1556, 604, 1556, 612, 476, 584, 500, 584, 504, 580, 504, 608, 1556, 600, 488, 580, 508, 548, 1612, 584, 1580, 608, 1556, 584, 504, 580, 504, 580, 508, 552, 536, 576, 508, 476, 608, 580, 508, 576, 508, 556, 1608, 580, 1584, 580, 1584, 580, 1584, 556, 1608, 508, 5204, 4348, 4340, 552, 1612, 576, 508, 552, 1612, 552, 1612, 552, 536, 548, 536, 552, 1612, 552, 536, 476, 608, 552, 1612, 552, 532, 552, 536, 548, 1616, 548, 1616, 548, 536, 552, 1616, 476, 608, 548, 1616, 548, 1612, 552, 1612, 552, 1612, 556, 532, 576, 1588, 576, 1588, 520, 1644, 576, 508, 580, 508, 552, 532, 580, 508, 552, 1612, 580, 504, 580, 508, 524, 1636, 584, 1580, 584, 1580, 584, 504, 580, 504, 584, 504, 584, 500, 584, 504, 552, 532, 584, 504, 584, 500, 584, 1580, 584, 1580, 584, 1580, 584, 1580, 556, 1612, 548};
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);
    Serial.println("Ar desligado!");
    arLigado = false;
    ledAzul(false);
    delay(15000);
  }
}

void ledBranco(boolean ligar){
  if (ligar){
    analogWrite(ledWhi, 80);
  }
  else{
    analogWrite(ledWhi, 0);
  }
}

void ledAzul(boolean ligar){
  if (ligar){
    analogWrite(ledBlu, 128);
  }
  else{
    analogWrite(ledBlu, 0);
  }
}

//Função ledBluetooth
//Led azul

//Função Controle Presença
void controlePresenca(){  
  if(Presenca()){
    tempoInativo = 0;
    ledBranco(false);
    Serial.println("Ativo");
    LigaAr();
  }
  else {
    tempoInativo++;
    // Liga led branco
    ledBranco(true);
    Serial.print("Inativo por: ");
    Serial.println(tempoInativo);
    if(tempoInativo == 3){
      DesligaAr();
      unsigned long minutes = 60000L * 20;
      delay(minutes);
    }
  }
}

void loop() {
  controlePresenca();
  delay(5000);
  Serial.println("");
}
