// Libraries
#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>

#include <WiFi.h>
#include <WebServer.h>

#include <ArduinoJson.h>
#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>
#include <MFRC522.h>
#include <SD.h> 
#include <Adafruit_BMP280.h>


// pins
#define GREEN_LED ??
#define RED_LED ??
#define BUZZER ??
#define BUTTON ??
#define POT ??

#define SCL 33 // i2c communication MPE280
#define SDA 32

#define MOSI 23    // shared spi pins  // mosi or/and D1
#define MISO 19
#define SCK 18  // D0
#define RESET 22 // RST

#define IRQ 17 // inturupt pin for MRC522

#define CS_MFRC552 18 // device select
#define CS_OLED 16
#define CS_SD_CARD 5

#define DC_OLED 4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// object creation
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, DC_OLED, RESET, CS_OLED); // lab 8

WebServer server(80); // lab 7

// Global variables

const char* ssid = ""; // lab7
const char* password = "password";

// functions 


void setup() {

	WiFi.softAP(ssid,password);
	Serial.print("IP Address =");
	Serial.println(WiFi.softAPIP());

    server.begin();
	Serial.println("web server started");
}

void loop() {

}
