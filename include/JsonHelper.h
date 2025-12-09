#pragma once
#include <Arduino.h>

class JsonHelper
{
public:
    static String createDhtJson(float temperature, float humidity);
};
