#include "HeaderMaster.h"

void main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");

    setPlayerParameters();
    Vector2 ballPosition = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
    Vector2 ballSpeed = { 5.0f, 4.0f };
    bool ballStop = true;
    float ballRadius = 12.0f;
    bool launchDirec = true;

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
            if (ballStop == false) {
                ballPosition.x += ballSpeed.x;
                ballPosition.y += ballSpeed.y;
            }

            //Scoring collisions
            if (ballPosition.x >= (GetScreenWidth() - ballRadius)) {
                players[0].score++;
                ballPosition.x = (GetScreenWidth() / 2);
                ballPosition.y = (GetScreenHeight() / 2);
                
                ballStop = true;
                launchDirec = true;
            }
            if (ballPosition.x <= (0 - ballRadius)) {
                players[1].score++;
                ballPosition.x = (GetScreenWidth() / 2);
                ballPosition.y = (GetScreenHeight() / 2);
                ballStop = true;
                launchDirec = false;
            }
            // Check walls collision for bouncing
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

            if (ballStop) {
                if (IsKeyDown(KEY_ENTER)) ballStop = false;
            }
        }
        else framesCounter++;
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(FormatText("%i", players[0].score), (GetScreenWidth() / 2) - 60, 20, 40, RED);
        DrawText(FormatText("%i", players[1].score), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);
        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), LIGHTGRAY);


        if (ballStop) {
            DrawText("PRESS ENTER to LAUNCH", GetScreenWidth() / 2 - 120, GetScreenHeight() - 25, 20, LIGHTGRAY);
            if(!launchDirec)
                DrawTriangleLines({ GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 - 15.0f }, RED);
            if(launchDirec)
                DrawTriangleLines({ GetScreenWidth() / 2 + 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 - 15.0f }, BLUE);
        }

        if(!ballStop)
        DrawText("PRESS SPACE to PAUSE", GetScreenWidth()/2-120, GetScreenHeight() - 25, 20, LIGHTGRAY);

        DrawCircleV(ballPosition, ballRadius, WHITE);
        DrawRectangleRec(players[0].rec, players[0].color);
        DrawRectangleRec(players[1].rec, players[1].color);

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