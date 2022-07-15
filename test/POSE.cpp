#include"POSE.h"
#include"Common.h"
#include"PLAYER.h"
#include"DxLib.h"

POSE pose;

POSE::POSE() {
	PoseTime = 0;
	PoseCount = 0;
}

void POSE::DrawPose() {
	if (++PoseCount > 60) {
		++PoseTime;
		PoseCount = 0;
	}
	if (input.Buttons[XINPUT_BUTTON_START] == 0) {
		g_KeyFLG = TRUE;
	}
	
	
	DrawBackGround();
	DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
	for (int i = 0; i < Apple_MAX; i++) { 
		DrawRotaGraph(g_apple[i].x, g_apple[i].y, 1.0f, 0, g_apple[i].img, TRUE, FALSE); 
	}
	DrawRotaGraph(520, 110, 0.9f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(570, 110, 0.9f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(620, 110, 0.9f, 0, Apple_Img[2], TRUE, FALSE);

	DrawFormatString(510, 140, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", AppleCount3);
	DrawFormatString(510, 200, 0xFFFFFF, "%02d", StartTime);
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//ブレンドモードをα(128/255)に設定
	DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(320, 240, "POSE", 0xffffff, 0);

	if (input.Buttons[XINPUT_BUTTON_START] == 1 && g_KeyFLG == TRUE) {
		g_KeyFLG = FALSE;
		g_GameState = 5;
	}
}