#include <TinyGPSPlus.h>

TinyGPSPlus gps;

// 東京タワーの緯度・経度
double lat1 = 35.658582;
double lng1 = 139.7454544;

// 東京スカイツリーの緯度・経度
double lat2 = 35.7100152;
double lng2 = 139.8107594;

void setup() {
    Serial.begin(115200);

    // 東京タワーとスカイツリーの距離を計算する
    double distance = gps.distanceBetween(
        lat1,
        lng1,
        lat2,
        lng2
    );

    // distance: 8217.95 [m]
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.println(" [m]");

    delay(1000);
}

void loop() {}