#include "sensor_SM_HD38.h"

#include <iostream>


sensor_sm_hd38::sensor_sm_hd38(const uint8_t sensorPin) {
    this->_sensorPin = sensorPin;
}

bool sensor_sm_hd38::measure() {
    this->_sensorValue = analogRead(this->_sensorPin);
    delay(20);

    constexpr int error_size = SENSOR_SM_HD38_ERROR_GND_Z;

    if  (this->_sensorValue < error_size) {
        return true;
    }
    std::cout << "The sensor need ground from board GND";
    return false;
}

float sensor_sm_hd38::getSensorValue() const {
    return this->_sensorValue;
}
