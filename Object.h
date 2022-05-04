#pragma once
#include <iostream>
#include <random>
#include <string>
#include "sgg/graphics.h"

using namespace std;

class Object
{
protected:	
	
	int x;
	int y;
	int rad; //aktina antikeimenou
	graphics::Brush br;
	bool selected;

public:
	
	Object(int x,int y, int rad,string icon_path);
	virtual void draw();
	int getx();
	int gety();
	void setSelected();
	void setUnSelected();
	bool isSelected();
	virtual void update() = 0;
	virtual bool isClicked();
	virtual ~Object();

};

