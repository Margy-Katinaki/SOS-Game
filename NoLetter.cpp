#include "NoLetter.h"

#include "sgg/graphics.h"

NoLetter::NoLetter(int x, int y, string icon_path): Letter (x, y, icon_path)
{
	clicked = false;
}

void NoLetter::update()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);		// Mathainoume tin katastasi toy pontikiou

	int mouseX = graphics::windowToCanvasX(mouse.cur_pos_x, true);
	int mouseY = graphics::windowToCanvasY(mouse.cur_pos_y, true);


	// an to klik einai mesa sto orthogwnio pou orizei to x,y tou antikeimenou kai tis aktinas
	if (mouse.button_left_pressed == true)
	{
		if (mouseX > x-rad/2 && mouseY > y-rad/2 && mouseX < x + rad/2 && mouseY < y + rad/2)
		{
			clicked = true;
		}
	}

}

bool NoLetter::isClicked()
{
	return clicked;
}

bool NoLetter::isO()
{
	return false;
}

bool NoLetter::isS()
{
	return false;
}

bool NoLetter::isRed()
{
	return false;
}

bool NoLetter::isBlue()
{
	return false;
}
 