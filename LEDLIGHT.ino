
#include "FastLED.h"
#include <EEPROM.h>

#define NUM_LEDS 16
#define DATA_PIN 3
#define EEPROM_address 0
#define EEPROM_address_1 4

CRGB leds[NUM_LEDS];
byte themode=0;
int thecount=0;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  delay( 500 ); // power-up safety delay
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  themode = EEPROM.read(EEPROM_address);
  int lockemode = EEPROM.read(EEPROM_address_1);
  if(lockemode!=1) {
    themode++;
  }
  if( themode > 5 ) {
    themode = 0;
  }
  EEPROM.write(EEPROM_address, themode);
  EEPROM.write(EEPROM_address_1, 0);
  FastLED.setBrightness( 255 );
  for( int i = 0; i <= themode; i++) {
    fill_solid( leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(150);
    fill_solid( leds, NUM_LEDS, CRGB::White);
    FastLED.show();
    delay(100);
  }
  //fill_solid( leds, NUM_LEDS, CRGB::Black);
  //FastLED.show();
  delay(1000);
  EEPROM.write(EEPROM_address_1, 1);
}

void loop() {
  switch ( themode ) {
    case 0:
      FastLED.setBrightness( 64 );
      fill_solid( leds, NUM_LEDS, CRGB::White);
      FastLED.show();
      delay(60000);
      break;
    case 1:
      FastLED.setBrightness( 255 );
      fill_solid( leds, NUM_LEDS, CRGB::White);
      FastLED.show();
      delay(60000);
      break;
    case 2:
      thecount++;
      if(thecount>=360) {
        thecount=0;
      }
      FastLED.setBrightness( ( sin( PI * thecount / 180 ) + 1 ) * 127 );
      //fill_solid( leds, NUM_LEDS, CRGB::White);
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(10);
      break;
    case 3:
      FastLED.setBrightness( 255 );
      fill_solid( leds, NUM_LEDS, CRGB::White);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(400);
      fill_solid( leds, NUM_LEDS, CRGB::White);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(1400);
      break;
    case 4:
      FastLED.setBrightness( 255 );
/*
      thecount++;
      if(thecount>=NUM_LEDS) {
        thecount=0;
      }

      fill_solid( leds, NUM_LEDS, CRGB::Black);
      leds[thecount] = CRGB::White;
      FastLED.show();
      delay(100);
*/
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Red);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(400);

      fill_solid( leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(100);
      fill_solid( leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(50);
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(400);

      break;
    case 5:
      FastLED.setBrightness( 255 );
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
      static uint8_t startIndex = 0;
      startIndex = startIndex + 1; /* motion speed */
      FillLEDsFromPaletteColors( startIndex);
      FastLED.show();
      FastLED.delay(50);
      break;
    default:
      fill_solid( leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(60000);
    break;
  }
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);
        colorIndex += 1;
    }
}
