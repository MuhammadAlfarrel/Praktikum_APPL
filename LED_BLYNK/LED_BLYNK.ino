#define BLYNK_TEMPLATE_ID "TMPL6I1_nxuFh"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "atag5U552I_7wSyXehpv34b-8b2Dskq0"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Galaxy A34 5G 1115";
char pass[] = "Alfarrel";

// Pin definitions
const int ledPin = 2; // GPIO2 pada ESP32

// Fungsi untuk menangani input dari Blynk (Virtual Pin V2)
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(ledPin, value);
  Serial.print("LED Status: ");
  Serial.println(value ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  
  // Inisialisasi pin LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  // Mulai koneksi Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}