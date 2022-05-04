#include "RedO.h"


RedO::RedO(int x, int y) : Letter(x, y, "assets\\redO.png")// assets\\reds.png
{

}

bool RedO::isO()
{
    return true;
}

bool RedO::isS()
{
    return false;
}

bool RedO::isRed()
{
    return true;
}

bool RedO::isBlue()
{
    return false;
}
