#include "libImage.h"

using namespace std;

image2D::image2D():image2D(DEFAULT_intRowS, DEFAULT_intColS)
{
};

image2D::image2D(int intRows, int intCols):image2D(intRows, intCols, DEFAULT_PV)
{
};

image2D::image2D(int intRows, int intCols, int intPixel)
{

    enforceRange(0, MAX, intRows);
    enforceRange(0, MAX, intCols);


    _intRows = intRows;
    _intCols = intCols;


    _pixels = new int*[_intRows];
    for(int r=0; r<_intRows; r++)
    {
        _pixels[r] = new int[_intCols];
        for(int c=0; c<_intCols; c++)
        {
            _pixels[r][c] = intPixel;
        }
    }
};

image2D::image2D(const image2D& objOriginal):image2D(objOriginal._intRows, objOriginal._intCols)
{

    for(int r=0; r<_intRows; r++)
    {
        for(int c=0; c<_intCols; c++)
        {
            _pixels[r][c] = objOriginal._pixels[r][c];
        }
    }
};

int image2D::getRows() const
{
    return _intRows;
};

int image2D::getCols() const
{
    return _intCols;
};

int image2D::getPixel(int intRow, int intCol) const
{
    assert(_pixels!=nullptr);

    checkIndex(intRow, intCol);

    return _pixels[intRow][intCol];
};

void image2D::imageGen(int minPixel, int maxPixel) const
{
    //CHECKS IF POINTER EXISTS
    assert(_pixels!=nullptr);

    //LOOPS AND GENERATES RANDOM NUMBERS FOR PIXEL
    for(int r=0; r<_intRows; r++)
    {
        for(int c=0; c<_intCols; c++)
        {

            _pixels[r][c] = getRandom(minPixel, maxPixel);
        }
    }
};


void image2D::enforceRange(int intLower, int intUpper, int intValue) const
{
    if(intValue < intLower || intValue > intUpper)
    {
        cerr << "Not in range" << endl;
        exit(ERROR_RANGE);
    }
};

void image2D::checkIndex(int intRow, int intCol) const
{
    //Checks if we're still within bounds
    enforceRange(0, _intRows-1, intRow);
    enforceRange(0, _intCols-1, intCol);
};

int image2D::getRandom(int intLower, int intUpper) const
{
    int intRange = intUpper - intLower + 1;

    int intRand = rand()%(intRange+intLower);

    return intRand;
}

image2D::~image2D() //Deallocates memory
{
    assert(_pixels!=nullptr);
    for(int r=0; r<_intRows; r++)
    {
        delete [] _pixels[r];
    }
    delete [] _pixels;
}
