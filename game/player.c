#include "player.h"

void Movement(float speed, Vector2* p) {

	if (IsKeyDown(KEY_RIGHT)) {
		p->x += speed;
	}
	else if (IsKeyDown(KEY_LEFT)) {
		p->x -= speed;
	}
	else if (IsKeyDown(KEY_UP)) {
		//gavity.y = 2;
		p->y -= speed + 1;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		p->y += speed;
	}
	else {
		//gavity.y = 100;
		p = p;
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
	else { p = p; }
}

