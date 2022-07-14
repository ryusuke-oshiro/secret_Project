/***********************************************************
**    ��5�́@�~�j�Q�[��������i�Q�j
**�@�@�@�@�@�@�@���[�X�������Q�[
************************************************************/
#include"DxLib.h"
#include"Common.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define RANKING_DATA 5
#include"PLAYER.h"
#include"APPLE.h"
#include"TITLE.h"
#include"Common.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int g_KeyFLG = TRUE;	//���̓L�[���


int g_OldKey;
int g_NowKey;
int g_KeyFlg;

int g_GameState = 0;	//�Q�[�����[�h

/*int g_TitleImage;*/		//�摜�p�ϐ�
int g_Menu, g_Cone;		//���j���[�摜�ϐ�

int g_Score = 0;		//�X�R�A

int g_RankingImage;		//�摜�p�ϐ�

int g_WaitTime = 0;

int g_WaitCount = 0;

int Time = 0;     //�҂�����
int StartTime;
int RefreshTime;

int g_EndImage;        //�G���h���

int g_Mileage;          //���s����

int Apple_Img[4]; //�����S�`��ϐ�
int g_Item[2];    //�A�C�e���摜�ϐ�
int g_Teki[3];    //�L�����摜�ϐ�

int g_StageImage;//�X�e�[�W�摜

int AppleCount1, AppleCount2, AppleCount3, AppleCount4; //�����S�J�E���g

int g_Car_left, g_Car_right, g_Car_Nowangle, g_Barrier;	//�L�����摜�ϐ�

int g_TitleBGM;
int g_MusicBGM;	//�X�e�[�W����
int g_GameOverSE;
int g_SE1;
int g_SE2;

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
int color_white;
double Fps = 0.0;

int x;
int x_flg = TRUE;

//�����L���O�f�[�^�i�\���́j
struct RankingData {
	int no;
	char name[11];
	long score;
};
//�����L���O�f�[�^�ϐ��錾
struct RankingData g_Ranking[RANKING_DATA];

/***************************************************
*�֐��̃v���g�^�C�v�錾
****************************************************/
void GameInit(void);	//�Q�[������������
void GameMain(void);	//�Q�[�����C������

void DrawGameTitle(void);//�^�C�g���`�揈��
void DrawGameOver(void);//�Q�[���I�[�o�[��ʕ`�揈��
void DrawEnd(void);//�Q�[���G���h�`�揈��
void DrawHelp(void);//�Q�[���w���v�`�揈��

void DrawRanking(void);//�����L���O�`�揈��
void InputRanking(void);//�����L���O����

int LoadImages(); //�摜�ǂݍ���

void SortRanking(void);	//�����L���O���ёւ�
int SaveRanking(void);	//�����L���O�f�[�^�̕ۑ�
int ReadRanking(void);	//�����L���O�f�[�^�ǂݍ���

void DrawBackGround();		//�w�i�摜�X�N���[������

int LoadSounds();	//�X�e�[�W

int LoadSounds();	//�X�e�[�W

void SetColor();
void FpsTimeFanction();

/****************************************************
*�v���O�����̊J�n
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{

	SetMainWindowText("Drive&Avoid");		//�^�C�g����ݒ�

	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1)return -1;		//DX���C�u�����̏���������



	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);			//�`����ʂ𗠂ɂ���
	SetColor();

	if (LoadImages() == -1)return -1;		//�摜�ǂݍ��݊֐����Ăяo��

	if (LoadSounds() == -1)return -1;		//�T�E���h�ǂݍ��݊֐����Ăяo��

	if (ReadRanking() == -1) return -1;		//�����L���O�f�[�^�̓ǂݍ���

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
		RefreshTime = GetNowCount();
		//���̓L�[�擾
		/*g_OldKey = g_NewKey;*/
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		

		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();			//��ʂ̏�����
		FpsTimeFanction();

		switch (g_GameState) {
		case 0:
			title.DrawGameTitle();		//�Q�[���^�C�g���`�揈��
			break;
		case 1:
			GameInit();				//�Q�[����������
			break;
		case 2:
			DrawRanking();			//�����L���O�`�揈��
			break;
		case 3:
			DrawHelp();				//�Q�[���w���v�`�揈��
			break;
		case 4:
			DrawEnd();				//�Q�[���G���h�`�揈��
			break;
		case 5:
			GameMain();				//�Q�[�����C������
			break;
		case 6:
			DrawGameOver();			//�Q�[���I�[�o�[�`�揈��
			break;
		case 7:
			InputRanking();			//�����L���O���͏���
			break;
		}
		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f
		while (GetNowCount() - RefreshTime < 17);
	}
	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;	//�\�t�g�̏I��
}


