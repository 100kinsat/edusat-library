#include <TinyGPSPlus.h>

TinyGPSPlus gps;
HardwareSerial hs(2);

void setup() {
    Serial.begin(115200);
    hs.begin(9600);
}

void loop() {
    while (hs.available() > 0) {
        char c = hs.read();
        gps.encode(c);
        if (gps.location.isUpdated()) {
            Serial.print(gps.location.lat(), 6);
            Serial.print("\t");
            Serial.println(gps.location.lng(), 6);
        }
    }
}