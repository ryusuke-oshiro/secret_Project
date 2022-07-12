#include<DxLib.h>
#include"Title.h"
#include"Common.h"
#include <math.h>
#include <corecrt_math_defines.h>

Title title;

void Title::DrawGameTitle() {

	static int MenuNo = 0;

	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK, FALSE);

	//メニューカーソル移動処理
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
		if (++MenuNo > 3)MenuNo = 0;
	}

	if (g_KeyFlg & PAD_INPUT_UP) {
				PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
				if (--MenuNo < 0)MenuNo = 3;
	}
	//Zキーでメニュー選択
	if (g_KeyFlg & PAD_INPUT_A) {
		StopSoundMem(g_TitleBGM);
		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
		g_GameState = MenuNo + 1;
	}

	//タイトル画像表示
	DrawGraph(0, 0, g_TitleImage, FALSE);
		
	//メニュー
	DrawGraph(120, 200, g_Menu, TRUE);
		
	//メニューカーソル
	DrawRotaGraph(90, 220 + MenuNo * 40, 0.7f, M_PI / 2, g_Cone, TRUE);
		
}

//void DrawGameTitle(void)
//{
//	static int MenuNo = 0;
//
//	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK, FALSE);
//
//	//メニューカーソル移動処理
//	if (g_KeyFlg & PAD_INPUT_DOWN) {
//		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
//		if (++MenuNo > 3)MenuNo = 0;
//	}
//	if (g_KeyFlg & PAD_INPUT_UP) {
//		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
//		if (--MenuNo < 0)MenuNo = 3;
//	}
//	//Zキーでメニュー選択
//	if (g_KeyFlg & PAD_INPUT_A) {
//		StopSoundMem(g_TitleBGM);
//		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
//		g_GameState = MenuNo + 1;
//	}
//	//タイトル画像表示
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//メニュー
//	DrawGraph(120, 200, g_Menu, TRUE);
//
//	//メニューカーソル
//	DrawRotaGraph(90, 220 + MenuNo * 40, 0.7f, M_PI / 2, g_Cone, TRUE);
//
//}


