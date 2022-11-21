#include <iostream>

#include "Elf.h"
#include "Branch.h"

#define TREECOUNT 2

int main() {
    std::vector<Branch*> trees;
    for (int i=0;i<TREECOUNT;++i){
        Branch* branch =new Branch(nullptr);
        trees.push_back(branch);
    }
    std::cout << "========= Elfs are settled ==========" << std::endl;
    std::cout << "Count neighbors for elf. ";
    Branch* found= nullptr;
    std::string find=Elf::inputName();
    for (int i=0;i<trees.size();++i){
        found=Elf::findElf(trees[i],find);
        if(found) break;
    }
    if (found){
        std::cout<< Elf::treeCount(
                Branch::bigBranch(found))-1;
    } else {
        std::cout << "Not found" << std::endl;
    }

}
