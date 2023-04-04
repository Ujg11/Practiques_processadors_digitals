# Pràctica 6 part 3

### Codi

```c
#include <SPI.h>
#include <MFRC522.h>
#include <SD.h>

#define RST_PIN	17    //Pin 9 para el reset del RC522
#define SS_PIN	5   //Pin 5 para el SS (SDA) del RC522
#define SS_SD 4
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

File myFile;

const char *c = "/";

void WriteFile(const char * path, const char * message);

void setup() {
	Serial.begin(9600); //Iniciamos la comunicación  serial
	if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
	SPI.begin();        //Iniciamos el Bus SPI
	mfrc522.PCD_Init(); // Iniciamos  el MFRC522
	Serial.println("Lectura del UID");
}

void loop() {
  char *s="";
	// Revisamos si hay nuevas tarjetas  presentes
	if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
  		//Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print("Card UID:");
                  for (byte i = 0; i < mfrc522.uid.size; i++) { 
                          s = s ;
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                  } 
                  Serial.println();
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();

                  WriteFile(c,s);  //FALTA FER QUE LA S SIGUI EL TEXT CORRECTE
            } 
        }     
	}	

  void WriteFile(const char * path, const char * message){
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(path, FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.printf("Writing to %s ", path);
    myFile.println(message);
    myFile.close(); // close the file:
    Serial.println("completed.");
  } 
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening file ");
    Serial.println(path);
  }
}
```

### Informe

Aquest codi serveix per unificar el funcionament dels dos apartats anteriors utilitzant la microSD per guardar les dades de les targetes detectades amb el lector a un
fitxer. El codi està inacabat i donava algun error de lectura o de velocitat del processador.
