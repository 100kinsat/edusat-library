#pragma once
#include <Arduino.h>
#include "esp32-hal-ledc.h"

class Motor {
public:
    /**
     * @brief Construct a new Motor object
     * @param in1 モータのプラスピン
     * @param in2 モータのマイナスピン
     * @param pwm モータのPWMピン
     * @param channel チャンネル
     */
    Motor(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t channel) {
        _in1 = in1;
        _in2 = in2;
        _pwm = pwm;
        _channel = channel;
    }

    ~Motor() {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        ledcWrite(_channel, LOW);
        ledcDetachPin(_pwm);
    }

    /**
     * @brief モータの設定の初期化
     * @param freq 周波数（Hz）
     * @param resolution_bits PWMの範囲（bit）
     */
    void init(double freq, uint8_t resolution_bits) {
        pinMode(_in1, OUTPUT);
        pinMode(_in2, OUTPUT);
        pinMode(_pwm, OUTPUT);

        ledcSetup(_channel, freq, resolution_bits);
        ledcAttachPin(_pwm, _channel);
    }

    /**
     * @brief モータの駆動
     * @param s1 プラスピンへの出力
     * @param s2 マイナスピンへの出力
     * @param duty PWM値
     */
    void drive(int s1, int s2, uint8_t duty) {
        digitalWrite(_in1, s1);
        digitalWrite(_in2, s2);
        ledcWrite(_channel, duty);
    }

protected:
    uint8_t _in1;
    uint8_t _in2;
    uint8_t _pwm;
    uint8_t _channel;
};
