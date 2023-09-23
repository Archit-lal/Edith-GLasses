//including libraries
//#include <ESP8266WiFi.h>
//#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//setting ssid and password of wifi or hotspot
const char *ssid     = "Pratyush1";
const char *password = "pratyush18";
//setting ntp client
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "pool.ntp.org");

//defining display specs
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET D5
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String text;

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();
  timeClient.setTimeOffset(19800);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.ssd1306_command(0xA0);
}

void loop() {
  //getting formatted time 
  //timeClient.update();
//String formattedTime = timeClient.getFormattedTime();
Serial.println(formattedTime); 
text = formattedTime;
//displaying the time 
display.clearDisplay();
display.setTextSize(3);
display.setTextColor(WHITE);
display.setCursor(3,16);
display.print(text);
display.display();
}
