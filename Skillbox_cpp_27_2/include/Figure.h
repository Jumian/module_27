#pragma once
#include <vector>
#include "Coords.h"

#define COLOR_COUNT 5
#define TYPE_COUNT 5

class Figure{
public:
enum COLOR{
    COLOR_NONE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_PINK,
};

static std::string COLOR_STR[COLOR_COUNT];

enum TYPE {
    TYPE_POINT,
    TYPE_CIRCLE,
    TYPE_SQUARE,
    TYPE_TRIANGLE,
    TYPE_RECTANGLE,
};

    static std::string TYPE_STR[TYPE_COUNT];

    Coords* center;
    COLOR color;
    TYPE type;
    std::vector<Coords> rect;
    virtual double area();
    Figure();
    void print();
    virtual void calcRect();
    static TYPE inputType();
};

class Circle : public Figure{
public:
    Circle();
    double area();
    double radius;
    void calcRect();
};

class Square : public Figure{
public:
    Square();
    double length;
    double area();
    void calcRect();
};

class Triangle : public Figure{
public:
    Triangle();
    double length;
    double area();
    void calcRect();
};

class Rectangle:public Figure{
public:
    Rectangle();
    double height;
    double width;
    double area();
    void calcRect();
};