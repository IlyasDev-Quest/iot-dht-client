#pragma once
#include <Arduino.h>

class HttpClient {
public:
  void sendJson(const String &url, const String &json);
};
