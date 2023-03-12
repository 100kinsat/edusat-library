#include "edusat.hpp"

LED led;

void setup() {
    led.init();

    delay(2000);
}

void loop() {
    led.on();
    delay(500);
    led.off();
    delay(500);
}
