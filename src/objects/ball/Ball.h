#pragma once
#include "raylib.h"
struct Pelota {
	int radius;
	Vector2 ballPositionInit;
	Vector2 ballPosition;
	float ballSpeedX;
	float ballSpeedY;
	Color color;
	int playerId;

};

extern Pelota ball;
void setBallParameters();