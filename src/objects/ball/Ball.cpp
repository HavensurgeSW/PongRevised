#include "Ball.h"
Pelota ball;

void setBallParameters() {
	ball.color = WHITE;
	ball.radius = 10;
	ball.ballPositionInit.x = GetScreenWidth() / 2;
	ball.ballPositionInit.y = GetScreenHeight() / 2;
	ball.ballPosition = ball.ballPositionInit;
	ball.ballSpeedX = GetFrameTime()*504.0f;
	ball.ballSpeedY = GetFrameTime()*351.6f;
	ball.playerId = 3;
}