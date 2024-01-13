#ifndef __CT_LITEONE_h
#define __CT_LITEONE_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "Adafruit_ADS1X15.h"
#include "CT_LEDCOLORS.h"

class CT_LITEONE {
// LED group define
#define CT_LITEONE_LED_PIN 25
#define CT_LITEONE_LED_COUNT 2
#define CT_LITEONE_RUN_LED 0
#define CT_LITEONE_STATUS_LED 1

// Button group define
#define CT_LITEONE_INPUT_BUTTON 39

// Digital input group define
#define CT_LITEONE_INPUT_D0 15
#define CT_LITEONE_INPUT_D1 34
#define CT_LITEONE_INPUT_D2 35

    private:
        // LED group variable
        bool runLEDInit = false;
        bool statusLEDInit = false;

        // Button group variable
        bool buttonInit = false;

        // Digital input group variable
        bool D0Init = false;
        bool D1Init = false;
        bool D2Init = false;

    public:
        // Global object
        Adafruit_NeoPixel ct_liteone_led = Adafruit_NeoPixel(CT_LITEONE_LED_COUNT, CT_LITEONE_LED_PIN, NEO_GRB + NEO_KHZ800);
        Adafruit_ADS1115 ct_liteone_ads;

        CT_LITEONE(); // Constructor

        // LED group function
        void ledBegin(bool runLED=true, bool statusLED=true);
        void controlLED(uint8_t position, uint32_t color);
        void runLED(uint32_t color);
        void statusLED(uint32_t color);

        // Button group function
        void buttonBegin();
        int readButton();

        // Digital input group function
        void digitalBegin(bool D0=true, bool D1=true, bool D2=true);
        int digitalReadPin(uint8_t position);
        int digitalReadPinD0();
        int digitalReadPinD1();
        int digitalReadPinD2();


};

#endif