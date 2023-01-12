// testcolors demo for Adafruit RGBmatrixPanel library.
// Renders 512 colors on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420
// Library supports 4096 colors, but there aren't that many pixels!  :)

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.
#include <Arduino.h>
#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK 8 // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
int incomingByte = 0;
int counter = 0;
int hue = 0;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(5));
  matrix.begin();
  matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, true));
  matrix.setCursor(1, 0);
  matrix.setTextSize(1);
}

void loop() {
  if (Serial.available() > 0) {
    matrix.fillScreen(0);
    matrix.setCursor(1, 0);
    hue += 100;
    if (hue >= 1536)
      hue -= 1536;
    matrix.setTextColor(
        matrix.Color333(random(0, 8), random(0, 8), random(0, 8)));
    counter = 0;
    while (Serial.available() > 0) {
      incomingByte = Serial.read();
      counter++;
      if (counter == 6) {
        matrix.setCursor(1, 9);
      }
      matrix.print((char)incomingByte);
    }
  }
  delay(5);
}
