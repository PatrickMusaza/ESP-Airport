#include <WiFi.h>
#include <WebServer.h>
#include "index.h"
#include "control.h"

// Network credentials


const char *ssid = "HLT B";
const char *password = "wedishuk113$";

/*
const char *ssid = "Patrick";
const char *password = "patrick@123";
*/

// Web server instance
WebServer server(80);

// GPIO pins
#define RELAY_PIN 26
#define FAN_PIN 27

void setup() {
  // Initialize GPIO pins
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // Initialize Serial Monitor
  Serial.begin(921600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Serve the main page
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", PAGE_MAIN);
  });

  // Handle control requests for light and fan
  server.on("/control", HTTP_GET, []() {
    String device = server.arg("device");
    String state = server.arg("state");
    //Control Logic
    server.send(200, "text/html", PAGE_CONTROL);
  });

  // Start the server
  server.begin();
  Serial.println("HTTP server started");

  // Print the IP address of the ESP32
  Serial.println(WiFi.localIP());
}

void loop() {
  // Handle client requests
  server.handleClient();
}
