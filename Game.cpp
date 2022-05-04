#include "Game.h"
#include <iostream>
#include <random>
#include <string>
#include "sgg/graphics.h"
#include "Letter.h"
#include "RedO.h"
#include "BlueO.h"
#include "BlackO.h"
#include "BlackS.h"
#include "RedS.h"
#include "BlueS.h"
#include "Score.h"
#include "NoLetter.h"


Game:: Game(){
	Game_table.resize(7);
	for (int i = 0; i < 7; i++) {
		Game_table[i].resize(7);
	}


	this->window_width = 1024;
	this->window_height = 768;
	this->canvas_width = 100.0f;
	this->canvas_height = 100.0f;

}





void Game::init(){
	graphics::Brush br;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.1f;
	br.fill_color[2] = 0.1f;
	graphics::setWindowBackground(br);
	graphics::setFont(assets_path + "Letters for Learners Outline Bold.ttf");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Game_table[i][j] = new NoLetter( 10+ (i+1)*10, (j+1)*10,"assets\\blank.png");
		}
	}

	
	playerLetterO = new BlackO(canvas_width / 2 - 10, canvas_height - 20);
	playerLetterS = new BlackS(canvas_width / 2 + 10, canvas_height - 20);

	player = 1;
	isOselected = true;
	playerLetterO->setSelected();

	Game_Objects.push_back(playerLetterO);
	Game_Objects.push_back(playerLetterS);


	blueScore = new Score( 5, canvas_height-5);
	redScore = new Score(canvas_width-40, canvas_height - 5);

	Game_Objects.push_back(blueScore);
	Game_Objects.push_back(redScore);

	gameOver = false;


}




void Game::draw(){
	

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Game_table[i][j]->draw();
		}
	}

	for (int i = 0; i < Game_Objects.size(); i++) {
		Game_Objects[i]->draw();
	}

	if (gameOver) {

		graphics::Brush br;
		br.outline_opacity = 0.0f;

		if (blueScore->getScore() > redScore->getScore()) {
			graphics::drawText(canvas_width / 2 - 40, canvas_height / 2, 8, "Game Over Blue wins", br);
		}
		else if (blueScore->getScore() < redScore->getScore()) {
			graphics::drawText(canvas_width / 2 - 40, canvas_height / 2, 8, "Game Over Red wins", br);
		}
		else {
			graphics::drawText(canvas_width / 2 - 40, canvas_height / 2, 8, "Game Over No Winner", br);
		}
	}
}

bool Game::game_over()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if( dynamic_cast<NoLetter*>(Game_table[i][j]) != nullptr )
			{
				return false;
			}
		}
	}
	gameOver = true;

	return true;
}


void Game::update(){

	if (gameOver == true)
		return;

	// Update olwn twn antikeimenwn
	for (int i = 0; i < Game_Objects.size(); i++) {
		Game_Objects[i]->update();

		if (dynamic_cast<BlackO*>(Game_Objects[i]) != nullptr && Game_Objects[i]->isSelected())
		{
			isOselected = true;
			playerLetterS->setUnSelected();
		}
		else if (dynamic_cast<BlackS*>(Game_Objects[i]) != nullptr && Game_Objects[i]->isSelected())
		{
			isOselected = false;
			playerLetterO->setUnSelected();
		}
	}

	// Update olwn twn kartwn
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Game_table[i][j]->update();

			// Koitame na doume an ekane klik panw tis
			if (Game_table[i][j]->isClicked() == true)
			{
				Letter* l;

				if (player == 1) {

					if (isOselected) {
						// Vazoume stin thesi tou to gramma pou prepei
						l  = new BlueO(Game_table[i][j]->getx(), Game_table[i][j]->gety());
					}
					else {
						l = new BlueS(Game_table[i][j]->getx(), Game_table[i][j]->gety());
					}

					player = 2;
				}
				else {

					if (isOselected) {
						// Vazoume stin thesi tou to gramma pou prepei
						l = new RedO(Game_table[i][j]->getx(), Game_table[i][j]->gety());
					}
					else {
						l = new RedS(Game_table[i][j]->getx(), Game_table[i][j]->gety());
					}

					player = 1;
				}

				// Svinw to noletter
				delete Game_table[i][j];
				Game_table[i][j] = l;

				checkSOS(i,j);

				break;
			}
		}
	}

	
	// Elegxei an teleiwse to paixnidi
	game_over();

	
}

