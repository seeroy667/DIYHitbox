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
  if (digitalRead(2) == LOW) {
    Keyboard.press('W');
    Serial.println("W pressed");
  }
  if (digitalRead(3) == LOW) {
    Keyboard.press('A');
    Serial.println("A pressed");
  }
  if (digitalRead(4) == LOW) {
    Keyboard.press('S');
    Serial.println("S pressed");
  }
  if (digitalRead(5) == LOW) {
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
  if (digitalRead(10) == LOW) {
    Keyboard.press('H');
    Serial.println("H pressed");
  }
  if (digitalRead(11) == LOW) {
    Keyboard.press('J');
    Serial.println("J pressed");
  }
  if (digitalRead(12) == LOW) {
    Keyboard.press('K');
    Serial.println("K pressed");
  }
  if (digitalRead(13) == LOW) {
    Keyboard.press('L');
    Serial.println("L pressed");
  }
  if (digitalRead(2) == HIGH) {
    Keyboard.release('W');
    Serial.println("W pressed");
  }
  if (digitalRead(3) == HIGH) {
    Keyboard.release('A');
    Serial.println("A pressed");
  }
  if (digitalRead(4) == HIGH) {
    Keyboard.release('S');
    Serial.println("S pressed");
  }
  if (digitalRead(5) == HIGH) {
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
  if (digitalRead(10) == HIGH) {
    Keyboard.release('H');
    Serial.println("H pressed");
  }
  if (digitalRead(11) == HIGH) {
    Keyboard.release('J');
    Serial.println("J pressed");
  }
  if (digitalRead(12) == HIGH) {
    Keyboard.release('K');
    Serial.println("K pressed");
  }
  if (digitalRead(13) == HIGH) {
    Keyboard.release('L');
    Serial.println("L pressed");
  }
}
