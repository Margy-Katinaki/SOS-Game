#include "BlackO.h"

BlackO::BlackO(int x, int y) : Letter(x, y, "assets\\blackO.png")
{

}

void BlackO::update()
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

bool BlackO::isO()
{
	return false;
}

bool BlackO::isS()
{
	return false;
}

bool BlackO::isRed()
{
	return false;
}

bool BlackO::isBlue()
{
	return false;
}

