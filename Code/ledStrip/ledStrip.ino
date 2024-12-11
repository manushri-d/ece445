#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>
#include <cstdlib>  // For atoi

// Replace with the MAC Address of your receiver
uint8_t broadcastAddress[] = {0xF8, 0xB3, 0xB7, 0x44, 0x58, 0x10};

// Microphone and LED Pins
const int sampleWindow = 30; // 30ms sample window
unsigned int sample;
unsigned int peakToPeakMin = 4096;
unsigned int peakToPeakMax = 0;
#define micPin 36
#define redPin 15
#define bluePin 2
#define greenPin 4
int intensity = 2;
// ESP-NOW Callbacks
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Last Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const esp_now_recv_info *recv_info, const uint8_t *incomingData, int len) {
  char receivedData[len + 1];
  memcpy(receivedData, incomingData, len);
  receivedData[len] = '\0';
  Serial.print("Received message: ");
  Serial.println(receivedData);

  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
           recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2],
           recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);
  Serial.print("From MAC: ");
  Serial.println(macStr);
  if(atoi(receivedData) > 90)
    intensity = 1;
  else
    intensity = 2;

}

void setup() {
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  unsigned long startMillis = millis();
  unsigned int signalMax = 0;
  unsigned int signalMin = 4096;

  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(micPin);
    if (sample > signalMax) signalMax = sample;
    if (sample < signalMin) signalMin = sample;
  }

  unsigned int peakToPeak = signalMax - signalMin;
  double volts = (peakToPeak * 5.0) / 4096;
  peakToPeakMax = max(peakToPeakMax, peakToPeak);
  peakToPeakMin = min(peakToPeakMin, peakToPeak);

  long colorPick = map(peakToPeak, peakToPeakMin, peakToPeakMax, 0, 9);
  Serial.print("colorPick: ");
  Serial.println(colorPick);
  // colorPick = (intensity-1) * 5 + colorPick;
  Serial.print("colorPick: ");
  Serial.println(colorPick);
  Serial.print("intensity: ");
  Serial.println(intensity);
  switch (colorPick) {
    case 0: changeLED(255, 0, 0); break; // Red
    case 1: changeLED(0, 255, 0); break; // Green
    case 2: changeLED(0, 0, 255); break; // White
    case 3: changeLED(255, 255, 0); break; // Blue
    case 4: changeLED(0, 255, 255); break; // Yellow
    case 5: changeLED(255, 0, 255); break; // Cyan
    case 6: changeLED(254, 254, 254); break; // Purple
    case 7: changeLED(255, 128, 0); break; // Pink
    case 8: changeLED(128, 0, 128); break; // Orange
    case 9: changeLED(0, 5, 128); break; // Bright Red

    default: changeLED(255, 255, 255); break; // All Off
  }


  // String message = String(volts, 2) + "V";
  // esp_now_send(broadcastAddress, (uint8_t *)message.c_str(), message.length());

  delay(100);
}

void changeLED(int redPinInp, int greenPinInp, int bluePinInp){
  redPinInp = redPinInp/intensity/intensity;
  greenPinInp = greenPinInp/intensity/intensity;
  bluePinInp = bluePinInp/intensity/intensity;
  analogWrite(redPin, redPinInp); 
  analogWrite(greenPin, greenPinInp); 
  analogWrite(bluePin, bluePinInp);
}
