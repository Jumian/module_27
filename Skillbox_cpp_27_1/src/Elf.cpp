#include "Elf.h"

std::string Elf::inputName(){
    std::string input;
    std::cout << "Input elf name:";
    std::cin >> input;
    return input;
}

Elf::Elf(Branch* home) {
    if (home== nullptr) {
        this->count=0;
    }
    this->home=home;
    this->name=inputName();
    if(name=="None" || name=="") {
        this->count=0;
        this->name="None";
    }
    else this->count =1;
}

Elf::Elf():Elf(nullptr) {}

Branch *Elf::findElf(Branch* branch,std::string name) {
    if (branch== nullptr||name=="") return nullptr;
    if (branch->type!=ROOT&&branch->elf){
        if (branch->elf->name==name) return branch;
    }
    for(int i=0;i<branch->size;++i){
        Branch* branchcur=findElf(branch->children[i],name);
        if(branchcur)
            return branchcur;
    }
    return nullptr;
}

int Elf::treeCount(Branch* branch) {
    int sum=0;
    if(branch== nullptr) return 0;
    if(branch->elf) sum+=branch->elf->count;
    if(branch->type==MIDDLE_BRANCH) return sum;
    if(!branch->children.empty()){
        for(int i=0;i<branch->children.size();++i){
            sum+=treeCount(branch->children[i]);
        }
    }
    return sum;
}
