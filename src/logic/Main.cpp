#include "raylib.h"

struct Player {
    Rectangle rec;
    int playerId;
    Color color;
    int score;
    Vector2 paddleSpeed;
    Vector2 paddleSize;
    bool powerUp;
};

Player players[2];
void setPlayerParameters() {
    players[0].paddleSpeed = { GetFrameTime() * 150.0f,GetFrameTime() * 420.0f };
    players[0].paddleSize = { 10.0f, 85.0f };
    players[1].paddleSpeed = { GetFrameTime() * 150.0f,GetFrameTime() * 420.0f };
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

    players[0].color = RED;
    players[1].color = BLUE;

    players[0].powerUp = false;
    players[1].powerUp = false;

}

void main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");

    setPlayerParameters();
    Vector2 ballPosition = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
    Vector2 ballSpeed = { 5.0f, 4.0f };
    float ballRadius = 12.0f;

    bool pause = 0;
    int framesCounter = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;
       

        if (!pause)
        {
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;

            // Check walls collision for bouncing
            if (ballPosition.x >= (GetScreenWidth() - ballRadius)) {
                players[0].score++;
                ballPosition.x = (GetScreenWidth() / 2, GetScreenHeight() / 2);
            }

            if (ballPosition.x <= (0 - ballRadius)) {
                players[1].score++;
                ballPosition.x = (GetScreenWidth() / 2, GetScreenHeight() / 2);
            }

            if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;
            if (CheckCollisionCircleRec(ballPosition, ballRadius, players[0].rec)) ballSpeed.x *= -1.0f;
            if (CheckCollisionCircleRec(ballPosition, ballRadius, players[1].rec)) ballSpeed.x *= -1.0f;
            //player vs wall Collisions
            if (players[0].rec.y <= 0)players[0].rec.y = 0;
            if (players[0].rec.y >= GetScreenHeight()-players[0].paddleSize.y)players[0].rec.y = (GetScreenHeight() - players[0].paddleSize.y);
            if (players[1].rec.y <= 0)players[1].rec.y = 0;
            if (players[1].rec.y >= GetScreenHeight() - players[1].paddleSize.y)players[1].rec.y = (GetScreenHeight() - players[1].paddleSize.y);


            if (IsKeyDown(KEY_W))players[0].rec.y -= 7;
            if (IsKeyDown(KEY_S))players[0].rec.y += 7;
            if (IsKeyDown(KEY_UP))players[1].rec.y -= 7;
            if (IsKeyDown(KEY_DOWN))players[1].rec.y += 7;
        }
        else framesCounter++;
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleV(ballPosition, ballRadius, WHITE);
        DrawRectangleRec(players[0].rec, players[0].color);
        DrawRectangleRec(players[1].rec, players[1].color);
        DrawText(FormatText("%i", players[0].score), (GetScreenWidth() / 2) - 60, 20, 40, RED);
        DrawText(FormatText("%i", players[1].score), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);
        //DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), GRAY);
        


        DrawText("PRESS SPACE to PAUSE", GetScreenWidth()/2-120, GetScreenHeight() - 25, 20, LIGHTGRAY);

        // On pause, we draw a blinking message
        if (pause && ((framesCounter / 30) % 2)) DrawText("PAUSED", 350, 200, 30, GRAY);
        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------



}