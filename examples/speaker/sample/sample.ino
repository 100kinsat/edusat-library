#include "edusat.hpp"

Speaker sp;

const float mC = 261.626; // ド
const float mD = 293.665; // レ
const float mE = 329.628; // ミ
const float mF = 349.228; // ファ
const float mG = 391.995; // ソ
const float mA = 440.000; // ラ 
const float mB = 493.883; // シ
const float nn = 0.0;

// 鳴らしたいメロディの配列
const float beep_example[8] = {
    mC * 2,
    mD * 2,
    mE * 2,
    mF * 2,
    mG * 2,
    mA * 2,
    mB * 2,
    mC * 4,
};

void setup() {
    sp.init();

    sp.beep(
        beep_example, // 鳴らしたいメロディの配列
        sizeof(beep_example) / sizeof(float), // 配列のサイズ
        150 // ひとつの音を鳴らす秒数（ミリ秒）
    );

    delay(2000);
}

void loop() {}