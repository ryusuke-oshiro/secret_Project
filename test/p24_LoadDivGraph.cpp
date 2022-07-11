//#include<DxLib.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1)  return 0;
//
//	int NumberImage[10];
//	int PosX = 600;
//	int PosY = 10;
//	int Score = 123400;
//	int TmpScore;
//
//	LoadDivGraph("images/number.bmp", 10, 10, 1, 20, 30, NumberImage);
//
//	TmpScore = Score;
//	do {
//		DrawGraph(PosX, PosY, NumberImage[TmpScore % 10], TRUE);
//		TmpScore /= 10;
//		PosX -= 16;
//	} while (TmpScore > 0);
//
//	WaitKey();
//	DxLib_End();
//	return 0;
//}