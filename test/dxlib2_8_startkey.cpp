//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1)		//DX���C�u��������������
//	{
//		return -1;				//�G���[���N�����璼���ɏI��
//	}
//
//	int PadInput;
//
//	DrawString(150, 200, "�p�b�h��START�{�^���������Ă�������", 0xFFFFFF);
//
//	PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	while ((PadInput & PAD_INPUT_START) == 0) {
//		if (ProcessMessage() == -1)	break;
//		PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	}
//
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}