//#include<DxLib.h>
//
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//int g_EndImage;
//int g_WaitTime = 0;
//int g_PosY;
//
//void DrawEnd(void);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmbLine, int nCmbShow)
//{
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)return -1;
//
//	if ((g_EndImage = LoadGraph("images/kadaiEnd.bmp")) == -1)return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ProcessMessage() == 0 && g_WaitTime < 900) {
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();
//		DrawEnd();
//		ScreenFlip();
//	}
//	DxLib_End();
//	return 0;
//}
//
//void DrawEnd(void)
//{
//	DrawGraph(0, 0, g_EndImage, FALSE);
//	SetFontSize(20);
//	if (++g_WaitTime < 600)g_PosY = 300 - g_WaitTime / 2;
//	DrawString(110,170+g_PosY,"�^�C�g��		�Z�Z�ZGame",0x000000);
//	DrawString(110,200+g_PosY,"�o�[�W����	2.0", 0x000000);
//	DrawString(110,230+g_PosY,"�ŏI�X�V��	2018�N07��01��", 0x000000);
//	DrawString(110,260+g_PosY,"�����		���ۓd�q�r�W�l�X���w�Z", 0x000000);
//	DrawString(110,290+g_PosY,"				��闳��", 0x000000);
//	DrawString(110,310+g_PosY,"�f�ޗ��p", 0x000000);
//	DrawString(110,340+g_PosY,"�@BGM		������", 0x000000);
//	DrawString(110,365+g_PosY,"�@SE			�����뉀", 0x000000);
//
//}