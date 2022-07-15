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
	//DrawGraph(20, 260, g_Item[0], TRUE);
	DrawString(20, 315, "���ƔR�����񕜂����", 0xffffff, 0);
	//DrawGraph(20, 335, g_Item[1], TRUE);
	DrawString(20, 385, "�_���[�W���󂯂Ă���Ƃ��Ɏ��Ƒϋv��", 0xffffff, 0);
	DrawString(20, 405, "�ϋv�������Ă��Ȃ�������R���������񕜂����", 0xffffff, 0);
	DrawString(20, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);

}

//void DrawHelp(void)
//{
//	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
//
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//	SetFontSize(16);
//	DrawString(20, 120, "�w���v���", 0xffffff, 0);
//
//	DrawString(20, 160, "����͏�Q��������Ȃ���", 0xffffff, 0);
//	DrawString(20, 180, "���葱����Q�[���ł�", 0xffffff, 0);
//	DrawString(20, 200, "�R�����s���邩��Q����", 0xffffff, 0);
//	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł�", 0xffffff, 0);
//	DrawString(20, 250, "�A�C�e���ꗗ", 0xffffff, 0);
//	DrawGraph(20, 260, g_Item[0], TRUE);
//	DrawString(20, 315, "���ƔR�����񕜂����", 0xffffff, 0);
//	DrawGraph(20, 335, g_Item[1], TRUE);
//	DrawString(20, 385, "�_���[�W���󂯂Ă���Ƃ��Ɏ��Ƒϋv��", 0xffffff, 0);
//	DrawString(20, 405, "�ϋv�������Ă��Ȃ�������R���������񕜂����", 0xffffff, 0);
//	DrawString(20, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);
//}