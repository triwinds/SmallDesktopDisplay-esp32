#ifndef SHT30_H
#define SHT30_H
#include <Wire.h>

class SHT3x
{
public:
    SHT3x(uint8_t SDA_PIN, uint8_t SCL_PIN);
    void init();
    void update();
    float getTemperature();
    float getHumidity();
private:
    uint8_t _sdaPin;
    uint8_t _sclPin;
    float _temperature = 0;
    float _humidity = 0;
};

#endif