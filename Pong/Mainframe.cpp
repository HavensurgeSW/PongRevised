#include "Mainframe.h"

Mainframe::Mainframe(){
	_winWidth = 800;
	_winHeight = 450;
	screenID screenId;
}
Mainframe::~Mainframe() {
	deInit();
}
void Mainframe::setScene(int scene) {
	switch (scene) {
	case 0:
		screenId = screenID::splash;
		break;
	case 1:
		screenId = screenID::menu;
		break;
	case 2:
		screenId = screenID::game;
		break;
	case 3:
		screenId = screenID::options;
		break;
	case 4:
		screenId = screenID::pause;
		break;
	}
}
void Mainframe::init() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");
	SetTargetFPS(60);
	screenId = screenID::splash;
}
void Mainframe::update() {

}
void Mainframe::draw() {

}
void Mainframe::deInit() {
	CloseWindow();
}