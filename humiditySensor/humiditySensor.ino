#include <DHT.h>

#define DHTPIN 17
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // Establishes serial communication between the arduino and another device
  Serial.begin(9600);

  delay(500);

  Serial.println("DHT11 Humidity + temperature sensor\n\n");

  dht.begin();  
  delay(5000);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\n");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("C\n");

  delay(30);
}
