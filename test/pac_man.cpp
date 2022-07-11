//#include"DxLib.h"
//
//#define MAP_WIDTH 21
//#define MAP_HIGHT 27
//
//int x, y, i, j;
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//
//int g_WaitTime;
//
//int PCcnt = 0;
//
//int PlayerWay;
//
//int g_GameState = 0;
//int g_TitleImage;
//int g_EndImage;
//int GHandle[10];
//
//int powercookie;
//int pacman_img[4];
//
//
//int control_flg;
//
////自機の構造体
//struct PLAYER {
//	int flg = FALSE;	//使用フラグ
//	int x = 200, y = 250;	//座標x,y
//	int angle = 3;	//自機アングル
//	int speed = 3;		//自機スピード
//	int hp = 3;		//体力
//
//};
////自機
//struct PLAYER g_player;
//
//unsigned int MAP_DATA[MAP_HIGHT][MAP_WIDTH] = {
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//		{1,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,1},
//		{1,2,4,4,4,2,4,4,4,2,4,2,4,4,4,2,4,4,4,2,1},
//		{1,2,4,3,4,2,4,3,4,2,4,2,4,3,4,2,4,3,4,2,1},
//		{1,2,4,4,4,2,4,4,4,2,4,2,4,4,4,2,4,4,4,2,1},
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
//		{1,2,1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,2,1},
//		{1,2,1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,2,1},
//		{1,2,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,2,1},
//		{1,1,1,1,1,2,1,1,1,3,1,3,1,1,1,2,1,1,1,1,1},
//		{3,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3,3},
//		{3,3,3,3,1,2,1,3,1,1,1,1,1,3,1,2,1,3,3,3,3},
//		{1,1,1,1,1,2,1,3,1,3,3,3,1,3,1,2,1,1,1,1,1},
//		{3,3,3,3,3,2,3,3,1,3,3,3,1,3,3,2,3,3,3,3,3},
//		{1,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1,1},
//		{3,3,3,3,1,2,1,3,3,3,3,3,3,3,1,2,1,3,3,3,3},
//		{3,3,3,3,1,2,1,3,1,1,1,1,1,3,1,2,1,3,3,3,3},
//		{1,1,1,1,1,2,1,3,1,1,1,1,1,3,1,2,1,1,1,1,1},
//		{1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1},
//		{1,2,1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,2,1},
//		{1,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,1},
//		{1,1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1,1},
//		{1,1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1,1},
//		{1,2,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,2,1},
//		{1,2,1,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,1,2,1},
//		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//
//const int SCREEN_WIDTH = 420;
//const int SCREEN_HIGHT = 540;
//
//
//void DrawBlock(void);
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
//	SetMainWindowText("PAC-MAN");
//	if (DxLib_Init() == -1)	return -1;
//	if ((g_TitleImage = LoadGraph("images/GameTitle.jpg")) == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする
//	if (LoadDivGraph("images/block.bmp", 10, 10, 1, 24, 24, GHandle) == -1)return -1;
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
//	if (KEY_INPUT_A & g_KeyFlg)g_GameState = 1;
//
//}
//
//void GameMain(void) {
//	/*PlayerControl();*/
//	DrawBlock();
//	PlayerControl();
//}



//void PlayerControl(void) {
//	if (g_player.flg = FALSE) {
//		DrawGraph(g_player.x, g_player.y, pacman_img[g_player.angle], FALSE);
//		g_player.flg = TRUE;
//	}
//
//
//	//画面をはみ出さないようにする
//	if (g_player.x > SCREEN_WIDTH - 35)g_player.x = SCREEN_WIDTH - 35;
//	if (g_player.x < 24)g_player.x = 24;
//	if (g_player.y > SCREEN_HIGHT - 35)g_player.y = SCREEN_HIGHT - 35;
//	if (g_player.y < 24)g_player.y = 24;
//
//
//	//自機の向き
//	if (PAD_INPUT_UP & g_KeyFlg) {
//		g_player.angle = 0;	//上
//	}
//	if (PAD_INPUT_DOWN & g_KeyFlg) {
//		g_player.angle = 1;	//下
//	}
//	if (PAD_INPUT_RIGHT & g_KeyFlg) {
//		g_player.angle = 2;	//右
//	}
//	if (PAD_INPUT_LEFT & g_KeyFlg) {
//		g_player.angle = 3;	//左
//	}
//	DrawGraph(g_player.x, g_player.y, pacman_img[g_player.angle], FALSE);
//
//	//自機の移動処理
//
//	switch (g_player.angle) {
//	case 0:
//		g_player.y -= g_player.speed*2;
//		break;
//	case 1:
//		g_player.y += g_player.speed*2;
//		break;
//	case 2:
//		g_player.x += g_player.speed*2;
//		break;
//	case 3:
//		g_player.x -= g_player.speed*2;
//		break;
//	default:
//			break;
//	}
//
//
//
//
//}
//
//
//void DrawBlock(void) {
//
//	for (i = 0; i < 27; i++) {
//		for (j = 0; j < 21; j++) {
//
//			switch (MAP_DATA[i][j]) {
//			case 1:
//				DrawGraph(20 * j, 20 * i, GHandle[5], TRUE);
//				break;
//			case 2:
//				DrawExtendGraph(20 * j + 5, 20 * i + 5, 20 * j + 20, 20 * i + 20, powercookie, TRUE);
//				PCcnt += 1;
//				break;
//			case 4:
//				DrawGraph(20 * j, 20 * i, GHandle[1], TRUE);
//				break;
//			default:
//				break;
//			}
//		}
//
//	}
//}
//int LoadImages(void)
//{
//	if ((pacman_img[0] = LoadGraph("images/PAC-MAN-0.jpg")) == -1)return -1;
//	if ((pacman_img[1] = LoadGraph("images/PAC-MAN-1.jpg")) == -1)return -1;
//	if ((pacman_img[2] = LoadGraph("images/PAC-MAN-2.jpg")) == -1)return -1;
//	if ((pacman_img[3] = LoadGraph("images/PAC-MAN-3.jpg")) == -1)return -1;
//	if ((powercookie = LoadGraph("images/powercookiepacman.png")) == -1)return -1;;
//	if (LoadDivGraph("images/block.bmp", 10, 10, 1, 24, 24, GHandle) == -1)return -1;
//	return 0;
//}