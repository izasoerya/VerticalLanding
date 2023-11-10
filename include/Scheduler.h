#ifndef SCHEDULELR_H
#define SCHEDULELR_H

#include <Arduino.h>

class TaskScheduler{
private:
    typedef void (*TaskFunction)();  // Define a typedef for the function pointer type
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