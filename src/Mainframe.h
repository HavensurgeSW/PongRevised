#pragma once
#include "raylib.h"
class Mainframe {
private:
	int _winWidth;
	int _winHeight;
	
public:

	enum class screenID {
		splash,
		menu,
		game,
		options,
		pause,
	};
	screenID screenId;

	Mainframe();
	~Mainframe();
	void setScene(int scene);
	void init();
	void update();
	void draw();
	void deInit();
};
