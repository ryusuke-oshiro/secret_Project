//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)		return -1;				//�G���[���N�����璼���ɏI��
//
//	int GHandle = LoadGraph("images/test1.bmp");
//
//	DrawGraph(0, 0, GHandle, TRUE);
//
//	DrawTurnGraph(100, 0, GHandle, FALSE);
//
//	DrawExtendGraph(100, 0, 420, 320, GHandle, TRUE);
//
//	DrawExtendGraph(100, 0, 150, 50, GHandle, TRUE);
//
//	DrawRotaGraph(320, 240, 1.5f, 3.14f / 2, GHandle, TRUE);
//
//
//	
//
//	WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}