#pragma once

#include "raylib.h"
#include "players.h"
#include "Ball.h"
#include <iostream>
using namespace std;

enum class screenID {
	splash,
    menu,
    game,
    finale,
    pause
};
screenID screenId;

bool launchDirec = false;


void initGame() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");
    SetTargetFPS(60);
    screenId = screenID::splash;
}
void splashScreen(){
	int framesCounter = 0;

	while (screenId==screenID::splash)    // Detect window close button or ESC key
	{
		
		framesCounter++;
		

			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("HAVENSURGE SOFTWORKS", GetScreenWidth()/4, GetScreenHeight()/2, GetScreenWidth()/24, WHITE);
			
			EndDrawing();
		
		if (((framesCounter / 300) % 5) == 1){
			screenId = screenID::game;
		}
		
	}
}
void menuScreen() {
    
    while (!WindowShouldClose()) { //PROBLEMA 2

        //Buttons

        Rectangle beginButton;
        beginButton.x = GetScreenWidth() / 3;
        beginButton.y = GetScreenHeight() - 80;
        beginButton.width = 20;
        beginButton.height = 20;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(FormatText("HSS Pong Revised"), GetScreenWidth() / 4.5, GetScreenHeight() / 10, 40, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), beginButton )) {
            DrawText(FormatText("BEGIN"), GetScreenWidth() / 3, GetScreenHeight() - 80, 20, RED);
        }
        DrawText(FormatText("BEGIN"), GetScreenWidth() / 3, GetScreenHeight() - 80, 20, WHITE);
        DrawText(FormatText("QUIT"), GetScreenWidth() / 2.7, GetScreenHeight() - 40, 20, WHITE);
        EndDrawing();
    }
}
/////GAME LOOP//////
void initGameObjects() {
    setPlayerParameters(); 
    setBallParameters();  
}
void drawGame() {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawCircleV(ball.ballPosition, 12.0f, WHITE);
    DrawText(FormatText("%i", players[0].score), (GetScreenWidth() / 2) - 60, 20, 40, RED);
    DrawText(FormatText("%i", players[1].score), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), LIGHTGRAY);


    if (ball.ballStop) {
        DrawText("PRESS ENTER to LAUNCH", GetScreenWidth() / 2 - 120, GetScreenHeight() - 25, 20, LIGHTGRAY);
        if (!launchDirec)
            DrawTriangleLines({ GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 - 15.0f }, RED);
        if (launchDirec)
            DrawTriangleLines({ GetScreenWidth() / 2 + 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 - 15.0f }, BLUE);
    }

    DrawRectangleRec(players[0].rec, RED);
    DrawRectangleRec(players[1].rec, BLUE);
    EndDrawing();

}
void collisions() {
	//Scoring collisions
	if (ball.ballPosition.x >= (GetScreenWidth() - ball.ballRadius)) {
		players[0].score++;
		ball.ballPosition.x = (GetScreenWidth() / 2);
		ball.ballPosition.y = (GetScreenHeight() / 2);

		ball.ballStop = true;
		launchDirec = true;
	}
	if (ball.ballPosition.x <= (0 - ball.ballRadius)) {
		players[1].score++;
		ball.ballPosition.x = (GetScreenWidth() / 2);
		ball.ballPosition.y = (GetScreenHeight() / 2);
		ball.ballStop = true;
		launchDirec = false;
	}
	// Check walls collision for bouncing
	if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballRadius)) || (ball.ballPosition.y <= ball.ballRadius)) ball.ballSpeed.y *= -1.0f;
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballRadius, players[0].rec)) ball.ballSpeed.x *= -1.0f;
	if (CheckCollisionCircleRec(ball.ballPosition, ball.ballRadius, players[1].rec)) ball.ballSpeed.x *= -1.0f;
	//player vs wall Collisions
	if (players[0].rec.y <= 0)players[0].rec.y = 0;
	if (players[0].rec.y >= GetScreenHeight() - players[0].paddleSize.y)players[0].rec.y = (GetScreenHeight() - players[0].paddleSize.y);
	if (players[1].rec.y <= 0)players[1].rec.y = 0;
	if (players[1].rec.y >= GetScreenHeight() - players[1].paddleSize.y)players[1].rec.y = (GetScreenHeight() - players[1].paddleSize.y);

	}
void input() {
	//MOVEMENT
	if (IsKeyDown(KEY_W))players[0].rec.y -= players[0].paddleSpeed.y;
	if (IsKeyDown(KEY_S))players[0].rec.y += players[0].paddleSpeed.y;
	if (IsKeyDown(KEY_UP))players[1].rec.y -= players[1].paddleSpeed.y;
	if (IsKeyDown(KEY_DOWN))players[1].rec.y += players[1].paddleSpeed.y;

	if (ball.ballStop) {
		if (IsKeyPressed(KEY_ENTER)) ball.ballStop = false;

	}
}
void update() {
	if (ball.ballStop == false) {
		ball.ballPosition.y += ball.ballSpeed.y;
		ball.ballPosition.x += ball.ballSpeed.x;
	}
}
void gameScreen() {
	initGameObjects();
    while (!WindowShouldClose()) {					
			input();
			update();
			collisions();
            drawGame();
    }

}

void main() {
    

    initGame();
	
		switch (screenId) {
		case screenID::splash:
			splashScreen();
			screenId = screenID::game;
		case screenID::menu:
			menuScreen();
			break;
		case screenID::game:
			gameScreen();
			break;
		}
	

    CloseWindow();        
  }