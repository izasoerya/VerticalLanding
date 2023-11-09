#ifndef SCHEDULELR_H
#define SCHEDULELR_H

#include <Arduino.h>

class TaskScheduler{
private:
    struct createTaskParam
    {
        String name;
        uint16_t delay;
        uint8_t idTask;
        uint32_t prevMillis = 0;
        void *theTask;
    };
    createTaskParam taskData[24]; 
    uint8_t iterationTask = 0;

public:
    TaskScheduler();
    void createTask(uint8_t idTask, String name, uint16_t delay, void (*thisF)());
    void runTask(uint8_t idTask);
    void suspendTask(uint8_t idTask);
    void resumeTask(uint8_t idTask);
};

#endif