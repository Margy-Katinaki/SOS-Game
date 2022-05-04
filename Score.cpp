#include "Score.h"


Score::Score(int x, int y): Object (x,y, 0, "")
{


}


void Score::draw()
{
	graphics::drawText(x,y, 10, "Score " + to_string(score), br);
}

void Score::update()
{
}

void Score::increase()
{
	score++;
}

int Score::getScore()
{
	return score;
}
