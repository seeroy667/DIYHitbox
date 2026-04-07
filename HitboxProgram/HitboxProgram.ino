/*
Author Name: Donavan Sirois
Date: 2026/04/06
Description: Code to use a Leonardo Arduino for a hitbox in order to play fighting games. The pins and button mappings can be changed.
*/

/*
The following code is meant to be used on a computer. The Arduino Leonardo is then emulating a keyboard.
To use the following, you need to change the board.txt file in the path:
C:\Users\$USER$\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7
In the Arduino Leonardo section, the lines to modify are the following leonardo.build.vid and leonardo.build.pid:
  leonardo.build.vid=0x2341
  leonardo.build.pid=0x8036
The HID will now be recognized as a Keyboard.
*/

// Uncomment the following code to use the Leonardo Arduino as a keyboard
/*
#include<Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(11) == LOW) {
    Keyboard.press('W');
    Serial.println("W pressed");
  }
  if (digitalRead(13) == LOW) {
    Keyboard.press('A');
    Serial.println("A pressed");
  }
  if (digitalRead(12) == LOW) {
    Keyboard.press('S');
    Serial.println("S pressed");
  }
  if (digitalRead(10) == LOW) {
    Keyboard.press('D');
    Serial.println("D pressed");
  }
  if (digitalRead(6) == LOW) {
    Keyboard.press('U');
    Serial.println("U pressed");
  }
  if (digitalRead(7) == LOW) {
    Keyboard.press('I');
    Serial.println("I pressed");
  }
  if (digitalRead(8) == LOW) {
    Keyboard.press('O');
    Serial.println("O pressed");
  } 
  if (digitalRead(9) == LOW) {
    Keyboard.press('P');
    Serial.println("P pressed");
  }
  if (digitalRead(5) == LOW) {
    Keyboard.press('H');
    Serial.println("H pressed");
  }
  if (digitalRead(2) == LOW) {
    Keyboard.press('J');
    Serial.println("J pressed");
  }
  if (digitalRead(4) == LOW) {
    Keyboard.press('K');
    Serial.println("K pressed");
  }
  if (digitalRead(3) == LOW) {
    Keyboard.press('L');
    Serial.println("L pressed");
  }
  if (digitalRead(11) == HIGH) {
    Keyboard.release('W');
    Serial.println("W pressed");
  }
  if (digitalRead(13) == HIGH) {
    Keyboard.release('A');
    Serial.println("A pressed");
  }
  if (digitalRead(12) == HIGH) {
    Keyboard.release('S');
    Serial.println("S pressed");
  }
  if (digitalRead(10) == HIGH) {
    Keyboard.release('D');
    Serial.println("D pressed");
  }
  if (digitalRead(6) == HIGH) {
    Keyboard.release('U');
    Serial.println("U pressed");
  }
  if (digitalRead(7) == HIGH) {
    Keyboard.release('I');
    Serial.println("I pressed");
  }
  if (digitalRead(8) == HIGH) {
    Keyboard.release('O');
    Serial.println("O pressed");
  } 
  if (digitalRead(9) == HIGH) {
    Keyboard.release('P');
    Serial.println("P pressed");
  }
  if (digitalRead(5) == HIGH) {
    Keyboard.release('H');
    Serial.println("H pressed");
  }
  if (digitalRead(2) == HIGH) {
    Keyboard.release('J');
    Serial.println("J pressed");
  }
  if (digitalRead(4) == HIGH) {
    Keyboard.release('K');
    Serial.println("K pressed");
  }
  if (digitalRead(3) == HIGH) {
    Keyboard.release('L');
    Serial.println("L pressed");
  }
}
*/

/*
The following code is meant to be used on a Switch Controller. The Arduino Leonardo is then emulating a Switch Controller.
To use the following, you need to change the board.txt file in the path:
C:\Users\$USER$\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7
In the Arduino Leonardo section, the lines to modify are the following leonardo.build.vid and leonardo.build.pid:
  leonardo.build.vid=0x0f0d
  leonardo.build.pid=0x00c1
The HID will now be recognized as a Switch Controller.
*/

// Uncomment the following code to use the Leonardo Arduino as a Switch Controller

#include <NintendoSwitchControlLibrary.h>

#define STICK_FULL_MIN  0x00   // Full tilt (run)
#define STICK_FULL_MAX  0xFF   // Full tilt other direction (run)
#define STICK_TILT_LO   0x48   // Partial tilt low (~28%) - walk speed
#define STICK_TILT_HI   0xB8   // Partial tilt high (~72%) - walk speed

void setup() {
  pinMode(2,  INPUT_PULLUP); // X
  pinMode(3,  INPUT_PULLUP); // A
  pinMode(4,  INPUT_PULLUP); // B
  pinMode(5,  INPUT_PULLUP); // Y
  pinMode(6,  INPUT_PULLUP); // Tilt modifier
  pinMode(7,  INPUT_PULLUP); // ZL
  pinMode(8,  INPUT_PULLUP); // L
  pinMode(9,  INPUT_PULLUP); // ZR
  pinMode(10, INPUT_PULLUP); // Right
  pinMode(11, INPUT_PULLUP); // Up
  pinMode(12, INPUT_PULLUP); // Down
  pinMode(13, INPUT_PULLUP); // Left
}

void loop() {
  // Start by reeleasing all buttons
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().releaseButton(Button::B);
  SwitchControlLibrary().releaseButton(Button::X);
  SwitchControlLibrary().releaseButton(Button::Y);
  SwitchControlLibrary().releaseButton(Button::ZL);
  SwitchControlLibrary().releaseButton(Button::L);
  SwitchControlLibrary().releaseButton(Button::PLUS);
  

  // Default stick to neutral
  uint8_t lx = Stick::NEUTRAL;
  uint8_t ly = Stick::NEUTRAL;

  // Check if tilt modifier is held
  bool tilt = (digitalRead(8) == LOW);

  // Directions — use partial values if tilt modifier is held
  if (digitalRead(11) == LOW) {
    ly = tilt ? STICK_TILT_LO : STICK_FULL_MIN;  // Up
    // SwitchControlLibrary().pressButton(Button::X); // X on up always
  }
  if (digitalRead(12) == LOW) ly = tilt ? STICK_TILT_HI : STICK_FULL_MAX;  // Down
  if (digitalRead(13) == LOW) lx = tilt ? STICK_TILT_LO : STICK_FULL_MIN;  // Left
  if (digitalRead(10) == LOW) lx = tilt ? STICK_TILT_HI : STICK_FULL_MAX;  // Right

  SwitchControlLibrary().moveLeftStick(lx, ly);

  // Action buttons
  if (digitalRead(7) == LOW) SwitchControlLibrary().pressButton(Button::X);
  if (digitalRead(6) == LOW) SwitchControlLibrary().pressButton(Button::A);
  if (digitalRead(4) == LOW) SwitchControlLibrary().pressButton(Button::B);
  if (digitalRead(3) == LOW) SwitchControlLibrary().pressButton(Button::Y);
  if (digitalRead(5) == LOW) SwitchControlLibrary().pressButton(Button::ZL);
  if (digitalRead(9) == LOW) SwitchControlLibrary().pressButton(Button::L);
  if (digitalRead(2) == LOW) SwitchControlLibrary().pressButton(Button::PLUS);

  SwitchControlLibrary().sendReport();
}