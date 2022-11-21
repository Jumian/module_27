#pragma once
#include <iostream>

class Validator {
public:
    static bool isNumberInt(std::string str);
    static bool isNumberReal(std::string str);
};

class Inputs{
public:
    static std::string inputStr(std::string prompt);
    static double inputDouble(const std::string& prompt);
    static double inputPosDouble(const std::string& prompt);
    static int inputInt(const std::string& prompt);
};
