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
