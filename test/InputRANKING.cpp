#include"DxLib.h"
#include"Common.h"
#include"RANKING.h"
#include"DrawRANKING.h"
#include"InputRANKING.h"

InputRANKING inputranking;
InputRANKING Alfabet[5][13];

InputRANKING::InputRANKING() {
	g_InputRankingImage = 0;
	count = 0;
	moji = 0;

	cursor_X = 0;
	cursor_Y = 0;

	upper = 65;
	rower = 97;
	number = 48;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			if (i <= 1) {
				Alfabet[i][j].moji = upper++;
			}
			else if (i <= 3) {
				Alfabet[i][j].moji = rower++;
			}
			else {
				Alfabet[i][j].moji = number++;
			}
		}
	}
	Alfabet[4][10].moji = 127;	//delete
	Alfabet[4][11].moji = 0;	//nothing(NULL)
	Alfabet[4][12].moji = 64;	//enter(@)
}

void InputRANKING::InputRanking()
{
	//ランキング画像表示
	DrawGraph(0, 0, g_InputRankingImage, FALSE);


	DrawFormatString(300, 100, 0x000000, "%d", input.Buttons[XINPUT_BUTTON_A]);
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X < 10 || cursor_Y </*!=*/ 4) {	//Aボタン押したときのカーソル位置
		if (ButtonFLG == TRUE) {													//にあるアルファベットのアスキーコードをランキングに入れる
			if (count > 9) {
				count = 9;
			}
			ranking.setName(count, Alfabet[cursor_Y][cursor_X].moji);
			count=count+1;
			ButtonFLG = FALSE;
		}
	}

	/*if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 10 && cursor_Y == 4) {
		if (ButtonFLG == TRUE) {
			if (count < 0) {
				count = 0;
			}
			ranking.setName()
		}
	}*/

	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		ButtonFLG = TRUE;
	}


	// フォントサイズの設定
	SetFontSize(40);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 13; j++) {
			DrawFormatString(70 + j * 35, 225 + i * 40, 0xFFFFFF, "%c", Alfabet[i - 1][j - 1].moji);
		}
	}

	if (input.ThumbLX > 17500) {	//右入力
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

	if (input.ThumbLX < -17500) {		//左入力
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

	if (input.ThumbLY > 17500) {		//上入力
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


	//カーソル描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//ブレンドモードをα(128/255)に設定
	DrawBox(100 + cursor_X * 35, 265 + cursor_Y * 40, 130 + cursor_X * 35, 305 + cursor_Y * 40, GetColor(0, 250, 154), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);



	// フォントサイズの設定
	SetFontSize(20);
	// 名前入力指示文字列の描画
	DrawString(150, 140, "ランキングに登録します", 0xFFFFFF);
	DrawString(150, 170, "名前を英字で入力してください", 0xFFFFFF);
	// 名前の入力
	DrawString(150, 210, "> ", 0xFFFFFF);
	DrawBox(160, 205, 300, 235, 0x000055, TRUE);


	for (int i = 0; i < count + 1; i++) {
		DrawFormatString(150+i*20, 200, 0xFFFFFF, "%c", ranking.getName2(4,i));		//今入力している文字
	}

	if (input.Buttons[XINPUT_BUTTON_A] == 1 && cursor_X == 12 && cursor_Y == 4) {	//決定押したとき
		ranking.setScore(g_Score);	// ランキングデータの5番目にスコアを登録
		ranking.SortRanking();		// ランキング並べ替え
		ranking.SaveRanking();		// ランキングデータの保存
		g_GameState = 2;			// ゲームモードの変更
	}

	//if (KeyInputSingleCharString(170, 210, 10, ranking.getName(4), FALSE) == 1) {
	//	ranking.setScore(g_Score);	// ランキングデータの5番目にスコアを登録
	//	ranking.SortRanking();		// ランキング並べ替え
	//	ranking.SaveRanking();		// ランキングデータの保存
	//	g_GameState = 2;		// ゲームモードの変更
	//}
}