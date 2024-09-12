﻿#include "Player.h"

#include <stdio.h>


Player::~Player()
{

}

void Player::Initialize()
{
	//プレイヤー
	player =
	{
		{64,64},
		{0,0},
		16
	};

	//弾諸々の初期化(スピード、半径)
	for (int i = 0; i < 20; i++)
	{
		bulletspeed[i] = 15;
		bulletradius[i] = 16;
	}
	enemy.Initialize();
}

void Player::Update(char* keys, char* prekeys)
{
	enemy.Update();
#pragma region プレイヤーの動き
	//右に動く
	if (keys[DIK_A])
	{
		player.velocity.X = -5;
	}
	if (keys[DIK_A] == 0 && prekeys[DIK_A])
	{
		player.velocity.X = 0;
	}

	//左に動く
	if (keys[DIK_D])
	{
		player.velocity.X = 5;
	}

	if (keys[DIK_D] == 0 && prekeys[DIK_D])
	{
		player.velocity.X = 0;
	}

	//重力
	player.velocity.Y += gravity;

	//弾発射(複数弾)
	if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == 0)
	{
		//連打してる時は落下しない
		player.velocity.Y -= 10.0f;

		  
		for (int i = 0; i < 20; i++)
		{
			if (isbulletFlag[i] == false)
			{
				bulletposX[i] = player.position.X;
				bulletposY[i] = player.position.Y;

				isbulletFlag[i] = true;

				break;
			}
		}
	}

	//弾のフラグとカウントを0にする
	for (int i = 0; i < bulletnum; i++)
	{
		//弾発射(動かす)
		if (isbulletFlag[i] == true)
		{
			bulletposY[i] -= bulletspeed[i];

			bulletAliveCount[i] += 1;

			if (enemy.enemy_.position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_.position.X + enemy.enemy_.radius &&
				enemy.enemy_.position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_.position.Y + enemy.enemy_.radius)

			{
				enemy.isenemyFlag = true;
				Novice::ScreenPrintf(50, 300, "atari");

			}
		}

		//カウントを進めて400になると順次弾を消してリセット
		if (bulletAliveCount[i] >= 300 && isbulletFlag[i] == true)
		{
			bulletAliveCount[i] = 0;
			isbulletFlag[i] = false;
		}
	}
	
	

	//弾と敵との判定
	
	

	//timer
	timer++;

	Novice::ScreenPrintf(50, 350, "%d", timer);

	if (timer == 1800)
	{
		gameoverflag = true;
	}
	if (timer == 600)
	{
		timerflag = true;
		timerflag2 = true;
	}
	if (timer == 1200)
	{
		timerflag2 = false;
		timerflag3 = true;
	}

#pragma endregion

#pragma region マップチップ判定(プレイヤー)
	//4頂点の座標
	float top = player.position.Y - player.radius;
	float down = player.position.Y + player.radius - 1;
	float right = player.position.X + player.radius - 1;
	float left = player.position.X - player.radius;

	//左右の判定
	if (map[(int)(top / 32)][(int)((left + player.velocity.X) / 32)] != 0 ||
		map[(int)(top / 32)][(int)((right + player.velocity.X) / 32)] != 0 ||
		map[(int)(down / 32)][(int)((left + player.velocity.X) / 32)] != 0 ||
		map[(int)(down / 32)][(int)((right + player.velocity.X) / 32)] != 0)
	{
		if (player.velocity.X > 0)
		{
			while (map[(int)(top / 32)][(int)((left + 1) / 32)] == 0 &&
				map[(int)(top / 32)][(int)((right + 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((left + 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((right + 1) / 32)] == 0)
			{
				player.position.Y += 1;
				left += 1;
				right += 1;
			}
		}

		if (player.velocity.X < 0)
		{
			while (map[(int)(top / 32)][(int)((left - 1) / 32)] == 0 &&
				map[(int)(top / 32)][(int)((right - 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((left - 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((right - 1) / 32)] == 0)
			{
				player.position.X -= 1;
				left -= 1;
				right -= 1;
			}
		}

		player.velocity.X = 0;

	}

	//上下の判定
	top = player.position.Y - player.radius;
	down = player.position.Y + player.radius - 1;
	right = player.position.X + player.radius - 1;
	left = player.position.X - player.radius;

	//ブロッが0以外の時に判定を取る
	//ブロックが0以外の時に判定を取る
	if (map[(int)((top + player.velocity.Y) / 32)][(int)((left) / 32)] != 0 ||
		map[(int)((top + player.velocity.Y) / 32)][(int)((right) / 32)] != 0 ||
		map[(int)((down + player.velocity.Y) / 32)][(int)((left) / 32)] != 0 ||
		map[(int)((down + player.velocity.Y) / 32)][(int)((right) / 32)] != 0)
	{

		if (player.velocity.Y > 0)
		{
			while (map[(int)((top + 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((top + 1) / 32)][(int)((right) / 32)] == 0 &&
				map[(int)((down + 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((down + 1) / 32)][(int)((right) / 32)] == 0)
			{
				player.position.Y += 1;
				top += 1;
				down += 1;
			}

		}


		//1回しかジャンプしない↓
		if (map[(int)((down + 1) / 32)][(int)((left) / 32)] == 1 ||
			map[(int)((down + 1) / 32)][(int)((right) / 32)] == 1)
		{
			//jampFlag = false;//貯めジャンプ
			//wallflag = false;//壁キック
		}
		//1回しかジャンプしない↑


		if (player.velocity.Y < 0)
		{
			while (map[(int)((top - 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((top - 1) / 32)][(int)((right) / 32)] == 0 &&
				map[(int)((down - 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((down - 1) / 32)][(int)((right) / 32)] == 0)
			{
				player.position.Y -= 1;
				top -= 1;
				down -= 1;
			}
		}

		player.velocity.Y = 0;

	}

	player.position.X += player.velocity.X;
	player.position.Y += player.velocity.Y;
	
#pragma endregion
	
}

void Player::Draw()
{

	enemy.Draw(enemy.x);

	if (timerflag == false)
	{
		Novice::DrawSprite(300, 30, timerirasuto3, 1, 1, 0.0f,WHITE);
	}
	if (timerflag2 == true)
	{
		Novice::DrawSprite(1300, 30, timerirasuto2, 1, 1, 0.0f,WHITE);

	}
	if (timerflag3 == true)
	{
		Novice::DrawSprite(300, 30, timerirasuto, 1, 1, 0.0f, WHITE);

	}

	//弾の描画
	for (int i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true)
		{
			Novice::DrawBox(bulletposX[i] - 3, bulletposY[i], bulletradius[i], bulletradius[i], 0.0f, RED, kFillModeSolid);
		}
	}

	//弾の座標など
	for (int i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true)
		{
			Novice::ScreenPrintf(10, i * 20, "bullet%d: x:%d,     y:%d,    isShot:%d", i, bulletposX[i], bulletposY[i], isbulletFlag[i]);
		}

		if (isbulletFlag[i] == true)
		{
			Novice::ScreenPrintf(500, i * 20, "Count %d", bulletAliveCount[i]);
			//Novice::ScreenPrintf(500, i * 20, "Count %d", ak);
		}
	}

	//自分
	Novice::DrawSprite(player.position.X - player.radius/*- scrolX*/, player.position.Y - player.radius, irasuto, 1, 1, 0.0f, WHITE);

	//ブロック描画
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			if (map[y][x] == BLOCK)//普通のブロック
			{
				Novice::DrawSprite(x * BLOCKsize/*- scrolX*/, y * BLOCKsize, BLOCKirasuto, 1, 1, 0.0f, WHITE);
			}
		}
	}
}


