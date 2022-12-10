//
// File: talkingpenguin.ino (2022-12-06)
//
// The Penguin will regularly voice the actual time and use its
// built-in Neopixels for a cozy Christmas feeling. Update the code
// from its clock function to speak over 1200+ other words. Or why
// not record your messages and make a unique Christmas ornament?
//
// Use the "Talkie Speech Amplifier Shield for ESP32 TinyPICO"
// https://www.tindie.com/products/28296/
//
// Use the shell script to explore 1200+ other pre-defined words.
// https://github.com/berrak/Arduino-Talkie-Speech-Amplifier/tree/master/script
// Learn to record you own phrases with 'Audicity'
// https://github.com/berrak/wav-files-to-arduino-talkie-lpc
//
// GNU Lesser General Public License v3.0

// Copyright (c) 2022 Debinix Team

// Include the configuration and your wifi-credentials
#include "config.h" // customize penguin clock here
#include "secret.h" // update WiFi credentials here
#include <WiFi.h>

const char *ssid = MY_SSID;
const char *password = MY_PWD;
const char *ntp_pool_server = NTP_POOL;

// --------- OTA ESP32 server -------
#include <AsyncElegantOTA.h> // https://github.com/ayushsharma82/AsyncElegantOTA
#include <ESPAsyncWebServer.h> // https://github.com/me-no-dev/ESPAsyncWebServer
// Project descriptions for the OTA update web page
String project_title = "The Talking Penguin";
String project_description =
    "The Talking Penguin.<p> <b>The ornament will regularly voice the actual"
    " time and use its built-in Neopixels for a cozy <a "
    "href='https://www.instructables.com/member/debinix/instructables/"
    "'>Christmas"
    " feeling.</a></p></b> ";

#include "ota_helper.h"

// ----------- Time -----------------
#include <ESP32Time.h>         // https://github.com/fbiego/ESP32Time
ESP32Time rtc(SEC_GMT_OFFSET); // ESP32 real time clock, offset to GMT
struct tm TimeInfo;
#ifdef CLOCK_12HOUR
bool clock_24h_format = false; // AM/PM
#else
bool clock_24h_format = true;
#endif

// ---------- Talkie ---------------
#include "Vocab_Special.h"
#include "Vocab_US_Clock.h"
#include "Vocab_US_Large.h"
#include <Talkie.h>             // https://github.com/ArminJo/Talkie
const int spkr_volume_pin = 26; // GPIO26 controls speaker volume
// forward declarations for helpers
void sayClock(int hour, int minute, bool clock_24h_format);
void sayMinute(int minute);
void sayGreeting(int hour);
void say12hClock(int hour, bool clock_24h_format);

Talkie voice; // The Talkie library for ESP32 use GPIO25.
#include "talkie_helper.h"

// ---------- Neopixels -----------
#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel
// forward declarations for helpers
void colorWipe(uint32_t color, int wait);
void theaterChase(uint32_t color, int wait);
void rainbow(int wait);
void theaterChaseRainbow(int wait);

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#include "adafruit_helper.h"

// ------------------------------------------------------------------
// SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP
// ------------------------------------------------------------------

void setup() {
    Serial.begin(9600);
    delay(100);

    dacWrite(spkr_volume_pin, SPKR_VOLUME_DAC2);

    // Setup WiFi and the OTA server on the ESP32
    otaWiFiInit();

    // Update RTC with NTP time
    // Only year field is important!
    rtc.setTime(00, 59, 23, 24, 12, 2000); // 24th Dec 2000 23:59:00

    // Adjust RTC with NTP
    configTime(0, 0, ntp_pool_server);
    if (getLocalTime(&TimeInfo)) {
        rtc.setTimeStruct(TimeInfo);
    }

    // Wait until date is today's date
    while (rtc.getYear() == 2000) {
        getLocalTime(&TimeInfo);
        rtc.setTimeStruct(TimeInfo);
        delay(1000);
    }

    // Neopixel setup
    strip.begin();
    strip.show();
    strip.setBrightness(LED_BRIGHTNESS);

    Serial.println("Setup completed...waiting for 'MS_UPDATE_TM'");
}
// ------------------------------------------------------------------
// MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP     MAIN LOOP
// ------------------------------------------------------------------

void loop() {

    static uint32_t previous_in_millis_tm = 0;

#ifndef MUTE
    // check to see if it's time to update the talking penguin
    uint32_t current_millis = millis();
    if (current_millis - previous_in_millis_tm >= MS_UPDATE_TM) {
        previous_in_millis_tm = current_millis; // Remember the time

        TimeInfo = rtc.getTimeStruct();
        Serial.println(&TimeInfo, "%A, %B %d %Y %H:%M:%S");

        // Tell the penguin to speak
        sayClock(rtc.getHour(true), rtc.getMinute(), clock_24h_format);
    }
#endif

    /*
     *   Neopixels variants for the cozy Christmas feeling
     *   (Comment/uncomment to combine your favorit effects)
     */

    /* Fill along the length of the ring in various colors */

    colorWipe(strip.Color(255, 0, 0), LED_BRIGHTNESS); // Red
    colorWipe(strip.Color(0, 255, 0), LED_BRIGHTNESS); // Green
    colorWipe(strip.Color(0, 0, 255), LED_BRIGHTNESS); // Blue

    colorWipe(strip.Color(255, 0, 0), LED_BRIGHTNESS); // Red
    colorWipe(strip.Color(0, 255, 0), LED_BRIGHTNESS); // Green
    colorWipe(strip.Color(0, 0, 255), LED_BRIGHTNESS); // Blue

    /* Do a theater marquee effect in various colors */

    //  theaterChase(strip.Color(127, 127, 127), LED_BRIGHTNESS); // White
    theaterChase(strip.Color(127, 0, 0), LED_BRIGHTNESS); // Red
    theaterChase(strip.Color(0, 0, 127), LED_BRIGHTNESS); // Blue

    /* Flowing rainbow cycle for all LEDs */

    rainbow(5);

    /* Rainbow-enhanced theater chase variant */

    //  theaterChaseRainbow(LED_BRIGHTNESS);
}

// EOF
