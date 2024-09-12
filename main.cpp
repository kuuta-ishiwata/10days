#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
const char kWindowTitle[] = "LE2C_02_イシワタクウタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 800);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player;
	player = new Player();

	player->Initialize();

	Enemy* enemy;
	enemy = new Enemy();
	enemy->Initialize();

	int scene = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys, preKeys);
		enemy->Update();
		//switch (scene)
		//{
		//case 0:
		//	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		//	{
		//		scene = 1;
		//	}
		//	break;
		//
		//case 1:
		//	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		//	{
		//		scene = 2;
		//		
		//	}
		//	break;
		//case 2:
		//	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		//	{
		//		scene = 3;
		//
		//	}
		//	break;
		//case 3:
		//	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		//	{
		//		scene = 0;
		//
		//	}
		//	break;
		//}

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		player->Draw();

		enemy->Draw();
		//if (scene == 1)
		//{
		//	Novice::DrawBox(0, 0, 800, 800, 0.0f, RED, kFillModeSolid);
		//}
		//else if (scene == 2)
		//{
		//	
		//}
		//else if (scene == 3)
		//{
		//	Novice::DrawBox(0, 0, 800, 800, 0.0f, BLUE, kFillModeSolid);
		//}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
