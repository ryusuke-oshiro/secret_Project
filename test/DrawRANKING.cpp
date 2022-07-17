#include"Common.h"
#include"DrawRANKING.h"
#include"RANKING.h"

DrawRANKING drawranking;

DrawRANKING::DrawRANKING() {
	RankingImage = 0;
}

void DrawRANKING::DrawRanking(){
	// B�L�[�Ń��j���[�ɖ߂�
	if (input.Buttons[XINPUT_BUTTON_B]) {
		g_GameState = 0;
	}

//�����L���O�摜�\��
	DrawGraph(0, 0, RankingImage, FALSE);

// �����L���O�ꗗ��\��
	SetFontSize(30);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%1d   %10s     %10d",
			ranking.getNomber(i), ranking.getName(i), ranking.getScore(i));
	}

// �����̕\��(�_��)
	if (++g_WaitTime < 30) {
		SetFontSize(24);
		DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);
	}
	else if (g_WaitTime > 60) {
		g_WaitTime = 0;
	}
}