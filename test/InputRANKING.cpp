#include"DxLib.h"
#include"Common.h"
#include"RANKING.h"
#include"DrawRANKING.h"
#include"InputRANKING.h"

InputRANKING inputranking;
InputRANKING Alfabet[3][10];

InputRANKING::InputRANKING() {
	flg = FALSE;
	moji = 0;
	ascii = 97;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			Alfabet[i][j].moji = ascii++;
		}
	}
}

void InputRANKING::InputRanking()
{
	//�����L���O�摜�\��
	DrawGraph(0, 0, drawranking.RankingImage, FALSE);

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);

	// ���O���͎w��������̕`��
	DrawString(150, 140, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawString(150, 170, "���O���p���œ��͂��Ă�������", 0xFFFFFF);
	// ���O�̓���
	DrawString(150, 210, "> ", 0xFFFFFF);
	DrawBox(160, 205, 300, 235, 0x000055, TRUE);

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10; j++) {
			DrawFormatString(160 + j * 25, 300 + i * 20, 0xFFFFFF, "%c", Alfabet[i-1][j-1].moji);
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//�u�����h���[�h����(128/255)�ɐݒ�
	DrawBox(185, 320, 190, 330, GetColor(0, 250, 154), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (KeyInputSingleCharString(170, 210, 10, ranking.getName(4), FALSE) == 1) {
		ranking.setScore(g_Score);	// �����L���O�f�[�^��5�ԖڂɃX�R�A��o�^
		ranking.SortRanking();		// �����L���O���בւ�
		ranking.SaveRanking();		// �����L���O�f�[�^�̕ۑ�
		g_GameState = 2;		// �Q�[�����[�h�̕ύX
	}
}