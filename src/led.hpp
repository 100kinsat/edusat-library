#pragma once
#include <Arduino.h>
#include "edusat_config.hpp"

class LED {
public:
    /**
     * @brief Construct a new LED object
     * @param pin LEDを接続しているGPIOピン
     */
    LED(uint8_t pin = LED_DEFAULT_PIN) {
        _pin_led = pin;
    }

    /**
     * @brief Destroy the LED object
     */
    ~LED() {
        digitalWrite(_pin_led, LOW);
    }

    /**
     * @brief GPIOピンの設定を行う
     */
    void init() {
        pinMode(_pin_led, OUTPUT);
    }

    /**
     * @brief LEDを点灯する
     */
    void on() {
        digitalWrite(_pin_led, HIGH);
    }

    /**
     * @brief LEDを消灯する
     */
    void off() {
        digitalWrite(_pin_led, LOW);
    }

private:
    uint8_t _pin_led;
};
