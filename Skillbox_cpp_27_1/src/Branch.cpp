#include "Branch.h"


Branch::Branch():Branch(nullptr) {}

Branch::Branch(Branch* parent) {
    static int treeCount=0;
    this->parent=parent;
    this->elf= nullptr;
    this->size=0;
    this->children.clear();
    int childrenSize=0;

    if(this->parent== nullptr){
        this->type=ROOT;
        ++treeCount;
        std::cout << "Tree #" << treeCount << std::endl;
        childrenSize=BIGBRANCHCOUNT;
    } else {
        this->type=BRANCH_TYPE(parent->type+1);
    }

    if(this->parent!= nullptr&&this->type>ROOT && this->type<=MIDDLE_BRANCH) {
        std::cout << BRANCH_STR[this->type]<< ". ";
        this->elf= new Elf(this);
    }

    if (this->type==BIG_BRANCH) childrenSize = MIDDLEBRANCHCOUNT ;

    this->addChildren(childrenSize);
}

Branch* Branch::getTopBranch()
{
    if (this->parent == nullptr) return nullptr;
    if (parent->parent == nullptr) return this->parent;
    return parent->getTopBranch();
}

bool Branch::addChildren(int size) {
    if(size<=0) {
        this->noChildren();
        return false;
    }
    if(this->type>=MIDDLE_BRANCH) return true;
    this->size =size;

    for (int i=0;i< this->size;++i){
        this->children.push_back(new Branch(this));
    }
    return true;
}

bool Branch::noChildren() {
    if (this->size<0) return false;
    if (this->size>0 && !this->children.empty()) {
        this->children.clear();
    }
    this->children.clear();
    return true;
}

Branch *Branch::bigBranch(Branch *branch) {
    if (branch->type==ROOT||branch== nullptr) return nullptr;
    if (branch->type==BIG_BRANCH) return branch;
    return bigBranch(branch->parent);
}









