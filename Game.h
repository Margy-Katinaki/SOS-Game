#pragma once
#include <iostream>
#include <random>
#include <string>
#include "sgg/graphics.h"
#include "Object.h"
#include <vector>
#include "RedO.h"
#include "BlueO.h"
#include "RedS.h"
#include "BlueS.h"
#include "NoLetter.h"
#include "Score.h"


using namespace std;


static const string assets_path = "assets/";

class Game
{
	int window_width = 1024;
	int window_height = 768;

	float canvas_width = 100.0f;
	float canvas_height = 100.0f;

	vector <Object*> Game_Objects; //ola ektos apo ta letters
	vector<vector<Letter*>> Game_table; // mono letters

	int player;
	char letter;

	Letter* playerLetterO;
	Letter* playerLetterS;
	bool isOselected;			// simeiwnei poio apo ta dyo grammata exei dialexei

	Score * blueScore;
	Score * redScore;

	

	bool gameOver;

public:

	Game();
	void init();

	void draw();

	bool game_over();

	void update();

	void checkSOS(int i, int j);

	int getww();
	int getwh();
	float getcw();
	float getch();










	~Game();









};

