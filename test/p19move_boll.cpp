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
