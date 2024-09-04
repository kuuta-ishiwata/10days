#pragma once
#include "Vector2.h"
#include <Novice.h>
class Player
{

public:

	void Initialize();

	void Update(char* keys);

	void Draw();


private:

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

	object player;
	//重力
	float gravity = 1.0f;
	//ジャンプのフラグ
	bool jampFlag = false;
};

