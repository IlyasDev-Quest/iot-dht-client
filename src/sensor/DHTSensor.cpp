#include "DHTSensor.h"
#include <Arduino.h>

void DHTSensor::begin() {
  dht.begin();
  Serial.println("DHT sensor initialized.");
}

float DHTSensor::readTemperature() {
  return dht.readTemperature();
}

float DHTSensor::readHumidity() {
  return dht.readHumidity();
}
