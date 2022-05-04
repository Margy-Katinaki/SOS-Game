#include "Object.h"


Object::Object(int x, int y, int rad,string icon_path)
{
	this->x = x;
	this->y = y;
	this->rad = rad;
	br.texture = icon_path;
	br.outline_opacity = 0.0f;

	selected = false;
}

void Object::draw()
{
	graphics::drawRect(x, y, rad, rad, br);
}

int Object::getx() {
	return x;
}



int Object::gety() {
	return y;
}

void Object::setSelected()
{
	selected = true;
	br.outline_opacity = 1.0f;
	br.outline_color[0] = 0.2;
	br.outline_color[1] = 0.8;
	br.outline_color[2] = 0.6;
}

void Object::setUnSelected()
{
	selected = false;
	br.outline_opacity = 0.0f;
}

bool Object::isSelected()
{
	return selected;
}



bool Object::isClicked()
{
	return false;
}

Object::~Object()
{
}
