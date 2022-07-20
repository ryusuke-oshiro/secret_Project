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
		PlaySoundMem(g_SE3, DX_PLAYTYPE_BACK, TRUE);
		g_GameState = 0;
	}
	DrawGraph(0, 0, g_HelpImage, FALSE);

	DrawOval(115, 339, 14, 7, GetColor(0, 0, 0), TRUE);
	DrawBox(109, 345, 122, 360, GetColor(0, 0, 0), TRUE);
	DrawOval(115, 356, 17, 7, GetColor(0, 0, 0), TRUE);
	DrawString(112, 335, "L", GetColor(255, 255, 255));

	DrawOval(360, 345, 34, 14, GetColor(0, 0, 0), TRUE);
	DrawString(339, 338, "START", GetColor(255, 255, 255));

	DrawCircle(100, 465, 10, GetColor(0, 0, 0), TRUE);
	DrawString(97, 458, "B", GetColor(255, 255, 255));

	DrawCircle(445, 465, 10, GetColor(0, 0, 0), TRUE);
	DrawString(442, 458, "A", GetColor(255, 255, 255));

}