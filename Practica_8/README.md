# Pràctica 8

### Codi

```c
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
```

### Informe

El objetivo de la practica es realizar un bucle de comunicacion de forma que los datos que se manden por el terminal rxd0 se redirijan a la uart 2 txd2
( que debe estar conectado a rxd2 ) y la recepcion de los datos de la uart2 se reenvien de nuevo a la salida txd0 para que aparezcan en la pantalla del 
terminal. El codigo es muy sencillo y intuitivo, así que para poder ver realmente lo que está pasando a nivel físico en las conexiones hemos conectado
la entrada y la salida a un osciloscopio del laboratorio. A continuación adjuntamos una imagen que nos permite ver la gráfica de voltaje respecto al tiempo
según el caracter leído, se trata de la señal enviada correspondiente al carácter de la tecla presionada por nuestro ordenador en el puerto série. Si está
en algo representa un 1 lógico y un 0 en caso contrario. En la imagen está representada la letra M mayúscula en código ASCII

![ffea4726-4594-4902-be7b-937b64facc6b](https://github.com/paudresaire/p8/assets/125595278/e7ece0d0-fccf-4a1c-b5a5-957d0e3e6b30)
<img width="872" alt="ascii_table_lge" src="https://github.com/paudresaire/p8/assets/125595278/0fed2c79-faae-4171-969e-4cd534f71184">

