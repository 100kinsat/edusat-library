#include "edusat.hpp"

Motor m = Motor(
    LEFT_MOTOR_PLUS_DEFAULT_PIN,
    LEFT_MOTOR_MINUS_DEFAULT_PIN,
    LEFT_MOTOR_PWM_DEFAULT_PIN,
    LEFT_MOTOR_LEDC_CHANNEL
);

void setup() {
    m.init(LEDC_BASE_FREQ_490, LEDC_TIMER_8_BIT);

    delay(2000);
}

void loop() {
    m.drive(HIGH, LOW, 255);
    delay(1000);

    m.drive(HIGH, HIGH, 0);
    delay(1000);

    m.drive(LOW, HIGH, 255);
    delay(1000);

    m.drive(HIGH, HIGH, 0);
    delay(1000);
}
