#pragma once

#include "raylib.h"
#include "../objects/players.h"
#include "../objects/Ball.h"
#include <iostream>
using namespace std;

enum class screenID {
	splash,
    menu,
    game,
    finale,
    pause,
	credits
};
screenID screenId;

bool launchDirec;


void initGame() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");
    SetTargetFPS(60);
    screenId = screenID::splash;
}
void splashScreen(){
	int framesCounter = 0;
	

	while (screenId==screenID::splash&&!WindowShouldClose())    // Detect window close button or ESC key
	{
		framesCounter++;
		
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("A HSS Production", GetScreenWidth()/3, GetScreenHeight()/2-40, GetScreenWidth()/24, WHITE);
			
			EndDrawing();
		
		if (((framesCounter / 180) % 3) == 1){ //60 fps on 5 seconds
			screenId = screenID::menu;
		}
		
	}
	
}
void menuScreen() {
	bool menuBool = true;
	bool creditsBool = false;

	Rectangle playButton;
	playButton.x = 20;
	playButton.y = GetScreenHeight() / 2;
	playButton.height = 30;
	playButton.width = 65;
	
	Rectangle creditsButton;
	creditsButton.x = 20;
	creditsButton.y = (GetScreenHeight() / 2) + 100;
	creditsButton.height = 30;
	creditsButton.width = 113;
	Rectangle closeButton;
	closeButton.x = 20;
	closeButton.y = (GetScreenHeight() / 2) + 150;
	closeButton.height = 30;
	closeButton.width = 81.25f;
	


	while (!WindowShouldClose()&&screenId==screenID::menu) {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(FormatText("PONG"), 20, GetScreenHeight() / 8, 120, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), playButton))
			DrawText(FormatText("Play"), 20, GetScreenHeight()/2, 30, RED);
		else
			DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, RED);
		else
			DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), closeButton))
			DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, RED);
		else
			DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);

			

		DrawText(FormatText("v 0.9"), GetScreenWidth() - 50, 1, 20, WHITE);


		if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			screenId = screenID::game;
		}
	

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton)) {
			DrawText(FormatText("Engine: Raylib 3.0"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 20, 30, WHITE);
			DrawText(FormatText("Created by:"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 100, 30, WHITE);
			DrawText(FormatText("Matias P. Karplus"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 130, 30, WHITE);
		}
		

		if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			exit(0);
		}
		EndDrawing();
	}
}
/////GAME LOOP//////
void initGameObjects() {
    setPlayerParameters(); 
    setBallParameters(); 
	launchDirec = false;
}
void drawGame() {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), LIGHTGRAY);
    DrawCircleV(ball.ballPosition, ball.ballRadius, WHITE);
    DrawText(FormatText("%i", players[0].score), (GetScreenWidth() / 2) - 60, 20, 40, players[0].color);
    DrawText(FormatText("%i", players[1].score), (GetScreenWidth() / 2) + 40, 20, 40, players[1].color);

    if (ball.ballStop) {
        DrawText("PRESS ENTER to LAUNCH", GetScreenWidth() / 2 - 120, GetScreenHeight() - 25, 20, LIGHTGRAY);
        if (!launchDirec)
            DrawTriangleLines({ GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 - 15.0f }, players[0].color);
        if (launchDirec)
            DrawTriangleLines({ GetScreenWidth() / 2 + 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 - 15.0f }, players[1].color);
    }
	if (players[0].powerUp){
		DrawLine(GetScreenWidth() / 2-20, 0, GetScreenWidth() / 2-20, GetScreenHeight(), players[0].color);
	}

	if (players[1].powerUp) {
		DrawLine(GetScreenWidth() / 2 + 20, 0, GetScreenWidth() / 2+20, GetScreenHeight(), players[1].color);
	}

    DrawRectangleRec(players[0].rec, players[0].color);
    DrawRectangleRec(players[1].rec, players[1].color);
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
		players[0].powerUp = true;
		//Win Con
		if (players[0].score == 10) {
			screenId = screenID::menu;
		}
	}
	if (ball.ballPosition.x <= (0 - ball.ballRadius)) {
		players[1].score++;
		ball.ballPosition.x = (GetScreenWidth() / 2);
		ball.ballPosition.y = (GetScreenHeight() / 2);

		ball.ballStop = true;
		launchDirec = false;
		players[1].powerUp = true;

		//WinCon
		if (players[1].score == 10) {
			screenId = screenID::menu;
		}
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
void timePU(int id) {
	float timer = 0.0f;
	Vector2 ballPosTemp = ball.ballPosition;
	float ballSXTemp = ball.ballSpeed.x;
	float ballSYTemp = ball.ballSpeed.y;
	ball.ballSpeed.x = 0;
	ball.ballSpeed.y = 0;

	if (id == 0) {
		bool warudoBool0 = true;
		if (players[0].powerUp = true) {
			do {


				if (IsKeyDown(KEY_W)) players[0].rec.y -= players[0].paddleSpeed.y;
				if (IsKeyDown(KEY_S)) players[0].rec.y += players[0].paddleSpeed.y;
				if (IsKeyDown(KEY_A)) players[0].rec.x -= players[0].paddleSpeed.x;
				if (IsKeyDown(KEY_D)) players[0].rec.x += players[0].paddleSpeed.x;
				if (players[0].rec.y <= 0) {
					players[0].rec.y = 1;
				}
				if (players[0].rec.y >= GetScreenHeight() - players[0].paddleSize.y) {
					players[0].rec.y = GetScreenHeight() - players[0].paddleSize.y - 0.1f;
				}

				if (players[0].rec.x <= 0) {
					players[0].rec.x = 1;
				}
				if (players[0].rec.x >= GetScreenWidth() / 2 - 20) {
					players[0].rec.x = GetScreenWidth() / 2 - 21;
				}

				drawGame();
				timer += GetFrameTime();
				if (timer >= 2.5f) {
					warudoBool0 = false;
				}


			} while (warudoBool0);
			players[0].powerUp = false;
		}
	}
	if (id == 1) {
		bool warudoBool1 = true;
		if (players[1].powerUp = true) {
			do {


				if (IsKeyDown(KEY_UP)) players[1].rec.y -= players[1].paddleSpeed.y;
				if (IsKeyDown(KEY_DOWN)) players[1].rec.y += players[1].paddleSpeed.y;
				if (IsKeyDown(KEY_LEFT)) players[1].rec.x -= players[1].paddleSpeed.x;
				if (IsKeyDown(KEY_RIGHT)) players[1].rec.x += players[1].paddleSpeed.x;
				if (players[1].rec.y <= 0) {
					players[1].rec.y = 1;
				}
				if (players[1].rec.y >= GetScreenHeight() - players[1].paddleSize.y) {
					players[1].rec.y = GetScreenHeight() - players[1].paddleSize.y - 0.1f;
				}

				if (players[1].rec.x <= 0) {
					players[1].rec.x = 1;
				}
				if (players[1].rec.x <= GetScreenWidth() / 2 + 20) {
					players[1].rec.x = GetScreenWidth() / 2 + 21;
				}

				drawGame();
				timer += GetFrameTime();
				if (timer >= 2.5f) {
					warudoBool1 = false;
				}


			} while (warudoBool1);
			players[1].powerUp = false;
		}
	}


	ball.ballPosition = ballPosTemp;
	ball.ballSpeed.x = ballSXTemp;
	ball.ballSpeed.y = ballSYTemp;
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

	if (IsKeyPressed(KEY_G)&&players[0].powerUp) {
		timePU(0);
		
	}
	if (IsKeyPressed(KEY_L) && players[1].powerUp) {
		timePU(1);
		
	}

}
void update() {
	if (!ball.ballStop) {
		ball.ballPosition.y += ball.ballSpeed.y;
		ball.ballPosition.x += ball.ballSpeed.x;
	}
}


void gameScreen() {
	initGameObjects();
	
	bool pauseBool = false;
    while (!WindowShouldClose()&&screenId==screenID::game) {					
			
		if (!pauseBool){
			input();
			if (IsKeyPressed(KEY_P)) {
				pauseBool = true;
				fflush(stdin);
			}
			update();
			collisions();
			drawGame();
		}
		else {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText(FormatText("%i", players[0].score), (GetScreenWidth() / 2) - 60, 20, 40, players[0].color);
			DrawText(FormatText("%i", players[1].score), (GetScreenWidth() / 2) + 40, 20, 40, players[1].color);
			DrawRectangleLines(players[0].rec.x, players[0].rec.y, players[0].rec.width, players[0].rec.height, players[0].color);
			DrawRectangleLines(players[1].rec.x, players[1].rec.y, players[1].rec.width, players[1].rec.height, players[1].color);
			DrawCircleLines(ball.ballPosition.x, ball.ballPosition.y, ball.ballRadius, WHITE);
			DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), LIGHTGRAY);

			DrawText("PAUSED", GetScreenWidth()/3.0f+20, GetScreenHeight()/3.0f, 60, WHITE);
			DrawText("RESUME [P]", GetScreenWidth() / 3.0f + 70, GetScreenHeight() / 3.0f+120, 30, WHITE);
			DrawText("MENU [M]", GetScreenWidth() / 3.0f + 90, GetScreenHeight()-60.0f, 30, WHITE);


			if (IsKeyPressed(KEY_P)) {
				pauseBool = false;
			}
			if (IsKeyPressed(KEY_M)) {
				screenId = screenID::menu;
			}
			EndDrawing();
		}

    }

}


void main() {
    
    initGame();
	
	while (!WindowShouldClose()){
		switch (screenId) {
		case screenID::splash:
			splashScreen();
		case screenID::menu:
			menuScreen();
		case screenID::game:
			gameScreen();
		case screenID::finale:

			menuScreen();
		}
	}
	

    CloseWindow();        
  }