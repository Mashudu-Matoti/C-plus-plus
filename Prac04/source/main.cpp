#include <vector>
#include "libImage.h"
#include "libPBM.h"
#include "libPGM.h"

using namespace std;

int convertString(string strNum)
{

    stringstream ss {strNum};
    int intNum;

    ss >> intNum;

    if(ss.fail())
    {
        cerr << " Couldn't convert " << strNum
                  << " to integer values" << endl;
        exit(ERROR_CONV);
    }

    return intNum;
};

void printImage(image2D* objimage){
    cout << objimage->toString();
};

int main(int argc, char** argv)
{
    srand(time(nullptr));

    if(argc!=4)
    {
        cerr << "Incorrect Number Of Command Line Arguments Entered! " << endl;
        exit(ERROR_COUNT);
    };

    int intRows = convertString(argv[1]);
    int intCols = convertString(argv[2]);
    int intChoice = convertString(argv[3]);

    /**
    vector storing PMG and PBM image
    */
    vector<image2D*> vImages;

    vImages.push_back((new imgPGM(intRows, intCols)));
    vImages.push_back((new imgPBM(intRows, intCols)));

    /**
    ERROR HANDLING OF SELECTION MADE
    */
    if((intChoice == 0))
    {
        vImages[intChoice]->imageGen(0, 255);
        printImage(vImages[intChoice]);
    }if((intChoice==1))
    {
        vImages[intChoice]->imageGen(0, 1);
        printImage(vImages[intChoice]);
    }if(intChoice!=1 && intChoice!=0){
        cerr << "Please choose between the values [0, 1]" << endl
             << intChoice << " Is not one of the option!" << endl;
        exit(SELECTION_ERR);
    };



    ///cout << objImage->toString() << endl;
    return SUCCESS;
};
