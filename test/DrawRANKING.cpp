#include"Common.h"
#include"DrawRANKING.h"
#include"RANKING.h"

DrawRANKING drawranking;

DrawRANKING::DrawRANKING() {
	RankingImage = 0;
}

void DrawRANKING::DrawRanking(){
	// Bキーでメニューに戻る
	if (input.Buttons[XINPUT_BUTTON_B]) {
		PlaySoundMem(g_SE3, DX_PLAYTYPE_BACK, TRUE);
		g_GameState = 0;
	}

//ランキング画像表示
	DrawGraph(0, 0, RankingImage, FALSE);

// ランキング一覧を表示
	SetFontSize(30);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%1d                  %10d",
			ranking.getNomber(i), ranking.getScore(i));
	}
	for (int i = 0; i < RANKING_DATA; i++) {
		for (int j = 0; j < 10; j++) {
			DrawFormatString(145+j*15, 170 + i * 25, 0xFFFFFF, "%c", ranking.getName2(i, j));
		}
	}
	SetFontSize(16);
	DrawCircle(210, 463, 10, GetColor(0, 0, 0), TRUE);
	DrawString(207, 456, "B", GetColor(255, 255, 255));
//// 文字の表示(点滅)
//	if (++g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "--  Bを押してタイトルへ  --", 0xFFFFFF);
//	}
//	else if (g_WaitTime > 60) {
//		g_WaitTime = 0;
//	}
}