//#include"DxLib.h"
//
//
//int x, y, i, j;
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//
//int g_GameState = 0;
//int g_TitleImage;
//
//int player_img[2];
//
////自機の構造体
//struct PLAYER {
//	int flg = FALSE;	//使用フラグ
//	int x = 320, y = 400;	//座標x,y
//	int angle = 1;	//自機アングル
//	int speed = 3;		//自機スピード
//	int hp = 3;		//体力
//
//};
////自機
//struct PLAYER g_player;
//
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HIGHT = 480;
//
//
//void DrawTitle(void);
//void GameMain(void);
//void PlayerControl(void);
//int LoadImages();
//
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("APPLEGAME");
//	if (DxLib_Init() == -1)	return -1;
//	if ((g_TitleImage = LoadGraph("images/BackGround.png")) == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする
//	
//
//	if (LoadImages() == -1)return -1;
//	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
//
//		//入力キー取得
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// 画面の初期化
//
//		switch (g_GameState) {
//		case 0:
//			DrawTitle();	//ゲームタイトル処理
//			break;
//		case 1:
//			GameMain();	//ゲームメイン
//			break;
//
//		}
//		ScreenFlip();			// 裏画面の内容を表画面に反映
//	}
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}
//
//void DrawTitle(void) {
//	// タイトル画像表示
//
//	DrawGraph(0, 0, g_TitleImage, TRUE);
//	if (KEY_INPUT_B & g_KeyFlg)g_GameState = 1;
//}
//
//void GameMain(void) {
//	PlayerControl();
//}
//
//void PlayerControl(void) {
//	DrawGraph(0, 0, g_TitleImage, TRUE);
//
//	if (g_player.flg = FALSE) {
//		DrawGraph(g_player.x, g_player.y, player_img[g_player.angle-1], FALSE);
//		g_player.flg = TRUE;
//	}
//
//
//	//画面をはみ出さないようにする
//	if (g_player.x > SCREEN_WIDTH - 35)g_player.x = SCREEN_WIDTH - 35;
//	if (g_player.x < 24)g_player.x = 24;
//	
//
//
//	//自機の向き
//	if (PAD_INPUT_RIGHT & g_KeyFlg) {
//		g_player.angle = 1;	//右
//	}
//	if (PAD_INPUT_LEFT & g_KeyFlg) {
//		g_player.angle = 2;	//左
//	}
//	DrawGraph(g_player.x, g_player.y, player_img[g_player.angle-1], FALSE);
//
//	//自機の移動処理
//
//	switch (g_player.angle) {
//	case 1:
//		g_player.x += g_player.speed*2;
//		break;
//	case 2:
//		g_player.x -= g_player.speed*2;
//		break;
//	default:
//			break;
//	}
//}
//
//
//int LoadImages(void)
//{
//	if ((player_img[0] = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
//	if ((player_img[1] = LoadGraph("images/PlayerA.png")) == -1)return -1;
//	return 0;
//}