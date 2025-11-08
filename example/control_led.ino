#include <Adafruit_NeoPixel.h>

#define LED_PIN 38

Adafruit_NeoPixel led = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  led.begin();
  led.show(); // Initialize all pixels to 'off'
}

void setLEDRed() {
  int ledRed = 255;
  int ledGreen = 0;
  int ledBlue = 0;
  led.setPixelColor(0, led.Color(ledRed, ledGreen, ledBlue));
  led.show();
}

void setLEDGreen() {
  int ledRed = 0;
  int ledGreen = 255;
  int ledBlue = 0;
  led.setPixelColor(0, led.Color(ledRed, ledGreen, ledBlue));
  led.show();
}

void setLEDBlue() {
  int ledRed = 0;
  int ledGreen = 0;
  int ledBlue = 255;
  led.setPixelColor(0, led.Color(ledRed, ledGreen, ledBlue));
  led.show();
}

void setLEDOff() {
  int ledRed = 0;
  int ledGreen = 0;
  int ledBlue = 0;
  led.setPixelColor(0, led.Color(ledRed, ledGreen, ledBlue));
  led.show();
}

void loop() {
  setLEDRed();
  delay(1000);
  setLEDGreen();
  delay(1000);
  setLEDBlue();
  delay(1000);
  setLEDOff();
  delay(1000);
}