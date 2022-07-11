//#include<DxLib.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1)  return -1;
//
//	int NumberImage[10];
//	int i;
//	LoadDivGraph("images/number.bmp", 10, 10, 1, 20, 30, NumberImage);
//
//	for (i = 0; i < 10; i++) {
//		DrawGraph(i * 30, 10, NumberImage[i], FALSE);
//	}
//
//	WaitKey();
//
//	DxLib_End();
//
//	return 0;
//
//}