#include <iostream>
#include "Inputs.h"
#include "Employee.h"

int main() {
    Employee::workerCount=Inputs::inputInt("Input number of workers of team:");
    Employee::teamCount=Inputs::inputInt("Input number of teams in company:");
    Ceo ceo;
    bool ne= true;
    while(ne) {
        ceo.getTask()->generateTask();
        ne=ceo.getTask()->haveFreeWorkers();
    }
}
