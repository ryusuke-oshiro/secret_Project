///********************************************************************
//**	��S�́@�Q�[���v���O���~���O�̊�{
//**	�@�u���b�N�����Q�[���̍쐬(2018)
//********************************************************************/
//#include "DxLib.h"
//#define _USE_MATH_DEFINES
//#include<math.h>
//#include"Ball.h"
//#include"Bar.h"
//#include"Rank.h"
//#include"DrawGame.h"
//#include"Block.h"
//
//#define HEIGHT 10
//#define WIDTH 16
//#define STAGE 5
//
//
///***********************************************
// * �ϐ��̐錾
// ***********************************************/
//int	g_OldKey;				// �O��̓��̓L�[
//int	g_NowKey;				// ����̓��̓L�[
////int	g_KeyFlg;				// ���̓L�[���
//
////int	g_MenuNumber = 0;		// ���j���[�J�[�\���ʒu
///*int g_MenuY;*/				// ���j���[�J�[�\���̂x���W
//
////int	g_TitleImage;			// �摜�p�ϐ�
////int	g_RankingImage;			// �摜�p�ϐ�
////int	g_EndImage;				// �摜�p�ϐ�
//
////int	g_WaitTime = 0;			// �҂�����
///*int g_PosY;*/					// �X�N���[�����̂x���W
//
////int	g_Score = 0;			// �X�R�A
////
////int	g_GameState = 0;		// �Q�[���X�e�[�^�X
//
//
///*int g_BallX, g_BallY;*/				//�{�[���̍��W
//
////int g_MoveX, g_MoveY;				//�{�[���̈ړ���
////
////int g_Speed;				//�{�[���̃X�s�[�h
///*float g_BallAngle;*/			//�{�[���̊p�x
//
////int g_BarX;					//�o�[�̍��W
////int g_BarY;
//
////int g_MouseX, g_MouseY;		//�}�E�X�̍��W
//
///*int g_BallFlg;*/				//�{�[���̏�ԁi0...�ړ����@1...�o�[�ڐG�j
//
////int g_BlockImage[8]; //�u���b�N�摜�p�ϐ�
//
////int g_RestBall;		//�c��{�[������
//
///*int g_Stage = 0;*/	//�X�e�[�W�p�ϐ�
//
////  �����̐F�́@��(0)�@��(1)�@��(2)�@ ���F(3)�@�@��(4)�@�s���N(5)�@���F(6)�@�@��(7)
////  �����Ӂ����̓u���b�N�Ȃ�
//
////int	g_BlockData[STAGE][HEIGHT][WIDTH] = {	// �u���b�N�z��
////	{	// 0�ð��
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
////		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
////	},
////	{	// 1�ð��
////		{ 0 , 0 , 0 , 0 , 0 , 0 , 2 , 2 , 2 , 2 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 2 , 3 , 3 , 3 , 3 , 2 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 2 , 2 , 3 , 4 , 4 , 4 , 4 , 3 , 2 , 2 , 0 , 0 , 0 },
////		{ 0 , 2 , 2 , 3 , 3 , 4 , 5 , 5 , 5 , 5 , 4 , 3 , 3 , 2 , 2 , 0 },
////		{ 2 , 3 , 3 , 4 , 4 , 5 , 0 , 0 , 0 , 0 , 5 , 4 , 4 , 3 , 3 , 2 },
////		{ 2 , 3 , 3 , 4 , 4 , 5 , 0 , 0 , 0 , 0 , 5 , 4 , 4 , 3 , 3 , 2 },
////		{ 0 , 2 , 2 , 3 , 3 , 4 , 5 , 5 , 5 , 5 , 4 , 3 , 3 , 2 , 2 , 0 },
////		{ 0 , 0 , 0 , 2 , 2 , 3 , 4 , 4 , 4 , 4 , 3 , 2 , 2 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 2 , 3 , 3 , 3 , 3 , 2 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 0 , 2 , 2 , 2 , 2 , 0 , 0 , 0 , 0 , 0 , 0 }
////	},
////	{	// 2�ð��
////		{ 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 },
////		{ 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 },
////		{ 0 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 0 },
////		{ 0 , 0 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 0 , 0 },
////		{ 0 , 0 , 0 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 4 , 4 , 4 , 4 , 4 , 4 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 3 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 3 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
////	},
////	{	// 3�ð��
////		{ 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 0 , 0 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 0 , 0 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 7 , 7 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 7 , 7 , 0 },
////		{ 0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 7 , 7 , 0 }
////	},
////	{	// 4�ð��
////		{ 7 , 1 , 0 , 0 , 1 , 7 , 3 , 3 , 3 , 0 , 7 , 0 , 4 , 4 , 0 , 7 },
////		{ 7 , 1 , 0 , 1 , 1 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 4 , 4 , 4 , 7 },
////		{ 7 , 1 , 1 , 1 , 0 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 0 , 0 , 4 , 7 },
////		{ 7 , 1 , 1 , 0 , 0 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 0 , 0 , 0 , 7 },
////		{ 7 , 1 , 0 , 0 , 0 , 7 , 3 , 3 , 3 , 0 , 7 , 4 , 0 , 0 , 0 , 7 },
////		{ 7 , 1 , 1 , 0 , 0 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 0 , 0 , 0 , 7 },
////		{ 7 , 1 , 1 , 1 , 0 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 0 , 0 , 4 , 7 },
////		{ 7 , 1 , 0 , 1 , 1 , 7 , 3 , 0 , 0 , 3 , 7 , 4 , 4 , 4 , 4 , 7 },
////		{ 7 , 1 , 0 , 0 , 1 , 7 , 3 , 3 , 3 , 0 , 7 , 0 , 4 , 4 , 0 , 7 },
////		{ 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 }
////	}
////};
//
//
//// �����L���O�f�[�^�i�\���́j
////struct	RankingData {
////	int		no;
////	char	name[11];
////	long	score;
////};
//// �����L���O�f�[�^�ϐ��錾
////struct	RankingData		g_Ranking[10];
//
////�u���b�N�f�[�^�i�\���̂̒�`�j
////struct ObjectBlock {
////	int flg;
////	int x, y;
////	int w, h;
////	int mx, my;
////	int image;
////	int score;
////};
//////�u���b�N�f�[�^�̐錾
////struct ObjectBlock g_Block[HEIGHT][WIDTH];
//
///***********************************************
// * �֐��̃v���g�^�C�v�錾
// ***********************************************/
//void GameInit(void);//�Q�[������������
//void GameMain(void);//�Q�[�����C������
//
////void DrawGameTitle(void);	//�Q�[���^�C�g������
////void DrawEnd(void);			//�Q�[���G���h����
//
///*void DrawBall(void);*/		//�{�[���̕`��
///*void DrawBar(void);*///�o�[�̕`�揈��
///*void MoveBall(void);*/		//�{�[���̈ړ�
///*void DrawRanking(void);	*/	//�����L���O�`��
////void InputRanking(void);	//�����L���O����
////void SortRanking(void);		//�����L���O���בւ�
////int  SaveRanking(void);		//�����L���O�f�[�^�̕ۑ�
////int  ReadRanking(void);		//�����L���O�f�[�^�ǂݍ���
////void DrawGameOver(void);  //�Q�[���I�[�o�[�`�揈��
////void DrawGameClear(void);//�Q�[���N���A�`�揈��
///*void ChangeAngle(void);*///�p�x�ύX����
///*void InitBlock(void);*///�u���b�N��������
////void MoveBar(void);//�o�[�̈ړ�����
////void HitBar(void);//�{�[���ƃo�[�̓����蔻��
///*void HitBlock(void);*///�{�[���ƃu���b�N�̓����蔻��
///*void DrawBlock(void);*///�{�[���`�揈��
///*void DrawScore(void);*///�X�R�A�`�揈��
///*int CheckBlock(void);*///�u���b�N�`�F�b�N����
//
///***********************************************
// * �v���O�����̊J�n
// ***********************************************/
//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
//										 LPSTR lpCmdLine, int nCmdShow )
//{
//
//	// �^�C�g���� test �ɕύX
//	SetMainWindowText("�u���b�N����");
//
//	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��
//
//	if ( DxLib_Init() == -1 ) return -1;	// DX���C�u�����̏���������
//	
//	//�^�C�g���摜�f�[�^�̓ǂݍ���
//	if((dg.g_TitleImage = LoadGraph("images/Title.bmp")) == -1) return -1;
//	//�����L���O�摜�f�[�^�̓ǂݍ���
//	if((dg.g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
//	//�G���h�摜�f�[�^�̓ǂݍ���
//	if((dg.g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
//
//	if  ( rank.ReadRanking() == -1  )  return  -1;    //�����L���O�f�[�^�̓ǂݍ���
//	
//	SetDrawScreen( DX_SCREEN_BACK );	// �`����ʂ𗠂ɂ���
//	
//	SetFontSize( 20 );		// �����T�C�Y��ݒ�
//
//	//�u���b�N�摜�f�[�^�̓ǂݍ���
//	if (LoadDivGraph("images/block.bmp", 8, 8, 1, 40, 8, block.g_BlockImage) == -1)return -1;
//
//	// �Q�[�����[�v
//	while ( ProcessMessage() == 0 && dg.g_GameState != 99){
//
//		// ���̓L�[�擾
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
//		dg.g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// ��ʂ̏�����
//
//		switch (dg.g_GameState){
//			case 0:
//				dg.DrawGameTitle();	//�Q�[���^�C�g������
//				break;
//			case 1:
//				GameInit();		//�Q�[����������
//				break;
//			case 2:
//				rank.DrawRanking();	//�����L���O�`�揈��
//				break;
//			case 3:
//				dg.DrawEnd();		//�G���h��ʕ`�揈��
//				break;
//			case 4:
//				GameMain();		//�Q�[�����C������
//				break;
//			case 5:
//				dg.DrawGameOver(); //�Q�[���I�[�o�[�`�揈��
//				break;
//			case 6:
//				dg.DrawGameClear();//�Q�[���N���A�`�揈��
//				break;
//			case 7:
//				rank.InputRanking(); //�����L���O���͏���
//				break;
//		}
//
//		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
//
//	}
//
//	DxLib_End();	// DX���C�u�����g�p�̏I������
//	
//	return 0;	// �\�t�g�̏I��
//}
//
///***********************************************
// * �Q�[����������
// ***********************************************/
//
//void GameInit(void)
//{
//	/*�ϐ��̏����ݒ�*/
//	/*ball.g_BallX = 320;
//	ball.g_BallY = 440 - 5;*/
//	/*bar.g_BarX = 290;
//	bar.g_BarY = 440;*/
//	ball.g_MoveX = 1;
//	ball.g_MoveY = -2;
//	dg.g_GameState = 4;	// �Q�[�����C��������
//	ball.g_RestBall = 2;		//�c��{�[���̐ݒ�
//	block.InitBlock();
//}
//
//
///***********************************************
// * �Q�[�����C��
// ***********************************************/
//void GameMain(void)
//{
//
//	bar.MoveBar();//�o�[�̈ړ�����
//	ball.MoveBall();//�{�[���̈ړ�
//	bar.HitBar();//�{�[���ƃo�[�̓����蔻��
//	ball.HitBlock();//�{�[���ƃu���b�N�̓����蔻��
//	ball.DrawBall();
//	bar.DrawBar();//�o�[�̕`��
//	block.DrawBlock();//�u���b�N��`�悷��
//	block.DrawScore();//�X�R�A��`�悷��
//}
//
///***********************************************
// * �����L���O�`�揈��
// ***********************************************/
////void DrawRanking(void)
////{
////	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
////	if(g_KeyFlg & PAD_INPUT_M) g_GameState = 0;
////
////	//�����L���O�摜�\��
////	DrawGraph( 0 , 0 , g_RankingImage , FALSE ) ;
////
////	// �����L���O�ꗗ��\��
////	SetFontSize(30);
////	for( int i=0; i<10; i++ ){
////		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
////							 g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
////	}
////
////	// �����̕\��(�_��)
////	if ( ++g_WaitTime < 30 ){
////		SetFontSize(24);
////		DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);
////	} else if ( g_WaitTime > 60 ){
////		g_WaitTime = 0;
////	}
////
////}
//
///***********************************************
// * �����L���O���͏���
// ***********************************************/
////void InputRanking(void)
////{
////	//�����L���O�摜�\��
////	DrawGraph( 0 , 0 , g_RankingImage, FALSE );
////
////	// �t�H���g�T�C�Y�̐ݒ�
////	SetFontSize(20);
////
////	// ���O���͎w��������̕`��
////	DrawString( 150 , 240 , "�����L���O�ɓo�^���܂�" , 0xFFFFFF ) ;
////	DrawString( 150 , 270 , "���O���p���œ��͂��Ă�������" , 0xFFFFFF ) ;
////
////	// ���O�̓���
////	DrawString( 150 , 310 , "> " , 0xFFFFFF ) ;
////	DrawBox( 160 , 305 , 300 , 335 , 0x000055 , TRUE) ;
////	if (KeyInputSingleCharString( 170 , 310 , 10 , g_Ranking[9].name , FALSE ) == 1){
////		g_Ranking[9].score = g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
////		SortRanking();		// �����L���O���בւ�
////		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
////		g_GameState = 2;		// �Q�[�����[�h�̕ύX
////	}
////
////}
//
///***********************************************
// * �����L���O���בւ�
// ***********************************************/
////void SortRanking(void)
////{
////	int i, j;
////	RankingData work;
////
////	// �I��@�\�[�g
////	for(i=0; i<9; i++){
////		for(j=i+1; j<10; j++){
////			if(g_Ranking[i].score <= g_Ranking[j].score) {
////				work = g_Ranking[i];
////				g_Ranking[i] = g_Ranking[j];
////				g_Ranking[j] = work;
////			}
////		}
////	}
////
////	// ���ʕt��
////	for(i=0; i<10; i++){
////		g_Ranking[i].no = 1;
////	}
////	// ���_�������ꍇ�́A�������ʂƂ���
////	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
////	for(i=0; i<9; i++) {
////		for(j=i+1; j<10; j++){
////			if(g_Ranking[i].score > g_Ranking[j].score) {
////				g_Ranking[j].no++;
////			}
////		}
////	}
////}
//
///***********************************************
// * �����L���O�f�[�^�̕ۑ�
// ***********************************************/
////int  SaveRanking(void)
////{
////	FILE *fp;
////	#pragma warning(disable:4996)
////
////	// �t�@�C���I�[�v��
////	if  ( ( fp = fopen("dat/rankingdata.txt", "w" ) )  ==  NULL )  {
////		/* �G���[���� */
////		printf( "Ranking Data Error\n" );
////		return -1;
////	}
////
////	// �����L���O�f�[�^���z��f�[�^����������
////	for( int  i = 0 ;  i < 10 ;  i++ ) {
////		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
////	}
////
////	//�t�@�C���N���[�Y
////	fclose(fp);
////
////	return 0;
////
////}
//
///*************************************
// * �����L���O�f�[�^�ǂݍ���
// *************************************/
////int ReadRanking(void)
////{
////	FILE *fp;
////	#pragma warning(disable:4996)
////
////	//�t�@�C���I�[�v��
////	if((fp = fopen("dat/rankingdata.txt","r"))== NULL){
////		//�G���[����
////		printf("Ranking Data Error\n");
////		return -1;
////	}
////
////	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
////	for( int i=0; i<10; i++){
////		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
////	}
////	
////	//�t�@�C���N���[�Y
////	fclose(fp);
////
////	return 0;
////}
//
///***********************************************
// * �Q�[���^�C�g���\���i���j���[��ʁj
// ***********************************************/
////void DrawGameTitle(void)
////{
////	//���j���[�J�[�\���ړ�����
////	if ( g_KeyFlg & PAD_INPUT_DOWN ){
////		if ( ++g_MenuNumber > 2 ) g_MenuNumber = 0;
////	}
////	if ( g_KeyFlg & PAD_INPUT_UP ){
////		if ( --g_MenuNumber < 0 ) g_MenuNumber = 2;
////	}
////	
////	// �y�L�[�Ń��j���[�I��
////	if(g_KeyFlg & PAD_INPUT_A) g_GameState = g_MenuNumber + 1;
////
////	//�^�C�g���摜�\��
////	DrawGraph( 0 , 0 , g_TitleImage, FALSE );
////
////	//���j���[�J�[�\���i�O�p�`�j�̕\��
////	g_MenuY = g_MenuNumber * 52;
////	DrawTriangle( 240, 255 + g_MenuY , 260, 270 + g_MenuY , 240, 285 + g_MenuY  , GetColor(255,0,0),TRUE);
////
////}
//
/////***********************************************
//// * �Q�[����������
//// ***********************************************/
////BALL::BALL()
////{
////	g_BallX = 320;
////	g_BallY = 440 - 5;
////	
////}
////void GameInit(void)
////{
////	//BALL ball;
////	///*�ϐ��̏����ݒ�*/
////	//ball.g_BallX = 320;
////	//ball.g_BallY = 440 - 5;
////	g_MoveX = 1;
////	g_MoveY = -2;
////	g_BarX = 290;
////	g_BarY = 440;
////	g_GameState = 4;	// �Q�[�����C��������
////	g_RestBall = 2;		//�c��{�[���̐ݒ�
////	InitBlock();
////}
////
////
/////***********************************************
//// * �Q�[�����C��
//// ***********************************************/
////void GameMain(void)
////{
////
////	MoveBar();//�o�[�̈ړ�����
////	MoveBall();//�{�[���̈ړ�
////	HitBar();//�{�[���ƃo�[�̓����蔻��
////	HitBlock();//�{�[���ƃu���b�N�̓����蔻��
////	
////	
////	ball.DrawBall();
////	
////	DrawBar();//�o�[�̕`��
////	DrawBlock();//�u���b�N��`�悷��
////	DrawScore();//�X�R�A��`�悷��
////}
//
///***********************************************
// * �Q�[���G���h�`�揈���i�G���h���[���j
// ***********************************************/
////void DrawEnd(void)
////{
////	//�G���h�摜�\��
////	DrawGraph( 0 , 0 , g_EndImage , FALSE ) ;
////
////	//�G���f�B���O�\��
////	if ( ++g_WaitTime < 600 ) g_PosY = 300 - g_WaitTime / 2;
////
////	SetFontSize(24);
////	DrawString(100, 170+g_PosY, "�^�C�g���@�@�@Game�@Title", 0xFFFFFF);
////	DrawString(100, 200+g_PosY, "�o�[�W�����@�@1.0", 0xFFFFFF);
////	DrawString(100, 230+g_PosY, "�ŏI�X�V���@�@201x�Nxx��xx��", 0xFFFFFF);
////	DrawString(100, 260+g_PosY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
////	DrawString(100, 290+g_PosY, "�@�@�@�@�@�@�@�w�w�w�@�w�w", 0xFFFFFF);
////	DrawString(100, 310+g_PosY, "�f�ޗ��p", 0xFFFFFF);
////	DrawString(100, 340+g_PosY, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
////	DrawString(100, 365+g_PosY, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);
////
////	//�^�C���̉��Z�������I��
////	if (++g_WaitTime > 900) g_GameState = 99;
////}
//
///***********************************************
// * �{�[���̕`�揈��
// ***********************************************/
////void DrawBall(void) {
////	DrawCircle(g_BallX, g_BallY, 4, 0xFFD700, TRUE);
////}
//
///***********************************************
//*�o�[�̕`�揈��
//************************************************/
////void DrawBar(void) {
////	//�o�[�̕`��
////	DrawBox(g_BarX, g_BarY, g_BarX + 60, g_BarY + 8, 0xFFD700, TRUE);
////}
//
///**********************************************
//*�{�[���ƃo�[�̓����蔻��
//***********************************************/
////void HitBar(void) {
////	
////	int mx0, mx1, my0, my1, sx0, sx1, sy0, sy1;
////
////	//���W�ʒu�̎��O�v�Z
////	mx0 = ball.g_BallX - 4;
////	mx1 = ball.g_BallX + 4;
////	my0 = ball.g_BallY - 4;
////	my1 = ball.g_BallY + 4;
////	sx0 = bar.g_BarX;
////	sx1 = bar.g_BarX + 60;
////	sy0 = bar.g_BarY;
////	sy1 = bar.g_BarY + 8;
////	//�{�[���ƃo�[�̓����蔻��
////	if (sx0 <= mx1 && sx1 >= mx0 && sy0 <= my1 && sy1 >= my0) {
////		if (ball.g_BallFlg == 0) {
////			ball.g_BallAngle = (0.3f / 60) * (mx1 - sx0) + 0.6f;
////			ball.ChangeAngle();
////			ball.g_BallFlg = 1;
////		}
////	}else {
////		if (ball.g_BallFlg != 2)ball.g_BallFlg = 0;
////	}
////}
//
///***************************************************************
//*�{�[���ƃu���b�N�̓����蔻��
//****************************************************************/
////void HitBlock(void) {
////	
////	//�{�[���ƃu���b�N�̓����蔻��
////	int x = ball.g_BallX / 40;
////	int y = (ball.g_BallY - 80) / 16;
////
////	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && g_Block[y][x].flg != 0) {
////		g_Block[y][x].flg = 0;
////
////		g_Block[y][x].flg = 0;
////
////		ball.g_BallAngle = (1 - ball.g_BallAngle);
////		ball.ChangeAngle();
////		score.g_Score += g_Block[y][x].score;
////		if (CheckBlock() == 0)dg.g_GameState = 6;
////	}
////}
//
///**********************************************
// *�{�[���̈ړ�����
// **********************************************/
////void MoveBall(void) {
////	
////	/*�{�[���̈ړ�*/
////	if (ball.g_BallFlg != 2) {
////		ball.g_BallX += ball.g_MoveX;
////		ball.g_BallY += ball.g_MoveY;
////	}
////	else {
////		ball.g_BallX = bar.g_BarX + 30;
////		ball.g_BallY = bar.g_BarY - 6;
////	}
////
////	/*�ǁE�V��ł̔���*/
////	if (ball.g_BallX < 4 || ball.g_BallX > 640 - 4) {		//���̕�
////		if (ball.g_BallX < 4) {
////			ball.g_BallX = 4;
////		}
////		else {
////			ball.g_BallX = 640 - 4;
////		}
////
////		ball.g_BallAngle = (1 - ball.g_BallAngle) + 0.5f;
////		if (ball.g_BallAngle > 1)ball.g_BallAngle -= 1.0f;
////		ball.ChangeAngle();
////	}
////
////	if (ball.g_BallY < 8) {				//��̕�
////		ball.g_BallAngle = (1 - ball.g_BallAngle);
////		ball.ChangeAngle();
////	}
////	/*��ʉ��𒴂�����Q�[���I�[�o�[*/
////	if (ball.g_BallY > 480 + 4)dg.g_GameState = 5;
////
////	if (ball.g_BallY > 480 + 4) {
////		ball.g_BallFlg = 2;
////		if (--ball.g_RestBall < 0) {
////			if (score.g_Score >= g_Ranking[9].score) {
////				dg.g_GameState = 7; //�����L���O���͏�����
////			}
////			else {
////				dg.g_GameState = 5; //�Q�[���I�[�o�[������
////			}
////		}
////	}
////}
///************************************************
//*�o�[�ړ�����
//*************************************************/
////void MoveBar(void) {
////	//�}�E�X������W��ǂݎ��
////	GetMousePoint(&g_MouseX, &g_MouseY);
////
////	bar.g_BarX = g_MouseX;
////	if (bar.g_BarX < 0) {
////		bar.g_BarX = 0;
////	}else if (bar.g_BarX > 640 - 60) {
////		bar.g_BarX = 580;
////	}
////	//�}�E�X���N���b�N�ŃQ�[���X�^�[�g
////	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && ball.g_BallFlg == 2) {
////		ball.g_BallFlg = 0;
////		//�X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
////		ball.g_Speed = 5;
////		ball.g_BallAngle = 0.625f;
////		ball.ChangeAngle();
////	}
////}
//
///************************************************
//*�p�x�ύX����
//*************************************************/
////void ChangeAngle(void) {
////	float rad = ball.g_BallAngle * (float)M_PI * 2;
////	g_MoveX = (int)(g_Speed * cosf(rad));
////	g_MoveY = (int)(g_Speed * sinf(rad));
////}
//
///************************************************
//*�Q�[���I�[�o�[��ʕ`�揈��
//*************************************************/
////void DrawGameOver(void)
////{
////	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
////	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
////
////	SetFontSize(48);
////	DrawString(200, 200, "Game Over", GetColor(255, 0, 0));
////
////		//�����̕\��(�_��)
////	if (++g_WaitTime < 30) {
////		SetFontSize(24);
////		DrawString(150, 450, "-- Press[SPACE]Key --", GetColor(255, 0, 0));
////	}else if (g_WaitTime > 60) {
////		g_WaitTime = 0;
////	}
////}
///******************************************************************************
//*�u���b�N��������
//*******************************************************************************/
////void InitBlock(void) {
////
////	//�u���b�N�z��̏�����
////	for (int i = 0; i < HEIGHT; i++) {
////		for (int j = 0; j < WIDTH; j++) {
////			if (g_BlockData[g_Stage][i][j] != 0) {
////				g_Block[i][j].flg = 1;
////				g_Block[i][j].x = j * 40;
////				g_Block[i][j].y = i * 16 + 80;
////				g_Block[i][j].w = 40;
////				g_Block[i][j].h = 8;
////				g_Block[i][j].image = g_BlockData[g_Stage][i][j];
////				g_Block[i][j].score = g_Block[i][j].image * 10;
////				ball.g_BallFlg = 2;
////			}
////		}
////	}
////}
//
///**********************************************************************************
//*�u���b�N�`�揈��
//***********************************************************************************/
////void DrawBlock(void) {
////
////	for (int i = 0; i < HEIGHT; i++) {
////		for (int j = 0; j < WIDTH; j++) {
////			if (g_Block[i][j].flg == 1) {
////				DrawGraph(g_Block[i][j].x, g_Block[i][j].y, g_BlockImage[g_Block[i][j].image], TRUE);
////			}
////		}
////	}
////}
///***********************************************************************************
//*�X�R�A�`�揈��
//************************************************************************************/
////void DrawScore(void) {
////
////	DrawFormatString(20, 20, 0xFFFFFF, "SCORE:%06d", g_Score);
////	SetFontSize(10);
////	DrawFormatString(600, 460, 0xFFD700, "�� x%d", g_RestBall);
////}
///*****************************************
//*�u���b�N�`�F�b�N����
//******************************************/
////int CheckBlock(void) {
////
////	//�u���b�N�z��̏�����
////	for (int i = 0; i < HEIGHT; i++) {
////		for (int j = 0; j < WIDTH; j++) {
////			if (g_Block[i][j].flg == 1)	return -1;
////		}
////	}
////	return 0;
////}
///*****************************************:
//*�Q�[���N���A��ʕ`�揈��
//******************************************/
////void DrawGameClear(void)
////{
////	//�X�y�[�X�L�[��NEXT�X�e�[�W��
////	if (g_KeyFlg & PAD_INPUT_M) {
////		g_GameState = 4;
////		if (++g_Stage > 4)g_Stage = 0;
////		InitBlock();
////	}
////	SetFontSize(48);
////	DrawString(120, 200, "Congratulations", 0x7F00F0);
////	//�����̕\���i�_�Łj
////	if (++g_WaitTime < 30) {
////		SetFontSize(24);
////		DrawString(150, 450, "-- Press[SPACE]Key --", 0xFF0000);
////	}else if(g_WaitTime > 60){
////		g_WaitTime = 0;
////	}
////}