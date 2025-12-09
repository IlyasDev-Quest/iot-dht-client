#pragma once
#include <DHT.h>

class DHTSensor {
public:
  void begin();
  float readTemperature();
  float readHumidity();

private:
  DHT dht = DHT(DHTPIN, DHTTYPE);
};
