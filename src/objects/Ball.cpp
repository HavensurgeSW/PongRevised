#include "Ball.h"

Ball ball;

void setBallParameters() {
	ball.ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	ball.ballSpeed = { -7.0f, 5.8f };
	ball.ballStop = true;
	ball.ballRadius = 12.0f;
}
