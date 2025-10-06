#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int gasSensorPin = 34;  // Analog pin for MQ-2
const int buzzerPin = 25;
const int ledPin = 26;

const int gasThreshold = 300;  // Adjust based on your sensor calibration

void setup() {
  Serial.begin(115200);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Gas Detector Starting...");
  display.display();
  delay(2000);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas sensor value: ");
  Serial.println(gasValue);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Gas Level:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(gasValue);

  if (gasValue > gasThreshold) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println("WARNING: Gas Leak!");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  display.display();
  delay(1000);
}