#define Azul 10
#define AzulTerra 12
#define AzulBrilho 128

#define Vermelho 9
#define VermelhoTerra 8
#define VermelhoBrilho 128

#define Branco 11
#define BrancoTerra 13
#define BrancoBrilho 80

void setup() {
  // put your setup code here, to run once:
  pinMode(Azul, OUTPUT);
  pinMode(AzulTerra, OUTPUT);  
  analogWrite(AzulTerra, 0);

  pinMode(Vermelho, OUTPUT);
  pinMode(VermelhoTerra, OUTPUT);  
  analogWrite(VermelhoTerra, 0);

  pinMode(Branco, OUTPUT);
  pinMode(BrancoTerra, OUTPUT);  
  analogWrite(BrancoTerra, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  analogWrite(Azul, AzulBrilho);
  analogWrite(Vermelho, VermelhoBrilho);  
  analogWrite(Branco, BrancoBrilho);
  delay(1000);
  analogWrite(Azul, 0);
  analogWrite(Vermelho, 0);
  analogWrite(Branco, 0);
}
