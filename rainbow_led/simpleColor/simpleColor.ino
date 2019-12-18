#include <NeoPixelBus.h>

const uint16_t PixelCount = 3; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 3;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 128

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);


void setup(){
  Serial.begin(9600);
  while (!Serial); // wait for serial attach

  strip.Begin();
  strip.Show();
}


void loop(){
  delay(500);

  //strip.SetPixelColor(0, red);
  //strip.SetPixelColor(1, red);
  //strip.SetPixelColor(2, red);
  strip.SetPixelColor(3, red);
  strip.Show();

  delay(500);

  Serial.println("Off ...");

  //strip.SetPixelColor(0, black);
  //strip.SetPixelColor(1, black);
  //strip.SetPixelColor(2, black);
  strip.SetPixelColor(3, black);
  strip.Show();
}
