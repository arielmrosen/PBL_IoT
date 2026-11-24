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
uint8_t byte; //byte recording states
unsigned long buzzerStartTime = 0; //buzzer start time
const unsigned long buzzerDuration = 3000; //duration for buzzer
bool buzzerOn = false; //buzzer on or off status, make an ISR

// Functions 

	//Bitwise Manipulation

	void setBit0(){ //set bit 0 to 1
		byte |= 0b00000001;
	}

	void setBit1(){ //set bit 1 to 1
		byte |= 0b00000010;
	}

	void setBit2(){ //set bit 2 to 1
		byte |= 0b00000100;
	}

	void clearBit0(){ //clear bit 0
		byte &= ~(1 << 0);
	}

	void clearBit1(){
		byte &= ~(1 << 1); //clear bit 1
	}

	void clearBit2(){
		byte &= ~(1 << 2); //clear bit 2
	}

	// Room Occupation & Authorization
	
	void authorizedEntry() { 
		digitalWrite(GREEN_LED, HIGH);
		digitalWrite(RED_LED, LOW);
		setBit0();
		//track time somehow
	}

	void unauthorizedEntry(){
		digitalWrite (GREEN_LED, LOW);
		digitalWrite (RED_LED, HIGH);
		//track time somehow
	}

	void emptyRoom(){ //used when authorizedEntry is not being used
		digitalWrite (GREEN_LED, LOW);
		digitalWrite (RED_LED, LOW);
		clearBit0; //clear bit 0
	}

void setup() {

	WiFi.softAP(ssid,password);
	Serial.print("IP Address =");
	Serial.println(WiFi.softAPIP());

    server.begin();
	Serial.println("web server started");

	pinMode(GREEN_LED, OUTPUT); //set green led as an output
	pinMode(RED_LED, OUTPUT); //set red led as an output
	pinMode(BUZZER, OUTPUT); //set buzzer as an output

}

void loop() {

}
