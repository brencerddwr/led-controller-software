/*
 * This class handles web requests and interfaces with the light strip.
 */

#ifndef API_h
#define API_h

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include "lightstripcontroller.h"

enum Path {
    ON,
    HUE,
    SATURATION,
    BRIGHTNESS,
    NAME,
    SAVE_DEFAULT
};

class APIHandler {
    public:
        void setup();
        void loop();

        APIHandler(ESP8266WebServer &aServer, LightStripController &lightStrip);

    private:
        ESP8266WebServer &server;
        LightStripController &strip;
        void handleRequest();
        void handleGETRequest();
        void handlePOSTRequest();
        void handleNotFound();
        void sendSuccess();
        void sendError(int code, String description);
        void sendRawValue(String value);
        Path parsePath();
};

#endif