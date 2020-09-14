#pragma once
#include "raylib.h"
#include <iostream>

class Player {
private:
    Rectangle rec;
    Color color;
    int score;
    Vector2 paddleSpeed;
    Vector2 paddleSize;
    bool powerUp;
	bool shield;
	Rectangle shields;
public:
	Player();
	~Player();
	Rectangle getRec();
	void setRecY(int y);
	void setRecX(int x);
	void setColor(Color c);
	Color getColor();
	void setScore(int i);
	int getScore();
	void setSpeed(int x, int y);
	Vector2 getSpeed();

	bool getPU();
	void setPU(bool p);

	bool getShield();
	void setShield(bool s);

	Rectangle getShields();
};

