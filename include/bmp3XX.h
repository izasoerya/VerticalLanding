#ifndef BMP3XX_H
#define BMP3XX_H

#include <Adafruit_BMP3XX.h>
#define BMP3XX_DEFAULT_SPIFREQ (1000000)  ///< The default SPI Clock speed
#define BMP3XX_DEFAULT_ADDRESS (0x77) ///< The default I2C address
class BMP3XX { 
 public:
  BMP3XX();
  Adafruit_BMP3XX bmp;

  float readTemperature(void);
  float readPressure(void);
  float readAltitude(float seaLevel);

  bool setTemperatureOversampling(uint8_t os);
  bool setPressureOversampling(uint8_t os);
  bool setIIRFilterCoeff(uint8_t fs);
  bool setOutputDataRate(uint8_t odr);

  /// Perform a reading in blocking mode
  bool performReading(void);

  /// Temperature (Celsius) assigned after calling performReading()
  double temperature;
  /// Pressure (Pascals) assigned after calling performReading()
  double pressure;

  private:
};
#endif