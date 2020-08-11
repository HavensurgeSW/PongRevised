#pragma once
#include "raylib.h"
struct Player{
	Rectangle rec;
	int playerId;
	Color color;
	int score;
	Vector2 paddleSpeed;
	Vector2 paddleSize;
	bool powerUp;
};

extern Player players[1];
void setPlayerParameters();