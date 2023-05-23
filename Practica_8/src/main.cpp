#include <Arduino.h>

void setup() {
  Serial.begin(115200); // Inicializa la comunicación serial por el puerto 0
  Serial2.begin(115200, SERIAL_8O1); // Inicializa la comunicación serial por el puerto 2, 0O1 paridad
}

void loop() {
  if (Serial.available()) { // Si hay datos disponibles en el puerto 0
    char data = Serial.read(); // Lee el dato
    Serial2.write(data); // Escribe el dato en el puerto 2
  }

  if (Serial2.available()) { // Si hay datos disponibles en el puerto 2
    char data = Serial2.read(); // Lee el dato
    Serial.write(data); // Escribe el dato en el puerto 0
  }
}