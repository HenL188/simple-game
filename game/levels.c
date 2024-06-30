#include "raylib.h"
#include "levels.h"
#include "ui.h"
#include "player.h"


void LevelOne(void) {
	ClearBackground(RAYWHITE);
	DrawText("Tounch the green square", 70, 100, 50, BLACK);
	DrawRectangleV((Vector2) { 400, 225 }, (Vector2) { 50, 50 }, GREEN);
}

void LevelTwo(int health, int lives) {
	ClearBackground(RAYWHITE);
	DrawText("Do not touch the red", 70, 100, 50, BLACK);
	DrawRectangle(300, 325, 50, 50, GREEN);
	DrawRectangle(200, 150, 50, 50, RED);
	HealthLives(health, lives);
}

void LevelThree(int health, int lives, bool pickUpHealth) {
	Rectangle box = { 300,325,20,20 };
	ClearBackground(RAYWHITE);
	DrawText("Blue iteams add health", 70, 100, 45, BLACK);
	for (int i = 0; i < 4; i++) {
		DrawRectangleRec(box, RED);
		box.x += 20;
	}
	box.x = 300;
	box.y = 245;
	for (int j = 0; j < 4; j++) {
		DrawRectangleRec(box, RED);
		box.x += 20;
	}
	box.x = 375;
	box.y = 255;
	for (int j = 0; j < 4; j++) {
		DrawRectangleRec(box, RED);
		box.y += 20;
	}

	DrawRectangle(355, 285, 20, 20, GREEN);
	
	HealthLives(health, lives);
	if (pickUpHealth == false) DrawRectangle(400, 225, 10, 10, BLUE);
	else { ; }
}

void LevelFour(int health, int lives, bool pickUpLife, Color color)
{
	Rectangle box = { 320,150,30,30 };
	Rectangle box2 = { 320,420,30,30 };
	ClearBackground(RAYWHITE);
	DrawText("Purple iteams add lives", 70, 100, 45, BLACK);
	HealthLives(health, lives);
	if (pickUpLife == false) DrawRectangle(390, 185, 10, 10, PURPLE);
	else { ; }
	DrawRectangle(375,183,40,40,color);
	DrawRectangle(375, 377, 40, 40, GREEN);
	for (int i = 0; i < 5; i++) {
		DrawRectangleRec(box, RED);
		box.x += 30;
	}
	box.x = 320;
	box.y = 180;
	for (int j = 0; j < 2; j++) {
		DrawRectangleRec(box, RED);
		box.y += 30;
	}
	box.x = 440;
	box.y = 180;
	for (int k = 0; k < 2; k++) {
		DrawRectangleRec(box, RED);
		box.y += 30;
	}
	for (int i = 0; i < 5; i++) {
		DrawRectangleRec(box2, RED);
		box2.x += 30;
	}
	box2.x = 320;
	box2.y = 390;
	for (int j = 0; j < 2; j++) {
		DrawRectangleRec(box2, RED);
		box2.y -= 30;
	}
	box2.x = 440;
	box2.y = 390;
	for (int k = 0; k < 2; k++) {
		DrawRectangleRec(box2, RED);
		box2.y -= 30;
	}
}

void LevelFive(int health, int lives)
{
	Rectangle box = { 200,160,50,50 };
	ClearBackground(RAYWHITE);
	DrawText("Use keys one to four to change size", 70, 100, 35, BLACK);
	DrawRectangle(418, 223, 7.5, 7.5, GREEN);
	HealthLives(health, lives);
	TaskBar();
	for (int i = 0; i < 4; i++) {
		DrawRectangleRec(box, RED);
		box.x += 70;
		box.height -= 10;
		box.width -= 10;
		box.y += 10;
	}
	box = (Rectangle){ 200,270,50,50 };
	for (int i = 0; i < 4; i++) {
		DrawRectangleRec(box, RED);
		box.x += 70;
		box.height -= 10;
		box.width -= 10;
		box.y -= 10;
	}
}

void LevelSix(int health, int lives, bool pickUpHealth) 
{
	ClearBackground(RAYWHITE);
	TaskBar();
	HealthLives(health, lives);
	if (pickUpHealth == false) DrawRectangle(500, 150, 10, 10, BLUE);
	else { ; }
	DrawRectangle(600, 225, 50, 50, GREEN);
}

void LevelSeven(int health, int lives, bool pickUpLife)
{
	ClearBackground(RAYWHITE);
	TaskBar();
	HealthLives(health, lives);
	if (pickUpLife == false) DrawRectangle(460, 245, 10, 10, PURPLE);
	else { ; }
	DrawRectangle(400, 225, 50, 50, GREEN);
	DrawCircle(520,245, 35, RED);
	DrawCircle(425,160, 35, RED);
	DrawCircle();
}

void LevelEight(int health, int lives)
{
}
