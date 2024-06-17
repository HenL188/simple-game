#include "raylib.h"
#include "ui.h"
#include "levels.h"

typedef enum Level { TITLE, ONE, TWO, GAMEOVER} Level;
typedef enum Shape {CIRCLE, SQUARE, REC, TRI} Shape;
int main() {
	InitWindow(800, 450, "Window");
	SetTargetFPS(60);
	
	Vector2 position = { 100, 100 };
	Vector2 boxPosition = { 400, 225 };
	const float radius = 25.0f;
	Color color = RED;
	float speed = 2.0f;
	//Vector2 gavity = { 0,100 };
	int health = 100;
	bool collison = false;
	bool redCollison = false;
	Level scene = TWO;
	Shape shape = CIRCLE;
	int lives = 3;
	while (!WindowShouldClose()) {
		if (scene == ONE) {
			collison = CheckCollisionCircleRec(position, radius, (Rectangle){400,225,50,50});
		}
		else if (scene == TWO) {
			collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 50, 50 });
			redCollison = CheckCollisionCircleRec(position, radius, (Rectangle) { 200, 150, 50, 50 });
		}

		if (IsKeyPressed(KEY_ENTER) && scene == TITLE ) {
			scene = ONE;
		}

		if (IsKeyPressed(KEY_ONE)) {
			shape = SQUARE;
		}
		
		Vector2* p;
		p = &position;
		if (IsKeyDown(KEY_RIGHT)) {
			p->x += speed;
			color = BLUE;
		}
		else if (IsKeyDown(KEY_LEFT)) {
			p->x -= speed;
			color = GREEN;
		}
		else if (IsKeyDown(KEY_UP)) {
			//gavity.y = 2;
			p->y -= speed + 1;
			color = YELLOW;
		}
		else if (IsKeyDown(KEY_DOWN)) {
			p->y += speed;
			color = ORANGE;
		}
		else {
			//gavity.y = 100;
			position = position;
			color = RED;
		}

		if (p->y > GetScreenHeight() - 25) {
			p->y = GetScreenHeight() - 25;
		}
		else if (p->y < 25) {
			p->y = 25;
		}
		else if (p->x > GetScreenWidth() - 25) {
			p->x = GetScreenWidth() - 25;
		}
		else if (p->x < 25) {
			p->x = 25;
		}
		else { position = position; }

		//position.y += gavity.y * GetFrameTime();
		switch (scene)
		{
		case ONE:
			if (collison) {
				scene = TWO;
			}
			break;
		case TWO:
			if (collison) {
				color = BLACK;
			}
			if (redCollison) {
				health -= 10 * GetFrameTime();
				if (health == 0) {
					position = (Vector2){ 100,100 };
					health = 100;
					lives -= 1;
					if (lives == 0) {
						scene = GAMEOVER;
					}
				}
			}
			break;
		default:
			scene = scene;
			break;
		}

		switch (scene) {
		case TITLE:
			ClearBackground(RAYWHITE);
			DrawText("Hit enter to play", 70, 100, 50, BLACK);
			break;
		case ONE:
			ClearBackground(RAYWHITE);
			DrawText("Tounch the green square", 70, 100, 50, BLACK);
			if (shape == CIRCLE) {
				DrawCircleV(position, radius, color);
			}
			else if (shape == SQUARE) {
				DrawRectangleV(position, (Vector2) { 50, 50 }, color);
			}
			DrawRectangleV(boxPosition, (Vector2) { 50, 50 }, GREEN);
			break;
		case TWO:
			ClearBackground(RAYWHITE);
			DrawCircleV(position, radius, color);
			LevelTwo(health,lives);
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
			DrawText("Failed to load scene", 400, 225, 100, BLACK);
			break;
		}
		
		EndDrawing();
	}

	CloseWindow();
}

