#pragma once

#include "Letter.h"
//
class NoLetter :public Letter
{
	bool clicked;

public:
	NoLetter(int x, int y, string icon_path);

	void update();

	bool isClicked();

	bool isO();
	bool isS() ;
	bool isRed() ;
	bool isBlue();
};

