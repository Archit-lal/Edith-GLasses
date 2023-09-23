#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
String text;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.ssd1306_command(0xC8);
  text="";
}


void loop() {
display.clearDisplay();
display.setTextSize(3);
display.setTextColor(WHITE);
display.setCursor(3,16);
if(Serial.available()){
  text = Serial.readString();
}
display.print(text);
display.display();
}
