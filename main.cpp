#include <iostream>
#include <fstream>

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


    //Program should be compatible with negative values


    if(argc >= 2){ //Error handling
        double a = 0;
        double sum = 0;
        double avg = 0;
        int bufferSize = 0;
        double* buffer;

        ifstream myReadFile;

        myReadFile.open(argv[1]);

        if(myReadFile.is_open()){ //Error handling
            while (myReadFile >> a)
            {   
                a = (int)(a * 1000 + .5); 
                a = a / 1000;

                buffer = addToArray(buffer, bufferSize, a);
                bufferSize++;

                sum += a;
            }
            myReadFile.close();
            
            if(!(bufferSize == 0 || sum == 0)){ //Error handling
                avg = sum / (double)bufferSize;

                for(int i = 0; i < bufferSize; i++){
                    if(buffer[i] > avg){
                        cout << buffer[i] << " "; 
                    }
                }

            }else{ //The file contents contained a invalid format
                cout << 0 << endl;
            }
        }else{ //The file were not correctly read
            cout << "File Error" << endl;
        }
    }else{ //Not enough initial parameters
        cout << "Error" << endl;
    }
    return 0;
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