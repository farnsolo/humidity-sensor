/**
  CREDIT FOR CODE
  https://www.upesy.com/blogs/tutorials/how-to-connect-wifi-acces-point-with-esp32?srsltid=AfmBOoq8sbuA8UbCs4aUyirATI1X6n9QeE1sDV3_Dy5tEp4M3Ta2VLbW#

**/

#include <WiFi.h>

const char* ssid = "Test123";
const char* password = "wow12345";

//accesSerial.println("HelloWorld");
void setup() {
  
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("\nConnecting");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
