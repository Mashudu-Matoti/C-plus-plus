#include "libStorage.h"
#include <iostream>

using namespace std;

int main()
{
    //Demonstration of overloaded operators
    GenericStorage2D<int> objStorage(2,2,0);
    GenericStorage2D<int> objStorage1(2,2,0);
    cin >> objStorage;
    cout << objStorage;
    cout << endl << endl;
    cin >> objStorage1;
    cout << objStorage1;

    if(objStorage == objStorage1)
    {
        cout << "They are equal" << endl;
    }
    else
        cout << "NOT EQUAL";

    return 0;
}
