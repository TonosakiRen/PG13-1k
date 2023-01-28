#include "Enemy.h"
#include "Novice.h"
bool Enemy::is = 1;
Enemy::Enemy(Vec2 pos) {
	this->pos = pos;
	speed = 4;
	radius = 20;
}
void Enemy::Update() {
	if (is == true) {
		if (pos.x + radius <= 0 || pos.x - radius >= 1280) {
			speed = speed * -1;
		}
		pos.x += speed;
	}
}
void Enemy::Draw() {
	if (is == true) {
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.0f, RED, kFillModeSolid);
	}
}