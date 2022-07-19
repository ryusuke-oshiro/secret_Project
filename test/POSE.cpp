#include"POSE.h"
#include"Common.h"
#include"PLAYER.h"
#include"DxLib.h"

POSE pose;

POSE::POSE() {
	PoseTime = 0;
	PoseCount = 0;
}

void POSE::initPose() {
	PoseCount = 0;
	PoseTime = 0;
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
	DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Player_Nowangle, TRUE, FALSE);
	for (int i = 0; i < Apple_MAX; i++) { 
		DrawRotaGraph(g_apple[i].x, g_apple[i].y, 1.0f, 0, g_apple[i].img, TRUE, FALSE); 
	}
	DrawRotaGraph(520, 310, 1.1f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(520, 375, 1.1f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(520, 440, 1.1f, 0, Apple_Img[2], TRUE, FALSE);
	SetFontSize(24);
	DrawFormatString(580, 300, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(580, 365, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(580, 430, 0xFFFFFF, "%03d", AppleCount3);
	
	SetFontSize(36);
	apple.AppleScore();
	DrawFormatString(550, 250, 0xFFFFFF, "%02d", NowTime);
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//�u�����h���[�h����(128/255)�ɐݒ�
	DrawBox(0, 0, 490, 480, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(100, 230, "-- P A U S E --", 0xffffff, 0);

	SetFontSize(16);
	DrawOval(220, 465, 28,12, GetColor(0, 0, 0), TRUE);
	DrawString(199, 458, "START   �ĊJ", GetColor(255, 255, 255));

	if (input.Buttons[XINPUT_BUTTON_START] == 1 && g_KeyFLG == TRUE) {
		g_KeyFLG = FALSE;
		PlaySoundMem(g_MusicBGM, DX_PLAYTYPE_BACK, FALSE);
		g_GameState = 5;
	}
}