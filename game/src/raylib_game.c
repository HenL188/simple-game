#include "raylib.h"
#include "ui.h"
#include "levels.h"
#include "player.h"

typedef enum Level { TITLE, ONE, TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN, GAMEOVER} Level;

int main() {
	InitWindow(800, 450, "Window");
	SetTargetFPS(60);
	
	Vector2 position = { 100, 100 };
	Vector2 boxPosition = { 400, 225 };
	float radius = 25.0f;
	Color color = BLACK;
	const float speed = 2.0f;
	//Vector2 gavity = { 0,100 };
	int health = 100;
	bool collison = false;
	bool redCollison = false;
	Level scene = ONE;
	int lives = 3;
	bool x = false;

	while (!WindowShouldClose()) {
		if (scene == ONE) {
			collison = CheckCollisionCircleRec(position, radius, (Rectangle){400,225,50,50});
		}
		else if (scene == TWO) {
			collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 300, 325, 50, 50 });
			redCollison = CheckCollisionCircleRec(position, radius, (Rectangle) { 200, 150, 50, 50 });
		}
		else if (scene == THREE) {
			collison = CheckCollisionCircleRec(position, radius, (Rectangle) { 400, 225, 10, 10 });
		}

		if (IsKeyPressed(KEY_ENTER) && scene == TITLE ) {
			scene = ONE;
		}
		
		Movement(speed, &position);
		Bounds(&position, radius);
		
		if (lives == 0) {
			scene = GAMEOVER;
		}else{
			scene = scene;
		}

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
				scene = THREE;
			}
			if (redCollison) {
				position.x += -10;
				health -= 10.0f;
				if (health == 0) {
					position = (Vector2){ 100,100 };
					health = 100;
					lives -= 1;
				} 
			}
			break;
		case THREE:
			if (collison) {
				x = true;
			}
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
			DrawCircleV(position, radius, color);
			DrawText("Tounch the green square", 70, 100, 50, BLACK);
			DrawRectangleV(boxPosition, (Vector2) { 50, 50 }, GREEN);
			break;
		case TWO:
			LevelTwo(health,lives);
			DrawCircleV(position, radius, color);
			break;
		case THREE:
			ClearBackground(RAYWHITE);
			DrawCircleV(position, radius, color);
			Vector2 pos = { 100,100 };
			for (int i = 0; i < 4; i++) {
				DrawRectangleV(pos, (Vector2) { 50, 50 }, RED);
				pos.x += 100;
			}
			if (x == false) DrawRectangle(400, 225, 10, 10, BLUE);
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

