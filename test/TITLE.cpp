#include"DxLib.h"
#include"TITLE.h"
#include"Common.h"
#define _USE_MATH_DEFINES
#include<math.h>

TITLE title;

TITLE::TITLE() {
	x = 0;
	g_CursorImage = 0;
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

	//メニューカーソル移動処理
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

	//Aキーでメニュー選択
	if (input.Buttons[12] == 1) {
		StopSoundMem(g_TitleBGM);
		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
		g_KeyFLG = FALSE;
		g_GameState = MenuNo + 1;
	}
	//タイトル画像表示
	DrawGraph(0, 0, g_TitleImage, FALSE);

	//メニューカーソル
	DrawRotaGraph(150 + x, 240 + MenuNo * 50, 0.7f, M_PI / 2, g_CursorImage, TRUE);
	SetFontSize(16);

	DrawOval(165, 459, 9, 5, GetColor(0, 0, 0), TRUE);
	DrawBox(162, 455, 168, 468, GetColor(0, 0, 0), TRUE);
	DrawOval(165, 471, 12, 5, GetColor(0, 0, 0), TRUE);
	DrawString(188, 458, " 選択 ", GetColor(255, 255, 255));

	DrawCircle(280, 465, 10, GetColor(0, 0, 0), TRUE);
	DrawString(277, 458, "A  決定", GetColor(255, 255, 255));

	DrawOval(393, 465, 24, 10, GetColor(0, 0, 0), TRUE);
	DrawString(367, 458, " BACK  終了 ", GetColor(255, 255, 255));


}