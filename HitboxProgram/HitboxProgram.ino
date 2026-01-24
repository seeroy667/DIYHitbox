#include<Keyboard.h>
#include <NintendoSwitchControlLibrary.h>

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
  if (digitalRead(2) == LOW) {
    Keyboard.write('W');
    Serial.println("W pressed");
  } else if (digitalRead(3) == LOW) {
    Keyboard.write('A');
    Serial.println("A pressed");
  } else if (digitalRead(4) == LOW) {
    Keyboard.write('S');
    Serial.println("S pressed");
  } else if (digitalRead(5) == LOW) {
    Keyboard.write('D');
    Serial.println("D pressed");
  } else if (digitalRead(6) == LOW) {
    Keyboard.write('U');
    Serial.println("U pressed");
  } else if (digitalRead(7) == LOW) {
    Keyboard.write('I');
    Serial.println("I pressed");
  } else if (digitalRead(8) == LOW) {
    Keyboard.write('O');
    Serial.println("O pressed");
  } else if (digitalRead(9) == LOW) {
    Keyboard.write('P');
    Serial.println("P pressed");
  } else if (digitalRead(10) == LOW) {
    Keyboard.write('H');
    Serial.println("H pressed");
  } else if (digitalRead(11) == LOW) {
    Keyboard.write('J');
    Serial.println("J pressed");
  } else if (digitalRead(12) == LOW) {
    Keyboard.write('K');
    Serial.println("K pressed");
  } else if (digitalRead(13) == LOW) {
    Keyboard.write('L');
    Serial.println("L pressed");
  }
}
