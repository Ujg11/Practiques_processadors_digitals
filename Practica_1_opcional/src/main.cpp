#include <Arduino.h>

const int potPin = 34;
int potValue = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    potValue = analogRead(potPin);
    Serial.println(potValue);
    delay(500);
}