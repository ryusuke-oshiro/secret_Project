//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("��{�̌`�F�E�B���h�E�^�C�g���̐ݒ�");
//
//	if (DxLib_Init() == -1)		//DX���C�u��������������
//	{ 
//		return -1;				//�G���[���N�����璼���ɏI��
//	}
//
//	int Cr = GetColor(255, 255, 255);				//���F�̒l���擾
//	SetFontSize(30);								//�����T�C�Y��ݒ�
//	DrawString(250, 200, "Hello C World!", Cr);		//�������`��
//
//	WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}