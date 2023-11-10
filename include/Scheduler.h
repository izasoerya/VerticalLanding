#ifndef SCHEDULELR_H
#define SCHEDULELR_H

#include <Arduino.h>
typedef void (*TaskFunction)();  // Define a typedef for the function pointer type

class TaskScheduler{
private:
    String name;
    uint16_t delay;
    uint8_t idTask;
    uint32_t prevMillis = 0;
    TaskFunction taskFunc;
    bool isSuspended = false;  

public:
    TaskScheduler(uint8_t idTask, String name, uint16_t delay, TaskFunction taskFunc);
    void runTask();
    void suspendTask();
    void resumeTask();
};

#endif