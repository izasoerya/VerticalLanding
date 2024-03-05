#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include "Models.h"

class LoraDevice
{
private:
public:
    LoraDevice();
    ~LoraDevice();

    void sendMessage(HardwareSerial &Lora, String message);
    String constructMessage(FlightData data);

    
    void receiveMessage();
};

#endif