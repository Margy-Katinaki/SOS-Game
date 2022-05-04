#include "BlueO.h"

BlueO::BlueO(int x, int y): Letter(x,y,"assets\\blueO.png")
{

}

bool BlueO::isO()
{
    return true;
}

bool BlueO::isS()
{
    return false;
}

bool BlueO::isRed()
{
    return false;
}

bool BlueO::isBlue()
{
    return true;
}


