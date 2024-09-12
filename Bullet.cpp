#include "Bullet.h"
#include<Novice.h>

Bullet::Bullet() {
	this->speed = 16.0f;
	this->radius = 16.0f;
	this->isShot = false;
}


void Bullet::Update() {
	if (isShot)
	{
		position.y -= speed;
	}
	if (position.y <= 0)
	{
		isShot = false;
	}
}
void Bullet::Oncollision()
{
	if (isShot)
	{
		isShot = false;
	}

}

void Bullet::Draw() {
	if (isShot)
	{
		Novice::DrawEllipse(position.x, position.y, radius, radius, 0.0f, WHITE, kFillModeSolid);
	}
}