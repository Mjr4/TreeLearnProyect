#include "fuentesEnergia.h"
#include "pantalla.h"

byte opcion = 0;
byte BTn1 = 22;
byte BTn2 = 24;
byte estado = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupFuentes();
  setupLcd();
  Serial.println("Paso la pantalla");
  pinMode(BTn1,INPUT);
  pinMode(BTn2,INPUT);
  
}

void loop() {
  if (digitalRead(BTn2) == HIGH){
    Seleccion(1);
  } 
  
  if (digitalRead(BTn1)== HIGH){
    opcion++;
    if (opcion == 4){
      opcion = 0;
    }
    Serial.println(opcion);
    delay(50);
    Seleccion(0);
  }
  delay(100);
}

void Seleccion(byte ini){
  if(opcion == 0){
      if(ini == 1){
        mostrarMensaje("Iniciando     ");
        Serial.println("Iniciando ");
        solarr();
      }else {
        mostrarMensaje("Energia Solar ");
        Serial.println("Solar");
      }
    }else if(opcion == 1){
      if(ini == 1){
        mostrarMensaje("Inciando      ");
        Serial.println("Iniciando     ");
        Eeolico();
      }else {
        mostrarMensaje("Energia Eolica ");
        Serial.println("Eolica");
      }

    }else if(opcion == 2){
      if(ini == 1){
        mostrarMensaje("Iniciando      ");
        Serial.println("Iniciando     ");
        pian();
      }else {
        mostrarMensaje("Piano         ");
        Serial.println("Piano");
      }
    }else if(opcion == 3){
      if(ini == 1){
        mostrarMensaje("Iniciando      ");
        Serial.println("Iniciando     ");
      }else {
        mostrarMensaje("Cerebro     ");
        Serial.println("Cerebro");
      }
    }
    delay(200);
}

void solarr(){
  int i = 0;
  delay(100);
  while (digitalRead(BTn2) == LOW){
    solar();
    digitalWrite(5, LOW);
  }
  delay(100);
  Seleccion(0);
}

void Eeolico(){
  delay(100);
  while (digitalRead(BTn2) == LOW){
    eolico();
  }
  delay(100);
  Serial.println("Experiencia");
  Seleccion(0);
}
void pian(){
  delay(100);
  Serial.println("Hola");
  while (digitalRead(BTn2) == LOW){
    piano();
  
  }
  delay(100);
  Serial.println("Experiencia");
  Seleccion(0);
}





