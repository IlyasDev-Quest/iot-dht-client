#include "HttpClient.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

void HttpClient::sendJson(const String &url, const String &json) {
    if (WiFi.status() != WL_CONNECTED) {
        #if DEBUG_HTTP
        Serial.println("WiFi not connected, skipping HTTP request.");
        #endif
        return;
    }

    WiFiClientSecure client;
    client.setInsecure();  // Skip SSL verification
    HTTPClient http;

    for (uint8_t attempt = 1; attempt <= HTTP_RETRIES; attempt++) {
        #if DEBUG_HTTP
        Serial.printf("[HTTP] Attempt %d of %d...\n", attempt, HTTP_RETRIES);
        Serial.println("URL: " + url);
        Serial.println("Payload: " + json);
        #endif

        http.begin(client, url);
        http.addHeader("Content-Type", "application/json");
        http.setTimeout(HTTP_TIMEOUT_MS);

        int httpResponseCode = http.POST(json);

        if (httpResponseCode > 0) {
            #if DEBUG_HTTP
            Serial.printf("[HTTP] Success: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println("Response: " + response);
            #endif
            http.end();
            return;
        } else {
            #if DEBUG_HTTP
            Serial.printf("[HTTP] Failed (code: %d). Retrying in %d ms...\n", httpResponseCode, HTTP_RETRY_DELAY_MS);
            #endif
            http.end();
            delay(HTTP_RETRY_DELAY_MS);
        }
    }

    #if DEBUG_HTTP
    Serial.println("[HTTP] All retries failed.");
    #endif
}
