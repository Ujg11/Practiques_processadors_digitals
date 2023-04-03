# Pràctica 1 - BLINK



### Codi de la pràctica:


```
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






### Diagrama de tiempo:








### En el programa que se ha realizado cual es el tiempo libre que tiene el procesador?







# Ejercicios voluntarios de mejora de nota
### Codi exercici voluntari

```
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
```

### Exercici voluntari:
Llegir el valor de un convertidor A/D de entrada; treurel per el port serie i treure el mateix valor per un altre pin
