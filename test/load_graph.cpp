//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("基本の形：ウィンドウタイトルの設定");
//
//	if (DxLib_Init() == -1)		return -1;				//エラーが起きたら直ちに終了
//	
//	int GHandle;
//	GHandle = LoadGraph("images/block.bmp");
//
//	DrawGraph(0, 0, GHandle, TRUE);
//
//    WaitKey();		//キー入力待ち
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}