# Practica 3 - Sistemas Operativos en Tiempo Real

# Ejercicio Práctico 1

Programar el siguiente código:

```
void setup()
{
Serial.begin(112500);
/* we create a new task here */
xTaskCreate(
anotherTask, /* Task function. */
"another Task", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL); /* Task handle to keep track of created task */
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
Serial.println("this is ESP32 Task");
delay(1000);
}
 
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
/* loop forever */
for(;;)
{
Serial.println("this is another Task");
delay(1000);
}
/* delete a task when finish,
this will never happen because this is infinity loop */
vTaskDelete( NULL );
}
```

### Describir la salida por el puerto série



### Explicar el funcionamiento

El programa consiste en crear una tarea con el nombre "another Task". 

# Ejercicio Práctico 2

Programa que enciende dos leds con tiempos de transición diferentes simultaniamente

```
#include <Arduino.h>

int pin_led1 = 23;
int pin_led2 = 22;



void anotherTask( void * parameter )
{
/* loop forever */

for(;;)
{
digitalWrite (pin_led1, HIGH);
vTaskDelay(1000 / portTICK_PERIOD_MS);
digitalWrite (pin_led1, LOW);
vTaskDelay(100 / portTICK_PERIOD_MS);

}
/* delete a task when finish,
this will never happen because this is infinity loop */
}


void setup()
{
Serial.begin(115200);
pinMode (pin_led1, OUTPUT);
pinMode (pin_led2, OUTPUT);
/* we create a new task here */
xTaskCreate(
anotherTask, /* Task function. */
"another Task", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL); /* Task handle to keep track of created task */
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
digitalWrite (pin_led2, HIGH);
vTaskDelay(300 / portTICK_PERIOD_MS);
digitalWrite (pin_led2, LOW);
vTaskDelay(300 / portTICK_PERIOD_MS);
}
```

### Vídeo que muestra el funcionamiento del código

[![IMAGE ALT TEXT](https://user-images.githubusercontent.com/125595278/228276521-23af8e58-4edf-4e23-aa8b-f4e6ba9a2187.jpg)](https://youtu.be/JYZZY1sFzr8)

