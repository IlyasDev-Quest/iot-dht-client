#include <Arduino.h>
#include "DHTSensor.h"
#include "WiFiManager.h"
#include "HttpClient.h"
#include "JsonHelper.h"
#include "secrets.h"

DHTSensor dhtSensor;
HttpClient httpClient;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Starting system...");
  
  WiFiManager::connectWiFi(); 
  dhtSensor.begin();  
}

void loop() {
  float temperature = dhtSensor.readTemperature();
  float humidity = dhtSensor.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    String payload = JsonHelper::createDhtJson(temperature, humidity);
    httpClient.sendJson(API_URL, payload); 

  } else {
    Serial.println("Failed to read from DHT sensor.");
  }
  delay(POST_INTERVAL_MS);
}
