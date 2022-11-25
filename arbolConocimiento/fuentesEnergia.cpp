#include <arduino.h>
int led = 5;
int motor = A2;
int fotocelda = A3;
int lectura;

//Pines para el piano
const int BOCINA = 2;
const int MUSICA = 33;
const int DO = 35;
const int RE = 37;
const int MI = 39;
const int FA = 41;
const int SOL = 43;
const int LA = 45;
const int SI = 46;
void setupFuentes(){
  pinMode(led, OUTPUT);
  pinMode(motor, INPUT);
  pinMode(fotocelda, INPUT);
  //pinMode(BOCINA, OUTPUT);
  pinMode(46, INPUT_PULLUP);
  for(int i = 33; i <= 47; i = i + 2){
    pinMode(i,INPUT_PULLUP);
    Serial.println(i);
  }
}

void eolico(){
  lectura = analogRead(motor);
  analogWrite(led ,map(lectura, 0, 50, 0, 255));
  delay(100);
}

void solar(){
  lectura = analogRead(fotocelda);
  analogWrite(led ,map(lectura, 220, 1000, 0,255));
  delay(100);
}
void midi(){
    tone(BOCINA, 391, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 329, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 329, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 254.25);
    delay(282.5);
    delay(17.5);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 440, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 864.0);
    delay(960.0);
    delay(240.0);
    tone(BOCINA, 293, 864.0);
    delay(960.0);
    delay(240.0);
    tone(BOCINA, 349, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 293, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 293, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 293, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 293, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 432.0);
    delay(480.0);
    delay(120.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 391, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 349, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 293, 216.0);
    delay(240.0);
    delay(60.0);
    tone(BOCINA, 329, 864.0);
    delay(960.0);
    delay(240.0);
    tone(BOCINA, 261, 864.0);
    delay(960.0);
}

void piano (){
  
  while(digitalRead(DO) == LOW){
    tone(BOCINA, 261.626, 100);
    Serial.println("Algodfo");
  }

  while(digitalRead(RE) == LOW){
    tone(BOCINA, 293.665, 100);
  }

  while(digitalRead(MI) == LOW){
    tone(BOCINA, 329.628, 100);
  }

  while(digitalRead(FA) == LOW){
    tone(BOCINA, 349.228, 100);
  }

  while(digitalRead(SOL) == LOW){
    tone(BOCINA,  391.995, 100);
  }

  while(digitalRead(LA) == LOW){
    tone(BOCINA, 440, 100);
  }
  
  while(digitalRead(SI) == LOW){
    tone(BOCINA,  493.883, 100);
  }
  
  if(digitalRead(MUSICA) == LOW){
    midi();
  }
  noTone(BOCINA);
}



