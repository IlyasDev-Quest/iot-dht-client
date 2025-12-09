#include "JsonHelper.h"
#include <ArduinoJson.h>

String JsonHelper::createDhtJson(float temperature, float humidity)
{
    JsonDocument jsonDoc;
    jsonDoc["temperature"] = temperature;
    jsonDoc["humidity"] = humidity;

    String output;
    serializeJson(jsonDoc, output);
    return output;
}
