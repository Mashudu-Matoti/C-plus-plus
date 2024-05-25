#ifndef LIBIMAGE_H_INCLUDED
#define LIBIMAGE_H_INCLUDED

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

enum eCODES
{
    SUCCESS,
    ERROR_RANGE = -1,
    ERROR_COUNT = -2,
    ERROR_CONV = -3,
    SELECTION_ERR = -4
};

class image2D
{
public:
    //CLASS CONSTRUCTOR
    image2D();
    image2D(int intRows, int intCols);
    image2D(int intRows, int intCols, int intPixel);
    image2D(const image2D& objimage);

    //ACCESSOR FUNCTIONS
    int getRows() const;
    int getCols() const;


    //MUTATOR FUNCTIONS
    int getPixel(int intRow, int intCol) const;
    void imageGen(int minpixel, int maxpixel) const;

    virtual string toString() = 0;

    static const int DEFAULT_intRowS = 600;
    static const int DEFAULT_intColS = 550;
    static const int DEFAULT_PV = 0;
    static const int MAX = 100000;

    //DESTRUCTOR
    virtual ~image2D();

protected:
    //MEMBER VARIABLES
    int _intRows;
    int _intCols;
    int** _pixels;

private:
    //HELPER FUNCTIONS
    void enforceRange(int intLower, int intUpper, int intValue) const;
    void checkIndex(int intRow, int intCol) const;
    int getRandom(int intLower, int intUpper) const;  ///random number generator

};


#endif // LIBIMAGE_H_INCLUDED
