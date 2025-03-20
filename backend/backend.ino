#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <SD.h>
#include "index.h"
#include "control.h"
#include "gallery.h"

// Network credentials
const char *ssid = "HLT B";
const char *password = "wedishuk113$";

// Web server instance
WebServer server(80);

// SD Card pins
#define SD_CS 5    // GPIO5 for SD card CS
#define SD_SCK 18  // GPIO18 for SD card SCK
#define SD_MOSI 23 // GPIO23 for SD card MOSI
#define SD_MISO 19 // GPIO19 for SD card MISO

// Relay pins
#define RELAY_1 21 // GPIO21 for Relay 1
#define RELAY_2 22 // GPIO22 for Relay 2
#define RELAY_3 23 // GPIO23 for Relay 3
#define RELAY_4 25 // GPIO25 for Relay 4
#define RELAY_5 2  // GPIO2 for Relay 5*
#define RELAY_6 33 // GPIO33 for Relay 6*
#define RELAY_7 27 // GPIO27 for Relay 7
#define RELAY_8 26 // GPIO26 for Relay 8

// Relay states
bool relayStates[8] = {false, false, false, false, false, false, false, false};

// Function to recursively list files and directories
void listFilesRecursively(File dir, String &output) {
    while (File entry = dir.openNextFile()) {
        if (entry.isDirectory()) {
            output += "Directory: " + String(entry.name()) + "\n";
            listFilesRecursively(entry, output); // Recursively list contents of the directory
        } else {
            output += "File: " + String(entry.name()) + " (" + entry.size() + " bytes)\n";
        }
        entry.close();
    }
}

void setup()
{
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Initialize SD Card
    Serial.println("Initializing SD card...");
    if (!SD.begin(SD_CS))
    {
        Serial.println("SD Card initialization failed!");
        Serial.println("Check wiring and SD card format.");
        return;
    }
    Serial.println("SD Card initialized.");

    // Check if the SD card is present
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE)
    {
        Serial.println("No SD card attached.");
        return;
    }

    // Print SD card type
    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC)
    {
        Serial.println("MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("SDHC");
    }
    else
    {
        Serial.println("UNKNOWN");
    }

    // Print SD card size
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %llu MB\n", cardSize);

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

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Serve the main page
    server.on("/", HTTP_GET, []()
              { server.send(200, "text/html", PAGE_MAIN); });

    // Serve the gallery page
    server.on("/gallery", HTTP_GET, []()
              { server.send(200, "text/html", PAGE_GALLERY); });

    // List images on the SD card
    server.on("/list-images", HTTP_GET, []() {
        File root = SD.open("/assets");
        String imageList = "[";
        bool firstImage = true;

        if (!root) {
            server.send(404, "application/json", "{\"error\": \"Directory not found\"}");
            return;
        }

        while (File file = root.openNextFile()) {
            const char *fileName = file.name();
            if (!file.isDirectory() && (strstr(fileName, ".jpg") || strstr(fileName, ".jpeg"))) {
                if (!firstImage) {
                    imageList += ",";
                }
                imageList += "\"/assets/" + String(fileName) + "\"";
                firstImage = false;
            }
        }
        imageList += "]";
        root.close();

        server.send(200, "application/json", imageList);
        Serial.println("List of images: " + imageList);
    });

    // Serve images from the SD card
    server.on("/image", HTTP_GET, []() {
        String imagePath = server.arg("path");
        if (SD.exists(imagePath)) {
            File file = SD.open(imagePath, FILE_READ);
            if (file) {
                server.streamFile(file, "image/jpeg");
                file.close();
            } else {
                server.send(404, "text/plain", "Failed to open image");
            }
        } else {
            server.send(404, "text/plain", "Image not found");
        }
    });

    // List all directories and files on the SD card
    server.on("/list-all", HTTP_GET, []() {
        File root = SD.open("/assets");
        String output = "SD Card Contents:\n";
        listFilesRecursively(root, output);
        root.close();
        server.send(200, "text/plain", output);
        Serial.println(output);
    });

    // Handle control requests for relays
    server.on("/control", HTTP_GET, []()
              {
        String device = server.arg("device");
        String state = server.arg("state");
      
        if (device.startsWith("relay")) {
            int relayNumber = device.substring(5).toInt();
            if (relayNumber >= 1 && relayNumber <= 8) {
                if (state == "on") {
                    digitalWrite(RELAY_1 + relayNumber - 1, LOW); // Turn relay ON
                    relayStates[relayNumber - 1] = true;
                    Serial.printf("Relay %d turned ON\n", relayNumber);
                } else if (state == "off") {
                    digitalWrite(RELAY_1 + relayNumber - 1, HIGH); // Turn relay OFF
                    relayStates[relayNumber - 1] = false;
                    Serial.printf("Relay %d turned OFF\n", relayNumber);
                }
                logRelayState(relayNumber, state);
            }
        }
      
        server.send(200, "text/html", PAGE_CONTROL); });

    // Start the server
    server.begin();
    Serial.println("HTTP server started");

    // Print the IP address of the ESP32
    Serial.println(WiFi.localIP());
}

void loop()
{
    // Handle client requests
    server.handleClient();
}

void logRelayState(int relayNumber, String state)
{
    File logFile = SD.open("/relay_log.txt", FILE_WRITE);
    if (logFile)
    {
        String logEntry = "Relay " + String(relayNumber) + " turned " + state + " at " + getTimeStamp();
        logFile.println(logEntry);
        logFile.close();
        Serial.println(logEntry);
    }
    else
    {
        Serial.println("Failed to open log file!");
    }
}

String getTimeStamp()
{
    // Placeholder for actual time stamp logic
    // You can use an RTC module or NTP to get the actual time
    return "2023-10-01 12:00:00";
}