#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>

/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */
int botaoOff = 4;
int botaoOn = 5;
int LED = 8;

IRsend irsend;

void setup()
{
  digitalWrite(botaoOff, INPUT_PULLUP);
  digitalWrite(botaoOn, INPUT_PULLUP);
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
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  if(digitalRead(botaoOff) == LOW){
    unsigned int irSignal[] = {4428, 4264, 560, 1604, 504, 584, 560, 1604, 556, 1608, 584, 500, 612, 476, 612, 1552, 584, 504, 584, 500, 584, 1580, 612, 472, 588, 500, 612, 1552, 584, 1576, 588, 500, 612, 1556, 580, 504, 584, 1580, 608, 1556, 608, 1556, 608, 1556, 584, 500, 612, 1552, 612, 1556, 604, 1556, 612, 476, 584, 500, 584, 504, 580, 504, 608, 1556, 600, 488, 580, 508, 548, 1612, 584, 1580, 608, 1556, 584, 504, 580, 504, 580, 508, 552, 536, 576, 508, 476, 608, 580, 508, 576, 508, 556, 1608, 580, 1584, 580, 1584, 580, 1584, 556, 1608, 508, 5204, 4348, 4340, 552, 1612, 576, 508, 552, 1612, 552, 1612, 552, 536, 548, 536, 552, 1612, 552, 536, 476, 608, 552, 1612, 552, 532, 552, 536, 548, 1616, 548, 1616, 548, 536, 552, 1616, 476, 608, 548, 1616, 548, 1612, 552, 1612, 552, 1612, 556, 532, 576, 1588, 576, 1588, 520, 1644, 576, 508, 580, 508, 552, 532, 580, 508, 552, 1612, 580, 504, 580, 508, 524, 1636, 584, 1580, 584, 1580, 584, 504, 580, 504, 584, 504, 584, 500, 584, 504, 552, 532, 584, 504, 584, 500, 584, 1580, 584, 1580, 584, 1580, 584, 1580, 556, 1612, 548};
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array. 
    Serial.println("1");
    led(botaoOff);
  } else if(digitalRead(botaoOn) == LOW){
    unsigned int irSignal[] = {4452, 4240, 536, 1628, 536, 552, 560, 1604, 532, 1632, 588, 500, 560, 524, 584, 1580, 560, 528, 588, 496, 584, 1580, 560, 528, 584, 500, 616, 1548, 560, 1604, 560, 528, 584, 1580, 584, 500, 588, 500, 584, 500, 584, 1580, 564, 1600, 560, 1604, 560, 1604, 560, 1608, 556, 1604, 560, 1604, 560, 1604, 612, 476, 560, 524, 560, 528, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 1604, 560, 1608, 560, 1604, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 528, 560, 524, 560, 528, 560, 528, 556, 1604, 560, 1604, 560, 1604, 476, 5236, 4292, 4396, 560, 1604, 560, 528, 556, 1604, 560, 1608, 556, 528, 560, 528, 556, 1604, 560, 528, 556, 532, 556, 1604, 560, 528, 556, 528, 560, 1604, 560, 1604, 560, 528, 556, 1608, 556, 528, 560, 528, 556, 528, 560, 1604, 560, 1604, 556, 1608, 560, 1604, 556, 1608, 556, 1608, 556, 1608, 556, 1608, 556, 528, 560, 528, 556, 528, 560, 528, 556, 532, 552, 532, 556, 1604, 560, 1604, 560, 1604, 560, 1604, 556, 532, 556, 528, 556, 532, 552, 1608, 560, 528, 556, 528, 556, 532, 556, 528, 556, 1608, 556, 1608, 556, 1608, 552};
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
    Serial.println("1");
    led(botaoOn);
  }
}
