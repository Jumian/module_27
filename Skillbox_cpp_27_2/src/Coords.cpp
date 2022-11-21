#include "Coords.h"

Coords::Coords(double x, double y) {
    this->x=x;
    this->y=y;
}

Coords::Coords():Coords(0.0,0.0) {}

double Coords::inputDouble(const std::string& prompt){
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


int Coords::inputInt(const std::string& prompt){
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

std::string Coords::toString() {
    char arr[100];
    std::snprintf(arr,100,"X=%0.3f,Y=%0.3f", this->getX(), this->getY());
    std::string str(arr);
    return str;
}

double Coords::inputPosDouble(const std::string &prompt) {
    double result=0;
    while(result<=0){
        result= inputDouble(prompt);
        if(result<0) std::cout << "Input number greter zero"<<std::endl;
    }
    return result;
}
