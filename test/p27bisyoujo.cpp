//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	
//	ChangeWindowMode(TRUE);
//	
//
//	if (DxLib_Init() == -1)		//DX���C�u��������������
//	{
//		return -1;				//�G���[���N�����璼���ɏI��
//	}
//
//	int BackImage;
//
//	int TitleImage;
//
//	int i;
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	BackImage = LoadGraph("images/back.bmp");
//	
//	TitleImage = LoadGraph("images/GameTitle.bmp");
//
//	for (i = 0; i < 255; i++) {
//		ClearDrawScreen();
//		
//		DrawGraph(0, 0, BackImage, FALSE);
//		
//		SetDrawBlendMode(DX_BLENDMODE_ALPHA, i);
//		
//		DrawGraph(120, 200, TitleImage, TRUE);
//		
//		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//		
//		ScreenFlip();
//	}
//	
//	WaitKey();		//�L�[���͑҂�
//	
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	
//	return 0;		//�\�t�g�̏I��
//}