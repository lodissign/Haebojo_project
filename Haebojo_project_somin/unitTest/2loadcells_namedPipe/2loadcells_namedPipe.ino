#include <Arduino.h>
#include "HX711.h"
//import os.path

const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

const int LOADCELL_DOUT_PIN2 = 14;
const int LOADCELL_SCK_PIN2 = 15;

HX711 scale;
HX711 scale2;

void setup() {
    Serial.begin(115200);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN2);
    
    scale.set_scale();
    scale2.set_scale();

    Serial.println("Tare. remove any weights");
    delay(500);
    scale.tare();
    scale2.tare();
    Serial.println("Tare done");
}

void loop() {
  if (scale.is_ready() && scale2.is_ready()){
    Serial.print("Place a known wieght");
    delay(500);
    long reading = scale.get_units(10);
    long reading2= scale2.get_units(10);

    Serial.println("...");
    Serial.println((String) "Result: " + reading + ", " + reading2);
  }
//  if (scale2.is_ready()){
//    scale2.set_scale();
//
//    Serial.println("Tare. remove");
//    delay(500);
//    scale2.tare();
//
//    Serial.println("Tare done");
//    Serial.print("Place a known wieght");
//    delay(500);
//    long reading2= scale2.get_units(10);
//
//    Serial.print("...");
//    Serial.println((String) "Result: " + reading2);
//  }
  else{
    Serial.println("hx711 connect error");
  }
  delay(500);
}
