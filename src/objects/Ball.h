#pragma once
#include "raylib.h"

struct Ball {
    Vector2 ballPosition;
    Vector2 ballSpeed;
    bool ballStop;
    float ballRadius;
	bool active;

};
extern Ball ball;
extern Ball multiball;
void setBallParameters();
