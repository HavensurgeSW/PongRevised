#include "Ball.h"

Ball::Ball() {
	_pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	_speed = { -7.0f, 5.8f };
	_stop= true;
	_radius = 12.0f;
	_active = false;
	_launchDirec = false;
}
Ball::~Ball() {
	
}
Vector2 Ball::getPos() {
	return _pos;
}
void Ball::setPos(Vector2 v) {
	_pos = v;
}
Vector2 Ball::getSpeed() {
	return _speed;
}
void Ball::setSpeed(Vector2 s) {
	_speed = s;
}
void Ball::invertSpeedY() {
	_speed.y = _speed.y * -1.0f;
}
void Ball::invertSpeedX() {
	_speed.x = _speed.x * -1.0f;
}
float Ball::getRadius() {
	return _radius;
}
bool Ball::getActive(){
	return _active;
}
void Ball::setActive(bool a) {
	_active = a;
}
bool Ball::getStop() {
	return _stop;
}
void Ball::setStop(bool s) {
	_stop = s;
}

bool Ball::getLaunch() {
	return _launchDirec;
}
void Ball::setLaunch(bool l) {
	_launchDirec = l;
}


