//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);/*ウィンドウサイズ設定*/
//	ChangeWindowMode(true);/*ウィンドウモード設定*/
//	if(DxLib_Init() == -1) return -1;/*DXライブラリ初期化*/
//
//	DrawPixel(320, 240, 0xffffff);
//	WaitKey();
//	DxLib_End();
//	return 0;
//}