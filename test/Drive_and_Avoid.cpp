/***********************************************************
**    ��5�́@�~�j�Q�[��������i�Q�j
**�@�@�@�@�@�@�@���[�X�������Q�[
************************************************************/
#include"DxLib.h"
#include"Common.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
#include"TITLE.h"
#include"POSE.h"
#include"RANKING.h"
#include"InputRANKING.h"
#include"DrawRANKING.h"
#include"Common.h"
#include"Help.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int g_KeyFLG = TRUE;	//���̓L�[���
int ButtonFLG = FALSE;

int g_GameState = 0;	//�Q�[�����[�h

int g_Menu;		//���j���[�摜�ϐ�

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
int g_SE3;

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
int color_white;
double Fps = 0.0;

int x;
int x_flg = TRUE;

/***************************************************
*�֐��̃v���g�^�C�v�錾
****************************************************/
void GameInit(void);	//�Q�[������������
void GameMain(void);	//�Q�[�����C������
void DrawEnd(void);//�Q�[���G���h�`�揈��

int LoadImages(); //�摜�ǂݍ���

void DrawBackGround();		//�w�i�摜�X�N���[������

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



	if ((drawranking.RankingImage = LoadGraph("images/BackGround_ranking2.png")) == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);			//�`����ʂ𗠂ɂ���
	SetColor();

	if (LoadImages() == -1)return -1;		//�摜�ǂݍ��݊֐����Ăяo��

	if (LoadSounds() == -1)return -1;		//�T�E���h�ǂݍ��݊֐����Ăяo��

	if (ranking.ReadRanking() == -1) return -1;		//�����L���O�f�[�^�̓ǂݍ���

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != 99 && !input.Buttons[XINPUT_BUTTON_BACK]) {
		RefreshTime = GetNowCount();
		
		GetJoypadXInputState(DX_INPUT_PAD1, &input);

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
			drawranking.DrawRanking();			//�����L���O�`�揈��
			break;
		case 3:
			help.DrawHelp();				//�Q�[���w���v�`�揈��
			break;
		case 4:
			DrawEnd();				//�Q�[���G���h�`�揈��
			break;
		case 5:
			GameMain();				//�Q�[�����C������
			break;
		case 6:
			inputranking.InputRanking();			//�����L���O���͏���
			break;
		case 7:
			pose.DrawPose();
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
	pose.initPose();
	AppleCount1 = 0;
	AppleCount2 = 0;
	AppleCount3 = 0;
	

	Time = GetNowCount();
	

	//�Q�[�����C��������
	g_GameState = 5;

	//�����̏����ݒ�

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

}

/******************************************
*�w�i�摜�`�揈��
*���@���F�Ȃ�
*�߂�l�F�Ȃ�
********************************************/
void DrawBackGround()
{
	DrawBox(0, 0, 640, 480, GetColor(143, 188, 143), TRUE);
	DrawGraph(0, 0, g_StageImage, FALSE);		//�摜�F��490+150(�X�R�A�\����)=640:�c480
}

/***************************************
*�T�E���h�ǂݍ���
****************************************/
int LoadSounds()
{
	if ((title.g_TitleBGM = LoadSoundMem("sounds/Title.wav")) == -1)return -1;
	if ((g_MusicBGM = LoadSoundMem("sounds/Playing.wav")) == -1)return -1;
	
	
	ChangeVolumeSoundMem(130, title.g_TitleBGM);
	
	//SE �f�[�^�ǂݍ���
	if ((g_SE1 = LoadSoundMem("sounds/SE01.wav")) == -1)return -1;
	if ((g_SE2 = LoadSoundMem("sounds/SE02.wav")) == -1)return -1;
	if ((g_SE3 = LoadSoundMem("sounds/SE03.wav")) == -1)return -1;

	//SE�̉��ʒ���
	ChangeVolumeSoundMem(255, g_SE1);
	ChangeVolumeSoundMem(255, g_SE2);
	ChangeVolumeSoundMem(255, g_SE3);

	return 0;
}
/****************************************
*�摜�ǂݍ���
*****************************************/
int LoadImages()
{
	//�^�C�g��
	if ((title.g_TitleImage = LoadGraph("images/BackGround_title.png")) == -1)return -1;
	if ((help.g_HelpImage = LoadGraph("images/BackGround_help.png")) == -1)return -1;
	//���j���[
	if ((title.g_CursorImage = LoadGraph("images/cursor.png")) == -1)return -1;
	//�����S
	if ((Apple_Img[0] = LoadGraph("images/RedApple.png")) == -1)return -1;
	if ((Apple_Img[1] = LoadGraph("images/GreenApple.png")) == -1)return -1;
	if ((Apple_Img[2] = LoadGraph("images/YellowApple.png")) == -1)return -1;
	if ((Apple_Img[3] = LoadGraph("images/PurpleApple.png")) == -1)return -1;

	//�X�e�[�W�w�i
	if ((g_StageImage = LoadGraph("images/BackGround.png")) == -1)return -1;
	if ((inputranking.g_InputRankingImage = LoadGraph("images/BackGround_ranking.png")) == -1)return -1;
	//�v���C���[
	if ((g_Car_left = LoadGraph("images/PlayerA.png")) == -1)return -1;
	if ((g_Car_right = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Car_Nowangle = LoadGraph("images/PlayerA_2.png")) == -1)return -1;

	return 0;
}