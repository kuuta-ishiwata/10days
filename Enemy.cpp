#include "Enemy.h"
#include <stdio.h>



void Enemy::Initialize()
{
	for (int i = 0; i < 20; i++)
	{
		enemyposX[i] = 100;
		enemyposY[i] = 220;
		enemyradius[i] = 32;

	}

}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	//for (int i = 0; i < 20; i++)
	//{
	//	if (isenemyFlag[i] == false)
	//	{
	//		Novice::DrawBox(enemyposX[i], enemyposY[i], enemyradius[i], enemyradius[i], 0.0f, BLUE, kFillModeSolid);
	//	}
	//}

}

