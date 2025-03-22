#include <WiFi.h>
#include <SD.h>
#include <SPI.h>
#include <WebServer.h>

// Access Point credentials
const char *apSSID = "ESP32-Airport-Control";  // SSID of the access point
const char *apPassword = "12345678";           // Password for the access point

// SD Card pins
#define SD_SCK 18   // GPIO18 for SD card SCK
#define SD_MISO 19  // GPIO19 for SD card MISO
#define SD_MOSI 23  // GPIO23 for SD card MOSI
#define SD_CS 5     // GPIO5 for SD card CS

// Relay pins
#define RELAY_1 21  // GPIO21 for Relay 1
#define RELAY_2 22  // GPIO22 for Relay 2
#define RELAY_3 23  // GPIO23 for Relay 3
#define RELAY_4 25  // GPIO25 for Relay 4
#define RELAY_5 2   // GPIO2 for Relay 5
#define RELAY_6 33  // GPIO33 for Relay 6
#define RELAY_7 27  // GPIO27 for Relay 7
#define RELAY_8 26  // GPIO26 for Relay 8

// Relay states
bool relayStates[8] = { false, false, false, false, false, false, false, false };

// Create WebServer object on port 80
WebServer server(80);

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);

  // Initialize Relay pins
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(RELAY_6, OUTPUT);
  pinMode(RELAY_7, OUTPUT);
  pinMode(RELAY_8, OUTPUT);

  // Turn off all relays initially
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);
  digitalWrite(RELAY_5, HIGH);
  digitalWrite(RELAY_6, HIGH);
  digitalWrite(RELAY_7, HIGH);
  digitalWrite(RELAY_8, HIGH);

  // Initialize SPI for SD card
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  // Initialize SD card
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card Mount Failed");
    return;
  }
  Serial.println("SD Card Mounted Successfully");

  // Start Access Point
  WiFi.softAP(apSSID, apPassword);
  Serial.println("Access Point Started");
  Serial.print("SSID: ");
  Serial.println(apSSID);
  Serial.print("Password: ");
  Serial.println(apPassword);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Route for root / web page
  server.on("/", HTTP_GET, []() {
    File file = SD.open("/index.html");
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }
    String content;
    while (file.available()) {
      content += String((char)file.read());
    }
    file.close();
    server.send(200, "text/html", content);
  });

  // Route for gallery page
  server.on("/gallery", HTTP_GET, []() {
    File file = SD.open("/gallery.html");
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }
    String content;
    while (file.available()) {
      content += String((char)file.read());
    }
    file.close();
    server.send(200, "text/html", content);
  });

  // Route for control page
  server.on("/control", HTTP_GET, []() {
    File file = SD.open("/control.html");
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }
    String content;
    while (file.available()) {
      content += String((char)file.read());
    }
    
    String device = server.arg("device");
    String state = server.arg("state");

    if (device.startsWith("relay")) {
      int relayNumber = device.substring(5).toInt();
      if (relayNumber >= 1 && relayNumber <= 8) {
        if (state == "on") {
          digitalWrite(RELAY_1 + relayNumber - 1, LOW);  // Turn relay ON
          relayStates[relayNumber - 1] = true;
          Serial.printf("Relay %d turned ON\n", relayNumber);
        } else if (state == "off") {
          digitalWrite(RELAY_1 + relayNumber - 1, HIGH);  // Turn relay OFF
          relayStates[relayNumber - 1] = false;
          Serial.printf("Relay %d turned OFF\n", relayNumber);
        }
        logRelayState(relayNumber, state);  // Log the relay state change
      }
    }

    file.close();
    server.send(200, "text/html", content);
  });

  // Handle control requests for relays
  server.on("/control/relay", HTTP_GET, []() {
    String device = server.arg("device");
    String state = server.arg("state");

    if (device.startsWith("relay")) {
      int relayNumber = device.substring(5).toInt();
      if (relayNumber >= 1 && relayNumber <= 8) {
        if (state == "on") {
          digitalWrite(RELAY_1 + relayNumber - 1, LOW);  // Turn relay ON
          relayStates[relayNumber - 1] = true;
          Serial.printf("Relay %d turned ON\n", relayNumber);
        } else if (state == "off") {
          digitalWrite(RELAY_1 + relayNumber - 1, HIGH);  // Turn relay OFF
          relayStates[relayNumber - 1] = false;
          Serial.printf("Relay %d turned OFF\n", relayNumber);
        }
        logRelayState(relayNumber, state);  // Log the relay state change
      }
    }

    server.send(200, "text/plain", "OK");
  });

  // Route to read log file
  server.on("/logs", HTTP_GET, []() {
    File logFile = SD.open("/log.txt");
    if (!logFile) {
      server.send(404, "text/plain", "Log file not found");
      return;
    }
    String logContent;
    while (logFile.available()) {
      logContent += String((char)logFile.read());
    }
    logFile.close();
    server.send(200, "text/plain", logContent);
  });

  // Route for serving static files (e.g., images, CSS, JS)
  server.onNotFound([]() {
    String path = server.uri();  // Get the requested URI
    if (SD.exists(path)) {       // Check if the file exists on the SD card
      File file = SD.open(path);
      if (file) {
        String contentType = getContentType(path);  // Determine the content type
        server.streamFile(file, contentType);       // Stream the file to the client
        file.close();
      } else {
        server.send(500, "text/plain", "Failed to open file");
      }
    } else {
      server.send(404, "text/plain", "File Not Found");
    }
  });

  // Start server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}

// Helper function to determine the content type based on file extension
String getContentType(String filename) {
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".png")) return "image/png";
  else if (filename.endsWith(".jpg") || filename.endsWith(".jpeg")) return "image/jpeg";
  else if (filename.endsWith(".gif")) return "image/gif";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".svg")) return "image/svg+xml";
  return "text/plain";
}

// Function to log relay state changes to a file on the SD card
void logRelayState(int relayNumber, String state) {
  File logFile = SD.open("/log.txt", FILE_APPEND);
  if (logFile) {
    String logEntry = "Relay " + String(relayNumber) + " turned " + state + " at " + getTimestamp() + "\n";
    logFile.print(logEntry);
    logFile.close();
    Serial.println("Logged: " + logEntry);
  } else {
    Serial.println("Failed to open log file");
  }
}

// Function to generate a timestamp
String getTimestamp() {
  time_t now = time(nullptr);
  struct tm timeinfo;
  localtime_r(&now, &timeinfo);
  char buffer[20];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
  return String(buffer);
}