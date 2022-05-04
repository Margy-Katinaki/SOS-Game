#include "BlackS.h"

BlackS::BlackS(int x, int y) : Letter(x, y, "assets\\blackS.png")
{
}


void BlackS::update()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);		// Mathainoume tin katastasi toy pontikiou

	int mouseX = graphics::windowToCanvasX(mouse.cur_pos_x, true);
	int mouseY = graphics::windowToCanvasY(mouse.cur_pos_y, true);


	// an to klik einai mesa sto orthogwnio pou orizei to x,y tou antikeimenou kai tis aktinas
	if (mouse.button_left_pressed == true)
	{
		if (mouseX > x - rad / 2 && mouseY > y - rad / 2 && mouseX < x + rad / 2 && mouseY < y + rad / 2)
		{
			setSelected();
		}
	}

}

bool BlackS::isO()
{
	return false;
}

bool BlackS::isS()
{
	return true;
}

bool BlackS::isRed()
{
	return false;
}

bool BlackS::isBlue()
{
	return false;
}
