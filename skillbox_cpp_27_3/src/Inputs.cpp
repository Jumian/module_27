#include "Inputs.h"



double Inputs::inputDouble(const std::string& prompt){
    std::string input=" ";
    bool notNumber=true;
    while(notNumber) {
        std::cout << prompt;
        std::cin >> input;
        notNumber=!Validator::isNumberReal(input);
        if(notNumber)std::cout << "Try again" << std::endl;
        else break;
    }
    return std::stod(input);
}


int Inputs::inputInt(const std::string& prompt){
    std::string input=" ";
    bool notNumber=true;
    while(notNumber) {
        std::cout << prompt;
        std::cin >> input;
        notNumber=!Validator::isNumberInt(input);
        if(notNumber)std::cout << "Try again" << std::endl;
        else break;
    }
    return std::stoi(input);
}

std::string Inputs::inputStr(std::string prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >>input;
    return input;
}


double Inputs::inputPosDouble(const std::string &prompt) {
    double result=0;
    while(result<=0){
        result= inputDouble(prompt);
        if(result<0) std::cout << "Input number greater zero"<<std::endl;
    }
    return result;
}

bool Validator::isNumberInt(std::string str) {
#define N (str[i])
    for (int i = 0; i < str.size(); ++i) {
        if (i == 0 && N == '-') continue;
        if (N > '9' && N < '0') return false;
    }
    return true;
}

bool Validator::isNumberReal(std::string str) {
    bool hasDot = false;
    for (int i = 0; i < str.size(); ++i) {
        if (N == '.' && hasDot) return false;
        else if (N == '.' && !hasDot) {
            hasDot = true;
            continue;
        }
        if (i == 0 && N == '-') continue;
        if (N > '9' || N < '0') return false;
    }
    return true;
}
#undef N