#include "BlueS.h"
#include "Letter.h"

BlueS::BlueS(int x, int y): Letter (x, y, "assets\\blueS.png")
{



}

bool BlueS::isO()
{
    return false;
}

bool BlueS::isS()
{
    return true;
}

bool BlueS::isRed()
{
    return false;
}

bool BlueS::isBlue()
{
    return true;
}


