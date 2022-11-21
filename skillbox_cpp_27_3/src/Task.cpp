#include "Task.h"
#include <ctime>

std::string  Task::TASK_TYPE_STR[]={"TASK A", "TASK B", "TASK C", "NO TASK"};

Task::Task(Employee *employee) {
    taskholder=employee;
    taskType=TASK_NONE;
    taskCount=0;
}

Employee* Task::taskHolder() {
    return taskholder;
}

int Task::getTaskCount() const {
    return taskCount;
}

Task::TASK_TYPE Task::getType() {
    return taskType;
}

void Task::setTaskCount(int task) {
    taskCount=task;
}

void Task::setType(TASK_TYPE ntype) {
    taskType=ntype;
}

void Task::generateTask() {
    if(this== nullptr || taskHolder()== nullptr) return;
    Employee* employee=taskHolder();
    Manager* manager=static_cast<Manager*>(employee);
    Ceo* ceo=static_cast<Ceo*>(employee);
    Worker* worker;
    Employee::EMPLOYEE_TYPE tt=employee->getType();
    int count=0;
    switch (tt) {
        case Employee::TYPE_CEO:
            setTaskCount(Inputs::inputInt("Input new task:"));
            print();
            for (int i=0;i<employee->subCount(); ++i) {
                ceo->getSubAt(i)->useTask(new Task(ceo->getSubAt(i)));
                ceo->getSubAt(i)->getTask()->generateTask();
            }
            break;
        case Employee::TYPE_WORKER:
            setType(TASK_TYPE(rand()%((TASK_COUNT)-1)));
            setTaskCount(0);
            print();
            break;
        case Employee::TYPE_MANAGER:

            std::srand(uint64_t(manager->id+manager->getBoss()->getTask()->getTaskCount())+ time(nullptr));
            if (manager->freeSubs>0) {
                int rande=rand();
                int use=0;
                if (manager->freeSubs==1) use=1;
                else use=1 + (rande % (manager->freeSubs - 1));
                setTaskCount(use);
            }
            setType(TASK_NONE);
            print();
            count=getTaskCount();
            for (int i=0;count>0&&i<manager->subCount();++i){
                if(manager->getSubAt(i)->getTask()== nullptr) {
                    manager->getSubAt(i)->useTask(new Task(manager->getSubAt(i)));
                    --count;
                }
                else continue;
                manager->getSubAt(i)->getTask()->generateTask();
                --manager->freeSubs;
            }
            break;
        default:
            std::cout << "Unknown TYPE";
    }
}

void Task::print() {
    std::cout << taskHolder()->name << " have task: " <<
              ((getTaskCount() == 0) ? (Task::TASK_TYPE_STR[getType()] ): std::to_string(getTaskCount())) << std::endl;
}

Task::TASK_TYPE Task::toTaskType(int number) {
    if(number>=0 && number<=TASK_COUNT) return TASK_TYPE(number);
    return Task::TASK_NONE;
}

bool Task::haveFreeWorkers(){
    return countFreeSubs()>0;
}

int Task::countFreeSubs() {

    if(taskHolder()->getType()==Employee::TYPE_MANAGER){
        return static_cast<Manager*>(taskHolder())->freeSubs;
    } else if (taskHolder()->getType()==Employee::TYPE_WORKER){
        return 0;
    }
    int sum=0;
    for (int i=0;i<taskHolder()->subCount();++i){
        if (taskHolder()->getSubAt(i)->getTask()!= nullptr)
        sum+=taskHolder()->getSubAt(i)->getTask()->countFreeSubs();
    }
    return sum;
}
