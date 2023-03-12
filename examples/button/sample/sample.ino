#include "edusat.hpp"

Button button;

void setup() {
    Serial.begin(115200);
    button.init();

    delay(2000);
}

void loop() {
    if (button.status()) {
        Serial.println("ON"); // ボタンが押されている
    } else {
        Serial.println("OFF"); // ボタンが押されていない
    }
    delay(100);
}