void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fps��\��
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //���F�n���h�����擾
	return;
}
///*********************************************
//*�Q�[���^�C�g���\���i���j���[��ʁj
//**********************************************/
//void DrawGameTitle(void)
//{
//	static int MenuNo = 0;
//	
//		if (x_flg == TRUE) {
//			++x;
//		}
//		else {
//			--x;
//		}
//			if (x >= 10) {
//				for (int j = 0; j <= 10; j++) {
//					x = 10;
//				}
//				x_flg = FALSE;
//			}
//			if (x <= -10) {
//				for (int k = 0; k <= 10; k++) {
//					x = -10;
//				}
//				x_flg = TRUE;
//			}
//
//
//	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK, FALSE);
//
//	//���j���[�J�[�\���ړ�����
//	if (input.ThumbLY <= -15000) {
//		if (g_KeyFLG == TRUE) { 
//			PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE); 
//			++MenuNo;
//			if (MenuNo > 3) {
//				MenuNo = 0;
//			}
//			g_KeyFLG = FALSE;
//		}
//		++g_WaitCount;
//		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
//	}
//	if (input.ThumbLY >= 15000) {
//		if (g_KeyFLG == TRUE) {
//			PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
//			--MenuNo;
//			if (MenuNo < 0) {
//				MenuNo = 3;
//			}
//			g_KeyFLG = FALSE;
//		}
//		++g_WaitCount;
//		if (g_WaitCount >= 30) { g_KeyFLG = TRUE; g_WaitCount = 0; }
//	}
//	if (input.ThumbLY > -15000 && input.ThumbLY < 15000) {
//		g_KeyFLG = TRUE; g_WaitCount = 0;
//	}
//	//Z�L�[�Ń��j���[�I��
//	if (input.Buttons[12] == 1) {
//		StopSoundMem(g_TitleBGM);
//		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
//		g_GameState = MenuNo + 1;
//	}
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//���j���[�J�[�\��
//	DrawRotaGraph(150 + x, 240 + MenuNo * 50, 0.7f, M_PI / 2, g_Cone, TRUE);
//
//}
/********************************************
*�Q�[������������
*********************************************/
void GameInit(void)
{
	//�X�R�A�̏�����
	g_Score = 0;

	//���s������������
	g_Mileage = 0;
	g_player.InitPlayer();
	apple.InitApple();

	Time = GetNowCount();
	

	//�Q�[�����C��������
	g_GameState = 5;

	//�����̏����ݒ�


	//�G�l�~�[�̏����ݒ�
	/*for (int i = 0; i < Apple_MAX; i++) {
		g_apple[i].flg = FALSE;
	}*/

}
/*******************************************
*�Q�[�������L���O�`�揈��
********************************************/
void DrawRanking(void)
{
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M) g_GameState = 0;

	//�����L���O�摜���� 
	//�����L���O�摜����
	DrawGraph(0, 0, g_RankingImage, FALSE);

	//�����L���O�ꗗ��\��
	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	DrawString(100, 450, "----�X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);

}
/*******************************************
*�Q�[���w���v�`�揈��
********************************************/
void DrawHelp(void)
{
	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;

	//�^�C�g���摜�\��
	DrawGraph(0, 0, title.g_TitleImage, FALSE);
	SetFontSize(16);
	DrawString(20, 120, "�w���v���", 0xffffff, 0);

	DrawString(20, 160, "����͏�Q��������Ȃ���", 0xffffff, 0);
	DrawString(20, 180, "���葱����Q�[���ł�", 0xffffff, 0);
	DrawString(20, 200, "�R�����s���邩��Q����", 0xffffff, 0);
	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł�", 0xffffff, 0);
	DrawString(20, 250, "�A�C�e���ꗗ", 0xffffff, 0);
	DrawGraph(20, 260, g_Item[0], TRUE);
	DrawString(20, 315, "���ƔR�����񕜂����", 0xffffff, 0);
	DrawGraph(20, 335, g_Item[1], TRUE);
	DrawString(20, 385, "�_���[�W���󂯂Ă���Ƃ��Ɏ��Ƒϋv��", 0xffffff, 0);
	DrawString(20, 405, "�ϋv�������Ă��Ȃ�������R���������񕜂����", 0xffffff, 0);
	DrawString(20, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);
}
/*******************************************
*�Q�[���G���h�`�揈��
********************************************/
void DrawEnd(void)
{
	//�G���h�摜�\��
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//�^�C���̉��Z�������I���i�R�b��j
	if (++g_WaitTime > 180)g_GameState = 99;
}
/******************************************
*�Q�[�����C��
******************************************/
void GameMain(void)
{
		PlaySoundMem(g_MusicBGM, DX_PLAYTYPE_LOOP, FALSE);

		DrawBackGround();

		apple.AppleControl();

		g_player.PlayerControl();


	

	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 6;

	SetFontSize(16);
	DrawString(20, 20, "�Q�[�����C��", 0xffffff, 0);
	DrawString(150, 450, "---- �X�y�[�X�L�[�������ăQ�[���I�[�o�[�� ----", 0xffffff, 0);
}



/******************************************
*�w�i�摜�X�N���[������
*���@���F�Ȃ�
*�߂�l�F�Ȃ�
********************************************/
void DrawBackGround()
{
	

	DrawGraph(0, 0, g_StageImage, FALSE);		//�摜�F��490+150(�X�R�A�\����)=640:�c480

	
}

