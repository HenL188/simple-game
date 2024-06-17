#include "raylib.h"
#include "levels.h"
#include "ui.h"

void LevelTwo(int x, int y){
	DrawText("Do not touch the red", 70, 100, 50, BLACK);
	DrawRectangle(300, 325, 50, 50, GREEN);
	DrawRectangle(200, 150, 50, 50, RED);
	HealthLives(x, y);
}