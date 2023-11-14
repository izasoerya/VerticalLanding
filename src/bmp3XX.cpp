#include "bmp3XX.h"

BMP3XX::BMP3XX(){
    _meas_end = 0;
  _filterEnabled = _tempOSEnabled = _presOSEnabled = false;
}

bool BMP3XX::begin_I2C(uint8_t addr, TwoWire *theWire) {
  if (i2c_dev)
    delete i2c_dev;
  if (spi_dev)
    delete spi_dev;
  spi_dev = NULL;
}
bool BMP3XX::begin_SPI(uint8_t cs_pin, SPIClass *theSPI) {
  if (i2c_dev)
    delete i2c_dev;
  if (spi_dev)
    delete spi_dev;
  i2c_dev = NULL;
}
