/*
  Copyright (c) 2019-2020 Blahlicus
  See the readme for credit to other people.

  Alternate input method example using german

  Demonstrates how to set the _asciimap bindings to alternate input methods.

  Users also have to change the OS level input method to match the one used
  in the firmware.

*/
/* #define HID_CUSTOM_LAYOUT // set this flag to indicate that a custom layout is selected
// if the above flag is not defined, then the default US layout is used instead

#define LAYOUT_US_ENGLISH // set this flag after the above flag to indicate the custom input method is German
// for more layouts, see /src/KeyboardLayouts/ImprovedKeylayouts.h */

// you must set the above flags before including HID-Project
#include "HID-Project.h"


void setup() {
  Keyboard.begin();
  delay(1000);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_R);
  Keyboard.release(KEY_LEFT_SHIFT);
}

void loop() {
  
}
