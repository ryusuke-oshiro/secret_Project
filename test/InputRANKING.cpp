#include"DxLib.h"
#include"Common.h"
#include"RANKING.h"
#include"DrawRANKING.h"
#include"InputRANKING.h"
#include<string.h>

InputRANKING inputranking;
char Alfabet[5][14] = { "ABCDEFGHIJKLM","NOPQRSTUVWXYZ","abcdefghijklm","nopqrstuvwxyz","0123456789?*@" };
char Name[11];

InputRANKING::InputRANKING() {
	count = 1;
	moji = 0;
	cursor_X = 0;
	cursor_Y = 0;
	
}

void InputRANKING::InputRanking()
{
	//�����L���O�摜�\��
	DrawGraph(0, 0, drawranking.RankingImage, FALSE);


	DrawFormatString(300, 100, 0x000000, "%d", input.Buttons[XINPUT_BUTTON_A]);

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X < 10 || cursor_Y != 4) {	//A�{�^���������Ƃ��̃J�[�\���ʒu
		if (ButtonFLG == TRUE) {													//�ɂ���A���t�@�x�b�g�̃A�X�L�[�R�[�h�������L���O�ɓ����
			if (count > 9) {
				count = 9;
			}
			Name[count-1] = Alfabet[cursor_Y][cursor_X];
			count++;
			ButtonFLG = FALSE;
		}
	}

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 10 && cursor_Y == 4) {	//�P�����폜�������Ƃ�
		if (ButtonFLG == TRUE && count>0) {
			if (count < 0) {
				count=0;
			}
			strncpy_s(Name, 11,Name, count);
			count--;
			ButtonFLG = FALSE;
		}
	}

	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		ButtonFLG = TRUE;
	}


	SetFontSize(40);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 13; j++) {
			DrawFormatString(70 + j * 35, 225 + i * 40, 0xFFFFFF, "%c", Alfabet[i - 1][j - 1]);
		}
	}

	if (input.ThumbLX > 17500) {	//�E����
		if (g_KeyFLG == TRUE) {
			++cursor_X;
			if (cursor_X > 12) {
				cursor_X = 0;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLX < -17500) {		//������
		if (g_KeyFLG == TRUE) {
			--cursor_X;
			if (cursor_X < 0) {
				cursor_X = 12;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLY > 17500) {		//�����
		if (g_KeyFLG == TRUE) {
			--cursor_Y;
			if (cursor_Y < 0) {
				cursor_Y = 4;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLY < -17500) {
		if (g_KeyFLG == TRUE) {
			++cursor_Y;
			if (cursor_Y > 4) {
				cursor_Y = 0;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}
	
	if (input.ThumbLY > -17500 && input.ThumbLY < 17500 && input.ThumbLX > -17500 && input.ThumbLX < 17500) {
		g_KeyFLG = TRUE; g_WaitCount = 0;
	}


	//�J�[�\���`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//�u�����h���[�h����(128/255)�ɐݒ�
	DrawBox(100 + cursor_X * 35, 265 + cursor_Y * 40, 130 + cursor_X * 35, 305 + cursor_Y * 40, GetColor(0, 250, 154), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);



	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);
	// ���O���͎w��������̕`��
	DrawString(150, 140, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawString(150, 170, "���O���p���œ��͂��Ă�������", 0xFFFFFF);
	// ���O�̓���
	DrawString(150, 210, "> ", 0xFFFFFF);
	DrawBox(160, 205, 300, 235, 0x000055, TRUE);

	
	
	DrawFormatString(150 + 0 * 20, 200, 0xFFFFFF, "%c", Name[0]);		//�����͂��Ă��镶��
	DrawFormatString(150 + 1 * 20, 200, 0xFFFFFF, "%c", Name[1]);
	DrawFormatString(150 + 2 * 20, 200, 0xFFFFFF, "%c", Name[2]);
	DrawFormatString(150 + 3 * 20, 200, 0xFFFFFF, "%c", Name[3]);
	DrawFormatString(150 + 4 * 20, 200, 0xFFFFFF, "%c", Name[4]);
	DrawFormatString(150 + 5 * 20, 200, 0xFFFFFF, "%c", Name[5]);
	DrawFormatString(150 + 6 * 20, 200, 0xFFFFFF, "%c", Name[6]);
	DrawFormatString(150 + 7 * 20, 200, 0xFFFFFF, "%c", Name[7]);
	DrawFormatString(150 + 8 * 20, 200, 0xFFFFFF, "%c", Name[8]);
	DrawFormatString(150 + 9 * 20, 200, 0xFFFFFF, "%c", Name[9]);

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 12 && cursor_Y == 4) {	//���艟�����Ƃ�
		strcpy_s(ranking.getName(4),11,Name);
		ranking.setScore(g_Score);	// �����L���O�f�[�^��5�ԖڂɃX�R�A��o�^
		ranking.SortRanking();		// �����L���O���בւ�
		ranking.SaveRanking();		// �����L���O�f�[�^�̕ۑ�
		g_GameState = 2;			// �Q�[�����[�h�̕ύX
	}

	//if (KeyInputSingleCharString(170, 210, 10, ranking.getName(4), FALSE) == 1) {
	//	ranking.setScore(g_Score);	// �����L���O�f�[�^��5�ԖڂɃX�R�A��o�^
	//	ranking.SortRanking();		// �����L���O���בւ�
	//	ranking.SaveRanking();		// �����L���O�f�[�^�̕ۑ�
	//	g_GameState = 2;		// �Q�[�����[�h�̕ύX
	//}
}