void Game::checkSOS(int i, int j)
{
	Letter* l;
	l = dynamic_cast<Letter*> (Game_table[i][j]);

	
	
	
	
	if (l->isRed() == true) {
		if (l->isO() == true) {
			for (int x = i - 1; x < (i + 2); x++) {
				for (int y = j - 1; y < (j + 2); y++) {
					if (x < 0 || y < 0 || x>6 || y>6 ) {
						break;
					}
					else if (Game_table[x][y]->isRed() == true && Game_table[x][y]->isS() == true){
						if ((2 * i - x) < 0 || (2 * j - y) < 0 || (2 * i - x) > 6 || (2 * j - y) > 6) {
							break;
						}
						else if (Game_table[2 * i - x][2 * j - y]->isS() == true && Game_table[2 * i - x][2 * j - y]->isRed() == true) {
							redScore->increase();
						}
						else {
							break;
						}
						
					}
					else {
						break;
					}
					
				}

			}
		}
		else if (l->isS() == true) {
			for (int x = i - 1; x <= (i + 1); x++) {
				for (int y = j - 1; y <= (j + 1); y++) {
					if (x < 0 || y < 0 || x>6 || y>6) {
						break;
					}
					else if (Game_table[x][y]->isO() == true &&
						Game_table[x][y]->isRed() == true) {
						if ((i + 2 * (x - i)) < 0 || (j + 2 * (y - j)) < 0 || (i + 2 * (x - i)) > 6 || (j + 2 * (y - j)) > 6) {
							break;
						}
						else if (Game_table[i + 2 * (x - i)][j + 2 * (y - j)]->isRed() == true && Game_table[i + 2 * (x - i)][j + 2 * (y - j)]->isS() == true) {
							redScore->increase();
						}
						else {
							break;
						}
						
					}
				}

			}
		}
	}
	else if (l->isBlue() == true) {
		if (l->isO() == true) {
			for (int x = i - 1; x < (i + 2); x++) {
				for (int y = j - 1; y < (j + 2); y++) {
					if (x < 0 || y < 0 || x>6 || y>6) {
						break;
					}
					else if (Game_table[x][y]->isBlue() == true && Game_table[x][y]->isS() == true) {
						if ((2 * i - x) < 0 || (2 * j - y) < 0 || (2 * i - x) > 7 || (2 * j - y) > 7) {
							break;
						}
						else if (Game_table[2 * i - x][2 * j - y]->isS() == true && Game_table[2 * i - x][2 * j - y]->isBlue() == true) {
							blueScore->increase();
						}
						else {
							break;
						}

					}
					else {
						break;
					}

				}

			}
		}
			else if (l->isS() == true) {
				for (int x = i - 1; x < (i + 2); x++) {
					for (int y = j - 1; y < (j + 2); y++) {
						if (x < 0 || y < 0 || x>6 || y>6) {
							break;
						}
						else if (Game_table[x][y]->isO() == true &&
								Game_table[x][y]->isBlue() == true) {
							if ((i + 2 * (x - i)) < 0 || (j + 2 * (y - j)) < 0 || (i + 2 * (x - i)) > 6 || (j + 2 * (y - j)) > 6) {
								break;
							}
							else if (Game_table[i + 2 * (x - i)][j + 2 * (y - j)]->isBlue() == true && Game_table[i + 2 * (x - i)][j + 2 * (y - j)]->isS() == true) {
								blueScore->increase();
							}
							
						}
					}

				}
			}
	}

	
	}




int Game::getww(){
	return window_width;
}



int Game::getwh(){
	return window_height;
}


float Game::getcw(){
	return canvas_width;
}


float Game:: getch(){
	return canvas_height;
}








Game:: ~Game(){
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			delete Game_table[i][j];
		}
	}
	for (int i = 0; i < Game_Objects.size(); i++) {
		delete Game_Objects[i];
	}

}
