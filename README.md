# DigiKeyboard PIN Brute-Force Script 🚀

## Overview 📋

This Arduino sketch uses a DigiSpark board to brute-force 4 and 5 digit PINs by simulating USB keyboard input. It tests all combinations from 0000 to 9999, then switches to 00000 to 99999, with a 31-second pause after every 5 attempts to handle lockouts. After testing all PINs, it stops and blinks an LED. 🔢

**Warning**: Use this script **only for educational purposes or authorized testing** ⚠️. Unauthorized use is **illegal** and may violate laws like the Computer Fraud and Abuse Act (CFAA). Always get explicit permission from the system owner.

## Features ✨

- Simulates keyboard input to test 4-digit (10,000) and 5-digit (100,000) PINs. ⌨️
- Pauses 31 seconds after every 5 attempts to avoid lockouts. ⏱️
- Uses LED (pin 1 or 0) to show status. 💡
- Stops and blinks LED after trying all PINs. 🛑
- Switches from 4-digit to 5-digit mode automatically. 🔄

## Hardware Needed 🛠️

- **DigiSpark board** (ATtiny85-based with USB). 🔌
- **USB connection** to the target device (e.g., computer or phone). 📱
- Optional: LED on pin 1 (or pin 0 for DigiSpark model B). 🌟

## Software Needed 💻

- **Arduino IDE** or similar. 🖥️
- **DigiKeyboard library** (available in Arduino Library Manager). 📚
- USB drivers for DigiSpark (if needed). 🔧

## Setup Steps 📝

1. **Install DigiKeyboard Library** 📥:
   - In Arduino IDE, go to `Sketch > Include Library > Manage Libraries`.
   - Search and install `DigiKeyboard`.
2. **Upload the Script** ⬆️:
   - Connect DigiSpark to your computer via USB.
   - Copy the script (`DigiKeyboard_BruteForce.ino`) to Arduino IDE.
   - Select board: `Tools > Board > Digispark (Default - 16.5mhz)`.
   - Upload the sketch.
3. **Connect to Target** 🔗:
   - Plug DigiSpark into the target device’s USB port.
   - Script starts after a 3-second delay for USB recognition.
4. **Adjust for Model B** ⚙️:
   - For DigiSpark model B, change `pinMode(1, OUTPUT)` and `digitalWrite(1, ...)` to pin 0 in the code.

## How It Works 🤖

- **Start**: Initializes USB keyboard and waits 3 seconds. ⏳
- **PIN Testing**: Sends 4-digit PINs (e.g., 0123), then 5-digit PINs (e.g., 01234), followed by Enter. 🔑
- **Lockout Handling**: Pauses 31 seconds after 5 attempts, with LED on during pause. 🕰️
- **Digit Increment**: Counts up digits like a counter (0000 to 9999, then 00000 to 99999). ➕
- **Completion**: Stops after all PINs are tried and blinks LED. 📊

## Performance 📈

- **4-Digit PINs**: ~10,000 attempts, ~20 hours (1s per attempt + 31s pause every 5 attempts). ⌛
- **5-Digit PINs**: ~100,000 attempts, ~8.3 days. ⏰
- Assumes no extra lockouts by the target system.

## Important Notes ⚠️

- **Syntax Fix**: The script has been fixed to avoid compilation errors.
- **LED Pin**: Use pin 1 for standard DigiSpark, pin 0 for model B.
- **Lockout Delay**: Adjust `delay(31000)` if the target system has a different lockout period.
- **Completion**: Script stops and blinks LED after testing all PINs.

## Ethical Warning 🚨

This script is for **educational or authorized testing only**. Unauthorized use to access systems without permission is **illegal** and may lead to legal consequences. Always get explicit consent from the system owner.

## License 📄

Provided under the MIT License. Use responsibly.

## Disclaimer ❗

The author is not responsible for misuse or consequences of this script. Ensure compliance with all laws and ethical guidelines.
