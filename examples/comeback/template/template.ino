#include "edusat.hpp"
#include <TinyGPSPlus.h>
#include "MPU9250.h"
#include "config.hpp"

Button button;
Heat heat;
LED led;
MPU9250 mpu;
MySD sd;
Rover rover;
Speaker sp;
TinyGPSPlus gps;

void setup() {
    Serial.begin(115200);

    // センサ類を初期化する
    button.init();
    heat.init();
    led.init();
    if (!sd.init()) {
        Serial.println("failed to initialize sd card");
        while(1);
    }
    rover.init();
    sp.init();

    delay(1000);

    // 起動音を鳴らす
    sp.beep(wakeup, sizeof(wakeup)/sizeof(float), 150);
    delay(2000);
}

void loop() {
    switch (state)
    {
    case ST_STAND_BY:
        standBy();
        break;

    case ST_DRIVE:
        drive();
        break;

    case ST_GOAL:
        goal();
        break;

    default:
        break;
    }
}

/** 待機状態の処理 */
void standBy() {
    // ここに待機状態の処理を書く
};

/** 目標地点へ走行するときの処理 */
void drive() {
    // ここに目標地点へ走行するときの処理を書く
}

void goal() {
    // ここに目標地点に到達したときの処理を書く
}
