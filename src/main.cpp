#include <Arduino.h>
#include "sensor_SM_HD38.h"

sensor_sm_hd38 hd38;
int value = 0;

void setup() {
    // attention baudrate
    Serial.begin(115200);

    hd38.init(4);

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
        value = hd38.getSensorValue();
        if (value < 700) {
            Serial.print("Salziges Wasser ");
        }
        if (value > 1000) {
            Serial.print("Die Erde wird Trocken ");
        }
        if (value > 2000) {
            Serial.print("Die Erde ist fast ausgetrocknet ");
        }
        Serial.println(value);
        Serial.println();
    } else {
        Serial.println("Error or extrem Dry.");
        Serial.print("Bodenfeuchte: ");
        value = hd38.getSensorValue();
        Serial.println(value);
        Serial.println();
    }
    delay(20000);
}