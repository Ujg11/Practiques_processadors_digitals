# Pràctica 4: WIFI y BLUETOOTH

### Codi de la pràctica A

```c
#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "nom del wifi";  // Enter your SSID here
const char* password = "contrasenya del wifi";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
 Serial.begin(115200);
 Serial.println("Try Connecting to ");
 Serial.println(ssid);

 // Connect to your wi-fi modem
 WiFi.begin(ssid, password);

 // Check wi-fi is connected to wi-fi network
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected successfully");
 Serial.print("Got IP: ");
 Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

 server.on("/", handle_root);

 server.begin();
 Serial.println("HTTP server started");
 delay(100); 
}

void loop() {
 server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
 server.send(200, "text/html", HTML);
}
```
**Imatge de la Web:**

![Imatge De la web:](Foto_captura_web.png)

#### Informe


Wifi: El codi serveix per crear una pàgina web a partir d’una connexió entre el wifi generat a un dispositiu de la classe i el nostre microprocessador. Després,
buscant la IP d’un dels dispositius personals de qualsevol alumne, podiem accedir a les pàgines creades per les diferents ESP-32 que hi havia al laboratori.



### Codi de la pràctica B

```c
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
void setup() {
Serial.begin(115200);
SerialBT.begin("O_P"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
}
void loop() {
if (Serial.available()) {
SerialBT.write(Serial.read());
}
if (SerialBT.available()) {
Serial.write(SerialBT.read());
}
delay(20);
}

```

**Imatge de la conversa per Bluetooth:**


![Imatge conversa bluetooth: ](conversa_bluetooth.jpg)

#### Informe:
En aquesta part de la pràctica fem un programa que utilitza el bluetooth de la ESP32. Li diem al wifi el nom que vulguem, en aquest cas O_P i l'enllaçem amb el mòvil.
Un cop enllaçat, podem tenir un chat entre els dos dispositius com podem veure en la imatge.
