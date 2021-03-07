#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(40, 0);
char i;
char n=0;
char i2;
char n2=0;
char i3;
char n3=0;
char bright=0;
char whichFrame = 0;
char colors [5][3]{
{255,255,255},
{255,0,0},
{165,42,42},
{0,255,0},
{255,158,0}
};
int state = 0;
long startTime = millis();
long startTime4 = millis();
long startTime2 = millis();
long startTime3 = millis();
long interval= 5000;
long interval2 = 5000;
long interval4 = 5000;
long interval3 = 5000;
long endTime3;
long endTime;
long endTime4;
long endTime2;

void setup() {
  strip.setBrightness(20);
  strip.begin();
  strip.clear();
  strip.show();
}

void loop() {
  
switch (state)
{
  case 0:
ani();
break;
  

        
case 1:
runningman();
        
break;

case 2:
cwheel(); 
break;
case 3:
off();
break;
}    
      
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void ani(){
     endTime3 = millis();
   for(int i3=0; i3< strip.numPixels(); i3++){
    int pixAddress = pixelMap[i3];
    int whichColor = animation[whichFrame][i3];
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
    if (pixAddress != -1) {
      strip.setPixelColor(pixAddress, red, green, blue);
    }
  }
   if(endTime3 - startTime3 >= interval3){
         startTime2=millis();
      state = 1;

    }
  strip.show();
  delay(50);
  whichFrame = (whichFrame + 1) %3;

}
void runningman(){
    endTime2 = millis();
  for(int i=0; i<=40; i++) { 
    strip.setPixelColor(i, 255,255,255);        
    strip.show();                          
    delay(50);
  }

  
    if(endTime2 - startTime2 >= interval2){
         startTime=millis();
      state = 2;

    }

strip.show();
n2=n2+1;
}
void cwheel(){
   endTime = millis();

  int i;
  int k;
  for (k = 0; k < 40 * 5; k++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 40 / strip.numPixels()) + k) & 255));
    }
    strip.show();
    delay(10);
  }



    if(endTime - startTime >= interval){
      strip.clear();
              startTime4=millis();

      state = 3;


    }

strip.show();
n=n+1;
}
void off(){
  endTime4=millis();
  strip.clear();
  strip.show();
  
    if(endTime4 - startTime4 >= interval4){
      strip.clear();
              startTime3=millis();

      state = 0;


    }
}
