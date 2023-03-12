const float mC = 261.626; // ド
const float mD = 293.665; // レ
const float mE = 329.628; // ミ
const float mF = 349.228; // ファ
const float mG = 391.995; // ソ
const float mA = 440.000; // ラ 
const float mB = 493.883; // シ
const float nn = 0.0;

// 起動音
const float wakeup[7] = {
    mE * 4,
    mA * 4,
    mB * 4,
    mA * 4,
    mE * 2,
    mE * 4,
    mB * 4
};

// CanSatのステータス
enum {
    ST_STAND_BY = 0, // 待機状態
    ST_DRIVE,        // 目標地点へ走行する状態
    ST_GOAL,         // 目標地点に到達した状態
};
int state = ST_STAND_BY;
