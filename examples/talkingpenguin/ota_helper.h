// ------------------------------------------------------------------
// HELPERS     HELPERS     HELPERS     HELPERS     HELPERS
// ------------------------------------------------------------------
//
// MIT License

// Copyright (c) 2021 Ralph Bacon
// https://github.com/RalphBacon/228-Wireless-Over-the-Air-OTA-ESP32-updates
// Copyright (c) 2022 Debinix Team,
// Adapted code for the The talking penguin clock.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

// ------------------------------------------------------------------
//          NOTE: NO EDITING BELOW THIS LINE IS REQUIRED
// ------------------------------------------------------------------

// ESP32 WiFi debugging
#include <esp_log.h>
#include <esp_wifi.h>

// forward declarations for helper
const char *wifiStatusToString(wl_status_t status);

AsyncWebServer Server(WEB_SERVER_PORT);
const char *hostname = "penguin";

// ----------------------------------------------------------------
// Connect to WiFi and create the web page, and start the server
// ----------------------------------------------------------------
void otaWiFiInit() {
    printf("Setting ESP32 as Station, no power savings, SSID %s\n", ssid);

    // WiFI debugging
    esp_log_level_set("wifi", ESP_LOG_VERBOSE);

    if (WiFi.status() == WL_CONNECTED) {
        WiFi.disconnect(true, true);
        printf("WiFi was previously connected - now disconnected\n");
    }

    WiFi.setHostname(hostname);

    WiFi.mode(WIFI_STA);
    WiFi.persistent(false);
    WiFi.setAutoReconnect(true);
    WiFi.setSleep(false);

    if (WiFi.begin(ssid, password)) {
        printf("WiFi begin success.\n");
    }
    // WiFi.setTxPower(WIFI_POWER_5dBm);
    delay(2000);

    printf("Connecting to WiFi .");
    uint8_t wifiStatus = WiFi.waitForConnectResult();

    // Successful connection?
    if ((wl_status_t)wifiStatus != WL_CONNECTED) {
        printf("WiFi Status: %s\n",
               wifiStatusToString((wl_status_t)wifiStatus));
        while (true) {
            printf("Failed WiFi connection. Correct the issue, and reset "
                   "controller when fixed.\n");
            delay(5000);
        }
    }

    // WiFi information
    printf("\nRunning on SSID %s with IP %s, Channel %d, MAC address %s\n",
           (char *)WiFi.SSID().c_str(),
           (char *)(WiFi.localIP()).toString().c_str(), WiFi.channel(),
           (char *)WiFi.macAddress().c_str());

    // This gets printed when you type the IP address followed by /whoami
    Server.on("/whoami", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", project_description);
    });

    Server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        // Sending response started
        request->send(200, "text/html",
                      R"(
        <!DOCTYPE HTML>
        <head><title>)" + String(project_title) +
                          R"(</title></head>
        <body style='font-size:1.1em;'>
          <h3>Arduino ESP OTA Home Page</h3>

          <div>Congratulations! You've reached your )" +
                          String(project_title) + R"( ESP32 device on IP )" +
                          String((char *)(WiFi.localIP()).toString().c_str()) +
                          R"(</div>

         <fieldset style="margin:20px 5px 20px 5px;border:1px;border-radius:5px;border:1px solid darkgray;background-color:white">
          <legend style="font-size:0.8em;">Project description:</legend>
            <div style="font-size:0.8em;background-color:#EEEEEE;padding:5px;border-radius:10px;">)" +
                          String(project_description) +
                          R"(</div>
          </fieldset>

          <p>To update your device from the Arduino IDE choose:
          <ul>
            <li><b>Sketch->Export compiled Binary</b>
            <li>then find the sketch folder by choosing
            <li><b>Sketch->Show Sketch Folder</b> and then
            <li>use the 'update' link below to navigate to your '.bin' file to upload.
          </ul>
          </p>

          <p> To update your code type this into your address bar:<br />
            <a href='http://)" +
                          String((char *)(WiFi.localIP()).toString().c_str()) +
                          R"(/update' target='_blank'>http://)" +
                          String((char *)(WiFi.localIP()).toString().c_str()) +
                          R"(/update</a> <br />
            or just click this link.
          </p>
        </body>
        </html>
      )");
        // Sending response ends
    });

    // Starting Async OTA web server
    AsyncElegantOTA.begin(&Server);
    Server.begin();
}

// Convert the WiFi (error) response to a string we can understand
const char *wifiStatusToString(wl_status_t status) {
    switch (status) {
    case WL_NO_SHIELD:
        return "WL_NO_SHIELD";
    case WL_IDLE_STATUS:
        return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL:
        return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED:
        return "WL_SCAN_COMPLETED";
    case WL_CONNECTED:
        return "WL_CONNECTED";
    case WL_CONNECT_FAILED:
        return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST:
        return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED:
        return "WL_DISCONNECTED";
    default:
        return "UNKNOWN";
    }
}

// EOF
