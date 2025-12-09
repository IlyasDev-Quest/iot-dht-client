# 🌡️ IoT DHT Client

## 📖 Description

**iot-dht-client** is an IoT project built to connect with the backend provided in the **iot-dht-project**.  
It reads temperature and humidity data from a DHT sensor, serializes it into JSON, and sends it over HTTP to the backend for storage and processing.

---

## 🛠️ Requirements

- 💻 Visual Studio Code  
- 🔌 PlatformIO extension installed  
- 🌡️ DHT11 sensor  
- 📡 ESP8266 board (e.g., ESP-01 1M, NodeMCU, Wemos D1 Mini)

---

## 🚀 Getting Started

### 1. Clone the Repository
Run:
```
git clone https://github.com/IlyasDev-Quest/iot-dht-client.git
cd iot-dht-client
```

### 2. Configure Your Secrets
Copy the example secrets file and set your WiFi and API configuration:
```
cp include/secrets.example.h include/secrets.h
```

Edit `include/secrets.h` and update the following:

```cpp
#pragma once

#define WIFI_SSID "YourWiFiName"
#define WIFI_PASSWORD "YourWiFiPassword"
#define API_URL "https://webhook.site/aef17cb1-60e8-437d-9a8b-032201fd3529"
```

### 3. Open the Project in VS Code

- Launch Visual Studio Code.
- Open the project folder you just cloned.
- Ensure the PlatformIO extension is installed and initialized.

### 4. Connect Your ESP8266 Board

- Plug your ESP8266 board into your computer via USB.
- Verify it is detected by PlatformIO.

### 5. Build and Upload the Firmware

- In VS Code, click `PlatformIO > Build` to compile the firmware.
- Click Upload to flash the firmware to your ESP8266.
- Open the Serial Monitor to view debug logs and sensor readings.

