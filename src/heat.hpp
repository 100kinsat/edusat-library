#pragma once
#include <Arduino.h>
#include "edusat_config.hpp"

class Heat {
public:
    /**
     * @brief Construct a new Heat object
     * @param pin 電熱線を接続しているGPIOピン
     */
    Heat(uint8_t pin = HEAT_DEFAULT_PIN) {
        _pin_heat = pin;
    }

    ~Heat() {
        digitalWrite(_pin_heat, LOW);
    }

    /**
     * @brief GPIOピンの設定を行う
     */
    void init() {
        pinMode(_pin_heat, OUTPUT);
        digitalWrite(_pin_heat, LOW); // 電熱線のピンはLOWにしておく
    }

    /**
     * @brief 電熱線を加熱する
     */
    void on() {
        digitalWrite(_pin_heat, HIGH);
    }

    /**
     * @brief 電熱線の加熱を停止する
     */
    void off() {
        digitalWrite(_pin_heat, LOW);
    }

private:
    uint8_t _pin_heat;
};
