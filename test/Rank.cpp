//#include<stdio.h>
//#include "DxLib.h"
//#include"DrawGame.h"
//#include"Rank.h"
//#include"Block.h"
//
//
//RANK rank;
//RANK g_Ranking[10];
//RANK work;
//
//void RANK::DrawRanking()
//{
//	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (dg.g_KeyFlg & PAD_INPUT_M) dg.g_GameState = 0;
//
//	//�����L���O�摜�\��
//	DrawGraph(0, 0, dg.g_RankingImage, FALSE);
//
//	// �����L���O�ꗗ��\��
//	SetFontSize(30);
//	for (int i = 0; i < 10; i++) {
//		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
//			g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	// �����̕\��(�_��)
//	if (++dg.g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);
//	}
//	else if (dg.g_WaitTime > 60) {
//		dg.g_WaitTime = 0;
//	}
//
//}
//
//void RANK::InputRanking()
//{
//	//�����L���O�摜�\��
//	DrawGraph(0, 0, dg.g_RankingImage, FALSE);
//
//	// �t�H���g�T�C�Y�̐ݒ�
//	SetFontSize(20);
//
//	// ���O���͎w��������̕`��
//	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
//	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);
//
//	// ���O�̓���
//	DrawString(150, 310, "> ", 0xFFFFFF);
//	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
//	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9].name, FALSE) == 1) {
//		g_Ranking[9].score = block.g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
//		SortRanking();		// �����L���O���בւ�
//		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
//		dg.g_GameState = 2;		// �Q�[�����[�h�̕ύX
//	}
//
//}
//
//int  RANK::ReadRanking()
//{
//	FILE* fp;
//#pragma warning(disable:4996)
//
//	//�t�@�C���I�[�v��
//	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
//		//�G���[����
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
//	for (int i = 0; i < 10; i++) {
//		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
//	}
//
//	//�t�@�C���N���[�Y
//	fclose(fp);
//
//	return 0;
//}
//
//int  RANK::SaveRanking()
//{
//	FILE* fp;
//#pragma warning(disable:4996)
//
//	// �t�@�C���I�[�v��
//	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
//		/* �G���[���� */
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	// �����L���O�f�[�^���z��f�[�^����������
//	for (int i = 0; i < 10; i++) {
//		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	//�t�@�C���N���[�Y
//	fclose(fp);
//
//	return 0;
//
//}
//
//void RANK::SortRanking()
//{
//	int i, j;
//
//
//
//	// �I��@�\�[�g
//	for (i = 0; i < 9; i++) {
//		for (j = i + 1; j < 10; j++) {
//			if (g_Ranking[i].score <= g_Ranking[j].score) {
//				work = g_Ranking[i];
//				g_Ranking[i] = g_Ranking[j];
//				g_Ranking[j] = work;
//			}
//		}
//	}
//
//	// ���ʕt��
//	for (i = 0; i < 10; i++) {
//		g_Ranking[i].no = 1;
//	}
//	// ���_�������ꍇ�́A�������ʂƂ���
//	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
//	for (i = 0; i < 9; i++) {
//		for (j = i + 1; j < 10; j++) {
//			if (g_Ranking[i].score > g_Ranking[j].score) {
//				g_Ranking[j].no++;
//			}
//		}
//	}
//}