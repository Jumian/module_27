#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Task.h"
#include "Inputs.h"

class Ceo;
class Manager;
class Task;

class Employee{
public:
#define EMPLOYEE_COUNT 3
    enum EMPLOYEE_TYPE{
        TYPE_CEO,
        TYPE_MANAGER,
        TYPE_WORKER,
    };
    static std::string EMPLOYEE_TYPE_STR[EMPLOYEE_COUNT];
    std::string name;
    int id=-1;
    Employee();
    Employee(Employee* boss,int subCount);
    EMPLOYEE_TYPE getType();
    void setType(EMPLOYEE_TYPE type);
    void addSubordinate(Employee* sub);
    int subCount();
    Employee* getSubAt(int index);
    Employee* getBoss();
    void setName(std::string name);
    Task* getTask();
    void useTask(Task* task);
    static uint32_t workerCount;
    static uint32_t teamCount;
protected:
    std::vector<Employee*> subordinate;
    Employee* boss;
    Task* ptask;
    EMPLOYEE_TYPE type;

};


class Worker : public Employee{
public:
    explicit Worker(Manager* manager);
    static int idCount;
};


class Manager : public Employee{
public:
    explicit Manager(Ceo* ceo);
    uint32_t freeSubs;
    static int idCount;
};

class Ceo : public Employee {
public:
    Ceo();
};
