#define BLYNK_TEMPLATE_ID "TMPL3sSYcu8WZ"
#define BLYNK_TEMPLATE_NAME "LED SWITCH"
#define BLYNK_AUTH_TOKEN "IYSjfghOEFUB-G_VyMTgbJ1F5jaKCgYm"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// 🔧 WiFi credentials
char ssid[] = "Wokwi-GUEST";      
char pass[] = "";                 

// 🔧 Relay Pins
#define RELAY1_PIN  5   
#define RELAY2_PIN  4   

// Relay 1 Control (V1 Button)
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(RELAY1_PIN, HIGH);  
  } else {
    digitalWrite(RELAY1_PIN, LOW);   
  }
}


BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(RELAY2_PIN, HIGH);  
  } else {
    digitalWrite(RELAY2_PIN, LOW);  
  }
}

void setup() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);

  Serial.begin(115200);

  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
