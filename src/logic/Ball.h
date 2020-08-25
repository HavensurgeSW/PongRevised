#pragma once
#include "raylib.h"

struct Ball {
    Vector2 ballPosition;
    Vector2 ballSpeed;
    bool ballStop;
    float ballRadius;

};
extern Ball ball;
void setBallParameters();
