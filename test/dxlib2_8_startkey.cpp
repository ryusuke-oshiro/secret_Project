//#include"DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1)		//DXライブラリ初期化処理
//	{
//		return -1;				//エラーが起きたら直ちに終了
//	}
//
//	int PadInput;
//
//	DrawString(150, 200, "パッドのSTARTボタンを押してください", 0xFFFFFF);
//
//	PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	while ((PadInput & PAD_INPUT_START) == 0) {
//		if (ProcessMessage() == -1)	break;
//		PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	}
//
//	DxLib_End();	//DXライブラリ使用の終了処理
//	return 0;		//ソフトの終了
//}