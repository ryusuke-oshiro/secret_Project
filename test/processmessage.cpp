//#include"DxLib.h"
//int g_LoopCount = 0;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)		//DX���C�u��������������
//	{
//		return -1;				//�G���[���N�����璼���ɏI��
//	}
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ProcessMessage() == 0) {
//		ClearDrawScreen();
//		DrawFormatString(0, 0, GetColor(255, 255, 255), "LoopCount = %d", g_LoopCount++);
//		ScreenFlip();
//	}
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}