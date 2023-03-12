#include "edusat.hpp"

Heat heat;

void setup() {
    heat.init();

    delay(2000);
}

void loop() {
    heat.on();
    delay(500); // !!!電熱線を加熱しすぎると危険であるため、電熱線への出力時間に注意すること!!!
    heat.off();
    delay(1000);

    while(1) {}
}
