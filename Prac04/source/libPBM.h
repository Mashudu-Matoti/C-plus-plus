#ifndef LIBPBM_H_INCLUDED
#define LIBPBM_H_INCLUDED

#include "libImage.h"
#include <string>

using namespace std;

class imgPBM : public image2D
{
public:
    ///class constructors
    imgPBM();
    imgPBM(int intRows, int intCols);
    imgPBM(int intRows, int intCols, int intPixel);
    imgPBM(const image2D& objPGM);

    ///display method
    virtual string toString();

    ///destructor
    virtual~imgPBM();

private:
    void translatepixels(int intRow, int intCol) const;
};


#endif // LIBPBM_H_INCLUDED
