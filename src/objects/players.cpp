#pragma once
#include "players.h"

using namespace std;

Player::Player(){
	paddleSpeed.y = 7;
	paddleSpeed.x = 3;
	paddleSize = { 10.0f, 85.0f };
	rec.width = paddleSize.x;
	rec.height = paddleSize.y;
	rec.x = GetScreenWidth() / 20.0f;
	rec.y = GetScreenHeight() / 2.0f;
	score = 0;
	powerUp = false;
	shield = false;
	shields.height = GetScreenHeight();
	shields.width = 5;
	shields.x = 0;
	shields.y = 0;
	color = RED;
}
Player::~Player() {
	
}
Rectangle Player::getRec() {
	return rec;
}
void Player::setRecY(int y) {
	rec.y = y;
}
void Player::setRecX(int x) {
	rec.x = x;
}
void Player::setColor(Color c) {
	color = c;
}
Color Player::getColor() {
	return color;
}
void Player::setSpeed(int x, int y) {
	paddleSpeed.x = x;
	paddleSpeed.x = y;
}
Vector2 Player::getSpeed() {
	return paddleSpeed;
}
void Player::setScore(int i) {
	score += i;
}
int Player::getScore() {
	return score;
}

bool Player::getPU() {
	return powerUp;
}
void Player::setPU(bool p) {
	powerUp = p;
}

bool Player::getShield() {
	return shield;
}
void Player::setShield(bool s) {
	shield = s;
}

Rectangle Player::getShields() {
	return shields;
}


//void setPlayerParameters() {
//
//	cout << GetFrameTime() << endl;
//	players[0].paddleSpeed.y = 7;
//	players[0].paddleSpeed.x = 3;
//
//	players[0].paddleSize = { 10.0f, 85.0f };
//	players[1].paddleSpeed.y = 7;
//	players[1].paddleSpeed.x = 3;
//	players[1].paddleSize = { 10.0f, 85.0f };
//
//	players[0].rec.width = players[0].paddleSize.x;
//	players[0].rec.height = players[0].paddleSize.y;
//	players[1].rec.width = players[1].paddleSize.x;
//	players[1].rec.height = players[1].paddleSize.y;
//
//	players[0].rec.x = (float)GetScreenWidth() / 20;
//	players[0].rec.y = (float)GetScreenHeight() / 2;
//	players[1].rec.x = (float)GetScreenWidth() - 40;
//	players[1].rec.y = (float)GetScreenHeight() / 2;
//
//	players[0].score = 0;
//	players[0].powerUp = false;
//	players[1].score = 0;
//	players[1].powerUp = false;
//
//	players[0].shield = false;
//	players[0].shields.height = GetScreenHeight();
//	players[0].shields.width = 5;
//	players[0].shields.x = 0;
//	players[0].shields.y = 0;
//
//	players[1].shield = false;
//	players[1].shields.height = GetScreenHeight();
//	players[1].shields.width = 5;
//	players[1].shields.x = GetScreenWidth()-5;
//	players[1].shields.y = 0;
//
//}