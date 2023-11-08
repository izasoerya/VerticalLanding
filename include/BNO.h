#ifndef BNO_H
#define BNO_H

#include <Adafruit_BNO055.h>

class BNO {
  public:
    BNO();
    void begin();
    void readSensor();
    float getHeading();
    float getRoll();
    float getPitch();
  private:
    Adafruit_BNO055 bno;
    float heading;
    float roll;
    float pitch;
};

#endif
