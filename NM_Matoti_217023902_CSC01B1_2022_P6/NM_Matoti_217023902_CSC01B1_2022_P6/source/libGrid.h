#ifndef LIBGRID_H_INCLUDED
#define LIBGRID_H_INCLUDED

#include <iostream>


using namespace std;

template <typename T>
class Matrix2D
{

public:
    Matrix2D();
    Matrix2D(int intRows, int intCols, T tDefault);
    Matrix2D(const Matrix2D<T>& objOriginal);

    const Matrix2D<T>& operator = (const Matrix2D<T>& objRHS);       //Overloading of assignment operator
    T& operator ()( int intRow, int intCol);                         //Overloading of Function invocation operator


    template <typename T1>                                          //Overloading of pre-increment operator
    friend Matrix2D<T1>& operator ++ ( Matrix2D<T1>& objRHS);

    template <typename T1>                                          // Overloading of Output stream operator
    friend ostream& operator << (ostream& osLHS, const Matrix2D<T1>& objRHS);

    template <typename T1>                                           //Overloading of input stram operator
    friend istream& operator >> (istream& isLHS, Matrix2D<T1>& objRHS);


    string toString();

    //Accessor functions
    int getRows() const;
    int getCols() const;
    T getElement(int intRow, int intCol) const;

    //Mutator Function
    void setElement(int intRow, int intCol, T tValue);

    static const int DEFAULT_ROWS = 500;
    static const int DEFAULT_COLS = 500;
    static const T DEFAULT_TYPE = 0;

    ~Matrix2D();

private:
    void AllocMem(int intRows, int intCols, T tDefault);
    void DeallocMem();
    void Copy(const Matrix2D<T>& objOriginal);
    void enforceRange(int intValue, int intMin, int intMax) const;

    int _rows;
    int _cols;
    T** _type;
};

#include "libGrid.txt"

#endif // LIBGRID_H_INCLUDED
