#include "Employee.h"
#include <string>
std::string Employee::EMPLOYEE_TYPE_STR[]={"CEO",
                                           "MANAGER",
                                           "WORKER",};


int Worker::idCount=0;
int Manager::idCount=0;

uint32_t Employee::teamCount=0;
uint32_t Employee::workerCount=0;

void Employee::addSubordinate(Employee *sub) {
    if (sub)
        subordinate.push_back(sub);
}

Employee::Employee(Employee *boss,int subCount) {
    this->boss=boss;
    this->ptask= nullptr;
}

Employee::Employee() : Employee(nullptr,0) {}

int Employee::subCount() {
    return subordinate.size();
}

Employee *Employee::getBoss() {
    return this->boss;
}

Employee *Employee::getSubAt(int index) {
    if(index>=subordinate.size()||index<0) return nullptr;
    return subordinate.at(index);
}

void Employee::setType(Employee::EMPLOYEE_TYPE type) {
    if (type<=TYPE_WORKER&&type>=TYPE_CEO)
        this->type=type;
}

Employee::EMPLOYEE_TYPE Employee::getType() {
    if (this->type>=0&& type<= EMPLOYEE_COUNT )
    return this->type;
    return Employee::TYPE_CEO;
}

void Employee::setName(std::string name) {
    this->name=name;
}

Task* Employee::getTask() {
    return this->ptask;
}

void Employee::useTask(Task* task) {
    if(ptask!= nullptr) {
        delete ptask;
    }
    this->ptask=task;
}

Ceo::Ceo() {
    this->type=TYPE_CEO;
    for(int i=0;i<Employee::teamCount;++i)
        subordinate.push_back(new Manager(this));
    this->ptask=new Task(this);
    this->id=0;
    this->name="CEO";
}

Worker::Worker(Manager *manager) {
    this->boss=manager;
    type=TYPE_WORKER;
    ++idCount;
    this->id=idCount;
    name="Worker "+ std::to_string(id);
}

Manager::Manager(Ceo *ceo) {
    this->boss=ceo;
    type=TYPE_MANAGER;
    ++idCount;
    this->id=idCount;
    name="Manager "+ std::to_string(id);
    this->freeSubs=Employee::workerCount;
    for(int i=0;i<Employee::workerCount;++i) {
        subordinate.push_back(new Worker(this));
    }
}
