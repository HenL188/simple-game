#include "raylib.h"
#include "ui.h"
#include "levels.h"
#include "player.h"
#include "game.h"

typedef struct sceneStart { bool one; bool two; bool three; bool four; bool five; bool six; bool seven; bool eight; bool nine; bool ten; } sceneStart;
int main() {
	InitWindow(800, 450, "Window");
	SetTargetFPS(60);

	Vector2 position = { 100, 100 };
	sceneStart start = {true ,true, true, true, true, true, true, true, true, true};
	float radius = 25.0f;
	Color color = BLACK;
	const float speed = 2.0f;
	//Vector2 gavity = { 0,100 };
	int health = 100;
	bool collison = false;
	bool redCollison = false;
	Level scene = TWO;
	int lives = 3;
	bool pickUpHealth = false;
	int healthUp = 0;
	bool collisonHealth = false;

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

		if (lives == 0) {
			scene = GAMEOVER;
		}
		else {
			;
		}

		if (IsKeyPressed(KEY_ENTER) && scene == GAMEOVER) {
			scene = TITLE;
			lives = 3;
		}
		else { ; }

		//position.y += gavity.y * GetFrameTime();
		switch (scene)
		{
		case ONE:
			collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 400, 225, 50, 50 });
			if (collison) {
				scene = TWO;
			}
			else{ ; }
			break;
		case TWO:
			collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 50, 50 });
			redCollison = CheckCollisionCircleRec(position, radius, (Rectangle) { 200, 150, 50, 50 });
			if (scene == TWO && start.two == true) {
				position = (Vector2){ 100,100 };
				start.two = false;
			}
			else { ; }
			if (collison) {
				scene = THREE;
			}
			else { ; }
			if (redCollison) {
				health -= 10.0f * GetFrameTime();
				if (health == 0) {
					position = (Vector2){ 100,100 };
					health = 100;
					lives -= 1;
				}
				else { ; }
			}
			else { ; }
			break;
		case THREE:
			collisonHealth = CheckCollisionCircleRec(position, radius, (Rectangle) { 400, 225, 10, 10 });
			redCollison = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 80, 20 });
			if (collisonHealth) {
				pickUpHealth = true;
			}
			else { ; }
			

			if (redCollison) {
				health -= 10.0f * GetFrameTime();
				if (health == 0) {
					position = (Vector2){ 100,100 };
					health = 100;
					lives -= 1;
				}
				else { ; }
			}
			else { ; }
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
			scene = LevelThree(health, lives,radius, pickUpHealth ,scene,position);
			if (pickUpHealth == true && health < 100) {
				if (healthUp == 0) {
					health += 10;
					healthUp = 1;
				}

			}
			else { ; }
			break;
		case FOUR:
			ClearBackground(RAYWHITE);
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