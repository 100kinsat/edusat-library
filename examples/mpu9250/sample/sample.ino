#include "MPU9250.h"

MPU9250 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.setup(0x68)) {
        Serial.println("failed to connect sensor");
        while(1);
    }

    delay(2000);
}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            Serial.print("acc x: ");    Serial.print(mpu.getAccX());
            Serial.print("\t y: ");     Serial.print(mpu.getAccY());
            Serial.print("\t z: ");     Serial.print(mpu.getAccZ());
            Serial.print("\tgyro x: "); Serial.print(mpu.getGyroX());
            Serial.print("\t y: ");     Serial.print(mpu.getGyroY());
            Serial.print("\t z: ");     Serial.print(mpu.getGyroZ());
            Serial.print("\t mag x: "); Serial.print(mpu.getMagX());
            Serial.print("\t y: ");     Serial.print(mpu.getMagY());
            Serial.print("\t z: ");     Serial.print(mpu.getMagZ());
            Serial.println();
            prev_ms = millis();
        }
    }
}
