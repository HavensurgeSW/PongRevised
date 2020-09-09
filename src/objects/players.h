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
	void setPlayer();
	void playerMovement();
};

//struct Player {
//
//	Rectangle rec;
//	int playerId;
//	Color color;
//	int score;
//	Vector2 paddleSpeed;
//	Vector2 paddleSize;
//	bool powerUp;
//	bool shield;
//	Rectangle shields;
//};

