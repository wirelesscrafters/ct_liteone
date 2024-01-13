#include "Arduino.h"
#include "CT_LITEONE.h"

// Constructor
CT_LITEONE::CT_LITEONE() {

}

// LED group function
void CT_LITEONE::ledBegin(bool runLED, bool statusLED) {
    ct_liteone_led.begin();
    ct_liteone_led.show();
    runLEDInit = runLED;
    statusLEDInit = statusLED;
}

void CT_LITEONE::controlLED(uint8_t position, uint32_t color) {
    if(position == 0 && runLEDInit) {
        ct_liteone_led.setPixelColor(CT_LITEONE_RUN_LED, color);
        ct_liteone_led.show();
        return;
    }
    if (position == 1 && statusLEDInit) {
        ct_liteone_led.setPixelColor(CT_LITEONE_STATUS_LED, color);
        ct_liteone_led.show();
        return;
    }
}

void CT_LITEONE::runLED(uint32_t color) {
    if(runLEDInit) {
        ct_liteone_led.setPixelColor(CT_LITEONE_RUN_LED, color);
        ct_liteone_led.show();
    }
}

void CT_LITEONE::statusLED(uint32_t color) {
    if(statusLEDInit) {
        ct_liteone_led.setPixelColor(CT_LITEONE_STATUS_LED, color);
        ct_liteone_led.show();
    }
}

// Button group function
void CT_LITEONE::buttonBegin() {
    pinMode(CT_LITEONE_INPUT_BUTTON, INPUT);
    buttonInit = true;
}

int CT_LITEONE::readButton() {
    if(buttonInit){
        return digitalRead(CT_LITEONE_INPUT_BUTTON);
    } else {
        return -1;
    }
}

// Digital input group function
void CT_LITEONE::digitalBegin(bool D0, bool D1, bool D2) {
    if(D0) {
        pinMode(CT_LITEONE_INPUT_D0, INPUT);
        D0Init = D0;
    }
    if(D1) {
        pinMode(CT_LITEONE_INPUT_D1, INPUT);
        D1Init = D1;
    }
    if(D2) {
        pinMode(CT_LITEONE_INPUT_D2, INPUT);
        D2Init = D2;
    }
}

int CT_LITEONE::digitalReadPin(uint8_t position) {
    if(position == 0 && D0Init) {
        return digitalRead(CT_LITEONE_INPUT_D0);
    } else if(position == 1 && D1Init) {
        return digitalRead(CT_LITEONE_INPUT_D1);
    } else if(position == 2 && D2Init) {
        return digitalRead(CT_LITEONE_INPUT_D2);
    } else {
        return -1;
    }
}

int CT_LITEONE::digitalReadPinD0() {
    if(D0Init){
        return digitalRead(CT_LITEONE_INPUT_D0);
    } else {
        return -1;
    }
}

int CT_LITEONE::digitalReadPinD1() {
    if(D1Init){
        return digitalRead(CT_LITEONE_INPUT_D1);
    } else {
        return -1;
    }
}

int CT_LITEONE::digitalReadPinD2() {
    if(D2Init){
        return digitalRead(CT_LITEONE_INPUT_D2);
    } else {
        return -1;
    }
}