#pragma once
#include "Letter.h"
#include "Object.h"

class BlackS : public Letter
{
public:
	BlackS(int x, int y);

	void update();

	bool isO();
	bool isS();
	bool isRed();
	bool isBlue();


};

