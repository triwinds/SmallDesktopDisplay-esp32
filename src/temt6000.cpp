#include "temt6000.h"

Temt6000::Temt6000(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

float Temt6000::read() {
    
    auto val = (float)analogRead(_pin) / 4095.0;
    // Kalman filter
    _p = _p + _q;
    _k = _p / (_p + _r);
    _x = _x + _k * (val - _x);
    _p = (1 - _k) * _p;
    // End Kalman filter
    return _x;
}