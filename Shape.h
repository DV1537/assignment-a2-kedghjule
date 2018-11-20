#include <string>
#include <iostream>
#ifndef SHAPE_H
#define SHAPE_H


class Shape{
    public:
        Shape(double* x, double* y, int points);
        std::string getType();
        double area();
        double circumference();
        //position()
        bool isConvex();
        double distance(Shape s);
    private:
        int p;
        double* pX;
        double* pY;
};

#endif