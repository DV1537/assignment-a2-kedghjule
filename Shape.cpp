#include <iostream>
#include <string>
#include <cmath>
#include "Shape.h"

using namespace std;

Shape::Shape(double* x, double* y, int points){
    pX = x;
    pY = y;
    p = points;
    std::string hello;
}

double Shape::area(){
    double cSum = 0;
	for (int i = 0; i < p; i++) {
		//Hämta index
        
		int iXH = 0; //Index ovanför vårt X
		int iXL = 0; //Index under vårt X
		if (i == 0) { //Kolla om vår X-punkt är i början av listan
			iXH = p - 1;
			iXL = 1;
		}else if (i == p - 1) { //Kolla om vår X-punkt är i slutet av listan
			iXH = i - 1;
			iXL = 0;
		}else { //Kolla om vår X-punkt är i mitten av listan
			iXH = i - 1;
			iXL = i + 1;
		}
		double c = pX[i] * (pY[iXL] - pY[iXH]); //Räkna summan av punkten
		cSum += c; //Lägg till punktens summa till total
	}

	double area = 0.5 * abs(cSum); //Beräkna arean

	return area;
}

bool Shape::isConvex(){ //https://pastebin.com/4ZnHu22Z old code
    bool convex = true;

    //Beräkna centrumpunkt i polygon med medelvärde
    double centerX = 0;
    double centerY = 0;

    double cXS = 0;
    double cYS = 0;
    for (int c = 0; c < p; c++) {
		cXS += pX[c];
        cYS += pY[c];
	}
    centerX = cXS / p;
    centerY = cYS / p;

    //Kontrollera alla punkter
    for (int i = 0; i < p; i++) {
		//Hämta närliggande index
		int iXH = 0; //Index ovanför vårt X
		int iXL = 0; //Index under vårt X
		if (i == 0) { //Kolla om vår X-punkt är i början av listan
			iXH = p - 1;
			iXL = 1;
		}else if (i == p - 1) { //Kolla om vår X-punkt är i slutet av listan
			iXH = i - 1;
			iXL = 0;
		}else { //Kolla om vår X-punkt är i mitten av listan
			iXH = i - 1;
			iXL = i + 1;
		}
		
        //Fastställ alla punkter i triangeln den utvalda triangeln
        //Grannpunkt
        double aX = pX[iXH]; 
        double aY = pY[iXH];
        //Denna punkt
        double bX = pX[i];
        double bY = pY[i];
        //Grannpunkt
        double cX = pX[iXL];
		double cY = pY[iXL];

        //Medelpunkt i triangeln
        double mX = (aX + cX + bX) / 3;
        double mY = (aY + cY + bY) / 3;
        
        double lOut = sqrt(pow(centerX-mX,2)+pow(centerY-mY,2)); //Längd från medelpunkt i triangeln till mitten
        double pOrigin = sqrt(pow(centerX-bX,2)+pow(centerY-bY,2)); //Längd från denna punkt till mitten

        //cout << "C{" << centerX << "," << centerY << "} | L: " << lOut << ", O: " << pOrigin << endl; //Lite debugging

        if(lOut > pOrigin)
            convex = false;
	}
    return convex;
}