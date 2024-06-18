#include "raylib.h"
#include"ui.h"

void HealthLives(int x, int y) {
	DrawText(TextFormat("Health: %i", x), 35, 10, 30, BLACK);
	DrawText(TextFormat("Lives: %i", y), 650, 10, 30, BLACK);
}

void TaskBar() {
	Vector2 startPosH = { 550,397 };
	Vector2 endPosH = { 248, 397};
	Vector2 startPosV = { 250,448 };
	Vector2 endPosV = { 250, 395 };
	for (int i = 0; i < 2; i++) {
		DrawLineEx(startPosH,endPosH, 3.0f, BLACK);
		startPosH.y += 50;
		endPosH.y += 50;
	}
	for (int i = 0; i < 5; i++) {
		DrawLineEx(startPosV, endPosV, 3.0f, BLACK);
		startPosV.x += 75;
		endPosV.x += 75;
	}
	DrawCircle(285, 422, 20.0f, RED);
	DrawRectangleV((Vector2) { 345, 405 }, (Vector2) { 35, 35 }, RED);
}