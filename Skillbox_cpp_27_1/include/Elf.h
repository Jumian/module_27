#pragma once
#include <string>
#include <iostream>
#include "Branch.h"

class Branch;

class Elf {
    std::string name;
    int count;
    Branch* home;
public:
    Elf();
    explicit Elf(Branch* home);
    static std::string inputName();
    static Branch* findElf(Branch* branch,std::string name);
    static int treeCount(Branch* branch);
};
