#pragma once
#include <iostream>
#include "Validator.h"

class Coords{
    double x;
    double y;
public:
    Coords();
    Coords(double x,double y);
    void setX(double new_x){x=new_x;}
    void setY(double new_y){y=new_y;}
    double getX() const {return x;}
    double getY() const {return y;}
    static double inputDouble(const std::string& prompt);
    static double inputPosDouble(const std::string& prompt);
    static int inputInt(const std::string& prompt);
    std::string toString();
};