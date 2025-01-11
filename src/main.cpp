#include <Arduino.h>
#include "sensor_SM_HD38.h"

sensor_sm_hd38 hd38(4);

void setup() {
    // attention baudrate
    Serial.begin(115200);

    // Check wire analog-connection of HD-38 board sensor.
    while (!hd38.measure()) {
        Serial.println("HD38 not found !");
        delay(1000);
    }

}



void loop() {
    // moisty sensor
    if (hd38.measure()) {
        Serial.print("Bodenfeuchte: ");
        Serial.println(hd38.getSensorValue());
        Serial.println();
    } else {
        Serial.println("HD38 read error");
    }
    delay(2000);
}