/***************************************
*�Q�[���I�[�o�[��ʕ`�揈��
****************************************/
void DrawGameOver(void)
{
	PlaySoundMem(g_GameOverSE, DX_PLAYTYPE_BACK, FALSE);
	g_Score = (g_Mileage / 10 * 10) + AppleCount3 * 50 + AppleCount1 * 200;

	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M) {
		if (g_Ranking[RANKING_DATA].score >= g_Score) {
			g_GameState = 0;
		}
		else {
			g_GameState = 7;
		}
	}

	DrawBox(150, 150, 490, 330, 0x009900, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", 0xcc0000);
	SetFontSize(16);
	DrawString(180, 200, "���s�����@�@�@", 0x000000);
	DrawRotaGraph(230, 230, 0.3f, M_PI / 2, g_Teki[2], TRUE, FALSE);

	DrawRotaGraph(230, 250, 0.3f, M_PI / 2, g_Teki[1], TRUE, FALSE);

	DrawRotaGraph(230, 270, 0.3f, M_PI / 2, g_Teki[0], TRUE, FALSE);

	DrawFormatString(260, 200, 0xFFFFFF, "%6d x  10 = %6d", g_Mileage / 10, g_Mileage / 10 * 10);

	DrawFormatString(260, 222, 0xFFFFFF, "%6d x  50 = %6d", AppleCount3, AppleCount3 * 50);

	DrawFormatString(260, 243, 0xFFFFFF, "%6d x  100 = %6d", AppleCount2, AppleCount2 * 100);

	DrawFormatString(260, 264, 0xFFFFFF, "%6d x  200 = %6d", AppleCount1, AppleCount1 * 200);

	DrawString(310, 290, "�X�R�A", 0x000000);

	DrawFormatString(260, 290, 0xFFFFFF, "          =%6d", g_Score);

	DrawString(150, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);

}
/****************************************
*�����L���O���͏���
****************************************/
void InputRanking(void)
{
	//�����L���O�摜�\��
	DrawGraph(0, 0, g_RankingImage, FALSE);

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);

	// ���O���͎w��������̕`��
	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);

	// ���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[RANKING_DATA].name, FALSE) == 1) {
		g_Ranking[RANKING_DATA].score = g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
		SortRanking();		// �����L���O���בւ�
		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
		g_GameState = 2;		// �Q�[�����[�h�̕ύX
	}
}
/************************************************:
*�����L���O���ёւ�
***********************************************/
void SortRanking(void) {
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}
/****************************************
*�����L���O�f�[�^�ۑ�
*****************************************/
int SaveRanking(void) {

	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;

}
/*****************************************
*�����L���O�f�[�^�ǂݍ���
******************************************/
int ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}
/***************************************
*�T�E���h�ǂݍ���
****************************************/
int LoadSounds()
{
	if ((title.g_TitleBGM = LoadSoundMem("sounds/Initial D - Night Of Fire.mp3")) == -1)return -1;
	//initial D����
	if ((g_MusicBGM = LoadSoundMem("sounds/Daisuke full ver. (�̎��E�a��t��).mp3")) == -1)return -1;
	if ((g_GameOverSE = LoadSoundMem("sounds/GameOver.mp3")) == -1)return -1;

	//SE1 �f�[�^�ǂݍ���
	if ((g_SE1 = LoadSoundMem("sounds/SE1.mp3")) == -1)return -1;
	//SE2 �f�[�^�ǂݍ���
	if ((g_SE2 = LoadSoundMem("sounds/SE2.mp3")) == -1)return -1;


	//SE�̉��ʒ���
	ChangeVolumeSoundMem(80, g_SE2);

	ChangeVolumeSoundMem(120, g_SE1);

	return 0;
}
/****************************************
*�摜�ǂݍ���
*****************************************/
int LoadImages()
{
	//�^�C�g��
	if ((title.g_TitleImage = LoadGraph("images/BackGround_title.png")) == -1)return -1;
	//���j���[
	if ((g_Cone = LoadGraph("images/cone.bmp")) == -1)return -1;
	//�����S
	if ((Apple_Img[0] = LoadGraph("images/RedApple.png")) == -1)return -1;
	if ((Apple_Img[1] = LoadGraph("images/GreenApple.png")) == -1)return -1;
	if ((Apple_Img[2] = LoadGraph("images/YellowApple.png")) == -1)return -1;
	if ((Apple_Img[3] = LoadGraph("images/PurpleApple.png")) == -1)return -1;
	//�A�C�e��
	if ((g_Item[0] = LoadGraph("images/gasoline.bmp")) == -1)return -1;
	if ((g_Item[1] = LoadGraph("images/supana.bmp")) == -1)return -1;
	
	//�X�e�[�W�w�i
	if ((g_StageImage = LoadGraph("images/BackGround.png")) == -1)return -1;
	//�v���C���[
	if ((g_Car_left = LoadGraph("images/PlayerA.png")) == -1)return -1;
	if ((g_Car_right = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Car_Nowangle = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Barrier = LoadGraph("images/barrier.png")) == -1)return -1;

	return 0;
}