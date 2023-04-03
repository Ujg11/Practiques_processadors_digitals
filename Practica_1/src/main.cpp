#include <Arduino.h>
#include <stdio.h>


int pin_led = 1;

void setup() {
   pinMode(pin_led, OUTPUT);
   //Serial.begin(115200);
}

void loop() {
    digitalWrite(pin_led, HIGH);
    delay(500);
    //Serial.println("ON");
    digitalWrite(pin_led, LOW);
    delay(500);
    //Serial.println("OFF");
}