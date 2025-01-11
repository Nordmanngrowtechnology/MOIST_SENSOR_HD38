#ifndef SENSOR_SM_HD38_H
#define SENSOR_SM_HD38_H

#include <Arduino.h>

#define SENSOR_SM_HD38_ERROR_GND_Z 4095; // if sensor have no GND contact on board it returns 4095 or 0


class sensor_sm_hd38 {
  private:

    int _sensorValue{};
    int _sensorPin{};

  public:
  sensor_sm_hd38() = default;
    bool init(uint8_t pin);
    bool measure();
    int getSensorValue() const;

     bool isWet() ;
};

#endif //SENSOR_SM_HD38_H
