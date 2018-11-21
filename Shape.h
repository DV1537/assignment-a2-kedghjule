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

        const Shape operator=(const Shape &rhs){
            if (this == &rhs) return *this;

            //Perform deep copy

            //Copy attributes
	        this->p = rhs.p;
            //Copy vertices
            double* tpX = new double[rhs.p];
            double* tpY = new double[rhs.p];
            for(int cpy = 0; cpy < rhs.p;cpy++){
                tpX[cpy] = rhs.pX[cpy];
                tpY[cpy] = rhs.pY[cpy];
            }
            delete[] pX;
            delete[] pY;
            pX = nullptr;
            pY = nullptr;
            pX = tpX;
            pY = tpY;

            //Return
            return *this;
        }
    private:
        int p;
        double* pX;
        double* pY;
};

#endif