#include <Arduino.h>

volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);//funciona com a lock()
    interruptCounter++;//va contant segons desde que el programa es posa en marxa
    portEXIT_CRITICAL_ISR(&timerMux);//funciona com a unlock()
}

void setup() {
    Serial.begin(115200);

    timer = timerBegin(0, 80, true);//s'inicialitza
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000000, true);//fa fins a 1M i torna a començar
    timerAlarmEnable(timer);//quan arribi a 1M ens diu que esta habilitat
}

void loop() {
    if (interruptCounter > 0) {
        portENTER_CRITICAL(&timerMux);
        interruptCounter--;
        portEXIT_CRITICAL(&timerMux);
        totalInterruptCounter++;
        Serial.print("An interrupt as occurred. Total number: ");
        Serial.println(totalInterruptCounter);
    }
}

