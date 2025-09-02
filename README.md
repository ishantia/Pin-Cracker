# DigiKeyboard PIN Brute-Force Script

## Overview
This Arduino sketch is designed for use with a DigiSpark (ATtiny85-based microcontroller) and the DigiKeyboard library to perform a brute-force attack on 4- and 5-digit PIN codes by simulating USB keyboard input. The script systematically tries all possible PIN combinations, starting with 4-digit codes (0000–9999) and then switching to 5-digit codes (00000–99999). It includes a delay mechanism to handle potential lockout periods on the target system.

**Note**: This script is intended **solely for educational purposes or authorized security testing**. Unauthorized use to access systems or devices without explicit permission is **illegal** and may violate laws such as the Computer Fraud and Abuse Act (CFAA) or similar regulations in other jurisdictions. Always obtain explicit consent from the system owner before use.

## Features
- Simulates USB keyboard input to enter PINs.
- Brute-forces 4-digit PINs (10,000 combinations) and 5-digit PINs (100,000 combinations).
- Includes a 31-second delay after every 5 attempts to bypass lockout mechanisms.
- Uses an LED (on pin 1 or 0, depending on the DigiSpark model) to indicate pause states.
- Transitions from 4-digit to 5-digit PINs automatically after exhausting 4-digit combinations.

## Hardware Requirements
- **DigiSpark board** (ATtiny85-based microcontroller with USB interface).
- **USB connection** to the target system (e.g., computer, smartphone, or other device accepting USB keyboard input).
- Optional: An LED connected to pin 1 (or pin 0 for DigiSpark model B) for visual feedback.

## Software Requirements
- **Arduino IDE** or compatible development environment.
- **DigiKeyboard library** (included in the Arduino Library Manager or downloadable from the DigiSpark repository).
- USB drivers for DigiSpark (if required by your system).

## Setup Instructions
1. **Install the DigiKeyboard Library**:
   - Open the Arduino IDE.
   - Go to `Sketch > Include Library > Manage Libraries`.
   - Search for `DigiKeyboard` and install it.
2. **Upload the Script**:
   - Connect the DigiSpark board to your computer via USB.
   - Copy the provided script into the Arduino IDE.
   - Ensure the correct board (e.g., "Digispark (Default - 16.5mhz)") is selected in `Tools > Board`.
   - Upload the sketch to the DigiSpark.
3. **Connect to Target**:
   - After uploading, plug the DigiSpark into the target device's USB port.
   - The script will wait 3 seconds before starting to allow the device to be recognized as a USB keyboard.
4. **Adjust Pin for DigiSpark Model**:
   - The script uses pin 1 for LED output by default. For DigiSpark model B, change `digitalWrite(1, ...)` to `digitalWrite(0, ...)` in the code.

## How It Works
- **Initialization** (`setup()`):
  - Initializes the DigiKeyboard library and sends a null keypress to ensure stability.
  - Waits 3 seconds for the USB connection to stabilize.
- **Main Loop** (`loop()`):
  - Sends a 4-digit PIN (e.g., "0123") as keystrokes, followed by an "Enter" keypress.
  - After exhausting 4-digit PINs (9999), switches to 5-digit PINs (e.g., "01234").
  - Increments PIN digits in a counter-like fashion (right to left).
  - After every 5 attempts, pauses for 31 seconds to avoid lockout mechanisms.
  - Toggles an LED (pin 1 or 0) during the pause for visual feedback.
- **Key Codes**:
  - Uses USB HID key codes for digits 0–9 (e.g., 39 for '0', 30 for '1', ..., 38 for '9').
  - Sends "Enter" (key code 40) to submit each PIN attempt.

## Code Limitations
- **Syntax Issue**: The original code has a missing brace in the `key_stroke_e == false` block. Ensure it is fixed before use:
  ```cpp
  if (key_stroke_e == false) {
      DigiKeyboard.sendKeyStroke(num[a]);
      DigiKeyboard.sendKeyStroke(num[b]);
      DigiKeyboard.sendKeyStroke(num[c]);
      DigiKeyboard.sendKeyStroke(num[d]);
  }
  ```
- **No Termination**: The script runs indefinitely, even after trying all 5-digit PINs. Consider adding a stop condition (e.g., halting or blinking an LED).
- **Lockout Assumption**: The 31-second delay assumes a specific lockout mechanism. Adjust the delay (`delay(31000)`) if the target system uses a different lockout period or attempt limit.
- **Redundant Logic**: The keystroke-sending logic can be optimized by combining 4- and 5-digit cases.

## Performance
- **4-Digit PINs**:
  - Total combinations: 10,000.
  - Time per attempt: ~1 second + keystroke time.
  - Delay: 31 seconds after every 5 attempts (2,000 delay cycles).
  - Estimated time: ~20 hours (72,000 seconds).
- **5-Digit PINs**:
  - Total combinations: 100,000.
  - Delay: 31 seconds after every 5 attempts (20,000 delay cycles).
  - Estimated time: ~8.3 days (720,000 seconds).
- These estimates assume no additional delays or lockouts on the target system.

## Ethical and Legal Warning
This script is designed for **educational purposes** or **authorized penetration testing** only. Using it to attempt unauthorized access to any system or device is **illegal** and may result in severe legal consequences. Always obtain explicit permission from the system owner before running this script.

## Improvements
- Fix the syntax error in the `key_stroke_e == false` block.
- Optimize keystroke logic to reduce redundancy:
  ```cpp
  DigiKeyboard.sendKeyStroke(num[a]);
  DigiKeyboard.sendKeyStroke(num[b]);
  DigiKeyboard.sendKeyStroke(num[c]);
  DigiKeyboard.sendKeyStroke(num[d]);
  if (key_stroke_e) {
      DigiKeyboard.sendKeyStroke(num[e]);
  }
  ```
- Add a termination condition to stop after all PINs are tried.
- Allow configurable delay periods via variables.
- Include error handling for USB connection issues.

## License
This project is provided under the [MIT License](https://opensource.org/licenses/MIT). Use it responsibly and at your own risk.

## Disclaimer
The author and contributors are not responsible for any misuse of this script or any consequences arising from its use. Ensure compliance with all applicable laws and ethical guidelines.
