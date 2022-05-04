#pragma once

#include "RedO.h"
#include "Letter.h"

class RedO : public Letter
{
public:
	RedO(int x, int y);

	bool isO();
	bool isS();
	bool isRed();
	bool isBlue();
};