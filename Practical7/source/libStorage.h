#ifndef LIBSTORAGE_H_INCLUDED
#define LIBSTORAGE_H_INCLUDED

#include <iostream>
 using namespace std;

template <typename T>
class GenericStorage2D
{

public:
    GenericStorage2D();
    GenericStorage2D(int intRows, int intCols, T tDefault);
    GenericStorage2D(const GenericStorage2D<T>& objOriginal);

    const GenericStorage2D<T>& operator = (const GenericStorage2D<T>& objRHS);
    const bool operator == (const GenericStorage2D<T>& objRHS);
    const bool operator != (const GenericStorage2D<T>& objRHS);

    template <typename T1>                                          // Overloading of Output stream operator
    friend ostream& operator << (ostream& osLHS, const GenericStorage2D<T1>& objRHS);

    template <typename T1>                                           //Overloading of input stream operator
    friend istream& operator >> (istream& isLHS, GenericStorage2D<T1>& objRHS);


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

    ~GenericStorage2D();

private:
    void AllocMem(int intRows, int intCols, T tDefault);
    void DeallocMem();
    void Copy(const GenericStorage2D<T>& objOriginal);
    void enforceRange(int intValue, int intMin, int intMax) const;

    int _rows;
    int _cols;
    T** _type;
};

#include "libStorage.imp"
#endif // LIBSTORAGE_H_INCLUDED
