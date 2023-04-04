# Pràctica 1 - BLINK



### Codi de la pràctica:


```c
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
   // Serial.println("ON");
    digitalWrite(pin_led, LOW);
    delay(500);
   // Serial.println("OFF");
}
```




### Fotografia del muntatge:

![image](https://user-images.githubusercontent.com/125595278/228271323-8b68768b-2fe1-4682-969f-68d08eb3e5ee.png)





### Diagrama de flujo:

![](Imatge_diagrama_flux.jpeg)





### Diagrama de tiempo:








### En el programa que se ha realizado cual es el tiempo libre que tiene el procesador?



