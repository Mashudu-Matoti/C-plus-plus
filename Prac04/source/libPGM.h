#ifndef LIBPGM_H_INCLUDED
#define LIBPGM_H_INCLUDED

#include "libImage.h"
using namespace std;

class imgPGM : public image2D
{
public:

    imgPGM();
    imgPGM(int intRows, int intCols);
    imgPGM(int intRows, int intCols, int intPixel);
    imgPGM(const image2D& objPGM);

    //DISPLAYS PGM
    virtual string toString();

    virtual ~imgPGM();
};


#endif // LIBPGM_H_INCLUDED
