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
//	int BackImage;
//	int MsgBoxImage;
//
//	BackImage = LoadGraph("images/back.bmp");		//�w�i�摜�̓ǂݍ���
//	MsgBoxImage = LoadGraph("images/msgbox.bmp");	//���b�Z�[�W�{�b�N�X�摜�̓ǂݍ���
//
//	//�w�i�摜��`�悷��
//	DrawGraph(0, 0, BackImage, FALSE);
//
//	//�A���t�@�u�����h�̐ݒ������
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
//
//	//������摜��\������
//	DrawGraph(80, 360, MsgBoxImage, TRUE);
//
//	//�A���t�@�u�����h�̐ݒ����������
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//
//	DrawString(100, 380, "�Q�[���v���O�����͊y�����I�I", 0x000000);
//    
//	WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}