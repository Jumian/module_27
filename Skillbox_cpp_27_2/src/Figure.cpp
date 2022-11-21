#include "Figure.h"
#include <cmath>

std::string Figure::COLOR_STR[COLOR_COUNT]={"NONE","RED","GREEN","BLUE","PINK"};
std::string Figure::TYPE_STR[TYPE_COUNT]={"point","circle","square","triangle","rectangle"};

Figure::Figure() {
    std::cout << "Input center coords:" << std::endl;
    this->center=new Coords(Coords::inputDouble("X:"),Coords::inputDouble("Y:"));
    for(int i=0;i<COLOR_COUNT;++i) std::cout <<i<<"-"<< COLOR_STR[i] << " ";
    this->color=Figure::COLOR(Coords::inputInt("Choose color:"));
    if (this->color>=COLOR_COUNT) this->color=COLOR_NONE;
}

void Figure::print() {
    std::cout<< TYPE_STR[this->type]<<" with " <<COLOR_STR[this->color] <<" color.\nArea is  "<<
                this->area()<<"\nrectangle coords:\n1:"<<
                this->rect.at(0).toString()<< "\n2:"<<
                this->rect.at(1).toString();
}

double Figure::area() {
    return 0;
}

void Figure::calcRect() {}

Figure::TYPE Figure::inputType() {
    std::string str;
    while (true) {
        std::cout<< "Input type of figure:";
        std::cin >> str;
        for (int i = 0; i < TYPE_COUNT; ++i) {
            if (str == TYPE_STR[i]) return Figure::TYPE(i);
        }
        std::cout << "Try again"<< std::endl;
    }

}

Circle::Circle():Figure() {
    this->type=TYPE_CIRCLE;
    this->radius=Coords::inputPosDouble("Input Circle Radius:");
    this->calcRect();
}


Square::Square():Figure() {
    this->type=TYPE_SQUARE;
    this->length=Coords::inputPosDouble("Input square length:");
    this->calcRect();
}


Triangle::Triangle():Figure() {
    this->type=TYPE_TRIANGLE;
    this->length=Coords::inputPosDouble("Input triangle length:");
    this->calcRect();
}

Rectangle::Rectangle() {
    this->type=TYPE_RECTANGLE;
    this->width=Coords::inputPosDouble("Input rectangle width:");
    this->height=Coords::inputPosDouble("Input rectangle height:");
    this->calcRect();
}


double Circle::area() {
    return M_PI*radius*radius;
}

double Rectangle::area() {
    return width*height;
}

double Square::area() {
    return length*length;
}

double Triangle::area() {
    return sqrt(3)*length*length/4;
}


void Circle::calcRect() {
#define CR(A,B) this->rect.push_back(Coords((A)+this->center->getX(),(B)+this->center->getY()));
    CR(-radius,-radius)
    CR(radius,radius)
}
void Square::calcRect() {
    CR(-length/2,-length/2)
    CR(length/2,length/2)
}
void Triangle::calcRect() {
    CR(-length/2,-sqrt(3)/2*length)
    CR(length/2,sqrt(3)/2*length)
}

void Rectangle::calcRect() {
    CR(-width/2,-height/2)
    CR(width/2,height/2)
}