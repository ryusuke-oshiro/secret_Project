//#include"DxLib.h"
//int g_LoopCount = 0;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)		//DXライブラリ初期化処理
//	{
//		return -1;				//エラーが起きたら直ちに終了
//	}
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ProcessMessage() == 0) {
//		ClearDrawScreen();
//		DrawFormatString(0, 0, GetColor(255, 255, 255), "LoopCount = %d", g_LoopCount++);
//		ScreenFlip();
//	}
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}