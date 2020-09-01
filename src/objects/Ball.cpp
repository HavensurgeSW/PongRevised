#include "Ball.h"

Ball ball;

void setBallParameters() {
	ball.ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	ball.ballSpeed = { -5.0f, 4.0f };
	ball.ballStop = true;
	ball.ballRadius = 12.0f;
}
