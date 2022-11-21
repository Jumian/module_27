#pragma once

#include "Employee.h"
class Employee;
class Task{
public:
#define TASK_COUNT 4
    enum TASK_TYPE{
        TASK_A,
        TASK_B,
        TASK_C,
        TASK_NONE
    };
    static std::string TASK_TYPE_STR[TASK_COUNT];
    static TASK_TYPE toTaskType(int number);
    explicit Task(Employee* employee);
    Employee* taskHolder();
    int getTaskCount() const;
    TASK_TYPE getType();
    void setTaskCount(int task);
    void setType(TASK_TYPE type);
    void generateTask();
    void print();
    bool haveFreeWorkers();
protected:
    int countFreeSubs();
    int taskCount;
    TASK_TYPE taskType;
    Employee* taskholder;
};
