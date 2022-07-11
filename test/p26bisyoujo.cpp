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
//	int BackImage;
//	int MsgBoxImage;
//
//	BackImage = LoadGraph("images/back.bmp");		//背景画像の読み込み
//	MsgBoxImage = LoadGraph("images/msgbox.bmp");	//メッセージボックス画像の読み込み
//
//	//背景画像を描画する
//	DrawGraph(0, 0, BackImage, FALSE);
//
//	//アルファブレンドの設定をする
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
//
//	//透ける画像を表示する
//	DrawGraph(80, 360, MsgBoxImage, TRUE);
//
//	//アルファブレンドの設定を解除する
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//
//	DrawString(100, 380, "ゲームプログラムは楽しい！！", 0x000000);
//    
//	WaitKey();		//キー入力待ち
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}