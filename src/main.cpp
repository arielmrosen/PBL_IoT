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
#define GREEN_LED 25
#define RED_LED 26
#define BUZZER 27
#define BUTTON_Call 13
#define BUTTON_Con 12
#define POT 2
#define FAN ??

#define SCL 33 // i2c communication MPE280
#define SDA 32

#define MOSI 23    // shared spi pins  // mosi or/and D1
#define MISO 19
#define SCK 18  // D0
#define RESET 22 // RST

#define IRQ 0 // inturupt pin for MRC522

#define CS_MFRC552 15 // device select
#define CS_OLED 16
#define CS_SD_CARD 17

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
const int NUM_SAMPLES = 10; //number of samples to save
int samples[NUM_SAMPLES];
time = millis() *1000;

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

	//bmp280 readings
	void takeSamples(){ //function from lab 11 
  for (int i = 0; i < NUM_SAMPLES; i++){
    samples[i] = BMP.readTemperature();
    delay(2000);
  }
	}

	float getAverage(){ //function from lab 11
  long sum = 0;                        // the total starts at 0
  for (int i = 0; i < NUM_SAMPLES; i++){
    sum = sum + samples[i];          // add element i to the total
  }
  return (float)sum / NUM_SAMPLES;    // (float) keeps the decimals
	}

	// oled display from lab 6
	oledshow(){
	float average = getAverage();
	Display.clear();
	display.setCursor(0,0);
	Display.print("current temp : ");
	Display.print(average);
	if(byte &= ~(1 << 1)){ //checks if bit 1 is high
	Display.print("room occupied");
	}
	else{
	Display.print("room unoccupied");
	}
	Display.Display
	}

	//read pot (ADC) lab12
	potfunction(){
	 float average = getAverage();
	 int POT_TEP_SET = map(POT, 0, 4096, 18, 28); //lab 11 dont know if its going to work
	 ledcWrite(Fan, duty); 
	 if(<= ){

	 }

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

 Serial.println(byte)
}
