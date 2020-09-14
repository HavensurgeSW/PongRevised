#include "Mainframe.h"

Player* p1;
Player* p2;
Ball* b1;
Ball* b2;

Mainframe::Mainframe(){
	_winWidth = 800;
	_winHeight = 450;
	screenID screenId;
	setScene(0);
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
	}
}
void Mainframe::init() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "HSS - Pong (Revised)");
	SetTargetFPS(60);
	Player* p1 = new Player;
	Player* p2 = new Player;
	Ball* b1 = new Ball;
	Ball* b2 = new Ball;
	b2->setActive(false);
	screenId = screenID::splash;
}
void Mainframe::mainLoop() {
	while (!WindowShouldClose()) {
		switch (screenId) {
		case screenID::splash:
			splashScreen();
		case screenID::menu:
			menuScreen();
		case screenID::game:
			gameScreen();
		case screenID::options:
			optionsScreen();
		}
	}
}

void Mainframe::splashScreen() {
	int framesCounter = 0;

	/*p1->setColor(RED);
	p2->setColor(BLUE);*/
	cout << "project launched" << endl;



	while (screenId == screenID::splash && !WindowShouldClose())  {
		framesCounter++;

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("A HSS Production", GetScreenWidth() / 3, GetScreenHeight() / 2 - 40, GetScreenWidth() / 24, WHITE);

		EndDrawing();

		if (((framesCounter / 180) % 3) == 1) { //60 fps on 5 seconds
			setScene(1);
		}

	}


}
void Mainframe::menuScreen() {
	
	Rectangle playButton;
	playButton.x = 20.0f;
	playButton.y = GetScreenHeight() / 2.0f;
	playButton.height = 30.0f;
	playButton.width = 65.0f;
	Rectangle optionsButton;
	optionsButton.x = 20.0f;
	optionsButton.y = (GetScreenHeight() / 2) + 50.0f;
	optionsButton.height = 30.0f;
	optionsButton.width = 113.0f;

	Rectangle creditsButton;
	creditsButton.x = 20.0f;
	creditsButton.y = (GetScreenHeight() / 2) + 100.0f;
	creditsButton.height = 30.0f;
	creditsButton.width = 113.0f;
	Rectangle closeButton;
	closeButton.x = 20.0f;
	closeButton.y = (GetScreenHeight() / 2) + 150.0f;
	closeButton.height = 30.0f;
	closeButton.width = 81.25f;



	while (!WindowShouldClose() && screenId == screenID::menu) {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(FormatText("PONG"), 20, GetScreenHeight() / 8, 120, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), playButton))
			DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, RED);
		else
			DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), optionsButton))
			DrawText(FormatText("Options"), 20, (GetScreenHeight() / 2) + 50, 30, RED);
		else
			DrawText(FormatText("Options"), 20, (GetScreenHeight() / 2) + 50, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, RED);
		else
			DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), closeButton))
			DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, RED);
		else
			DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);



		DrawText(FormatText("v 1.0"), GetScreenWidth() - 50, 1, 20, WHITE);


		if (CheckCollisionPointRec(GetMousePosition(), playButton)) {
			DrawText(FormatText("GAME DETAILS"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 20, 30, WHITE);
			DrawText(FormatText("Gamemode: "), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 60, 20, WHITE);
			if (_PvP) {
				DrawText(FormatText("PvP"), (GetScreenWidth() / 2 + 150), (GetScreenHeight() / 4) + 60, 20, WHITE);
			}
			else {
				DrawText(FormatText("PvAI"), (GetScreenWidth() / 2 + 150), (GetScreenHeight() / 4) + 60, 20, WHITE);
			}

			DrawText(FormatText("Player 1"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 100, 20, RED);
			DrawText(FormatText("[W/S] [G]"), (GetScreenWidth() / 2 + 130), (GetScreenHeight() / 4) + 100, 20, RED);
			DrawText(FormatText("Player 2"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 140, 20, BLUE);
			DrawText(FormatText("[UP/DOWN] [L]"), (GetScreenWidth() / 2 + 130), (GetScreenHeight() / 4) + 140, 20, BLUE);

			DrawText(FormatText("[P]ause"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 4) + 180, 20, WHITE);


		}

		if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			screenId = screenID::game;
		}

		if (CheckCollisionPointRec(GetMousePosition(), optionsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			screenId = screenID::options;
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
void Mainframe::gameScreen() {
	bool pauseBool = false;
	while (!WindowShouldClose() && screenId == screenID::game&&_PvP) {

		if (!pauseBool) {
			input();
			update();
			collisions();
			draw();
		}
		else {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText(FormatText("%i", p1->getScore()), (GetScreenWidth() / 2) - 60, 20, 40, RED);
			DrawText(FormatText("%i", p2->getScore()), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);
			DrawRectangleLines(p1->getRec().x, p1->getRec().y, p1->getRec().width, p1->getRec().height, RED);
			DrawRectangleLines(p2->getRec().x, p2->getRec().y, p2->getRec().width, p2->getRec().height, BLUE);
			DrawCircleLines(b1->getPos().x, b1->getPos().y, b1->getRadius(), WHITE);
			if (b2->getActive()) {
				DrawCircleLines(b2->getPos().x, b2->getPos().y, b2->getRadius(), GOLD);
			}

			DrawText("PAUSED", GetScreenWidth() / 3.0f + 20, GetScreenHeight() / 3.0f, 60, WHITE);
			DrawText("RESUME [P]", GetScreenWidth() / 3.0f + 70, GetScreenHeight() / 3.0f + 120, 30, WHITE);
			DrawText("MENU [M]", GetScreenWidth() / 3.0f + 90, GetScreenHeight() - 60.0f, 30, WHITE);
			EndDrawing();


			if (IsKeyPressed(KEY_P)) {
				pauseBool = false;
			}
			if (IsKeyPressed(KEY_M)) {
				screenId = screenID::menu;
			}
		}

	}
	
}
void Mainframe::optionsScreen() {
	Rectangle backButton;
	backButton.x = 20;
	backButton.y = 20;
	backButton.height = 30;
	backButton.width = 70;
	Rectangle PvPButton;
	PvPButton.x = 20;
	PvPButton.y = GetScreenHeight() / 4 + 40;
	PvPButton.height = 30;
	PvPButton.width = 48.75f;
	Rectangle PvAIButton;
	PvAIButton.x = 20;
	PvAIButton.y = GetScreenHeight() / 4 + 80;
	PvAIButton.height = 30;
	PvAIButton.width = 65;

	Rectangle invPaddle0;
	invPaddle0.x = GetScreenWidth() / 2 + 90;
	invPaddle0.y = PvPButton.y + 10;
	invPaddle0.height = 10;
	invPaddle0.width = 85;
	Rectangle invPaddle1;
	invPaddle1.x = GetScreenWidth() / 2 + 90;
	invPaddle1.y = PvAIButton.y + 10;
	invPaddle1.height = 10;
	invPaddle1.width = 85;

	int color0 = 0;
	int color1 = 1;

	while (!WindowShouldClose() && screenId == screenID::options) {

		BeginDrawing();
		ClearBackground(BLACK);

		if (CheckCollisionPointRec(GetMousePosition(), backButton))
			DrawText(FormatText("Back"), 20, 20, 30, RED);
		else
			DrawText(FormatText("Back"), 20, 20, 30, WHITE);

		DrawText(FormatText("|PADDLE COLORS|"), GetScreenWidth() / 2, GetScreenHeight() / 4, 30, WHITE);
		DrawRectangle(GetScreenWidth() / 2 + 90, PvPButton.y + 10, 85, 10, RED);
		DrawRectangle(GetScreenWidth() / 2 + 90, PvAIButton.y + 10, 85, 10, BLUE);


		//--------------------
		DrawText(FormatText("|GAMEMODE|"), 20, GetScreenHeight() / 4, 30, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), PvPButton))
			DrawText(FormatText("PvP"), 20, PvPButton.y, 30, RED);
		else
			DrawText(FormatText("PvP"), 20, PvPButton.y, 30, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), PvAIButton))
			DrawText(FormatText("PvAI"), 20, PvAIButton.y, 30, RED);
		else
			DrawText(FormatText("PvAI"), 20, PvAIButton.y, 30, WHITE);
		//--------------------

		EndDrawing();


		if (CheckCollisionPointRec(GetMousePosition(), PvPButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			_PvP = true;
		}
		if (CheckCollisionPointRec(GetMousePosition(), PvAIButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			_PvP = false;
		}


		if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			screenId = screenID::menu;
		}

		if (CheckCollisionPointRec(GetMousePosition(), invPaddle0) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			color0++;
			if (color0 > 5)
				color0 = 0;

			switch (color0) {
			case 0:
				p1->setColor(RED);
				break;
			case 1:
				p1->setColor(BLUE);
				break;
			case 2:
				p1->setColor(YELLOW);
				break;
			case 3:
				p1->setColor(GREEN);
				break;
			case 4:
				p1->setColor(VIOLET);
				break;
			case 5:
				p1->setColor(BROWN);
				break;
			}
		}

		if (CheckCollisionPointRec(GetMousePosition(), invPaddle1) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			color1++;
			if (color1 > 5)
				color1 = 0;

			switch (color1) {
			case 0:
				p2->setColor(RED);
				break;
			case 1:
				p2->setColor(BLUE);
				break;
			case 2:
				p2->setColor(YELLOW);
				break;
			case 3:
				p2->setColor(GREEN);
				break;
			case 4:
				p2->setColor(VIOLET);
				break;
			case 5:
				p2->setColor(BROWN);
				break;
			}
		}
	}
}
void Mainframe::update() {
	if (!b1->getStop()) {
		b1->setPos(b1->getSpeed());
	}
	if (b2->getActive()) {
		b2->setPos(b2->getSpeed());
	}

	if (_randomPU >= 6) {
		hazards();
		_randomPU = 0;
	}

	if (p2->getScore() >= 10 || p1->getScore() >= 10) {
		screenId = screenID::menu;
	}
}
void Mainframe::draw() {
	if (screenId==screenID::game){
		if (!_pause) {
			BeginDrawing();

			ClearBackground(BLACK);

			DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), LIGHTGRAY);
			DrawText(FormatText("%i", p1->getScore()), (GetScreenWidth() / 2) - 60, 20, 40, RED);
			DrawText(FormatText("%i", p2->getScore()), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);
			DrawCircleV(b1->getPos(), b1->getRadius(), WHITE);

			if (b1->getStop()) {
				DrawText("PRESS ENTER to LAUNCH", GetScreenWidth() / 2 - 120, GetScreenHeight() - 25, 20, LIGHTGRAY);
				if (!b1->getLaunch())
					DrawTriangleLines({ GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 - 30.0f, GetScreenHeight() / 2 - 15.0f }, RED);
				if (b1->getLaunch())
					DrawTriangleLines({ GetScreenWidth() / 2 + 60.0f, GetScreenHeight() / 2.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 + 15.0f }, { GetScreenWidth() / 2 + 30.0f, GetScreenHeight() / 2 - 15.0f }, BLUE);
			}

			if (p1->getShield()) {
				DrawRectangleRec(p1->getShields(), RED);
			}
			if (p2->getShield()) {
				DrawRectangleRec(p2->getShields(), BLUE);
			}
			if (b2->getActive()) {
				DrawCircleV(b2->getPos(), b2->getRadius(), GOLD);
			}
			if (p1->getPU()) {
				DrawLine(GetScreenWidth() / 2 - 20, 0, GetScreenWidth() / 2 - 20, GetScreenHeight(), RED);
			}

			if (p2->getPU()) {
				DrawLine(GetScreenWidth() / 2 + 20, 0, GetScreenWidth() / 2 + 20, GetScreenHeight(), RED);
			}

			DrawRectangleRec(p1->getRec(), RED);
			DrawRectangleRec(p2->getRec(), BLUE);
			EndDrawing();
		}
		else {
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText(FormatText("%i", p1->getScore()), (GetScreenWidth() / 2) - 60, 20, 40, RED);
			DrawText(FormatText("%i", p2->getScore()), (GetScreenWidth() / 2) + 40, 20, 40, BLUE);
			DrawRectangleLines(p1->getRec().x, p1->getRec().y, p1->getRec().width, p1->getRec().height, RED);
			DrawRectangleLines(p2->getRec().x, p2->getRec().y, p2->getRec().width, p2->getRec().height, BLUE);
			DrawCircleLines(b1->getPos().x, b1->getPos().y, b1->getRadius(), WHITE);
			if (b2->getActive()) {
				DrawCircleLines(b2->getPos().x, b2->getPos().y, b2->getRadius(), GOLD);
			}

			DrawText("PAUSED", GetScreenWidth() / 3.0f + 20, GetScreenHeight() / 3.0f, 60, WHITE);
			DrawText("RESUME [P]", GetScreenWidth() / 3.0f + 70, GetScreenHeight() / 3.0f + 120, 30, WHITE);
			DrawText("MENU [M]", GetScreenWidth() / 3.0f + 90, GetScreenHeight() - 60.0f, 30, WHITE);
			EndDrawing();
		}
	}
	
}
void Mainframe::input() {
	if (screenId == screenID::game) {
		if (IsKeyDown(KEY_W))p1->setRecY(p1->getRec().y - p1->getSpeed().y);
		if (IsKeyDown(KEY_S))p1->setRecY(p1->getRec().y + p1->getSpeed().y);
		if (IsKeyPressed(KEY_G) && p1->getPU()) {
			timePU(0);
		}

		if (_PvP) {
			if (IsKeyDown(KEY_UP))p2->setRecY(p2->getRec().y - p2->getSpeed().y);
			if (IsKeyDown(KEY_DOWN))p2->setRecY(p2->getRec().y + p2->getSpeed().y);
			if (IsKeyPressed(KEY_L) && p2->getPU()) {
				timePU(1);
			}
		}
		if (!_PvP) {
			if (b1->getPos().y > p2->getRec().y) {
				p2->setRecY(p2->getRec().y + p2->getSpeed().y);
			}
			if (b1->getPos().y < p2->getRec().y) {
				p2->setRecY(p2->getRec().y - p2->getSpeed().y);
			}
		}
		if (b1->getStop()) {
			if (IsKeyPressed(KEY_ENTER)) b1->setStop(false);
		}

		if (IsKeyPressed(KEY_P)) {
			_pause = true;
			fflush(stdin);
		}

		if (_pause) {
			if (IsKeyPressed(KEY_P)) {
				_pause = false;
			}
			if (IsKeyPressed(KEY_M)) {
				screenId = screenID::menu;
			}
		}

	}

}
void Mainframe::collisions(){
	//Scoring collisions
	if (b2->getPos().x >= (GetScreenWidth() - b2->getRadius())) {
		p1->setScore(1);
		b2->setPos({ GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f });
		b2->setActive(false);
	}
	if (b1->getPos().x >= (GetScreenWidth() - b1->getRadius())) {
		p1->setScore(1);
		b1->setPos({ GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f });

		b1->setStop(true);
		b2->setActive(false);
		b1->setLaunch(true);
		_randomPU = 0;
		p1->setPU(true);
		p2->setShield(true);
		

	}
	if (b2->getPos().x <= (0 - b2->getRadius())) {
		p2->setScore(1);
		b2->setPos({ GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f });
		b2->setActive(false);
	}

	if (b1->getPos().x <= (0 - b1->getRadius())) {
		p2->setScore(1);
		b1->setPos({ GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f });

		b1->setStop(true);
		b2->setActive(false);
		b1->setLaunch(true);
		_randomPU = 0;
		p2->setPU(true);
		p1->setShield(true);


	}
	// Check walls collision for bouncing
	if ((b1->getPos().y>= (GetScreenHeight() - b1->getRadius())) || (b1->getPos().y <= b1->getRadius())) b1->invertSpeedY();
	if ((b2->getPos().y >= (GetScreenHeight() - b2->getRadius())) || (b2->getPos().y <= b2->getRadius())) b2->invertSpeedY();


	// Ball v Paddles
	if (CheckCollisionCircleRec(b1->getPos(), b1->getRadius(), p1->getRec())) {
		b1->invertSpeedX();
		if (p1->getRec().x != GetScreenWidth() / 20)
			p1->setRecX(GetScreenWidth() / 20);
		_randomPU++;
	}
	////////////////////////////B v SHIELDS 1
	if (CheckCollisionCircleRec(b1->getPos(), b1->getRadius(), p1->getShields()) && p1->getShield()) {
		b1->invertSpeedX();
		p1->setShield(false);
	}

	if (CheckCollisionCircleRec(b2->getPos(), b2->getRadius(), p1->getShields()) && p1->getShield()) {
		b2->invertSpeedX();
		p1->setShield(false);
	}
	//////////////////////////B v SHIELDS 2
	if (CheckCollisionCircleRec(b1->getPos(), b1->getRadius(), p2->getShields()) && p2->getShield()) {
		b1->invertSpeedX();
		p2->setShield(false);
	}

	if (CheckCollisionCircleRec(b2->getPos(), b2->getRadius(), p2->getShields()) && p2->getShield()) {
		b2->invertSpeedX();
		p2->setShield(false);
	}

	if (CheckCollisionCircleRec(b2->getPos(),b2->getRadius(), p1->getRec())) {
		b2->invertSpeedX();
	}
	if (CheckCollisionCircleRec(b2->getPos(), b2->getRadius(), p2->getRec())) {
		b2->invertSpeedX();
	}

	if (CheckCollisionCircleRec(b1->getPos(), b1->getRadius(), p2->getRec())) {
		b1->invertSpeedX();

		if (p2->getRec().x != GetScreenWidth() / 20)
			p2->setRecX(GetScreenWidth() / 20);
		_randomPU++;
	}


	//player vs wall Collisions
	if (p1->getRec().y <= 0)p1->setRecY(0);
	if (p1->getRec().y >= GetScreenHeight() - p1->getRec().height)p1->setRecY(GetScreenHeight() - p1->getRec().height);
	if (p2->getRec().y <= 0)p2->setRecY(0);
	if (p2->getRec().y >= GetScreenHeight() - p2->getRec().height)p2->setRecY(GetScreenHeight() - p2->getRec().height);

}
void Mainframe::deInit() {
	delete p1;
	delete p2;
	delete b1;
	delete b2;
	
	CloseWindow();
}

