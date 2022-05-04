#pragma once

#include "Object.h"



class Letter :public Object
{
public:
	Letter(int x, int y, string icon_path);
	
	void update();
	
	virtual bool isO() = 0;
	virtual bool isS() = 0 ;
	virtual bool isRed() = 0 ;
	virtual bool isBlue() = 0 ;
	
};

