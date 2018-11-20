#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"
/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
using namespace std;

double* addToArray(double* array, int bufferSize, double value);

int main(int argc, const char * argv[])
{
    double a = 0;
    int c = 1;
    int xBufferSize = 0;
	double* xBuffer = { 0 };
	int yBufferSize = 0;
	double* yBuffer = { 0 };

    ifstream myReadFile;

    myReadFile.open(argv[1]);

    while (myReadFile >> a)
    {   
        a = (int)(a * 1000 + .5); 
        a = a / 1000;
        if (c % 2 == 0) {
			//Fyll på i Y
			yBuffer = addToArray(yBuffer, yBufferSize, a);
			yBufferSize++;
		}else {
			//Fyll på i X
			xBuffer = addToArray(xBuffer, xBufferSize, a);
			xBufferSize++;
		}
		c++;
    }    
    myReadFile.close();

    Shape basic(xBuffer, yBuffer, xBufferSize);

    cout << basic.area() << endl;

    bool jes = basic.isConvex();

    cout << jes << endl;

}

double* addToArray(double* array, int bufferSize, double value){
    if(array == nullptr){
        //If array is empty, create first slot and add the value
        return new double[1] {value};
    }else{
        double* buffer = new double[bufferSize + 1];
        
        for(int i = 0; i < bufferSize; i++){
            buffer[i] = array[i];
        }
        buffer[bufferSize] = value;
        
        
        //Array should probably be deleted

        return buffer;
    }
}