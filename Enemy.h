#pragma once
#include <Novice.h>
#include "Vector2.h"

class Enemy
{
public:

	typedef struct vector
	{
		float X;
		float Y;
	}vector;

	typedef struct object
	{
		vector position;
		vector velocity;
		float radius;
	}object;
 
	object enemy_;
	
public:
	

	void Initialize();

	void Update();
	
	
	void Draw();
	const int enemynum = 20;
	int enemyposX[20] = {0};
	int enemyposY[20] = { 0 };
	int enemyspeed[20] = { 0 };
	int enemyradius[20];
	int isenemyFlag[20] = {false};



	

};

