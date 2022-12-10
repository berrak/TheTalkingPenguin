// ------------------------------------------------------------------
// HELPERS     HELPERS     HELPERS     HELPERS     HELPERS
// ------------------------------------------------------------------
// Adafruit GNU Lesser General Public License v3.0
// ------------------------------------------------------------------

// Adafruit example sketch
void colorWipe(uint32_t color, int wait) {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

// Adafruit example sketch
void theaterChase(uint32_t color, int wait) {
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 3; b++) {
            strip.clear();
            for (int c = b; c < strip.numPixels(); c += 3) {
                strip.setPixelColor(c, color);
            }
            strip.show();
            delay(wait);
        }
    }
}

// Adafruit example sketch
void rainbow(int wait) {

    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536;
         firstPixelHue += 256) {
        strip.rainbow(firstPixelHue);
        strip.show();
        delay(wait);
    }
}

// Adafruit example sketch
void theaterChaseRainbow(int wait) {
    int firstPixelHue = 0;
    for (int a = 0; a < 30; a++) {
        for (int b = 0; b < 3; b++) {
            strip.clear();

            for (int c = b; c < strip.numPixels(); c += 3) {

                int hue = firstPixelHue + c * 65536L / strip.numPixels();
                uint32_t color =
                    strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
                strip.setPixelColor(c, color);
            }
            strip.show();
            delay(wait);
            firstPixelHue += 65536 / 90;
        }
    }
}
