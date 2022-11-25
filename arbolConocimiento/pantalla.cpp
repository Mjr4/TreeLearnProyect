
#include <arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setupLcd() {
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
  // Escribimos el Mensaje en el LCD.
  lcd.setCursor(0,0);
  lcd.print("Experiencia:");
}

void mostrarMensaje(String mensaje){
  lcd.setCursor(0,1);
  lcd.print(mensaje);
  delay(100);
}
