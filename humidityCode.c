#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>

#define DHT11_PIN 3
// uint8_t unsigned integer of length 8 bits (byte)

void start_signal(void){
    // Set pin to Output
    pinMode(DHT11_PIN,OUTPUT);
    digitalWrite(DHT11_PIN, LOW);
    delay(18);
    digitalWrite(DHT11_PIN, HIGH);
    pinMode(DHT11_PIN, INPUT);
    // Perhaps redundant? leave in for now
    digitalWrite(DHT11_PIN, HIGH);
}

void read_dht11(void){
    uint16_t rawHumidity = 0;
    uint16_t rawTemperature = 0;
}
