#include "raylib.h"
#include "levels.h"
#include "ui.h"
#include "player.h"


void LevelOne(void) {
	ClearBackground(RAYWHITE);
	DrawText("Tounch the green square", 70, 100, 50, BLACK);
	DrawRectangleV((Vector2) { 400, 225 }, (Vector2) { 50, 50 }, GREEN);
}

void LevelTwo(int x, int y) {
	ClearBackground(RAYWHITE);
	DrawText("Do not touch the red", 70, 100, 50, BLACK);
	DrawRectangle(300, 325, 50, 50, GREEN);
	DrawRectangle(200, 150, 50, 50, RED);
	HealthLives(x, y);
}

void LevelThree(int health, int lives, bool pickUpHealth) {
	Rectangle box = { 300,325,20,20 };
	ClearBackground(RAYWHITE);
	DrawText("Blue iteams add health", 70, 100, 45, BLACK);
	for (int i = 0; i < 4; i++) {
		DrawRectangleRec(box, RED);
		box.x += 20;
	}
	HealthLives(health, lives);
	if (pickUpHealth == false) DrawRectangle(400, 225, 10, 10, BLUE);
	else { ; }
	
}