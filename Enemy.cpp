#include "Enemy.h"
#include <stdio.h>



void Enemy::Initialize()
{
	
	enemy_ =
	{
		{100,200},
		{3,0},
		32
	};
	

}

void Enemy::Update()
{
	
	enemy_.position.X += enemy_.velocity.X;
	
	if (enemy_.position.X >= 500)
	{
		 enemy_.velocity.X *= -1;
	}
	if (enemy_.position.X <= 100)
	{

		enemy_.velocity.X *= -1;
	}


}

void Enemy::Draw(int x)
{
	
	if (isenemyFlag== false)
	{
		Novice::DrawBox(enemy_.position.X, enemy_.position.Y, enemy_.radius, enemy_.radius, 0.0f, BLUE, kFillModeSolid);
	}
	

}

