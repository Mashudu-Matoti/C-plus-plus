#include "libPGM.h"

#include <sstream>

using namespace std;

imgPGM::imgPGM():image2D(DEFAULT_intRowS, DEFAULT_intColS)
{
};

imgPGM::imgPGM(int intRows, int intCols):image2D(intRows, intCols, DEFAULT_PV)
{
};

imgPGM::imgPGM(int intRows, int intCols, int intPixel):image2D(intRows, intCols, intPixel)
{
};

imgPGM::imgPGM(const image2D& objPGM):image2D(objPGM)
{
};

string imgPGM::toString()
{
    assert(_pixels!=nullptr);

    stringstream ssPGM;
    ssPGM << "P2" << endl
          << _intCols << ' ' << _intRows << endl
          << "255" << endl;

    for(int r=0; r<_intRows; r++)
    {
        for(int c=0; c<_intCols; c++)
        {

            ssPGM << _pixels[r][c] << ' ';
        }
        ssPGM << endl;
    }

    return ssPGM.str();
};

imgPGM::~imgPGM()
{
};
