#include <Arduino.h>
#include "HX711.h"

const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

const int LOADCELL_DOUT_PIN2 = 14;
const int LOADCELL_SCK_PIN2 = 15;

HX711 scale1;
HX711 scale2;
int avg1 = 0, avg2 = 0;
long reading1[11], reading2[11];

void setup() {
  Serial.begin(115200);
  scale1.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN2);

  scale1.set_scale();
  scale2.set_scale();
  scale1.tare();
  scale2.tare();
  delay(100);

  // input data 10개 평균 값 구하기.
  if (scale1.is_ready() && scale2.is_ready()) {
    for (int i = 0; i < 10; i++) {
      avg1 += scale1.get_units(10);
      avg2 += scale2.get_units(10);
    }
    avg1 /= 10;
    avg2 /= 10;
    Serial.println((String) "\n" + avg1 + ", " + avg2);
  }
  else {
    Serial.println("hx711 connect error");
  }

  Serial.println("3");
}

void loop() {
for (int i = 0; i < 10; i++) {
    reading1[i] = scale1.get_units(10);
    reading2[i] = scale2.get_units(10);
    if (reading1[i] < (reading1[i - 1] - avg1)) {
      Serial.println((String) "1, " + reading1);
    }
  }

  reading1[0] = reading1[i - 1];
  reading2[0] = reading2[i - 1];
  
//  delay(500);
}
