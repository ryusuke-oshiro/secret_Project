//#include<DxLib.h>
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmbLine, int nCmbShow)
//
//{
//	SetGraphMode(640, 480, 16);
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1) return -1;
//
//	int BallX, BallY;
//	int GrBall;
//	int PadInput;
//	int x, y;
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	GrBall = LoadGraph("images/test2.bmp");
//
//	BallX = 320;
//	BallY = 240;
//	x = 4, y = 4;
//	PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	while ((PadInput & PAD_INPUT_START) == 0)
//	{
//		if (BallX < 0 ||BallX > 640 - 20)
//		{
//			x = -x;
//		}
//
//		if (BallY < 0 ||BallY > 480 - 20)
//		{
//			y = -y;
//		}
//		BallX += x;
//		BallY += y;
//
//		ClearDrawScreen();
//
//		DrawGraph(BallX, BallY, GrBall, TRUE);
//
//		ScreenFlip();
//
//		PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//
//		
//
//	}
//	DxLib_End();
//
//	return 0;
//
//}
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
//	int Cr = GetColor(0, 0, 255);
//	DrawCircle(320, 240, 200, Cr,TRUE);		//�x�[�X
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 240, 200, Cr,FALSE);		//�x�[�X�̍��g
//	
//	Cr = GetColor(255, 255, 255);
//	DrawCircle(320, 280, 160, Cr,TRUE);		//���x�[�X
//    
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 280, 160, Cr, FALSE);		//���x�[�X�̍��g
//
//	Cr = GetColor(255, 0, 0);
//	DrawCircle(320, 240, 40, Cr,TRUE);				//�@
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(320, 240, 40, Cr,FALSE);		//�@�̍��g
//
//	Cr = GetColor(255, 255, 255);
//	DrawOval(270,150, 40, 60, Cr, TRUE);		//�E��
//
//	Cr = GetColor(0, 0, 0);
//	DrawOval(270, 150, 40, 60, Cr, FALSE);		//�E�ڂ̍��g
//
//	Cr = GetColor(255, 255, 255);
//	DrawOval(370, 150, 40, 60, Cr, TRUE);		//����
//
//	Cr = GetColor(0, 0, 0);
//	DrawOval(370, 150, 40, 60, Cr, FALSE);		//���ڂ̍��g
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(270, 150, 3, Cr, TRUE);			//�E�̍���
//
//	Cr = GetColor(0, 0, 0);
//	DrawCircle(370, 150, 3, Cr, TRUE);			//���̍���
//
//	Cr = GetColor(0, 0, 0);
//	DrawLine(320, 280, 320, 320, Cr);			//�@��
//
//	Cr = GetColor(255, 0, 0);
//	DrawTriangle(320, 400, 180, 320, 460, 320, Cr, TRUE);	//��
//
//	Cr = GetColor(0, 0, 0);
//	DrawLine(250, 250, 150, 230, Cr);			//�E�ǂ�
//	DrawLine(250, 270, 150, 270, Cr);
//	DrawLine(250, 290, 150, 310, Cr);
//    
//	DrawLine(390, 250, 490, 230, Cr);
//	DrawLine(390, 270, 490, 270, Cr);
//	DrawLine(390, 290, 490, 310, Cr);
//
//
//	WaitKey();		//�L�[���͑҂�
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}