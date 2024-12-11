#include <Wire.h>
#include <MAX30105.h>
#include <WiFi.h>
#include <esp_now.h>

// Initialize MAX30105 sensor
MAX30102 sensor;

// MAC Address of the receiver device (update if needed)
uint8_t broadcastAddress[] = {0xF8, 0xB3, 0xB7, 0x44, 0x58, 0x10};

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Last Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

// Variables for heart rate detection
int lastIRValue = 0;
unsigned long lastPulseTime = 0;
int pulseCount = 0;
float heartRate = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP-NOW Heart Rate Sender");

  // Initialize I2C for MAX30105
  Wire.begin(23, 22);  // SDA on GPIO 23, SCL on GPIO 22
  if (!sensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 not found. Check wiring.");
    while (1);  // Halt execution if sensor not found
  }

  // Configure the MAX30105 sensor
  sensor.setFIFOAverage(1);     // Minimal averaging for faster data
  sensor.setSampleRate(100);    // 100 samples per second
  sensor.setPulseWidth(69);     // Shortest pulse width (69 µs)
  sensor.setPulseAmplitudeRed(0x1F);
  sensor.setPulseAmplitudeIR(0x1F);
  Serial.println("MAX30105 configured.");

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);

  // Register the peer
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
  Serial.println("ESP-NOW initialized.");
}

void loop() {
  // Check for new data from MAX30105

  // if (sensor.check()) {
    int irValue = sensor.getIR();  // Retrieve IR light value
    int redValue = sensor.getRed();  // Retrieve Red light value

    // Simple peak detection to count pulses
    if (irValue > 50000 && lastIRValue <= 50000) {  // Detect rising edge
      // unsigned long currentTime = millis();
      // if (currentTime - lastPulseTime > 300) {  // Ignore pulses that are too close together
        pulseCount++;
        // lastPulseTime = currentTime;
      // }
    }

    lastIRValue = irValue;

    // Calculate heart rate if we have enough pulses
    if (pulseCount > 0) {
      unsigned long elapsedTime = millis() - lastPulseTime;
      heartRate = (pulseCount * 60.0) / (elapsedTime / 1000.0);  // Calculate heart rate in beats per minute
      pulseCount = 0;  // Reset pulse count for the next period
    }

    // Send HR data over ESP-NOW
    if (heartRate > 0) {
      String hrData = String(heartRate);
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)hrData.c_str(), hrData.length() + 1);
      if (result == ESP_OK) {
        Serial.print("Sent HR: ");
        Serial.println(hrData);
      } else {
        Serial.println("Error sending HR data.");
      }
    }
  // }

  // delay(40);  // Adjust the delay for faster or slower transmission
}
