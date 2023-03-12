#pragma once
#include <Arduino.h>
#include "edusat_config.hpp"
#include "motor.hpp"

class Rover {
public:
    /**
     * @brief Construct a new Rover object
     */
    Rover() {}

    /**
     * @brief モータの設定の初期化
     * @param freq 周波数（Hz）
     * @param resolution_bits PWMの範囲（bit）
     */
    void init(double freq = LEDC_BASE_FREQ_490, uint8_t resolution_bits = LEDC_TIMER_8_BIT) {
        m1.init(freq, resolution_bits);
        m2.init(freq, resolution_bits);
    }

    /**
     * @brief 機体を前進させる
     * @param left_pwm 左モータの出力値
     * @param right_pwm 右モータの出力値
     */
    void forward(uint8_t left_pwm, uint8_t right_pwm) {
        m1.drive(LOW, HIGH, left_pwm);
        m2.drive(HIGH, LOW, right_pwm);
    }

    /**
     * @brief 機体を左へ旋回させる
     * @param left_pwm 左モータの出力値
     * @param right_pwm 右モータの出力値
     */
    void turnLeft(uint8_t left_pwm, uint8_t right_pwm) {
        m1.drive(HIGH, LOW, left_pwm);
        m2.drive(HIGH, LOW, right_pwm);
    }

    /**
     * @brief 機体を右へ旋回させる
     * @param left_pwm 左モータの出力値
     * @param right_pwm 右モータの出力値
     */
    void turnRight(uint8_t left_pwm, uint8_t right_pwm) {
        m1.drive(HIGH, LOW, left_pwm);
        m2.drive(LOW, HIGH, right_pwm);
    }

    /**
     * @brief 機体を後退させる
     * @param left_pwm 左モータの出力値
     * @param right_pwm 右モータの出力値
     */
    void back(uint8_t left_pwm, uint8_t right_pwm) {
        m1.drive(HIGH, LOW, left_pwm);
        m2.drive(LOW, HIGH, right_pwm);
    }

    /**
     * @brief 機体を停止させる
     */
    void stop() {
        m1.drive(HIGH, HIGH, LOW);
        m2.drive(HIGH, HIGH, LOW);
    }

private:
    /** 左モータ */
    Motor m1 = Motor(
        LEFT_MOTOR_PLUS_DEFAULT_PIN,
        LEFT_MOTOR_MINUS_DEFAULT_PIN,
        LEFT_MOTOR_PWM_DEFAULT_PIN,
        LEFT_MOTOR_LEDC_CHANNEL
    );

    /** 右モータ */
    Motor m2 = Motor(
        RIGHT_MOTOR_PLUS_DEFAULT_PIN,
        RIGHT_MOTOR_MINUS_DEFAULT_PIN,
        RIGHT_MOTOR_PWM_DEFAULT_PIN,
        RIGHT_MOTOR_LEDC_CHANNEL
    );
};
