#include"DxLib.h"
#include"Common.h"
#include"RANKING.h"
#include"DrawRANKING.h"
#include"InputRANKING.h"
#include<string.h>

InputRANKING inputranking;
char Alfabet[5][14] = { "ABCDEFGHIJKLM","NOPQRSTUVWXYZ","abcdefghijklm","nopqrstuvwxyz","0123456789   " };


InputRANKING::InputRANKING() {
	g_InputRankingImage = 0;
	g_EnterImage = 0;
	g_BackSpaceImage = 0;
	count = 0;
	moji = 0;
	cursor_X = 0;
	cursor_Y = 0;
}

void InputRANKING::InputRanking()
{
	//ランキング画像表示
	DrawGraph(0, 0, g_InputRankingImage, FALSE);

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && (cursor_X < 10 || cursor_Y < 4)) {	//Aボタン押したときのカーソル位置
		if (ButtonFLG == TRUE) {													//にあるアルファベットのアスキーコードをランキングに入れる
			if (count > 8) {
				count = 8;
			}
			Name[count] = Alfabet[cursor_Y][cursor_X];
			count++;
			ButtonFLG = FALSE;
		}
	}

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 10 && cursor_Y == 4) {	//１文字削除押したとき
		if (ButtonFLG == TRUE && count>0) {
			if (count < 0) {
				count=0;
			}
			strncpy_s(Name, 11,Name, count-1);
			count--;
			ButtonFLG = FALSE;
		}
	}


	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		ButtonFLG = TRUE;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//ブレンドモードをα(128/255)に設定
	DrawBox(90, 250, 560, 470, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetFontSize(40);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 13; j++) {
			DrawFormatString(70 + j * 35, 215 + i * 42, 0xFFFFFF, "%c", Alfabet[i - 1][j - 1]);
		}
	}
	DrawRotaGraph(465, 443, 0.7f, 0, g_BackSpaceImage, TRUE, FALSE);
	DrawRotaGraph(535, 445, 0.8f, 0, g_EnterImage, TRUE, FALSE);
	
	//////////////////////////////////////////////////////////// パッド入力
	if (input.ThumbLX > 17500) {	//右入力
		if (g_KeyFLG == TRUE) {
			++cursor_X;
			if (cursor_X > 12) {
				cursor_X = 0;
			}
			if (cursor_X == 11 && cursor_Y == 4) {
				cursor_X = 12;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLX < -17500) {		//左入力
		if (g_KeyFLG == TRUE) {
			--cursor_X;
			if (cursor_X < 0) {
				cursor_X = 12;
			}
			if (cursor_X == 11 && cursor_Y == 4) {
				cursor_X = 10;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLY > 17500) {		//上入力
		if (g_KeyFLG == TRUE) {
			--cursor_Y;
			if (cursor_Y < 0) {
				cursor_Y = 4;
			}
			if (cursor_X == 11 && cursor_Y == 4) {
				cursor_Y = 3;
			}
			g_KeyFLG = FALSE;
		}
		++g_WaitCount;
		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
	}

	if (input.ThumbLY < -17500) {		//下入力
		if (g_KeyFLG == TRUE) {
			++cursor_Y;
			if (cursor_Y > 4) {
				cursor_Y = 0;
			}
			if (cursor_X == 11 && cursor_Y == 4) {
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
	//////////////////////////////////////////////////////パッド入力


	//カーソル描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//ブレンドモードをα(128/255)に設定
	DrawBox(97 + cursor_X * 35, 258 + cursor_Y * 42, 133 + cursor_X * 35, 293 + cursor_Y * 42, GetColor(0, 250, 154), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetFontSize(30);
	DrawFormatString(185 + 0 * 28, 200, 0xFFFFFF, "%c", Name[0]);		//今入力している文字
	DrawFormatString(185 + 1 * 28, 200, 0xFFFFFF, "%c", Name[1]);
	DrawFormatString(185 + 2 * 28, 200, 0xFFFFFF, "%c", Name[2]);
	DrawFormatString(185 + 3 * 28, 200, 0xFFFFFF, "%c", Name[3]);
	DrawFormatString(185 + 4 * 28, 200, 0xFFFFFF, "%c", Name[4]);
	DrawFormatString(185 + 5 * 28, 200, 0xFFFFFF, "%c", Name[5]);
	DrawFormatString(185 + 6 * 28, 200, 0xFFFFFF, "%c", Name[6]);
	DrawFormatString(185 + 7 * 28, 200, 0xFFFFFF, "%c", Name[7]);
	DrawFormatString(185 + 8 * 28, 200, 0xFFFFFF, "%c", Name[8]);

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 12 && cursor_Y == 4) {	//決定押したとき
		if (Name[0] == ' ') {
			DrawString(185, 200, "Input Your Name!", 0xFFFFFF);
		}
		if (Name[0] != ' ') {
			ButtonFLG = FALSE;
			strcpy_s(ranking.getName(4), 12, Name);
			ranking.setScore(g_Score);	// ランキングデータの5番目にスコアを登録
			ranking.SortRanking();		// ランキング並べ替え
			ranking.SaveRanking();		// ランキングデータの保存
			g_GameState = 2;			// ゲームモードの変更
		}
	}
}
