#ifndef TEMT6000_H
#define TEMT6000_H
#include <Wire.h>

class Temt6000
{
public:
    Temt6000(uint8_t pin);
    float read();
private:
    uint8_t _pin;

    // Kalman filter
    float _q = 0.001;  // Process variance
    float _r = 0.01;  // Measurement variance
    float _x = 0.1;      // Last estimate
    float _p = _r * _r;      // Last estimate covariance
    float _k = _p / (_p + _r);      // Kalman gain
};

#endif