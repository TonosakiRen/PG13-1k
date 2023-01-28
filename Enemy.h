#pragma once
#include "Vec2.h"
class Enemy
{
public:
	Vec2 pos;
	int speed;
	int radius;
public:
	static bool is;
	Enemy(Vec2 pos);
	void Update();
	void Draw();
};

