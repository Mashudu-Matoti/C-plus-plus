#include "libPBM.h"

#include <sstream>

using namespace std;

imgPBM::imgPBM():image2D(DEFAULT_intRowS, DEFAULT_intColS)
{
};

imgPBM::imgPBM(int intRows, int intCols):imgPBM(intRows, intCols, DEFAULT_PV)
{
}

imgPBM::imgPBM(int intRows, int intCols, int intPixel):image2D(intRows, intCols, intPixel)
{
};

imgPBM::imgPBM(const image2D& objOriginal):image2D(objOriginal)
{
};

string imgPBM::toString()
{///overriding the tostring function

    assert(_pixels!=nullptr);

    stringstream ssPBM;
    ssPBM << "P2" << endl
          << _intCols << ' ' << _intRows << endl
          << "1" << endl;

    for(int r=0; r<_intRows; r++)
    {
        for(int c=0; c<_intCols; c++)
        {
            //translating the pixels before displaying them

            translatepixels(r, c);

            ssPBM << _pixels[r][c] << ' ';
        }
        ssPBM << endl;
    }

    return ssPBM.str();

};

void imgPBM::translatepixels(int intRow, int intCol) const
{
    if(_pixels[intRow][intCol] <= 0){
        _pixels[intRow][intCol] = 0;
    }else{
        _pixels[intRow][intCol] = 1;
    }
}

imgPBM::~imgPBM()
{
};
