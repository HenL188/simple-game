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

void Bounds(Vector2* p, float radis) {
	if (p->y > GetScreenHeight() - radis) {
		p->y = (float)GetScreenHeight() - radis;
	}
	else if (p->y < radis) {
		p->y = radis;
	}
	else if (p->x > GetScreenWidth() - radis) {
		p->x = (float)GetScreenWidth() - radis;
	}
	else if (p->x < radis) {
		p->x = radis;
	}
	else { p = p; }
}