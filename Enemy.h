#pragma once
#include <Novice.h>
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
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
	int x = 0;
public:
	

	void Initialize();

	void Update();
	
	
	void Draw(int x);
	int isenemyFlag = false;



	

};

