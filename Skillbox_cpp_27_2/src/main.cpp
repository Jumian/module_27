#include <iostream>
#include "Figure.h"

int main() {
    Circle* circle;
    Square* square;
    Rectangle* rectangle;
    Triangle* triangle;

    Figure::TYPE type = Figure::inputType();
    switch (type) {
        case Figure::TYPE_CIRCLE:
            circle = new Circle();
            circle->print();
            break;
        case Figure::TYPE_SQUARE:
            square = new Square();
            square->print();
            break;
        case Figure::TYPE_TRIANGLE:
            triangle = new Triangle();
            triangle->print();
            break;
        case Figure::TYPE_RECTANGLE:
            rectangle = new Rectangle();
            rectangle->print();
            break;
    }
}
