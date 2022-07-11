//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	
//	ChangeWindowMode(TRUE);
//	
//
//	if (DxLib_Init() == -1)		//DXライブラリ初期化処理
//	{
//		return -1;				//エラーが起きたら直ちに終了
//	}
//
//	int BackImage;
//
//	int TitleImage;
//
//	int i;
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	BackImage = LoadGraph("images/back.bmp");
//	
//	TitleImage = LoadGraph("images/GameTitle.bmp");
//
//	for (i = 0; i < 255; i++) {
//		ClearDrawScreen();
//		
//		DrawGraph(0, 0, BackImage, FALSE);
//		
//		SetDrawBlendMode(DX_BLENDMODE_ALPHA, i);
//		
//		DrawGraph(120, 200, TitleImage, TRUE);
//		
//		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//		
//		ScreenFlip();
//	}
//	
//	WaitKey();		//キー入力待ち
//	
//	DxLib_End();	//DXライブラリ使用の終了処理
//	
//	return 0;		//ソフトの終了
//}