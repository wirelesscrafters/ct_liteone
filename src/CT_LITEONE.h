#ifndef __CT_LITEONE_h
#define __CT_LITEONE_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "ModbusMaster.h"
#include "CT_LEDCOLORS.h"
#include "SPI.h"

class CT_LITEONE {


    private:
        // LED pin group variable
        static const uint8_t CT_LITEONE_LED_PIN         = 25;
        static const uint8_t CT_LITEONE_LED_COUNT       = 2;
        static const uint8_t CT_LITEONE_RUN_LED         = 0;
        static const uint8_t CT_LITEONE_STATUS_LED      = 1;

        // Button pin group variable
        static const uint8_t CT_LITEONE_INPUT_BUTTON    = 39;

        // Digital input pin group variable
        static const uint8_t CT_LITEONE_INPUT_D0        = 15;
        static const uint8_t CT_LITEONE_INPUT_D1        = 34;
        static const uint8_t CT_LITEONE_INPUT_D2        = 35;

        // SPI pin group variable
        static const uint8_t CT_LITEONE_SPI_CS        = 5;
        static const uint8_t CT_LITEONE_SPI_CLK       = 18;
        static const uint8_t CT_LITEONE_SPI_MISO      = 19;
        static const uint8_t CT_LITEONE_SPI_MOSI      = 23;

        // RS485 pin group variable
        static const uint8_t CT_LITEONE_INPUT_FC        = 12; // FC or DE
        static const uint8_t CT_LITEONE_INPUT_TX        = 13;
        static const uint8_t CT_LITEONE_INPUT_RX        = 14;

        // LED group variable
        bool runLEDInit = false;
        bool statusLEDInit = false;

        // Button group variable
        bool buttonInit = false;

        // Digital input group variable
        bool D0Init = false;
        bool D1Init = false;
        bool D2Init = false;

        // Analog input group variable
        bool spiInit = false;
        bool adcInit = false;
        uint8_t _Vref = 0;

        // RS485 group variable
        bool RS485Init = false;

        void _preTransmission();
        void _postTransmission();
        uint8_t spiTransfer(uint8_t);

    public:
        // Global object
        Adafruit_NeoPixel ct_liteone_led = Adafruit_NeoPixel(CT_LITEONE_LED_COUNT, CT_LITEONE_LED_PIN, NEO_GRB + NEO_KHZ800);
        ModbusMaster ct_liteone_rs485;

        CT_LITEONE(); // Constructor

        // Chip detial group function

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
        int digitalReadPin(uint8_t pin);
        int digitalReadPinD0();
        int digitalReadPinD1();
        int digitalReadPinD2();

        // Analog input group function
        void adcBegin(uint8_t Vref);
        uint16_t analogRead(uint8_t pin)

        // RS485 group function
        void rs485Begin(uint32_t baudrate=9600, uint32_t config=SERIAL_8N1, uint32_t timeout=1000);
        int rs485Configure(uint16_t address=0x01);
};

#endif