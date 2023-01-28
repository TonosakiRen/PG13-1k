#include "Player.h"
#include "Key.h"
#include <Novice.h>
Player::Player(Vec2 pos, int radius, int speed) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->radius = radius;
	this->speed = speed;
	bulletRadius = 10;
}
void Player::Update() {
	if (Key::IsPressed(DIK_W)) {
		pos.y -= speed;
	}
	if (Key::IsPressed(DIK_A)) {
		pos.x -= speed;
	}
	if (Key::IsPressed(DIK_S)) {
		pos.y += speed;
	}
	if (Key::IsPressed(DIK_D)) {
		pos.x += speed;
	}
	for (int i = 0; i < BulletNum; i++) {
		if (Key::IsTrigger(DIK_SPACE)) {
			if (bullet[i].is == false) {
				bullet[i].pos = pos;
				bullet[i].is = true;
				break;
			}
		}
	}
	for (int i = 0; i < BulletNum; i++) {
		if (bullet[i].is == true) {
			bullet[i].pos.y -= 6;
		}
		if (bullet[i].pos.y <= -bulletRadius) {
 			bullet[i].is = false;
		}
	}
}
void Player::Draw() {
	for (int i = 0; i < BulletNum; i++) {
		if (bullet[i].is == true) {
			Novice::DrawEllipse(bullet[i].pos.x, bullet[i].pos.y, bulletRadius, bulletRadius, 0.0f, WHITE, kFillModeSolid);
		}
	}
	Novice::DrawEllipse(pos.x, pos.y, radius,radius, 0.0f, GREEN, kFillModeSolid);
}