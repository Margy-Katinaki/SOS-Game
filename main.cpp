#include <iostream>
#include <random>
#include <string>
#include "Game.h"
#include "sgg/graphics.h"


void draw(){
	Game* game = (Game * ) graphics::getUserData();
	game->draw();
}


void update(float ms) {
	Game* game = (Game*)graphics::getUserData();
	game->update();
}



int main()
{
	Game game;

	graphics::createWindow(game.getww(), game.getwh(), "SOS Game"); 
	
	
	game.init();

	const auto assests = graphics::preloadBitmaps("assets");
	for (const auto asset : assests) {
		std::cout << "PRELOADING : " << asset << std::endl;
	}

	graphics::Brush br;
	br.texture = "";
	br.fill_color[0] = 0.1f;		
	br.fill_color[1] = 0.1f;		
	br.fill_color[2] = 0.1f;		
	graphics::setWindowBackground(br);

	graphics::setUserData(&game);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::setFont("assets/Letters for Learners Outline Bold.ttf");
	
	graphics::setCanvasSize(game.getcw(), game.getch());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
