// Blink WS2812B LED on Waveshare RP2040 Zero board
// Requires Adafruit_NeoPixel library
#include <Adafruit_NeoPixel.h>

// Define pin used to drive WS2812B/NeoPixel
// PIN_NEOPIXEL is predefined pin for Waveshare RP2040 Zero (see Arduino_pins.h)
//#define PIN PIN_NEOPIXEL
#define PIN 28

// Number of NeoPixels attached to the Arduino
#define NUMPIXELS 23 
#define DELAYVAL 500  // Blink time (ms)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel status(1, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin(); // Init NeoPixel strip object
  pixels.clear(); // Set all pixel colors to 'off'
                  
  status.begin();
  status.setPixelColor(0, pixels.Color(0,1,0));
  status.show();
}

#define HUE_SPEED 64
#define HUE_SPREAD 2048
#define HUE_DELAY 1
void HSVCycle()
{
  static uint16_t hue = 0;

  hue += HUE_SPEED;
  if (hue > 65384)
    hue = 0;

  for (int i=0; i < NUMPIXELS; i++)
    pixels.setPixelColor(i, pixels.ColorHSV(hue+i*2048, 255, 4));
  
  pixels.show();
  delay(HUE_DELAY);
}

void loop()
{
 HSVCycle();
}
