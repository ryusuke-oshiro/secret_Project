#include"DxLib.h"
#include"Common.h"
#include"END.h"

END end;

END::END() {
	g_EndImage = 0;
}

void END::DrawEnd() {
	//�G���h�摜�\��
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//�^�C���̉��Z�������I���i�R�b��j
	if (++g_WaitTime > 180)g_GameState = 99;
}