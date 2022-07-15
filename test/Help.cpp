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

	DrawString(20, 120, "�w���v���", 0xffffff, 0);
	
	DrawString(20, 160, "����͏�Q��������Ȃ���", 0xffffff, 0);
	DrawString(20, 180, "���葱����Q�[���ł�", 0xffffff, 0);
	DrawString(20, 200, "�R�����s���邩��Q����", 0xffffff, 0);
	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł�", 0xffffff, 0);
	DrawString(20, 250, "�A�C�e���ꗗ", 0xffffff, 0);
	DrawString(20, 315, "���ƔR�����񕜂����", 0xffffff, 0);
	DrawString(20, 385, "�_���[�W���󂯂Ă���Ƃ��Ɏ��Ƒϋv��", 0xffffff, 0);
	DrawString(20, 405, "�ϋv�������Ă��Ȃ�������R���������񕜂����", 0xffffff, 0);
	DrawString(20, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);

}