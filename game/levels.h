#pragma once
#include "raylib.h"
#include "game.h"

void LevelOne(void);
void LevelTwo(int x, int y);
Level LevelThree(int health, int lives, float radius, bool pickUpHealth, Level scene, Vector2 position);