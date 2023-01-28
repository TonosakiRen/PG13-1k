#include <Novice.h>
#include "Key.h"
#include "Player.h"
#include "Enemy.h"
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Player* player = new Player({ 1280 / 2.0f, 720 / 2.0f + 300 }, 30, 3);
	Enemy* enemy = new Enemy({ 1280 / 2.0f, 720 / 2.0f });
	Enemy* enemy1 = new Enemy({ 1280 / 2.0f + 300, 720 / 2.0f - 100 });

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Key::Input();

		///
		/// ↓更新処理ここから
		///
		player->Update();
		enemy->Update();
		enemy1->Update();
		for (int i = 0; i < BulletNum; i++) {
			if (player->bullet[i].is == true) {
				if ((player->bullet[i].pos - enemy->pos).Length() <= player->bulletRadius + enemy->radius) {
					Enemy::is = false;
				}
				if ((player->bullet[i].pos - enemy1->pos).Length() <= player->bulletRadius + enemy1->radius) {
					Enemy::is = false;
				}
			}
		}
		
		if (Key::IsTrigger(DIK_R)) {
			Enemy::is = true;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemy->Draw();
		enemy1->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Key::IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}
	delete player;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
