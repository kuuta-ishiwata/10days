#include "Player.h"

void Player::Initialize()
{
	player = { {50,50},{0,0},16 };


}

void Player::Update(char* keys)
{
	if (keys[DIK_A])
	{
		player.velocity.X = -5;
	}
	if (keys[DIK_D])
	{
		player.velocity.X = +5;
	}



}

void Player::Draw()
{
	Novice::DrawBox(player.position.X, player.position.Y, player.radius, player.radius, 0.0f, RED, kFillModeSolid);

}
