#pragma once
#include "Vector2.h"
class Bullet
{
public:


	const int MAX = 20;

	Vector2 position;
	float speed;
	float radius;
	int isShot;

public:
	Vector2 Getcenter() { return position; }
	float GetspeedX() { return speed; }
	float Getradius() { return radius; }
	int GetIsShot() { return isShot; }

	void Setcenter(Vector2 pos) { this->position = pos; }
	void Setspeed(float speed) { this->speed = speed; }
	void Setradius(float radius) { this->radius = radius; }
	void SetIsShot(int isShot) { this->isShot = isShot; }

	Bullet();

	void Update();

	void Oncollision();

	void Draw();


};


