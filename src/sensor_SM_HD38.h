#ifndef SENSOR_SM_HD38_H
#define SENSOR_SM_HD38_H

#include <Arduino.h>

#define SENSOR_SM_HD38_PIN 4
#define SENSOR_SM_HD38_ERROR_GND_Z 4095; // if sensor have no GND contact on board it returns 4095 or 0


class sensor_sm_hd38 {
  private:
    float _sensorValue{};
    int _sensorPin;

  public:
    explicit sensor_sm_hd38(uint8_t sensorPin = SENSOR_SM_HD38_PIN);
    bool measure();
    float getSensorValue() const;
};

#endif //SENSOR_SM_HD38_H
