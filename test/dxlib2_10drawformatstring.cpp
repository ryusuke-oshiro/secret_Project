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
//	int mx = 500, my = 0;
//	int Score = 123400;
//	//�����̕`��
//	DrawFormatString(mx, my, 0xFFFFFF, "Score:%d", Score);
//
//	WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}