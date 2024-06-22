#include "raylib.h"
#include "ui.h"
#include "levels.h"
#include "player.h"
#include "game.h"

typedef struct sceneStart { bool one; bool two; bool three; bool four; bool five; bool six; bool seven; bool eight; bool nine; bool ten; } sceneStart;
int main() {
	InitWindow(800, 450, "Window");
	SetTargetFPS(60);

	Vector2 position = { 0, 225 };
	Vector2 spawn = { 0, 225 };
	sceneStart start = {true ,true, true, true, true, true, true, true, true, true};
	float radius = 25.0f;
	Color color = BLACK;
	const float speed = 2.0f;
	//Vector2 gavity = { 0,100 };
	int health = 100;
	Level scene = ONE;
	int lives = 3;
	bool pickUpHealth = false;
	int healthUp = 0;

	while (!WindowShouldClose()) {

		Movement(speed, &position);
		Bounds(&position, radius);


		if (IsKeyPressed(KEY_ENTER) && scene == TITLE) {
			scene = ONE;
		}
		else { ; }

		if (IsKeyPressed(KEY_ONE)) {
			radius = 25.0f;
		}
		else if (IsKeyPressed(KEY_TWO)) {
			radius = 20.0f;
		}
		else if (IsKeyPressed(KEY_THREE)) {
			radius = 15.0f;
		}
		else if (IsKeyPressed(KEY_FOUR)) {
			radius = 10.0f;
		}
		else {
			radius = radius;
		}

		if (IsKeyPressed(KEY_ENTER) && scene == GAMEOVER) {
			scene = TITLE;
			lives = 3;
		}
		else { ; }

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
			
			
		default:
			;
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
			LevelThree(health, lives,radius, pickUpHealth);
			break;
		case FOUR:
			ClearBackground(RAYWHITE);
			HealthLives(health,lives);
			TaskBar();
			break;
		case GAMEOVER:
			ClearBackground(RAYWHITE);
			DrawText("GAMEOVER", 70, 100, 50, BLACK);
			if (IsKeyPressed(KEY_ENTER)) {
				scene = TITLE;
			}
			break;
		default:
			ClearBackground(RAYWHITE);
			DrawText("Failed to load scene", 400, 225, 5, BLACK);
			break;
		}

		EndDrawing();
	}

	CloseWindow();
}