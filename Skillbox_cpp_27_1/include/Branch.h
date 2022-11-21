#pragma once
#include <vector>
#include <cassert>
#include "Elf.h"

#define BIGBRANCHCOUNT 1//(rand()%3+3)
#define MIDDLEBRANCHCOUNT 5// (rand()%2+2)

class Elf;

enum BRANCH_TYPE{
    ROOT=0,
    BIG_BRANCH,
    MIDDLE_BRANCH
};
const static std::string BRANCH_STR[3]={"Root","Big branch","Middle branch"};



class Branch {
public:
    BRANCH_TYPE type;
    int size;
    Branch* parent;
    std::vector<Branch*> children;
    Elf * elf;
    Branch();
    explicit Branch(Branch* parent = nullptr);
    Branch* getTopBranch();
    bool addChildren(int size);
    bool noChildren();
    static Branch* bigBranch(Branch* branch);
};


