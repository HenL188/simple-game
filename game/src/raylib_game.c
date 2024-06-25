#include "raylib.h"
#include "ui.h"
#include "levels.h"
#include "player.h"

typedef struct sceneStart { bool one; bool two; bool three; bool four; bool five; bool six; bool seven; bool eight; bool nine; bool ten; } sceneStart;
typedef enum Level { TITLE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, GAMEOVER, CREDITS } Level;
int main() {
	InitWindow(800, 450, "Window");
	SetTargetFPS(60);

	Vector2 position = { 0, 225 };
	Vector2 spawn = { 0, 225 };
	sceneStart start = {true ,true, true, true, true, true, true, true, true, true};
	float radius = 25.0f;
	Color color = BLACK;
	Color hidden = GREEN;
	const float speed = 2.0f;
	//Vector2 gavity = { 0,100 };
	int health = 100;
	int healthUp = 0;
	Level scene = 4;
	int lives = 3;
	int lifeUp = 0;
	bool pickUpHealth = false;
	bool pickUpLife = false;

	while (!WindowShouldClose()) {

		Movement(speed, &position);
		Bounds(&position, radius);
		radius = SizeChage(radius);

		if (lives == 0) {
			scene = GAMEOVER;
		}
		else { ; }

		if (health > 100) {
			health = 100;
		}
		else { ; }

		//position.y += gavity.y * GetFrameTime();
		switch (scene)
		{
		case TITLE:
			if (IsKeyPressed(KEY_ENTER)) {
				scene = ONE;
			}
			else { ; }
			break;
		case ONE:
			if (start.one == true) {
				bool collison = false;
				collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 400, 225, 50, 50 });
				if (collison) {
					scene = TWO;
				}
			}
			break;
		case TWO:
			if (start.two == true) {
				position = spawn;
				start.two = false;
			}
			else {
				bool collison = false;
				bool redCollison = false;
				collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 50, 50 });
				redCollison = CheckCollisionCircleRec(position, radius, (Rectangle) { 200, 150, 50, 50 });
				if (collison) {
					scene = THREE;
				}
				else { ; }
				if (redCollison) {
					health -= 10.0f * GetFrameTime();
					if (health == 0) {
						position = spawn;
						health = 100;
						lives -= 1;
					}
					else { ; }
				}
				else { ; }
			}
			
			break;
		case THREE:
			if (start.three == true) {
				position = spawn;
				health = 90;
				start.three = false;
			}
			else {
				bool collison = false;
				bool collisonHealth = false;
				bool redCollison1 = false;
				bool redCollison2 = false;
				bool redCollison3 = false;
				collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 355, 285, 20, 20, });
				collisonHealth = CheckCollisionCircleRec(position, radius, (Rectangle) { 400, 225, 10, 10 });
				redCollison1 = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 80, 20 });
				redCollison2 = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 245, 80, 20 });
				redCollison3 = CheckCollisionCircleRec(position, radius, (Rectangle) { 375, 255, 20, 80 });

				if (collison) {
					scene = FOUR;
				}
				else { ; }

				if (collisonHealth) {
					pickUpHealth = true;
				}
				else { ; }
				if (pickUpHealth == true && health < 100) {
					if (healthUp == 0) {
						health += 10;
						healthUp = 1;
					}
				}
				else { ; }

				if (redCollison1 || redCollison2 || redCollison3) {
					health -= 10.0f * GetFrameTime();
					if (health == 0) {
						position = spawn;
						health = 100;
						lives -= 1;
					}
					else { ; }
				}
				else { ; }
			}
			break;
		case FOUR:
			if (start.four == true) {
				position = spawn;
				lives = 2;
				start.four = false;
			}
			else {
				bool collison1 = false;
				bool collison2 = false;
				bool collisonLife = false;
				bool collisonRed = false;
				bool collisonRed2 = false;
				bool collisonRed3 = false;
				bool collisonRed4 = false;
				bool collisonRed5 = false;
				bool collisonRed6 = false;

				collisonLife = CheckCollisionCircleRec(position, radius, (Rectangle) { 390, 185, 10, 10 });
				collison1 = CheckCollisionCircleRec(position, radius, (Rectangle) { 375, 183, 40, 40 });
				collison2 = CheckCollisionCircleRec(position, radius, (Rectangle) { 375, 377, 40, 40 });
				collisonRed = CheckCollisionCircleRec(position, radius, (Rectangle) { 320, 150, 150, 30 });
				collisonRed2 = CheckCollisionCircleRec(position, radius, (Rectangle) { 320, 420, 150, 30 });
				collisonRed3 = CheckCollisionCircleRec(position, radius, (Rectangle) { 320, 180, 30, 60 });
				collisonRed4 = CheckCollisionCircleRec(position, radius, (Rectangle) { 440, 180, 30, 60 });
				collisonRed5 = CheckCollisionCircleRec(position, radius, (Rectangle) { 320, 390, 30, 60 });
				collisonRed6 = CheckCollisionCircleRec(position, radius, (Rectangle) { 440, 390, 30, 60 });
				
				if (collisonRed || collisonRed2 || collisonRed3 ||  collisonRed4 || collisonRed5 || collisonRed6) {
					health -= 10.0f * GetFrameTime();
					if (health == 0) {
						position = spawn;
						health = 100;
						lives -= 1;
					}
					else { ; }
				}
				if (collisonLife) pickUpLife = true;
				else { ; }
				if (pickUpLife == true) {
					if (lifeUp == 0) {
						lives += 1;
						lifeUp = 1;
					}
					else { ; }
					if (collison2) scene = FIVE;
					else { ; }
				}
				else { ; }
				if (collison1 == true) hidden = (Color){ 245,245,245,0 };
				else { hidden = GREEN; }
			}
			break;
		case GAMEOVER:
			if (IsKeyPressed(KEY_ENTER)) {
				scene = TITLE;
				lives = 3;
			}
			else { ; }
			break;
		case CREDITS:
			break;
		default:
			NULL;
		break;
		}

		BeginDrawing();

		switch (scene) {
		case TITLE:
			ClearBackground(RAYWHITE);
			DrawText("Hit enter to play", 70, 100, 50, BLACK);
			break;
		case ONE:
			LevelOne();
			DrawCircleV(position, radius, color);
			break;
		case TWO:
			LevelTwo(health, lives);
			DrawCircleV(position, radius, color);
			break;
		case THREE:
			DrawCircleV(position, radius, color);
			LevelThree(health, lives, pickUpHealth);
			break;
		case FOUR:
			DrawCircleV(position, radius, color);
			LevelFour(health,lives,pickUpLife,hidden);
			break;
		case FIVE:
			ClearBackground(RAYWHITE);
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case SIX:
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case SEVEN:
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case EIGHT:
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case NINE:
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case TEN:
			TaskBar();
			DrawCircleV(position, radius, color);
			break;
		case GAMEOVER:
			ClearBackground(RAYWHITE);
			DrawText("GAMEOVER", 70, 100, 50, BLACK);
			if (IsKeyPressed(KEY_ENTER)) {
				scene = TITLE;
			}
			break;
		case CREDITS:
			NULL;
			break;
		default:
			ClearBackground(RAYWHITE);
			DrawText("Failed to load level", 300, 200, 30, BLACK);
			DrawText("Hit enter to contiue or exit game", 200, 225, 30, BLACK);
			if (IsKeyDown(KEY_ENTER)) {
				scene = TITLE;
			}
			break;
		}

		EndDrawing();
	}

	CloseWindow();
}