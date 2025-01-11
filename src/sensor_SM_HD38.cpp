#include "sensor_SM_HD38.h"

#include <iostream>



bool sensor_sm_hd38::init(const uint8_t pin) {
    this->_sensorPin = pin;
    return true;
}

bool sensor_sm_hd38::measure() {
    this->_sensorValue = analogRead(this->_sensorPin);

    delay(20);

    constexpr int error_size = SENSOR_SM_HD38_ERROR_GND_Z;

    if  (this->_sensorValue < error_size && this->_sensorValue > 0) {
        std::cout << "The sensor have a valid measure";
        return true;
    }

    std::cout << "The sensor need ground from board GND or real dry.";
    return false;
}

int sensor_sm_hd38::getSensorValue() const {
    return this->_sensorValue;
}

bool sensor_sm_hd38::isWet() {

    if (measure()) {
        return true;
    }
    return false;
}
