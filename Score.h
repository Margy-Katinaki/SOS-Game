#pragma once

#include "Object.h"



class Score : public Object
{
	int score = 0;
public:

	Score(int x, int y);
	
	void draw();
	void update();

	void increase();

	int getScore();

};

