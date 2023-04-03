# PRACTICA 2B - Interrupción por timer

A continuación se muestra un vídeo del funcionamiento de la practica:
[![IMAGE ALT TEXT](https://user-images.githubusercontent.com/125595278/228276521-23af8e58-4edf-4e23-aa8b-f4e6ba9a2187.jpg)](https://www.youtube.com/watch?v=WwuuoC3X09A)


### Funcionamiento del código

En aquest cas el programa conta el nombre d'interrupcions que hi ha. En el programa hi ha zones crítiques i per aconseguir que aquestes no afectin utilitzem
"portENTER_CRITICAL_ISR(&timerMux)" que funciona com un lock i "portEXIT_CRITICAL_ISR(&timerMux)" que funciona com a unlock. D'aquesta manera, amb el contador dins la 
zona crítica **interruptCounter** es va controlant el nombre total d'interrupcions i quan aquesta val més que 0, la variable **totalInterruptCounter** es suma una unitat
i es mostra per pantalla.
