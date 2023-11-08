#ifndef SCHEDULELR_H
#define SCHEDULELR_H

#include <Arduino.h>
#include <vector.h>

class TaskScheduler{
private:
    struct createTaskParam
    {
        String name;
        uint16_t delay;
        uint8_t idTask;
    };
    createTaskParam taskData[24]; 
    uint32_t prevMillis;
    uint8_t iterationTask = 0;

public:
    TaskScheduler();
    void createTask(uint8_t idTask, String name, uint16_t delay);
    void runTask(createTaskParam taskData);
    void suspendTask(uint8_t idTask);
    void resumeTask(uint8_t idTask);
};

#endif