#include "player.h"

void Movement(float speed, Vector2* p) {

	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
		p->x += speed;
	}
	else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
		p->x -= speed;
	}
	else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
		//gavity.y = 2;
		p->y -= speed + 1;
	}
	else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
		p->y += speed;
	}
	else {
		//gavity.y = 100;
		;
	}
}

void Bounds(Vector2* p, float radius) {
	if (p->y > GetScreenHeight() - radius) {
		p->y = (float)GetScreenHeight() - radius;
	}
	else if (p->y < radius) {
		p->y = radius;
	}
	else if (p->x > GetScreenWidth() - radius) {
		p->x = (float)GetScreenWidth() - radius;
	}
	else if (p->x < radius) {
		p->x = radius;
	}
	else { ; }
}
