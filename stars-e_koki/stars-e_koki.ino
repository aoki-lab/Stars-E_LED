#include <Adafruit_NeoPixel.h>
#define MAX_VAL 255  // 0 to 255 for brightness
#define DELAY_TIME 10
#define DELAY_TIME2 10
#define HIGH 1
#define LOW 0
#define PIN 10
#define NUMPIXELS 45

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int inputchar;
int H ;
int R , G , B ;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  inputchar = Serial.read();

  if(inputchar != -1) {
    switch ( inputchar ) {
      case 's':
        Serial.print("pattern S\n");
        delay(4000);
          R = 0;
          B = 255 ;
          G = 0;
          analogWrite(3,R) ;               // 3番ピンから赤LEDの出力
          analogWrite(5,G) ;               // 5番ピンから緑LEDの出力
          analogWrite(6,B) ;               // 6番ピンから青LEDの出力
        for(int i = 0; i < 2; i++) {
          colorWipe(pixels.Color(0, 0, MAX_VAL), 1); // Blue
          colorWipe(pixels.Color(0, 0, MAX_VAL), 1); // Blue
          colorWipe(pixels.Color(0, 0, MAX_VAL), 1); // Blue
          colorWipe(pixels.Color(0, 0, MAX_VAL), 1); // Blue
          colorWipe(pixels.Color(0, 0, MAX_VAL), 1); // Blue
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1);           
        }
          R = 0;
          B = 0 ;
          G = 0;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
      break; 

      case 'd':
        Serial.print("pattern D\n");
        delay(4000);
          R = 0;
          B = 0 ;
          G = 255;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
        for(int i = 0; i < 2; i++) {
          colorWipe(pixels.Color(0, MAX_VAL,0 ), 1); 
          colorWipe(pixels.Color(0, MAX_VAL,0 ), 1); 
          colorWipe(pixels.Color(0, MAX_VAL,0 ), 1); 
          colorWipe(pixels.Color(0, MAX_VAL,0 ), 1); 
          colorWipe(pixels.Color(0, MAX_VAL,0 ), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1);  
        }
          R = 0;
          B = 0 ;
          G = 0;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
      break;

      case 'b':
        Serial.print("pattern B\n");
        delay(4000);
          R = 255;
          B = 0;
          G = 0;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
        for(int i = 0; i < 2; i++) {
          colorWipe(pixels.Color(MAX_VAL,0,0 ), 1); 
          colorWipe(pixels.Color(MAX_VAL,0,0 ), 1);
          colorWipe(pixels.Color(MAX_VAL,0,0 ), 1);
          colorWipe(pixels.Color(MAX_VAL,0,0 ), 1);
          colorWipe(pixels.Color(MAX_VAL,0,0 ), 1);
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1);  
        }
          R = 0;
          B = 0 ;
          G = 0;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
      break;

      case 'i':
        Serial.print("pattern I\n");
        delay(4000);
          R = 255;
          B = 255;
          G = 255;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
        for(int i = 0; i < 2; i++) {
          colorWipe(pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL ), 1); 
          colorWipe(pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL ), 1);
          colorWipe(pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL ), 1);
          colorWipe(pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL ), 1);
          colorWipe(pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL ), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1); 
          colorWipe(pixels.Color(0, 0, 0), 1);  
        }
          R = 0;
          B = 0 ;
          G = 0;
          analogWrite(3,R) ;               // 　９番ピンから赤LEDの出力
          analogWrite(5,G) ;               // １１番ピンから緑LEDの出力
          analogWrite(6,B) ;               // １０番ピンから青LEDの出力
      break;

      case 'e':
        delay(4000);
        Serial.print("pattern E\n");
        rainbowCycle(DELAY_TIME2);
      break;
  
      case 'f':
        Serial.print("pattern F\n");
        delay(4000);
        for(int i = 0; i< NUMPIXELS; i++) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(0,255,0));
          pixels.setPixelColor(16-i, pixels.Color(0,0,255));
          if(i < 16) {
            pixels.setPixelColor(16+i, pixels.Color(255,0,0));
          } else {
            pixels.setPixelColor(i-16, pixels.Color(255,0,0));
          }
          pixels.show();
          delay(300);
        }
      } 
      
     Serial.print("Ready\n");
  } else {
        for(int i = 0; i< NUMPIXELS; i++) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
          pixels.setPixelColor(i, pixels.Color(MAX_VAL,MAX_VAL,MAX_VAL));
          pixels.show();
          delay(30);
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


