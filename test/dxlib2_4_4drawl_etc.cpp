//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);/*ウィンドウサイズ設定*/
//	ChangeWindowMode(true);/*ウィンドウモード設定*/
//	if (DxLib_Init() == -1) return -1;/*DXライブラリ初期化*/
//    
//	int Cr = GetColor(0, 255, 0);
//	DrawLine(50, 250, 350, 250, Cr);
//	
//	Cr = GetColor(255, 0, 0);
//	DrawBox(100, 300, 300, 400, Cr, 1);
//	
//	Cr = GetColor(0, 0, 255);
//	DrawCircle(500, 300, 100, Cr, 0, 10);
//	
//	Cr = GetColor(255, 255, 0);
//	DrawPixel(320, 240, Cr);
//	
//	Cr = GetColor(255, 0, 0);
//	DrawOval(100, 100, 50, 10, Cr, FALSE);
//
//	Cr = GetColor(100, 50, 200);
//	DrawTriangle(200, 100, 100, 200, 300, 200, Cr, FALSE);
//	
//	WaitKey();
//	DxLib_End();
//	return 0;
//}