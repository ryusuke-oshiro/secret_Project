//#include<stdio.h>
//#include "DxLib.h"
//#include"DrawGame.h"
//#include"Block.h"
//
//DRAWGAME dg;
//
//DRAWGAME::DRAWGAME()
//{
//	g_GameState = 0;
//	g_MenuNumber = 0;
//	g_WaitTime = 0;			
//}
//
//void DRAWGAME::DrawGameOver()
//{
//	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
//
//	SetFontSize(48);
//	DrawString(200, 200, "Game Over", GetColor(255, 0, 0));
//
//	//�����̕\��(�_��)
//	if (++g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "-- Press[SPACE]Key --", GetColor(255, 0, 0));
//	}
//	else if (g_WaitTime > 60) {
//		g_WaitTime = 0;
//	}
//}
//
//void DRAWGAME::DrawGameClear()
//{
//	//�X�y�[�X�L�[��NEXT�X�e�[�W��
//	if (g_KeyFlg & PAD_INPUT_M) {
//		g_GameState = 4;
//		if (++block.g_Stage > 4)block.g_Stage = 0;
//		block.InitBlock();
//	}
//	SetFontSize(48);
//	DrawString(120, 200, "Congratulations", 0x7F00F0);
//	//�����̕\���i�_�Łj
//	if (++g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "-- Press[SPACE]Key --", 0xFF0000);
//	}
//	else if (g_WaitTime > 60) {
//		g_WaitTime = 0;
//	}
//}
//
//void DRAWGAME::DrawGameTitle()
//{
//	//���j���[�J�[�\���ړ�����
//	if (g_KeyFlg & PAD_INPUT_DOWN) {
//		if (++g_MenuNumber > 2) g_MenuNumber = 0;
//	}
//	if (g_KeyFlg & PAD_INPUT_UP) {
//		if (--g_MenuNumber < 0) g_MenuNumber = 2;
//	}
//
//	// �y�L�[�Ń��j���[�I��
//	if (g_KeyFlg & PAD_INPUT_A) g_GameState = g_MenuNumber + 1;
//
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//���j���[�J�[�\���i�O�p�`�j�̕\��
//	g_MenuY = g_MenuNumber * 52;
//	DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
//
//}
//
//void DRAWGAME::DrawEnd()
//{
//	//�G���h�摜�\��
//	DrawGraph(0, 0, g_EndImage, FALSE);
//
//	//�G���f�B���O�\��
//	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;
//
//	SetFontSize(24);
//	DrawString(100, 170 + g_PosY, "�^�C�g���@�@�@Game�@Title", 0xFFFFFF);
//	DrawString(100, 200 + g_PosY, "�o�[�W�����@�@1.0", 0xFFFFFF);
//	DrawString(100, 230 + g_PosY, "�ŏI�X�V���@�@201x�Nxx��xx��", 0xFFFFFF);
//	DrawString(100, 260 + g_PosY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
//	DrawString(100, 290 + g_PosY, "�@�@�@�@�@�@�@�w�w�w�@�w�w", 0xFFFFFF);
//	DrawString(100, 310 + g_PosY, "�f�ޗ��p", 0xFFFFFF);
//	DrawString(100, 340 + g_PosY, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
//	DrawString(100, 365 + g_PosY, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);
//
//	//�^�C���̉��Z�������I��
//	if (++g_WaitTime > 900) g_GameState = 99;
//}