void Mainframe::timePU(int id) {
	float timer = 0.0f;
	Vector2 ballPosTemp = b1->getPos();
	Vector2 ballSTemp = b1->getSpeed();
	b1->setSpeed({0, 0});

	if (id == 0) {
		bool warudoBool0 = true;
		if (p1->getPU()) {
			do {
				if (IsKeyDown(KEY_W))p1->setRecY(p1->getRec().y - p1->getSpeed().y);
				if (IsKeyDown(KEY_S))p1->setRecY(p1->getRec().y + p1->getSpeed().y);
				if (IsKeyDown(KEY_A))p1->setRecX(p1->getRec().x - p1->getSpeed().x);
				if (IsKeyDown(KEY_D))p1->setRecX(p1->getRec().x + p1->getSpeed().x);
				if (p1->getRec().y <= 0) {
					p1->setRecY(1);
				}
				if (p1->getRec().y >= GetScreenHeight() - p1->getRec().height) {
					p1->setRecY(GetScreenHeight() - p1->getRec().height - 0.1f);
				}

				if (p1->getRec().x <= 0) {
					p1->setRecX(1);

				}
				if (p1->getRec().x >= GetScreenWidth() / 2 - 20) {
					p1->setRecX(GetScreenWidth() / 2 - 21);
				}

				draw();
				timer += GetFrameTime();
				if (timer >= 2.5f) {
					warudoBool0 = false;
				}


			} while (warudoBool0);
			p1->setPU(false);
		}
	}
	if (id == 1) {
		bool warudoBool1 = true;
		if (p2->getPU()) {
			do {
				if (IsKeyDown(KEY_UP))p2->setRecY(p2->getRec().y - p2->getSpeed().y);
				if (IsKeyDown(KEY_DOWN))p2->setRecY(p2->getRec().y + p2->getSpeed().y);
				if (IsKeyDown(KEY_LEFT))p2->setRecX(p2->getRec().x - p2->getSpeed().x);
				if (IsKeyDown(KEY_RIGHT))p2->setRecX(p2->getRec().x + p2->getSpeed().x);
				if (p2->getRec().y <= 0) {
					p2->setRecY(1);
				}
				if (p2->getRec().y >= GetScreenHeight() - p2->getRec().height) {
					p2->setRecY(GetScreenHeight() - p2->getRec().height - 0.1f);
				}

				if (p2->getRec().x >= GetScreenWidth()) {
					p2->setRecX(GetScreenWidth() - 1);

				}
				if (p2->getRec().x <= GetScreenWidth() / 2 + 20) {
					p2->setRecX(GetScreenWidth() / 2 + 21);
				}

				draw();
				timer += GetFrameTime();
				if (timer >= 2.5f) {
					warudoBool1 = false;
				}


			} while (warudoBool1);
			p2->setPU(false);
		}

	}
	b1->setPos(ballPosTemp);
	b1->setSpeed(ballSTemp);
}
void Mainframe::hazards() {
	switch (GetRandomValue(1, 1)) {
	case 1:
		b2->setActive(true);
		break;
	}
}