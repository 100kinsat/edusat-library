#include "edusat.hpp"

MySD sd;

void setup() {
    Serial.begin(115200);
    if (!sd.init()) {
        Serial.println("failed to initialize sd card");
        while(1);
    }
    delay(1000);

    if (
        sd.writeFile("/100kinsat.txt", "Hello 100kinSAT!!!\n")
    ) {
        Serial.println("success written to file");
    } else {
        Serial.println("failed to write file");
    }
    delay(1000);

    if (
        sd.appendFile("/100kinsat.txt", "This is additional text.\n")
    ) {
        Serial.println("success written to file");
    } else {
        Serial.println("failed to write file");
    }
    delay(1000);

    Serial.println("done");
    delay(1000);
}

void loop() {}