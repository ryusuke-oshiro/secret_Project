//#include"DxLib.h"
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//int g_MenuNumber = 0;
//int g_MenuY;
//int g_TitleImage;
//
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1){return -1;}
//	if ((g_TitleImage = LoadGraph("images/kadaiTitle.bmp")) == -1)return -1;
//	SetDrawScreen(DX_SCREEN_BACK);
//	while (ProcessMessage() == 0) {
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		if (g_KeyFlg & PAD_INPUT_DOWN) {
//			if (++g_MenuNumber > 2) g_MenuNumber = 0;
//		}
//		if (g_KeyFlg & PAD_INPUT_UP) {
//			if (--g_MenuNumber < 0) g_MenuNumber = 2;
//		}
//		ClearDrawScreen();
//		DrawGraph(0, 0, g_TitleImage, FALSE);
//
//		g_MenuY = g_MenuNumber * 52;
//		DrawCircle(460, 340 + g_MenuY, 10, GetColor(255, 0, 0), TRUE);
//		DrawCircle(460, 340 + g_MenuY, 10, GetColor(0, 0, 0), FALSE);
//		ScreenFlip();
//
//	}
//
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}