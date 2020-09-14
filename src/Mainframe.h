#pragma once
#include "raylib.h"
#include "objects/players.h"
#include "objects/Ball.h"
#include <iostream>
using namespace std;


class Mainframe {
private:
	int _winWidth;
	int _winHeight;
	bool _PvP;
	bool _pause;
	int _randomPU;
public:

	enum class screenID {
		splash,
		menu,
		game,
		options,
	};
	screenID screenId;

	Mainframe();
	~Mainframe();
	void init();
	void deInit();

	void setScene(int scene);
	void mainLoop();
	void splashScreen();
	void menuScreen();
	void gameScreen();
	void optionsScreen();

	void update();
	void draw();
	void input();
	void collisions();

	void timePU(int id);
	void hazards();

};

extern Player* p1;
extern Player* p2;
extern Ball* b1;
extern Ball* b2;
