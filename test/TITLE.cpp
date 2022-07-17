#include"DxLib.h"
#include"TITLE.h"
#include"Common.h"
#define _USE_MATH_DEFINES
#include<math.h>

TITLE title;

TITLE::TITLE() {
	x = 0;
	x_flg = TRUE;
	g_TitleImage = 0;
	g_TitleBGM = 0;
}

void TITLE::DrawGameTitle(void)
{
	static int MenuNo = 0;

	if (x_flg == TRUE) {
		++x;
	}
	else {
		--x;
	}
	if (x >= 10) {
		for (int j = 0; j <= 10; j++) {
			x = 10;
		}
		x_flg = FALSE;
	}
	if (x <= -10) {
		for (int k = 0; k <= 10; k++) {
			x = -10;
		}
		x_flg = TRUE;
	}


	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK, FALSE);

	//���j���[�J�[�\���ړ�����
	if (input.ThumbLY <= -15000) {
		if (g_KeyFLG == TRUE) {
			PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
			++MenuNo;
			if (MenuNo > 3) {
				MenuNo = 0;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}
	if (input.ThumbLY >= 15000) {
		if (g_KeyFLG == TRUE) {
			PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
			--MenuNo;
			if (MenuNo < 0) {
				MenuNo = 3;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLY > -15000 && input.ThumbLY < 15000) {
		g_KeyFLG = TRUE; g_WaitCount = 0;
	}

	//A�L�[�Ń��j���[�I��
	if (input.Buttons[12] == 1) {
		StopSoundMem(g_TitleBGM);
		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
		g_KeyFLG = FALSE;
		g_GameState = MenuNo + 1;
	}
	//�^�C�g���摜�\��
	DrawGraph(0, 0, g_TitleImage, FALSE);

	//���j���[�J�[�\��
	DrawRotaGraph(150 + x, 240 + MenuNo * 50, 0.7f, M_PI / 2, g_Cone, TRUE);

}