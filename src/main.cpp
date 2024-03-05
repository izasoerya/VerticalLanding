#include <Arduino.h>
#include <Scheduler.h>
#include "BNO.h"
#include "BME280.h"
#include "bmp3XX.h"
#include "Models.h"

void dataBMEFunc();
void dataBNOFunc();
void dataBMPFunc();
void printDataFunc();

TaskScheduler dataBME(1, "dataBME", 100, dataBMEFunc);
TaskScheduler dataBMP(2, "dataBMP", 100, dataBMPFunc);
TaskScheduler dataBNO(3, "dataBNO", 100, dataBNOFunc);
TaskScheduler printData(3, "PrintData", 1000, printDataFunc);

BNO bno;
BME bme;
BMP bmp;
FlightData data;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    bno.begin();
    bno.calibrate();
    bme.begin();
    bme.getTemperature();
    bme.setCurrentPressure();
    bmp.begin();
    bmp.getTemperature();
    float pressure = bmp.getPressure();
    data.basePressure = bme.getPressure();
    Serial.println("base pressure: " + String(data.basePressure));
}

void loop()
{
    // put your main code here, to run repeatedly:
    dataBME.runTask();
    dataBNO.runTask();
    dataBMP.runTask();
    printData.runTask();
}

void dataBMEFunc()
{
    data.temperatureBME = bme.getTemperature();
    data.pressureBME = bme.getPressure();
    data.altitudeBME = bme.getAltitude();
}

void dataBNOFunc()
{
    bno.readSensor();
    data.angleX = bno.getRoll();
    data.angleY = bno.getPitch();
    data.angleZ = bno.getYaw();
}

void dataBMPFunc()
{
    data.temperatureBMP = bmp.getTemperature();
    data.pressureBMP = bmp.getPressure();
    data.altitudeBMP = bmp.getAltitude(data.basePressure / 100.0F);
}

void printDataFunc()
{
    char buffer[256];
    snprintf(buffer, sizeof(buffer),
             "BME280: Temp %0.1f, Press %0.1f, Alti %0.1f,     BMP388: Temp %0.1f, Press %0.1f, Alti %0.1f       BNO055: Roll %0.1f, Pitch %0.1f, Yaw %0.1f,",
             data.temperatureBME, data.pressureBME, data.altitudeBME, data.temperatureBMP, data.pressureBMP, data.altitudeBMP, data.angleX, data.angleY, data.angleZ);
    Serial.println(String(buffer));
}