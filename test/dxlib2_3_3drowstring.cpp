//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("基本の形：ウィンドウタイトルの設定");
//
//	if (DxLib_Init() == -1)		//DXライブラリ初期化処理
//	{ 
//		return -1;				//エラーが起きたら直ちに終了
//	}
//
//	int Cr = GetColor(255, 255, 255);				//白色の値を取得
//	SetFontSize(30);								//文字サイズを設定
//	DrawString(250, 200, "Hello C World!", Cr);		//文字列を描画
//
//	WaitKey();		//キー入力待ち
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}