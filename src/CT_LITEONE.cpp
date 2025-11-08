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

int CT_LITEONE::digitalReadPin(uint8_t pin) {
    if(pin == 0 && D0Init) {
        return digitalRead(CT_LITEONE_INPUT_D0);
    } else if(pin == 1 && D1Init) {
        return digitalRead(CT_LITEONE_INPUT_D1);
    } else if(pin == 2 && D2Init) {
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

// Analog input group function
void CT_LITEONE::adcBegin(uint8_t Vref) {
    pinMode(CT_LITEONE_SPI_CS, OUTPUT);
    digitalWrite(CT_LITEONE_SPI_CS, HIGH);
    if(!spiInit) {
        SPI.begin();
        spiInit = true;
    }
    _Vref = Vref;
    adcInit = true;
}

uint8_t CT_LITEONE::spiTransfer(uint8_t i) {
    if(spiInit && adcInit) {
        uint8_t d;
        d = SPI.transfer(i);
        return d;
    }
    return 0;
}

uint16_t CT_LITEONE::analogRead(uint8_t pin) {
    if(spiInit && adcInit) {
        uint8_t addr = 0b01100000 | ((pin & 0b111) << 2);
        digitalWrite(CT_LITEONE_SPI_CS, LOW);
        (void) spiTransfer(addr);
        uint8_t b1 = spiTransfer(0);
        uint8_t b2 = spiTransfer(0);
        digitalWrite(CT_LITEONE_SPI_CS, HIGH);

        return (b1 << 4) | (b2 >> 4);
    }
    return 0
}

// RS485 group function

void CT_LITEONE::_preTransmission() { digitalWrite(CT_LITEONE_INPUT_FC, 1); }
void CT_LITEONE::_postTransmission() { digitalWrite(CT_LITEONE_INPUT_FC, 0); }

void CT_LITEONE::rs485Begin(uint32_t baudrate, uint32_t config, uint32_t timeout) {
    pinMode(CT_LITEONE_INPUT_FC, OUTPUT);
    digitalWrite(CT_LITEONE_INPUT_FC, LOW);
    Serial1.begin(baudrate, config, CT_LITEONE_INPUT_RX, CT_LITEONE_INPUT_TX, timeout_ms=timeout);
    RS485Init = true;
}

int CT_LITEONE::rs485Configure(uint16_t address) {
    if(RS485Init) {
        ct_liteone_rs485.begin(address, Serial1);
        ct_liteone_rs485.preTransmission(_preTransmission);
        ct_liteone_rs485.postTransmission(_postTransmission);
        return 1;
    } else {
        return -1;
    }
}