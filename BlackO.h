#pragma once

#include "Letter.h"
#include "Object.h"

class BlackO : public Letter
{

public:
	BlackO(int x, int y);

	void update();

	bool isO();
	bool isS();
	bool isRed();
	bool isBlue();















};
