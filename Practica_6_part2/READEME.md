# Pràctica 6 part 2

### Codi
```
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN	 17  //Pin 9 para el reset del RC522
#define SS_PIN	5   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522


void setup() {
	Serial.begin(9600); //Iniciamos la comunicación  serial
	SPI.begin();        //Iniciamos el Bus SPI
	mfrc522.PCD_Init(); // Iniciamos  el MFRC522
	Serial.println("Lectura del UID");
}

void loop() {
	// Revisamos si hay nuevas tarjetas  presentes
	if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
  		//Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print("Card UID:");
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                  } 
                  Serial.println();
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();         
            }      
	}	
}

```

### Describir la salida por el puerto série

La sortida del port serie son el numero de la targeta que hi passem amb un salt de linea. Cada vegada que hi passem una targeta apareix el seu numero de la forma seguant: Card UID: 66 E6 77 82 (per exemple).

### Explciar el funcionamiento

El codi consisteix en conectar el MFRC522 que és un lector de targetes al esp32. D'aquesta manera aconseguim veure els ID de les targetes i amb el bucle de la linea 
29 separem els nombres amb base hexadecimal  i hi introdueix un 0 o un espai segons calgui.
