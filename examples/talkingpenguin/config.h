// ------------------------------------------------------------------
// CONFIGURATION     CONFIGURATION    CONFIGURATION     CONFIGURATION
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// TIME ZONES       TIME ZONES      TIME ZONES      TIME ZONES
// ------------------------------------------------------------------

// https://www.pool.ntp.org/zone/north-america

#define NTP_POOL "us.pool.ntp.org"
#define SEC_GMT_OFFSET 68400 // New York, EST (GMT-5 i.e. GMT+19)
// #define SEC_GMT_OFFSET 64800     // Dallas, CST (GMT-6 i.e. GMT+18)
// #define SEC_GMT_OFFSET 57600     // San Francisco, PST (GMT-8 i.e. GMT+16)

// #define NTP_POOL "ca.pool.ntp.org"
// #define SEC_GMT_OFFSET 68400     // Torronto, EST (GMT-5 i.e. GMT+19)

// https://www.pool.ntp.org/zone/europe

// #define NTP_POOL "uk.pool.ntp.org"
// #define SEC_GMT_OFFSET 0          // London, GMT
// #define NTP_POOL "de.pool.ntp.org"
// #define SEC_GMT_OFFSET 3600       // Berlin, CET (GMT+1)
// #define NTP_POOL "fr.pool.ntp.org"
// #define SEC_GMT_OFFSET 3600       // Paris, CET (GMT+1)

// ------------------------------------------------------------------
// NEOPIXEL SETTINGS        NEOPIXEL SETTINGS  NEOPIXEL SETTINGS
// ------------------------------------------------------------------

// High brightness and a large number of used LEDs draw lots of
// electrical currents. Be conservative not to overload the ESP
// 5V pin output. If using a more significant number of LEDs,
// use an external 5V adapter to drive these.

#define LED_PIN 4    // ESP32 TinyPICO GPIO 4
#define LED_COUNT 12 // 12 LEDs Neopixel pixel ring

#define LED_BRIGHTNESS 25 // Adjust LED brightness (max = 255)

// ------------------------------------------------------------------
// PENGUIN TALKING      PENGUIN TALKING     PENGUIN TALKING
// ------------------------------------------------------------------

// How often the penguin will speach, in milliseconds

// #define MS_UPDATE_TM 3600000     // 1 hour
// #define MS_UPDATE_TM 1800000     // 30 minutes
// #define MS_UPDATE_TM  900000     // 15 minutes
// #define MS_UPDATE_TM   60000     // 1 minutes
#define MS_UPDATE_TM 10000 // 10 seconds, for test

// Speaker volume '0 to 255'

#define SPKR_VOLUME_DAC2 255 // 3.3V

// Remove comment to stop the penguin from talking ;-(
// #define MUTE

// ------------------------------------------------------------------
// CLOCK 12/24H     CLOCK 12/24H        CLOCK 12/24H
// ------------------------------------------------------------------

#define CLOCK_12HOUR // Comment out for 24-hour clock

// ------------------------------------------------------------------
// WIFI-OTA UPDATE      WIFI-OTA UPDATE     WIFI-OTA UPDATE
// ------------------------------------------------------------------

#define WEB_SERVER_PORT 80 // The Over-The-Air ESP32 update server port

// EOF
