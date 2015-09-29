#include <Adafruit_NeoPixel.h>
#define MAX_VAL 64  // 0 to 255 for brightness
#define DELAY_TIME 30
#define DELAY_TIME2 10
#define HIGH 1
#define LOW 0
#define PIN 6
#define NUMPIXELS 8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int inputchar;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  inputchar = Serial.read();

  if(inputchar != -1) {
    switch ( inputchar ) {
      case 'a':
        Serial.print("pattern A\n");
        for(int i = 0; i < 5; i++) {
          colorWipe(pixels.Color(MAX_VAL, 0, 0), DELAY_TIME); // Red
          colorWipe(pixels.Color(0, MAX_VAL, 0), DELAY_TIME); // Green
          colorWipe(pixels.Color(MAX_VAL, MAX_VAL, 0), DELAY_TIME); // Yellow
          colorWipe(pixels.Color(0, 0, MAX_VAL), DELAY_TIME); // Blue
          colorWipe(pixels.Color(MAX_VAL, 0, MAX_VAL), DELAY_TIME); // Purple
          colorWipe(pixels.Color(0, MAX_VAL, MAX_VAL), DELAY_TIME); // Cyan
          colorWipe(pixels.Color(MAX_VAL, MAX_VAL, MAX_VAL), DELAY_TIME); // White
        }
      break; 

      case 'b':
        Serial.print("pattern B\n");
        rainbow(DELAY_TIME2);
        rainbow(DELAY_TIME2);
        rainbow(DELAY_TIME2);
        rainbow(DELAY_TIME2);
      break;

      case 'c':
        Serial.print("pattern C\n");
        rainbowCycle(DELAY_TIME2);
      break;
  
      case 'd':
        Serial.print("pattern D\n");
        for(int i = 0; i< NUMPIXELS; i++) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(0,255,0));
          pixels.setPixelColor(4-i, pixels.Color(0,0,255));
          if(i < 4) {
            pixels.setPixelColor(4+i, pixels.Color(255,0,0));
          } else {
            pixels.setPixelColor(i-4, pixels.Color(255,0,0));
          }
          pixels.show();
          delay(300);
        }

      case 'e':
        Serial.print("pattern E\n");
        pixels.setPixelColor(1, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(2, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(3, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(4, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(5, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(6, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(7, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.setPixelColor(0, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
        pixels.show(); 
        delay(3000);       
      break;
     
      }   
     Serial.print("Ready\n");
  } else {
        for(int i = 0; i< NUMPIXELS; i++) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
          pixels.show();
          delay(100);
        }    
  }
}  
   

// Some example procedures showing how to display to the pixels:
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, c);
      pixels.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
  return pixels.Color((WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255, 0);
  } else if(WheelPos < 170) {
  WheelPos -= 85;
  return pixels.Color((255 - WheelPos * 3)*MAX_VAL/255, 0, (WheelPos * 3)*MAX_VAL/255);
  } else {
  WheelPos -= 170;
  return pixels.Color(0, (WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255);
  }
}


