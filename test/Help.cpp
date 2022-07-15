#include "HELP.h"
#include "Common.h"
#include "DxLib.h"

HELP help;

HELP::HELP() {
	g_HelpImage = 0;
}

void HELP::DrawHelp() {
	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		g_KeyFLG = TRUE;
	}
	if(input.Buttons[XINPUT_BUTTON_A] && g_KeyFLG==TRUE){
		g_GameState = 1;
	}

	if (input.Buttons[XINPUT_BUTTON_B] && g_KeyFLG == TRUE) {
		g_GameState = 0;
	}
	DrawGraph(0, 0, g_HelpImage, FALSE);
	SetFontSize(16);
	DrawFormatString(300, 100, 0x000000, "%d", input.Buttons[XINPUT_BUTTON_A]);

	DrawString(20, 120, "ヘルプ画面", 0xffffff, 0);
	
	DrawString(20, 160, "これは障害物を避けながら", 0xffffff, 0);
	DrawString(20, 180, "走り続けるゲームです", 0xffffff, 0);
	DrawString(20, 200, "燃料が尽きるか障害物に", 0xffffff, 0);
	DrawString(20, 220, "数回当たるとゲームオーバーです", 0xffffff, 0);
	DrawString(20, 250, "アイテム一覧", 0xffffff, 0);
	//DrawGraph(20, 260, g_Item[0], TRUE);
	DrawString(20, 315, "取ると燃料が回復するよ", 0xffffff, 0);
	//DrawGraph(20, 335, g_Item[1], TRUE);
	DrawString(20, 385, "ダメージを受けているときに取ると耐久回復", 0xffffff, 0);
	DrawString(20, 405, "耐久が減っていなかったら燃料が少し回復するよ", 0xffffff, 0);
	DrawString(20, 450, "---- スペースキーを押してタイトルへ戻る ----", 0xffffff, 0);

}

//void DrawHelp(void)
//{
//	// スペースキーでメニューに戻る
//	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
//
//	//タイトル画像表示
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//	SetFontSize(16);
//	DrawString(20, 120, "ヘルプ画面", 0xffffff, 0);
//
//	DrawString(20, 160, "これは障害物を避けながら", 0xffffff, 0);
//	DrawString(20, 180, "走り続けるゲームです", 0xffffff, 0);
//	DrawString(20, 200, "燃料が尽きるか障害物に", 0xffffff, 0);
//	DrawString(20, 220, "数回当たるとゲームオーバーです", 0xffffff, 0);
//	DrawString(20, 250, "アイテム一覧", 0xffffff, 0);
//	DrawGraph(20, 260, g_Item[0], TRUE);
//	DrawString(20, 315, "取ると燃料が回復するよ", 0xffffff, 0);
//	DrawGraph(20, 335, g_Item[1], TRUE);
//	DrawString(20, 385, "ダメージを受けているときに取ると耐久回復", 0xffffff, 0);
//	DrawString(20, 405, "耐久が減っていなかったら燃料が少し回復するよ", 0xffffff, 0);
//	DrawString(20, 450, "---- スペースキーを押してタイトルへ戻る ----", 0xffffff, 0);
//}