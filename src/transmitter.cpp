#include "transmitter.h"

LoraDevice::LoraDevice() {}
LoraDevice::~LoraDevice() {}

String LoraDevice::constructMessage(DataType data)
{
    char buffer[64];
    snprintf(buffer, sizeof(buffer),
             "%s,"
             "%.2f,%.2f,%.2f,"
             "%.2f",
             data.state,
             data.angleX, data.angleY, data.angleZ,
             data.altitude);
    return buffer;
}

void LoraDevice::sendMessage(HardwareSerial &Lora, String message)
{
    Lora.println(message);
}