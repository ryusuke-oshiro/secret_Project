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
//	int mx = 500, my = 0;
//	int Score = 123400;
//	//文字の描画
//	DrawFormatString(mx, my, 0xFFFFFF, "Score:%d", Score);
//
//	WaitKey();		//キー入力待ち
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}