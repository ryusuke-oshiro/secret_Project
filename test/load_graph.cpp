//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("��{�̌`�F�E�B���h�E�^�C�g���̐ݒ�");
//
//	if (DxLib_Init() == -1)		return -1;				//�G���[���N�����璼���ɏI��
//	
//	int GHandle;
//	GHandle = LoadGraph("images/block.bmp");
//
//	DrawGraph(0, 0, GHandle, TRUE);
//
//    WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}