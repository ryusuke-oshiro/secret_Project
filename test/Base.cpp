//#include "DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	XINPUT_STATE g_NowKey;
//	XINPUT_STATE g_OldKey;
//
//	int i;
//	int Color;
//
//	// �c�w���C�u�����̏�����
//	if (DxLib_Init() < 0) return -1;
//
//	// �`���𗠉�ʂɂ���
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	// ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
//	while (ProcessMessage() == 0)
//	{
//		// ��ʂ̃N���A
//		ClearDrawScreen();
//
//		// ���͏�Ԃ��擾
//		GetJoypadXInputState(DX_INPUT_PAD1, &g_NowKey);
//
//		g_OldKey = g_NowKey;
//
//		// ��ʂ� XINPUT_STATE �̒��g��`��
//		Color = GetColor(255, 255, 255);
//		DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
//			g_NowKey.LeftTrigger, g_NowKey.RightTrigger);
//		DrawFormatString(0, 16, Color, "ThumbLX:%d ThumbLY:%d",
//			g_NowKey.ThumbLX, g_NowKey.ThumbLY);
//		DrawFormatString(0, 32, Color, "ThumbRX:%d ThumbRY:%d",
//			g_NowKey.ThumbRX, g_NowKey.ThumbRY);
//		DrawString(0, 64, "Button", Color);
//		for (i = 0; i < 16; i++)
//		{
//			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
//				"%2d:%d", i, g_NowKey.Buttons[i]);
//		}
//
//		// ����ʂ̓��e��\��ʂɔ��f
//		ScreenFlip();
//	}
//
//	// �c�w���C�u�����̌�n��
//	DxLib_End();
//
//	// �\�t�g�̏I��
//	return 0;
//}