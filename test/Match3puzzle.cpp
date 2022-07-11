///***********************************************
//**�@��W�́@�~�j�Q�[�������i�T�j
//**�@�@�@�@�@�@Match 3 Puzzle(�}�b�`�R�p�Y��)
//*************************************************/
//#include"DxLib.h"
//#include<stdlib.h>
//
///*************************************************
//*�񋓌^�̐錾
//**************************************************/
//typedef enum GAME_MODE{
//	GAME_TITLE,
//	GAME_INIT,
//	GAME_END,
//	GAME_MAIN,
//	GAME_CLEAR,
//	GAME_OVER,
//	END = 99
//};
//
///**********************************
//*�萔�̐錾
//************************************/
//const int HEIGHT = 12;
//const int WIDTH = 12;
//const int BLOCKSIZE = 48;
//const int MARGIN = 0;
//const int ITEM_MAX = 8;
//const int TIMELIMIT = 3600 * 3;
//
///***********************************
//*�ϐ��̐錾
//************************************/
//int g_OldKey;	//�O��̓��̓L�[
//int g_NowKey;	//����̓��̓L�[
//int g_KeyFlg;	//���̓L�[���
//int g_MouseX;	//�}�E�XX���W
//int g_MouseY;	//�}�E�XY���W
//
//int g_GameState = GAME_TITLE;//�Q�[�����[�h
//
//int g_GameClearImage;		//�Q�[���N���A�摜
//
//int g_TitleImage;			//�^�C�g���摜
//
//int g_StageImage;			//�X�e�[�W�摜
//
//int g_GameOverImage;		//�Q�[���I�[�o�[�摜
//
//int g_BlockImage[10];		//�u���b�N�摜
//
//int g_NumberImage[10];		//�i���o�[�摜
//
//int g_Score;				//�X�R�A
//int g_Level;				//���׃�
//int g_Mission;				//�~�b�V����
//int g_Item[ITEM_MAX];		//�X�e�[�W�N���A�p�̕ϐ�
//int g_Time;					//��������
//
//int g_Status = 0;			//�X�e�[�W�̃X�e�[�^�X�i0..�v���C���[���쒆�Ȃǁj
//int g_SelectX1;				//1��ڂɑI�������u���b�N�̓񎟌��z��i���j
//int g_SelectY1;				//1��ڂɑI�������u���b�N�̓񎟌��z��i�c�j
//int g_SelectX2;				//2��ڂɑI�������u���b�N�̓񎟌��z��i���j
//int g_SelectY2;				//2��ڂɑI�������u���b�N�̓񎟌��z��i�c�j
//
//int g_TitleBGM;	//�^�C�g��BGM
//int g_GameClearSE;	//�Q�[���N���A
//int g_GameOverSE;	//�Q�[���I�[�o�[
//int g_ClickSE;		//�}�E�X�N���b�N���ʉ�
//int g_FadeOutSE;	//�u���b�N�������ʉ�
//int g_MoveBlockSE;	//�u���b�N�ړ������ʉ�
//
///************************************
//*�\���̂̐錾
//*************************************/
//struct Object {
//	int flg;	//�t���O(0:�\�����Ȃ�,1:�\��)
//	int x, y;	//���Wx,y
//	int w, h;	//��w�@������
//	int image;	//�摜
//	int backup;	//�摜�o�b�N�A�b�v
//};
//struct Object g_Block[HEIGHT][WIDTH];
//
///************************************
//*�֐��̃v���g�^�C�v�錾
//*************************************/
//void GameInit(void);	//�Q�[������������
//void GameMain(void);	//�Q�[�����C������
//void DrawGameTitle(void);//�^�C�g���`�揈��
//void DrawGameClear(void);//�Q�[���N���A��ʕ`�揈��
//void DrawGameOver(void);//�Q�[���I�[�o�[�摜�`�揈��
//void DrawEnd(void);//�G���h�摜�`�揈��
//
//int LoadImages(void);	//�摜�ǂݍ���
//
//int LoadSounds(void);
//
//void DrawStage(void);	//Block[][]�̒��g�ŁA��ʂ�`��
//
//void StageInit(void);	//�X�e�[�W��������
//
//int RensaCheck(int y, int x);	//�u���b�N�̘A���`�F�b�N
//int RensaCheckH(int y, int x, int* cnt, int* col);	//�u���b�N�A���`�F�b�N�i�c�j
//int RensaCheckW(int y, int x, int* cnt, int* col);	//�u���b�N�A���`�F�b�N�i���j
//void SaveBlock(void);			//�u���b�N���o�b�N�A�b�v����
//void RestoreBlock(void);		//�o�b�N�A�b�v�u���b�N��߂�
//
//void SelectBlock(void);			//Block��I��
//
//void MoveBlock(void);			//�u���b�N�ړ�
//
//void CheckBlock(void);			//�u���b�N�A�����`�F�b�N����
//
//void CheckClear(void);			//�N���A�����̃`�F�b�N
//
//void FadeOutBlock(void);		//��������u���b�N���t�F�[�h�A�E�g����
//
///**************************************
//*�v���O�����̊J�n
//***************************************/
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmbLine, int nCmbShow)
//{
//	SetMainWindowText(" Match 3 Puzzle(�}�b�`�R�p�Y��)");	//�^�C�g����ݒ�
//	ChangeWindowMode(TRUE);									//�E�B���h�E���[�h�ŋN��
//	if (DxLib_Init() == -1)return -1;						//DX���C�u�����̏���������
//	SetDrawScreen(DX_SCREEN_BACK);							//�`����ʂ𗠂ɂ���
//	if (LoadImages() == -1)return -1;						//�摜�ǂݍ��݊֐����Ăяo��
//	if (LoadSounds() == -1)return -1;						//�T�E���h�ǂݍ��݊֐����Ăяo��
//	//�Q�[�����[�v
//	while (ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)) {
//		//���̓L�[�擾
//		g_OldKey = g_NowKey;
//		g_NowKey = GetMouseInput();
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		//�}�E�X�̈ʒu���擾
//		GetMousePoint(&g_MouseX, &g_MouseY);
//
//		ClearDrawScreen();		//��ʂ̏�����
//
//		switch (g_GameState) {
//		case GAME_TITLE:
//			DrawGameTitle();	//�^�C�g���`�揈��
//			break;
//		case GAME_INIT:
//			GameInit();			//�Q�[����������
//			break;
//		case GAME_END:
//			DrawEnd();			//�G���h��ʕ`�揈��
//			break;
//		case GAME_MAIN:
//			GameMain();			//�Q�[�����C������
//			break;
//		case GAME_CLEAR:
//			DrawGameClear();	//�Q�[���N���A��ʕ`�揈��
//			break;
//		case GAME_OVER:
//			DrawGameOver();		//�Q�[���I�[�o�[��ʕ`�揈��
//			break;
//		}
//
//		ScreenFlip();			//����ʂ̓��e��\��ʂɔ��f
//	}
//
//	DxLib_End();	//DX���C�u�����g�p�̏I������
//	return 0;		//�\�t�g�̏I��
//}
//
///***********************************************
//*�Q�[���^�C�g���`�揈���i���j���[��ʁj
//************************************************/
//void DrawGameTitle(void)
//{
//	//�^�C�g��BGM���Đ�
//	if (CheckSoundMem(g_TitleBGM) == 0) {
//		PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK);
//	}
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//�Q�[�����[�h��؂�ւ���
//	if (g_KeyFlg & MOUSE_INPUT_LEFT) {
//		if (g_MouseX > 120 && g_MouseX < 290 && g_MouseY > 260 && g_MouseY < 315) {
//			g_GameState = GAME_INIT;	//�Q�[���X�^�[�g�̑I��
//			StopSoundMem(g_TitleBGM);	//�^�C�g��BGM���~�߂�
//		}
//		else if (g_MouseX > 120 && g_MouseX < 220 && g_MouseY>345 && g_MouseY < 400) {
//			g_GameState = GAME_END;		//�Q�[���G���h�̑I��
//			StopSoundMem(g_TitleBGM);	//�^�C�g��BGM���~�߂�
//		}
//	}
//}
//
///*********************************************
//*�Q�[����������
//**********************************************/
//void GameInit(void)
//{
//	//�Q�[�����C��������
//	g_GameState = GAME_MAIN;
//
//	//�u���b�N�̏�����
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			if (j == 0 || j == WIDTH - 1 || i == HEIGHT - 1 || i == 0) {
//				g_Block[i][j].flg = 0;
//				g_Block[i][j].image = 0;
//			}
//			else {
//				g_Block[i][j].flg = 1;
//				g_Block[i][j].x = (j - 1) * BLOCKSIZE + MARGIN;
//				g_Block[i][j].y = (i - 1) * BLOCKSIZE;
//				g_Block[i][j].w = BLOCKSIZE;
//				g_Block[i][j].h = BLOCKSIZE;
//				g_Block[i][j].image = GetRand(7) + 1;//1?8�܂ł̗����𔭐�
//			}
//		}
//	}
//	//�X�R�A�̏�����
//	g_Score = 0;
//	//���x���̏�����
//	g_Level = 0;
//	//�~�b�V�����̏������i���x���P�͏�������u���b�N�����R����X�^�[�g�j
//	g_Mission = 2;
//	//�X�e�[�W��������
//	StageInit();
//}
//
///************************************************
//*�G���h�`�揈��
//**************************************************/
//void DrawEnd(void)
//{
//	static int WaitTime = 0;
//
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	SetFontSize(24);
//	DrawString(360, 480 - 24, "Thank you for Playing", 0x003333, 0);
//
//	//�^�C���̉��Z�������I���i�R�b��j
//	if (++WaitTime > 180)g_GameState = END;
//}
//
///************************************************
//*�Q�[�����C��
//**************************************************/
//void GameMain(void)
//{
//	//�X�e�[�W�摜�\��
//	DrawGraph(0, 0, g_StageImage, FALSE);
//
//	//�u���b�N�`��
//	DrawStage();
//
//	//�X�e�[�^�X�ɂ�菈���𕪂���
//	switch (g_Status) {
//		case 0:
//			SelectBlock();		//Block��I��
//			break;
//		case 1:
//			FadeOutBlock();		//�u���b�N���t�F�[�h�A�E�g���ď���
//			break;
//		case 2:
//			MoveBlock();		//Block�ړ�
//			break;
//		case 3:
//			CheckBlock();		//Block�̘A���`�F�b�N
//			break;
//		case 4:
//			CheckClear();		//�N���A�����̃`�F�b�N
//			break;
//	}
//	//�^�C���ϐ����f�N�������g���āA�O�����Ȃ�Q�[���I�[�o�[�ֈڍs����
//	if (--g_Time < 0) {
//		g_GameState = GAME_OVER;
//	}
//}
//
///***********************************************
//*�Q�[���N���A�\��
//***********************************************/
//void DrawGameClear(void)
//{
//	static int GameClearFlg = 0;
//	//�Q�[���N���A���ʉ����Đ�
//	if (CheckSoundMem(g_GameClearSE) == 0) {
//		if (GameClearFlg++ == 0) {
//			PlaySoundMem(g_GameClearSE, DX_PLAYTYPE_BACK);
//		}else {
//			//g_GameState=GAME_TITLE;
//			//�X�e�[�W��������
//			StageInit();
//			g_GameState = GAME_MAIN;
//			GameClearFlg = 0;
//		}
//	}
//	//�Q�[���N���A�摜�\��
//	DrawGraph(0, 0, g_GameClearImage, FALSE);
///*
//	//�E�N���b�N�Ń��j���[�ɖ߂�
//	if (g_KeyFlg & MOUSE_INPUT_RIGHT) {//g_GameState = GAME_TITLE;
//		//�X�e�[�W��������
//		StageInit();
//		g_GameState = GAME_MAIN;
//	}
//
//	//DrawString(150,450,"---- �E�N���b�N�������ă^�C�g���֖߂� ----",0xffffff,0);
//
//	SetFontSize(20);
//	DrawString(150, 450, "---- �E�N���b�N�����̃X�e�[�W�� ----", 0xffffff, 0);
//*/
//}
//
///************************************************
//*�N���A�����̃`�F�b�N
//*************************************************/
//void CheckClear(void)
//{
//	//�N���A�����̃`�F�b�N
//	//�N���A�����t���O���[���Ƃ��A�e�X�N�[���̏����u���b�N��
//	//���x�������������Ȃ�������A�`�F�b�N�����𒆒f���ăQ�[���𑱍s����
//	int ClearFlg = 0;
//	for (int i = 0; i < ITEM_MAX; i++) {
//		if (g_Item[i] < g_Mission) {
//			ClearFlg = 1;
//			break;
//		}
//	}
//	if (ClearFlg == 0) {
//		g_GameState = GAME_CLEAR;
//	}else {
//		g_Status = 0;
//	}
//}
//
///*************************************************
//*�Q�[���I�[�o�[����
//**************************************************/
//void DrawGameOver(void)
//{
//	static int GameOverFlg = 0;
//	//�Q�[���I�[�o�[���ʉ����Đ�
//	if (CheckSoundMem(g_GameOverSE) == 0){
//		if (GameOverFlg++ == 0) {
//			PlaySoundMem(g_GameOverSE,DX_PLAYTYPE_BACK);
//		}else {
//			g_GameState=GAME_TITLE;
//			GameOverFlg=0;
//		}
//	}
//	//�Q�[���I�[�o�[�摜�\��
//	DrawGraph(0, 0, g_GameOverImage, FALSE);
///*
//	//�E�N���b�N�Ń��j���[�ɖ߂�
//	if (g_KeyFlg & MOUSE_INPUT_RIGHT)g_GameState = GAME_TITLE;
//
//	SetFontSize(16);
//	DrawString(150, 450, "---- �E�N���b�N�������ă^�C�g���֖߂� ----", 0xffffff, 0);
//*/
//}
//
///****************************************************
//*�X�e�[�W�Ƀu���b�N��`��
//*****************************************************/
//void DrawStage(void)
//{
//	//���x����`��
//	int TmpLevel = g_Level;
//	int PosX = 600;
//	do {
//		DrawRotaGraph(PosX, 80, 0.5f, 0, g_NumberImage[TmpLevel % 10], TRUE);
//		TmpLevel /= 10;
//		PosX -= 30;
//	} while (TmpLevel > 0);
//
//	//�X�R�A��`��
//	int TmpScore = g_Score;
//	PosX = 620;
//	do {
//		DrawRotaGraph(PosX, 160, 0.3f, 0, g_NumberImage[TmpScore % 10], TRUE);
//		TmpScore /= 10;
//		PosX -= 20;
//	} while (TmpScore > 0);
//
//	//�~�b�V������`��
//	SetFontSize(20);
//	DrawFormatString(590, 211, 0xFFFFFF, "%3d", g_Mission);
//
//	//�A�C�e���̎擾����`��
//	for (int i = 0; i < ITEM_MAX; i++) {
//		DrawRotaGraph(540, 245 + i * 30, 0.5f, 0, g_BlockImage[i + 1], TRUE, 0);
//		DrawFormatString(580, 235 + i * 30, 0xFFFFFF, "%3d", g_Item[i]);
//	}
//
//	//�u���b�N��`��
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			if (g_Block[i][j].flg != 0 && g_Block[i][j].image != 0) {
//				DrawGraph(g_Block[i][j].x, g_Block[i][j].y, g_BlockImage[g_Block[i][j].image], TRUE);
//			}
//		}
//	}
//
//	//�^�C���o�[��`��
//	DrawBox(491, 469, 509, 469 - g_Time / 60 * 2, 0x0033ff, TRUE);
//}
//
///*************************************************
//*�X�e�[�W��������
//**************************************************/
//void StageInit(void)
//{
//	int Result = 0;
//
//	//��̃u���b�N�𐶐����鏈��
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			if (g_Block[i][j].image == 0) {
//				g_Block[i][j].image = GetRand(7) + 1;
//			}
//		}
//	}
//	//�u���b�N�A���`�F�b�N
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			Result += RensaCheck(i, j);
//		}
//	}
//	if (Result == 0) {
//		//�Q�[�����C��������
//		g_GameState = GAME_MAIN;
//
//		//���x��
//		g_Level += 1;
//		//�~�b�V����
//		g_Mission += 1;
//		//��������
//		g_Time = TIMELIMIT;
//
//		//�J�E���g�z��̏�����
//		for (int i = 0; i < ITEM_MAX; i++) {
//			g_Item[i] = 0;
//		}
//	}
//}
//
///*************************************************
//*�אڂ��Ă��铯�F�̌��𒲂ׂ�i�T����ɏ����j
//* �����Fx�F���݂�X���W�A���F���݂�Y���W
//*�߂�l�F�P�c�R�ȏ�̘A���A�O�c�A������ 
//**************************************************/
//int RensaCheck(int y, int x)
//{
//	int CountH = 0;
//	int ColorH = 0;
//	SaveBlock();//�u���b�N���o�b�N�A�b�v����
//	RensaCheckH(y, x, &CountH, &ColorH);
//	if (CountH < 3) {
//		RestoreBlock();	//�u���b�N�̘A�����R�����Ȃ�u���b�N��߂�
//	}
//
//	int CountW = 0;
//	int ColorW = 0;
//	SaveBlock();	//�u���b�N���o�b�N�A�b�v����
//	RensaCheckW(y, x, &CountW, &ColorW);
//	if (CountW < 3) {
//		RestoreBlock();	//�u���b�N�̘A�����R�����Ȃ�u���b�N��߂�
//	}
//
//	if ((CountH >= 3 || CountW >= 3)) {
//		if (CountH >= 3) {
//			g_Item[ColorH - 1] += CountH;
//			g_Score += CountH * 10;
//			g_Time += 60;
//		}
//		if (CountW >= 3) {
//			g_Item[ColorW - 1] += CountW;
//			g_Score += CountW * 10;
//			g_Time += 60;
//		}
//		return 1;
//	}
//	return 0;
//}
//
///**************************************************
//*�c�̗אڂ��Ă��铯�F�̌��𒲂ׂ�i�T����ɏ����j
//*�����F���F�����W�A���F�����W�Acnt���Acol�F
//*�߂�l�F�c�̗אڂ��Ă��铯�F�̌�
//***************************************************/
//int RensaCheckH(int y, int x, int* cnt, int* col)
//{
//
//	//�Ώۃu���b�N���O�g�̏ꍇreturn�ŏ����𔲂���
//	if (g_Block[y][x].image == 0)return 0;
//
//	*col = g_Block[y][x].image;
//	int c = g_Block[y][x].image;	//�F���擾
//	g_Block[y][x].image = 0;
//	(*cnt)++;
//
//	if (g_Block[y + 1][x].image == c)RensaCheckH(y + 1, x, cnt, col);
//	if (g_Block[y - 1][x].image == c)RensaCheckH(y - 1, x, cnt, col);
//
//	return 0;
//}
//
///**************************************************
//*���̗אڂ��Ă��铯�F�̌��𒲂ׂ�i�T����ɏ����j
//*�����F���F�����W�A���F�����W�Acnt��,col�F
//*�߂�l�F���̗אڂ��Ă��铯�F�̌�
//***************************************************/
//int RensaCheckW(int y, int x, int* cnt, int* col)
//{
//
//	//�Ώۃu���b�N���O�g�̏ꍇreturn�ŏ����𔲂���
//	if (g_Block[y][x].image == 0)return 0;
//
//	*col = g_Block[y][x].image;
//	int c = g_Block[y][x].image;
//	g_Block[y][x].image = 0;
//	(*cnt)++;
//
//	if (g_Block[y][x + 1].image == c)RensaCheckW(y, x + 1, cnt, col);
//	if (g_Block[y][x - 1].image == c)RensaCheckW(y, x - 1, cnt, col);
//
//	return 0;
//}
//
///***************************************************
//*�u���b�N���o�b�N�A�b�v����
//****************************************************/
//void SaveBlock(void)
//{
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			g_Block[i][j].backup = g_Block[i][j].image;
//		}
//	}
//}
//
///***************************************************
//*�o�b�N�A�b�v�u���b�N��߂�
//****************************************************/
//void RestoreBlock(void)
//{
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			g_Block[i][j].image = g_Block[i][j].backup;
//		}
//	}
//}
//
///***************************************************
//*�u���b�N��I��
//****************************************************/
//void SelectBlock(void)
//{
//	static int ClickFlg = 0;
//
//	int SelectX = g_MouseX / BLOCKSIZE;
//	int SelectY = g_MouseY / BLOCKSIZE;
//
//	//�I���u���b�N�͈̔͂𐧌�
//	if (SelectX < 0)SelectX = 0;
//	if (SelectX > WIDTH - 3)SelectX = WIDTH - 3;
//	if (SelectY < 0)SelectY = 0;
//	if (SelectY > HEIGHT - 3)SelectY = HEIGHT - 3;
//
//	//�N���b�N�Ńu���b�N��I��
//	if (g_KeyFlg & MOUSE_INPUT_LEFT) {
//		//�N���b�N���̌��ʉ����Đ�
//		PlaySoundMem(g_ClickSE, DX_PLAYTYPE_BACK);
//		if (ClickFlg == 0) {
//			g_SelectX1 = SelectX;
//			g_SelectY1 = SelectY;
//			ClickFlg = 1;
////		}else if(ClickFlg==1){
//		}else if (ClickFlg == 1 && ((abs(g_SelectX1 - SelectX) == 1 && abs(g_SelectY1 - SelectY) == 0) || (abs(g_SelectX1 - SelectX) == 0 && abs(g_SelectY1 - SelectY) == 1))) {
//			g_SelectX2 = SelectX;
//			g_SelectY2 = SelectY;
//			ClickFlg = 2;
//		}
//	}
//	//�I���u���b�N��`��
//	DrawGraph(SelectX * BLOCKSIZE, SelectY * BLOCKSIZE, g_BlockImage[9], TRUE);
//	if (ClickFlg >= 1) {
//		DrawGraph(g_SelectX1 * BLOCKSIZE, g_SelectY1 * BLOCKSIZE, g_BlockImage[9], TRUE);
//	}
//	//�I���u���b�N������
//	if (ClickFlg == 2) {
//		int TmpBlock = g_Block[g_SelectY1 + 1][g_SelectX1 + 1].image;
//		g_Block[g_SelectY1 + 1][g_SelectX1 + 1].image = g_Block[g_SelectY2 + 1][g_SelectX2 + 1].image; 
//		g_Block[g_SelectY2 + 1][g_SelectX2 + 1].image = TmpBlock;
//		//���ɃN���b�N���ł���悤��ClickFlg���O�ɂ���
//		ClickFlg = 0;
//		//�A�����R�ȏォ�𒲂ׂ�
//		int Result = 0;
//		Result += RensaCheck(g_SelectY1 + 1, g_SelectX1 + 1);
//		Result += RensaCheck(g_SelectY2 + 1, g_SelectX2 + 1);
//
//		//�A�����R�����Ȃ�I���u���b�N�����ɖ߂�
//		if (Result == 0) {
//			int TmpBlock = g_Block[g_SelectY1 + 1][g_SelectX1 + 1].image;
//			g_Block[g_SelectY1 + 1][g_SelectX1 + 1].image = g_Block[g_SelectY2 + 1][g_SelectX2 + 1].image;
//			g_Block[g_SelectY2 + 1][g_SelectX2 + 1].image = TmpBlock;
//		}
//		else {
//			//�A�����R�ȏ�Ȃ�u���b�N�������A�u���b�N�ړ������ֈړ�����
//			g_Status = 2;
//		}
//		//���ɃN���b�N���ł���悤�ɁAClickFlg���O�ɂ���B
//		ClickFlg = 0;
//	}
//}
//
///**************************************************
//*�u���b�N�ړ�
//****************************************************/
//void MoveBlock(void)
//{
//	//�u���b�N�ړ������ʉ����Đ�
//	PlaySoundMem(g_MoveBlockSE, DX_PLAYTYPE_BACK);
//	//���ֈړ����鏈��
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			if (g_Block[i][j].image == 0) {
//				for (int k = i; k > 0; k--) {
//					g_Block[k][j].image = g_Block[k - 1][j].image;
//					g_Block[k - 1][j].image = 0;
//				}
//			}
//		}
//	}
//	//��̃u���b�N�𐶐����鏈��
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			if (g_Block[i][j].image == 0) {
//				g_Block[i][j].image = GetRand(7) + 1;
//			}
//		}
//	}
//
//	//�u���b�N�I�������ֈړ�����
//	//g_Status = 0;
//
//	//�u���b�N�A���`�F�b�N�����ֈړ�����
//	g_Status = 3;
//}
//
///***************************************************
//*�u���b�N�A���`�F�b�N
//****************************************************/
//void CheckBlock(void)
//{
//	int Result = 0;
//
//	//�u���b�N�A���`�F�b�N
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			Result += RensaCheck(i, j);
//		}
//	}
//
//	//�A�����Ȃ��Ȃ�΁A�u���b�N�I���ֈڍs����
//	//�����łȂ���΁A�u���b�N�ړ��ֈڍs���ĘA���`�F�b�N���p������
//	if (Result == 0) {
//		//�u���b�N�I�������ֈڍs����
//		//g_Status = 0;
//
//		//�N���A�����̃`�F�b�N�����ֈڍs����
//		g_Status = 4;
//	}else {
//		//�A�����R�ȏ�Ȃ�u���b�N�������A�u���b�N�ړ������ֈڍs����
//		g_Status = 2;
//	}
//}
//
///***************************************************
//*��������u���b�N���t�F�[�h�A�E�g����
//*****************************************************/
//void FadeOutBlock(void)
//{
//	//�t�F�[�h�A�E�g�����ʉ����Đ�
//	if (CheckSoundMem(g_FadeOutSE) == 0) {
//		PlaySoundMem(g_FadeOutSE, DX_PLAYTYPE_BACK);
//	}
//	static int BlendMode = 255;
//	//�`��u�����h���[�h���A���t�@�u�����h�ɂ���
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendMode);
//	for (int i = 1; i < HEIGHT - 1; i++) {
//		for (int j = 1; j < WIDTH - 1; j++) {
//			if (g_Block[i][j].image == 0) {
//				DrawGraph(g_Block[i][j].x, g_Block[i][j].y, g_BlockImage[g_Block[i][j].backup], TRUE);
//			}
//		}
//	}
//	//�`��u�����h���[�h���m�[�u�����h�ɂ���
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//
//	BlendMode -= 5;
//	if (BlendMode <= 0) {
//		BlendMode = 255;
//		g_Status = 2;
//		//�t�F�[�h�A�E�g�����ʉ����Đ�
//		StopSoundMem(g_FadeOutSE);
//	}
//}
///***************************************************
//*�摜�ǂݍ���
//*****************************************************/
//int LoadImages(void)
//{
//	//�^�C�g��
//	if ((g_TitleImage = LoadGraph("images/title.png")) == -1)return -1;
//	//�X�e�[�W�摜�̓ǂݍ���
//	if ((g_StageImage = LoadGraph("images/stage.png")) == -1)return -1;
//	//�Q�[���N���A�摜�̓ǂݍ���
//	if ((g_GameClearImage = LoadGraph("images/gameclear.png")) == -1)return -1;
//	//�Q�[���I�[�o�[�摜�ǂݍ���
//	if ((g_GameOverImage = LoadGraph("images/gameover.png")) == -1)return -1;
//	if(LoadDivGraph("images/number.png", 10, 10, 1, 60, 120,g_NumberImage)== -1)return -1;
//	//�u���b�N�摜�̓ǂݍ��݁i�����ǂݍ��݁j
//	if (LoadDivGraph("images/block.png", 10, 10, 1, 48, 48, g_BlockImage) == -1)return -1;
//	return 0;
//}
//
///************************************************
//*�T�E���h�ǂݍ���
//*************************************************/
//int LoadSounds(void)
//{
//	//�^�C�g��BGM
//	if ((g_TitleBGM = LoadSoundMem("sounds/muci_hono_r01.mp3")) == -1)return -1;
//	//�Q�[���N���A
//	if ((g_GameClearSE = LoadSoundMem("sounds/muci_fan_06.mp3")) == -1)return -1;
//	//�Q�[���I�[�o�[
//	if ((g_GameOverSE = LoadSoundMem("sounds/muci_bara_07.mp3")) == -1)return -1;
//	//�}�E�X�N���b�N���ʉ�
//	if ((g_ClickSE = LoadSoundMem("sounds/ta_ta_warekie02.mp3")) == -1)return -1;
//	//�u���b�N�������ʉ�
//	if ((g_FadeOutSE = LoadSoundMem("sounds/ani_ta_biyon02.mp3")) == -1)return -1;
//	//�u���b�N�ړ������ʉ�
//	if ((g_MoveBlockSE = LoadSoundMem("sounds/ta_ta_doron01.mp3")) == -1)return -1;
//	
//	return 0;
//}