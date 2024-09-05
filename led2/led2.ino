#include <EEPROM.h>

#include "Adafruit_NeoPixel.h"
#define LED_COUNT 15
#define LED_PIN 3
boolean but0;
int r;
int g;
int b = 250;
int q = 30; // скорось прорисовки
int e = 10; // скорость смены оттенка
int y = 250; // яркость
int key = 1; // режимы
int rr = 0;
int gg = 0;
int bb = 0;
int yy = 250;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin(); //Инициализируем ленту.
  strip.show();
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  rr = EEPROM.read(4);
  gg = EEPROM.read(8);
  bb = EEPROM.read(12);
  yy = EEPROM.read(16);
}
void loop() {
  
  Serial.print(!digitalRead(5));
  but0 = !digitalRead(2);
  y = analogRead(A1)/4;
  yy = analogRead(A1)/4;
  if (but0){key++; delay(400);}
  if (key > 5){key = 0;}
  strip.show();
  if (key == 0){
    if (key > 0){return;}
    for (r = 0; r < 250; r+=e){
    b-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        delay(q);
      }
    }
    if (key > 0){break;}
   }
   if (key > 0){return;}
   for (g = 0; g < 250; g+=e){
    r-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        
        delay(q);
      }
    }
    if (key > 0){break;}
   }
   if (key > 0){return;}
   for (b = 0; b < 250; b+=e){
    g-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        delay(q);
      }
    }
    if (key > 0){break;}
   }
   if (key > 0){return;}
   for (g = 0; g < 250; g+=e){
    b-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        delay(q);
      }
    }
    if (key > 0){break;}
   }
   if (key > 0){return;}
   for (r = 0; r < 250; r+=e){
    g-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        delay(q);
      }
    }
    if (key > 0){break;}
   }
   if (key > 0){return;}
   for (b = 0; b < 250; b+=e){
    r-=e;
    for (int i = 0; i < LED_COUNT; i++){
      if (!digitalRead(2)) {key++; delay(400); break;}else{
        strip.setBrightness(y);
        strip.setPixelColor(i, strip.Color(r, g, b)); // цвет.
        strip.show();
        delay(q);
      }
    }
    if (key > 0){break;}
   }
  }
  if (key == 1){ // 
     for (int i = 0; i < LED_COUNT; i++){
      strip.setBrightness(y);
      strip.setPixelColor(i, strip.Color(250, 250, 250)); // цвет.
      strip.show();
    }
  }
   
  if (key == 5){
    EEPROM.put(4, rr);
    EEPROM.put(8, gg);
    EEPROM.put(12, bb);
    EEPROM.put(16, yy);
     for (int i = 0; i < LED_COUNT; i++){
      strip.setBrightness(yy);
      strip.setPixelColor(i, strip.Color(rr, gg, bb)); // цвет.
      strip.show();
    }
  }
}
