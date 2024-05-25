#include "libGrid.h"
#include <iostream>

using namespace std;

int main()
{
    //Demonstration of overloaded operators
    Matrix2D<int> objMatrix(2,2,0);
    cin >> objMatrix;
    cout << objMatrix;
    cout << ++objMatrix;
    cout << endl << "************************" << endl;
    objMatrix(1,2) = 9;
    cout << objMatrix(1,2)  ;
    /*cin >> objMatrix;
    cout << objMatrix << "Heu";
    Matrix2D<char> objMatrix2 = objMatrix; //Copy constructor
    Matrix2D<char> objMatrix3(7,7, 'c');
    objMatrix = objMatrix3;*/
    return 0;
}
