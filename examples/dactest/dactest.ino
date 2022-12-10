//
// File: dactest.ino (2022-12-04)
// Demo: Test DAC output from a non-official ESP32 board.
// Recommended boards: UM ESP32 TinyPICO (or Lolin ESP32-S2 D1-mini).
// Use the "The TinyLedSwitch Breakout Board" for this DAC test setup.
// https://www.tindie.com/stores/debinix/
//
// GNU Lesser General Public License v3.0

// Copyright (c) 2022 Debinix Team

// Verify you can set the DAC pins with code.
// Use the 'TinyLedSwitch Breakout Board' (from the Tindie store),
// or use discrete LEDs and two current limiting resistors.
// Alternatively, use a voltmeter to check voltages at the pins.

// DAC1 and DAC2 are pre-defined as GPIO25 and GPIO26, respectively.

#define DAC_OFF 0
const int value = 255; // 8bit DAC '255' = max voltage out, i.e. 3.3V.

// ------------------------------------------------------------------
// SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP
// ------------------------------------------------------------------
void setup() {
    Serial.begin(9600);
    delay(1000);
    Serial.println("Setup completed...");
}
// ------------------------------------------------------------------
// MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP
// ------------------------------------------------------------------
void loop() {

    dacWrite(DAC1, value);
    dacWrite(DAC2, DAC_OFF);
    delay(2000);
    dacWrite(DAC1, DAC_OFF);
    dacWrite(DAC2, value);
    delay(2000);
}
