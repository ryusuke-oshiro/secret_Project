//#include<DxLib.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmbLine, int nCmbShow)
//
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1) return -1;
//
//	int BallX, BallY;
//	int GrBall;
//	int PadInput;
//	int x, y;
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	GrBall = LoadGraph("images/test2.bmp");
//
//	BallX = 320;
//	BallY = 240;
//	x = 4, y = 4;
//	PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	while ((PadInput & PAD_INPUT_START) == 0)
//	{
//		if (BallX < 0 ||BallX > 640 - 20)
//		{
//			x = -x;
//		}
//
//		if (BallY < 0 ||BallY > 480 - 20)
//		{
//			y = -y;
//		}
//		BallX += x;
//		BallY += y;
//
//		ClearDrawScreen();
//
//		DrawGraph(BallX, BallY, GrBall, TRUE);
//
//		ScreenFlip();
//
//		PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//
//		
//
//	}
//	DxLib_End();
//
//	return 0;
//
//}
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
//	int Cr = GetColor(0, 0, 255);
//	DrawCircle(320, 240, 200, Cr,TRUE);		//青ベース
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 240, 200, Cr,FALSE);		//青ベースの黒枠
//	
//	Cr = GetColor(255, 255, 255);
//	DrawCircle(320, 280, 160, Cr,TRUE);		//白ベース
//    
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 280, 160, Cr, FALSE);		//白ベースの黒枠
//
//	Cr = GetColor(255, 0, 0);
//	DrawCircle(320, 240, 40, Cr,TRUE);				//鼻
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 240, 40, Cr,FALSE);		//鼻の黒枠
//
//	Cr = GetColor(255, 255, 255);
//	DrawOval(270,150, 40, 60, Cr, TRUE);		//右目
//
//	Cr = GetColor(0, 0, 0);
//	DrawOval(270, 150, 40, 60, Cr, FALSE);		//右目の黒枠
//
//	Cr = GetColor(255, 255, 255);
//	DrawOval(370, 150, 40, 60, Cr, TRUE);		//左目
//
//	Cr = GetColor(0, 0, 0);
//	DrawOval(370, 150, 40, 60, Cr, FALSE);		//左目の黒枠
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(270, 150, 3, Cr, TRUE);			//右の黒目
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(370, 150, 3, Cr, TRUE);			//左の黒目
//
//	Cr = GetColor(0, 0, 0);
//	DrawLine(320, 280, 320, 320, Cr);			//鼻下
//
//	Cr = GetColor(255, 0, 0);
//	DrawTriangle(320, 400, 180, 320, 460, 320, Cr, TRUE);	//口
//
//	Cr = GetColor(0, 0, 0);
//	DrawLine(250, 250, 150, 230, Cr);			//髭ども
//	DrawLine(250, 270, 150, 270, Cr);
//	DrawLine(250, 290, 150, 310, Cr);
//    
//	DrawLine(390, 250, 490, 230, Cr);
//	DrawLine(390, 270, 490, 270, Cr);
//	DrawLine(390, 290, 490, 310, Cr);
//
//
//	WaitKey();		//キー入力待ち
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}