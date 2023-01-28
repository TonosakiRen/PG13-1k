#pragma once
#include "Vec2.h"
const int BulletNum = 20;
class Player
{
public:
	Vec2 pos;
	int radius;
	int speed;
	struct Bullet {
		Vec2 pos;
		bool is = false;
	};
	Bullet bullet[BulletNum];
	int bulletRadius;
public:
	Player(Vec2 pos, int radius, int speed);
	void Update();
	void Draw();
};

