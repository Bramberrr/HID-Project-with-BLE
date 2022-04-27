#include "HID-Project.h"

BluetoothKeyboard_ BLEKeyboard(10, 14, 9600);
const int pinLed = LED_BUILTIN;

void setup() {
  pinMode(pinLed, OUTPUT);
  BLEKeyboard.begin();
  BLEKeyboard.press(KEY_LEFT_SHIFT);
  BLEKeyboard.write(KEY_R);
  BLEKeyboard.release(KEY_LEFT_SHIFT);
}



void loop() 
{
  
}