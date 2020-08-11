#include "Player.h"
Player players[1];

void setPlayerParameters() {
	players[0].paddleSpeed = { GetFrameTime()*150.0f,GetFrameTime()*420.0f };
	players[0].paddleSize = { 10.0f, 85.0f };
	players[1].paddleSpeed = { GetFrameTime()*150.0f,GetFrameTime()*420.0f };
	players[1].paddleSize = { 10.0f, 85.0f };
	players[0].rec.width = players[0].paddleSize.x;
	players[0].rec.height = players[0].paddleSize.y;
	players[1].rec.width = players[1].paddleSize.x;
	players[1].rec.height = players[1].paddleSize.y;
	for (int i = 0; i < 2; i++)
	{
		players[i].score = 0;
		players[i].playerId = i;
	}
	players[0].rec.x = (float)GetScreenWidth() / 20;
	players[0].rec.y = (float)GetScreenHeight() / 2;
	players[1].rec.x = (float)GetScreenWidth() - 40;
	players[1].rec.y = (float)GetScreenHeight() / 2;

	players[0].powerUp = false;
	players[1].powerUp = false;

}