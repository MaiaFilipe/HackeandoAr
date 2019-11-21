#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


int botaoOnOff =4;
int botaoVolumeUp = 5;
int botaoVolumeDown = 6;
int LED = 8;

IRsend irsend;

void setup(){
  digitalWrite(botaoOnOff, INPUT_PULLUP);
  digitalWrite(botaoVolumeUp, INPUT_PULLUP);
  digitalWrite(botaoVolumeDown, INPUT_PULLUP);
  digitalWrite(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void led(int x){
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  digitalWrite(x, HIGH);
}

void loop() {
  if(digitalRead(botaoOnOff) == LOW){
    irsend.sendNEC(0x20DF02FD, 32); 
    Serial.println("1");
    led(botaoOnOff);
  } else if(digitalRead(botaoVolumeUp) == LOW){
    irsend.sendNEC(0x20DFD02F, 32);
    Serial.println("2");
    led(botaoVolumeUp);
  } else if(digitalRead(botaoVolumeDown) == LOW){
    irsend.sendNEC(0x20DFA857, 32);
    Serial.println("3");
    led(botaoVolumeDown);
}
}
