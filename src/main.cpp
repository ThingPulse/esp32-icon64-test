
#include "Arduino.h"
#include <FastLED.h>

#define I2S_DOUT      25
#define I2S_BCLK      26
#define I2S_LRC       22

#define MODE_PIN       33

// digital pin 39 has a pushbutton attached to it. Give it a name:
int pushButton = 39;


// Which pin on the ESP32 is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     32

// How many pixels are attached to the Arduino?
#define LED_COUNT  64

// brightness brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50


CRGB leds[LED_COUNT];

uint8_t color = 0;
uint8_t mode = 0;
uint8_t hue = 0;

CRGB testColors[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::White, CRGB::Black};
const uint8_t COLORS = 5;

void setup() { 
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(BRIGHTNESS);
 }

void loop() {
  mode = (millis() / 5000) % 2;
  if (mode == 0) {
    fill_solid( &(leds[0]), 64 /*number of leds*/, testColors[color] );
    FastLED.show();
    color = (color + 1) % COLORS;
    delay(1000);
  } else if (mode == 1) {
    fill_solid( &(leds[0]), 64 /*number of leds*/, CHSV( hue, 255, 255));
    FastLED.show();
    hue++;
  }
}

