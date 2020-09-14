#pragma once
#include "raylib.h"

class Ball {
private:
	Vector2 _pos;
	Vector2 _speed;
	bool _stop;
	float _radius;
	bool _active;
	bool _launchDirec;
public:

	Ball();
	~Ball();
	Vector2 getPos();
	void setPos(Vector2 v);
	Vector2 getSpeed();
	void setSpeed(Vector2 s);
	void invertSpeedY();
	void invertSpeedX();
	float getRadius();
	bool getActive();
	void setActive(bool a);
	bool getStop();
	void setStop(bool s);
	bool getLaunch();
	void setLaunch(bool l);

};

