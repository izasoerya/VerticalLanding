#ifndef BMP388_H
#define BMP388_H

#include "Adafruit_BMP3XX.h"
#include <math.h>


class SensorBMP {
private:
    Adafruit_BMP3XX bmp;
    struct kalmanVar {
      float Estimate = 0;
      float ErrorEstimate = 0.3;
      float Gain;
      float Measurement;
    };
    float ePressure;
public:
    SensorBMP();
    bool begin();
    float getTemperature();
    float getPressure();
    float getAltitude(float basePressure);
    bool getSensorStatus();

};

#endif