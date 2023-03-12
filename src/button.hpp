#pragma once
#include <Arduino.h>
#include "edusat_config.hpp"

class Button {
public:
    /**
     * @brief Construct a new Button object
     * @param pin ボタンを接続しているGPIOピン
     */
    Button(uint8_t pin = BUTTON_DEFAULT_PIN) {
        _pin_button = pin;
    }

    /**
     * @brief GPIOピンの設定を行う
     */
    void init() {
        pinMode(_pin_button, INPUT);
    }

    /**
     * @brief ボタンのステータスを返却する
     * @return true ボタンが押されている
     * @return false ボタンが押されていない
     */
    bool status() {
        return !digitalRead(_pin_button);
    }

private:
    uint8_t _pin_button;
};
