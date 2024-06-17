#include "raylib.h"
#include"ui.h"

void HealthLives(int x, int y) {
	DrawText(TextFormat("Health: %i", x), 35, 10, 30, BLACK);
	DrawText(TextFormat("Lives: %i", y), 650, 10, 30, BLACK);
}