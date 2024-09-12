#include "Enemy.h"
#include <stdio.h>



void Enemy::Initialize()
{
	
	enemy_[1] =
	{
		{100,200},
		{3,0},
		32
	};
	enemy_[2] =
	{
		{100,300},
		{3,0},
		32
	};

	enemy_[3] =
	{
		{100,400},
		{4,0},
		32
	};

	enemy_[4] =
	{
		{100,500},
		{2.5,0},
		32
	};

	enemy_[5] =
	{
		{100,700},
		{3.5,0},
		32
	};


}

void Enemy::Update()
{
	
	enemy_[1].position.X += enemy_[1].velocity.X;
	
	if (enemy_[1].position.X >= 500)
	{
		 enemy_[1].velocity.X *= -1;
	}
	if (enemy_[1].position.X <= 100)
	{

		enemy_[1].velocity.X *= -1;
	}
	//�G2
	enemy_[2].position.X += enemy_[2].velocity.X;

	if (enemy_[2].position.X >= 500)
	{
		enemy_[2].velocity.X *= -1;
	}
	if (enemy_[2].position.X <= 100)
	{

		enemy_[2].velocity.X *= -1;
	}
	//�G3
	enemy_[3].position.X += enemy_[3].velocity.X;

	if (enemy_[3].position.X >= 500)
	{
		enemy_[3].velocity.X *= -1;
	}
	if (enemy_[3].position.X <= 100)
	{

		enemy_[3].velocity.X *= -1;
	}
	//�G4
	enemy_[4].position.X += enemy_[4].velocity.X;

	if (enemy_[4].position.X >= 500)
	{
		enemy_[4].velocity.X *= -1;
	}
	if (enemy_[4].position.X <= 100)
	{

		enemy_[4].velocity.X *= -1;
	}
	//�G5
	enemy_[5].position.X += enemy_[5].velocity.X;

	if (enemy_[5].position.X >= 500)
	{
		enemy_[5].velocity.X *= -1;
	}
	if (enemy_[5].position.X <= 100)
	{

		enemy_[5].velocity.X *= -1;
	}
}

void Enemy::Draw(int x)
{
	
	if (isenemyFlag== false)
	{
		Novice::DrawBox(enemy_[1].position.X, enemy_[1].position.Y, enemy_[1].radius, enemy_[1].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag2 == false)
	{
		Novice::DrawBox(enemy_[2].position.X, enemy_[2].position.Y, enemy_[2].radius, enemy_[2].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag3 == false)
	{
		Novice::DrawBox(enemy_[3].position.X, enemy_[3].position.Y, enemy_[3].radius, enemy_[3].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag4 == false)
	{
		Novice::DrawBox(enemy_[4].position.X, enemy_[4].position.Y, enemy_[4].radius, enemy_[4].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag5 == false)
	{
		Novice::DrawBox(enemy_[5].position.X, enemy_[5].position.Y, enemy_[5].radius, enemy_[5].radius, 0.0f, BLUE, kFillModeSolid);
	}

}

