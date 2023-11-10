#ifndef SCHEDULELR_H
#define SCHEDULELR_H

#include <Arduino.h>

class TaskScheduler{
private:
    String name;
    uint16_t delay;
    uint8_t idTask;
    uint32_t prevMillis = 0;
    void *theTask;    

public:
    TaskScheduler(uint8_t idTask, String name, uint16_t delay, void (*theTask)());
    void runTask(uint8_t idTask);
    void suspendTask(uint8_t idTask);
    void resumeTask(uint8_t idTask);
};

#endif