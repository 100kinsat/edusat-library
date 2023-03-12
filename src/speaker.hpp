#pragma once
#include <Arduino.h>
#include "esp32-hal-ledc.h"
#include "edusat_config.hpp"

class Speaker {
public:
    /**
     * @brief Construct a new Speaker object
     * @param pin スピーカーのピン
     * @param channel チャンネル
     */
    Speaker(uint8_t pin = SPEAKER_DEFAULT_PIN, uint8_t channel = SPEAKER_LEDC_CHANNEL) {
        _sp = pin;
        _channel = channel;
    }

    ~Speaker() {
        ledcWrite(_channel, LOW);
        ledcDetachPin(_sp);
    }

    /**
     * @brief GPIOピンの設定を行う
     * @param freq 周波数（Hz）
     * @param resolution_bits PWMの範囲（bit）
     */
    void init(double freq = LEDC_BASE_FREQ_5000, uint8_t resolution_bits = LEDC_BASE_FREQ_5000) {
        pinMode(_sp, OUTPUT);
        ledcSetup(_sp, freq, resolution_bits);
        ledcAttachPin(_sp, _channel);
    }

    /**
     * @brief スピーカーから音を鳴らす
     * @param mm 鳴らしたい音の配列
     * @param m_size 配列のサイズ
     * @param t_ms ひとつの音を鳴らす秒数
     */
    void beep(const float *mm, int m_size, int t_ms) {
        for (int i = 0; i < m_size; i++) {
            _tone(mm[i], t_ms);
        }
        _noTone();
    }

private:
    uint8_t _sp;
    uint8_t _channel;

    /**
     * @brief スピーカーの音を鳴らす
     * @param freq 鳴らす音の周波数
     * @param t_ms 鳴らす秒数
     */
    void _tone(float freq, int t_ms) {
        ledcWriteTone(_channel, freq);
        delay(t_ms);
    }

    /**
     * @brief スピーカーの音を止める
     */
    void _noTone() {
        ledcWriteTone(_channel, 0.0);
    }
};
