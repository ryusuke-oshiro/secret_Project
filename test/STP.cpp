//#include"DxLib.h"
//
//
//int x, y, i, j;
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//
//int g_GameState = 0;
//int g_TitleImage;
//
//int player_img[2];
//
////���@�̍\����
//struct PLAYER {
//	int flg = FALSE;	//�g�p�t���O
//	int x = 320, y = 400;	//���Wx,y
//	int angle = 1;	//���@�A���O��
//	int speed = 3;		//���@�X�s�[�h
//	int hp = 3;		//�̗�
//
//};
////���@
//struct PLAYER g_player;
//
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HIGHT = 480;
//
//
//void DrawTitle(void);
//void GameMain(void);
//void PlayerControl(void);
//int LoadImages();
//
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmbShow)
//{
//	SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);
//	ChangeWindowMode(TRUE);
//	SetMainWindowText("APPLEGAME");
//	if (DxLib_Init() == -1)	return -1;
//	if ((g_TitleImage = LoadGraph("images/BackGround.png")) == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���
//	
//
//	if (LoadImages() == -1)return -1;
//	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
//
//		//���̓L�[�擾
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// ��ʂ̏�����
//
//		switch (g_GameState) {
//		case 0:
//			DrawTitle();	//�Q�[���^�C�g������
//			break;
//		case 1:
//			GameMain();	//�Q�[�����C��
//			break;
//
//		}
//		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
//	}
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}
//
//void DrawTitle(void) {
//	// �^�C�g���摜�\��
//
//	DrawGraph(0, 0, g_TitleImage, TRUE);
//	if (KEY_INPUT_B & g_KeyFlg)g_GameState = 1;
//}
//
//void GameMain(void) {
//	PlayerControl();
//}
//
//void PlayerControl(void) {
//	DrawGraph(0, 0, g_TitleImage, TRUE);
//
//	if (g_player.flg = FALSE) {
//		DrawGraph(g_player.x, g_player.y, player_img[g_player.angle-1], FALSE);
//		g_player.flg = TRUE;
//	}
//
//
//	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
//	if (g_player.x > SCREEN_WIDTH - 35)g_player.x = SCREEN_WIDTH - 35;
//	if (g_player.x < 24)g_player.x = 24;
//	
//
//
//	//���@�̌���
//	if (PAD_INPUT_RIGHT & g_KeyFlg) {
//		g_player.angle = 1;	//�E
//	}
//	if (PAD_INPUT_LEFT & g_KeyFlg) {
//		g_player.angle = 2;	//��
//	}
//	DrawGraph(g_player.x, g_player.y, player_img[g_player.angle-1], FALSE);
//
//	//���@�̈ړ�����
//
//	switch (g_player.angle) {
//	case 1:
//		g_player.x += g_player.speed*2;
//		break;
//	case 2:
//		g_player.x -= g_player.speed*2;
//		break;
//	default:
//			break;
//	}
//}
//
//
//int LoadImages(void)
//{
//	if ((player_img[0] = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
//	if ((player_img[1] = LoadGraph("images/PlayerA.png")) == -1)return -1;
//	return 0;
//}