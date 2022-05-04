#include "RedS.h"

RedS::RedS(int x, int y): Letter(x,y,"assets\\redS.png")// assets\\reds.png
{

}

bool RedS::isO()
{
    return false;
}

bool RedS::isS()
{
    return true;
}

bool RedS::isRed()
{
    return true;
}

bool RedS::isBlue()
{
    return false;
}
