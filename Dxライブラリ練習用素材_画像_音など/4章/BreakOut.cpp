///********************************************************************
//**	��S�́@�Q�[���v���O���~���O�̊�{
//**	�@�u���b�N�����Q�[���̍쐬(2018)
//********************************************************************/
//#include "DxLib.h"
//
///***********************************************
// * �ϐ��̐錾
// ***********************************************/
//int	g_OldKey;				// �O��̓��̓L�[
//int	g_NowKey;				// ����̓��̓L�[
//int	g_KeyFlg;				// ���̓L�[���
//
//int	g_MenuNumber = 0;		// ���j���[�J�[�\���ʒu
//int g_MenuY;				// ���j���[�J�[�\���̂x���W
//
//int	g_TitleImage;			// �摜�p�ϐ�
//int	g_RankingImage;			// �摜�p�ϐ�
//int	g_EndImage;				// �摜�p�ϐ�
//
//int	g_WaitTime = 0;			// �҂�����
//int g_PosY;					// �X�N���[�����̂x���W
//
//int	g_Score = 0;			// �X�R�A
//
//int	g_GameState = 0;		// �Q�[���X�e�[�^�X
//
//
//
//// �����L���O�f�[�^�i�\���́j
//struct	RankingData {
//	int		no;
//	char	name[11];
//	long	score;
//};
//// �����L���O�f�[�^�ϐ��錾
//struct	RankingData		g_Ranking[10];
//
///***********************************************
// * �֐��̃v���g�^�C�v�錾
// ***********************************************/
//void GameInit(void);		//�Q�[������������
//void GameMain(void);		//�Q�[�����C������
//
//void DrawGameTitle(void);	//�Q�[���^�C�g������
//void DrawEnd(void);			//�Q�[���G���h����
//
//void DrawRanking(void);		//�����L���O�`��
//void InputRanking(void);	//�����L���O����
//void SortRanking(void);		//�����L���O���בւ�
//int  SaveRanking(void);		//�����L���O�f�[�^�̕ۑ�
//int  ReadRanking(void);		//�����L���O�f�[�^�ǂݍ���
//
//
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
//	if((g_TitleImage = LoadGraph("images/Title.bmp")) == -1) return -1;
//	//�����L���O�摜�f�[�^�̓ǂݍ���
//	if((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
//	//�G���h�摜�f�[�^�̓ǂݍ���
//	if((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
//
//	if  ( ReadRanking() == -1  )  return  -1;    //�����L���O�f�[�^�̓ǂݍ���
//	
//	SetDrawScreen( DX_SCREEN_BACK );	// �`����ʂ𗠂ɂ���
//	
//	SetFontSize( 20 );		// �����T�C�Y��ݒ�
//
//	// �Q�[�����[�v
//	while ( ProcessMessage() == 0 && g_GameState != 99){
//
//		// ���̓L�[�擾
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// ��ʂ̏�����
//
//		switch (g_GameState){
//			case 0:
//				DrawGameTitle();	//�Q�[���^�C�g������
//				break;
//			case 1:
//				GameInit();		//�Q�[����������
//				break;
//			case 2:
//				DrawRanking();	//�����L���O�`�揈��
//				break;
//			case 3:
//				DrawEnd();		//�G���h��ʕ`�揈��
//				break;
//			case 4:
//				GameMain();		//�Q�[�����C������
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
// * �����L���O�`�揈��
// ***********************************************/
//void DrawRanking(void)
//{
//	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if(g_KeyFlg & PAD_INPUT_M) g_GameState = 0;
//
//	//�����L���O�摜�\��
//	DrawGraph( 0 , 0 , g_RankingImage , FALSE ) ;
//
//	// �����L���O�ꗗ��\��
//	SetFontSize(30);
//	for( int i=0; i<10; i++ ){
//		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
//							 g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	// �����̕\��(�_��)
//	if ( ++g_WaitTime < 30 ){
//		SetFontSize(24);
//		DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);
//	} else if ( g_WaitTime > 60 ){
//		g_WaitTime = 0;
//	}
//
//}
//
///***********************************************
// * �����L���O���͏���
// ***********************************************/
//void InputRanking(void)
//{
//	//�����L���O�摜�\��
//	DrawGraph( 0 , 0 , g_RankingImage, FALSE );
//
//	// �t�H���g�T�C�Y�̐ݒ�
//	SetFontSize(20);
//
//	// ���O���͎w��������̕`��
//	DrawString( 150 , 240 , "�����L���O�ɓo�^���܂�" , 0xFFFFFF ) ;
//	DrawString( 150 , 270 , "���O���p���œ��͂��Ă�������" , 0xFFFFFF ) ;
//
//	// ���O�̓���
//	DrawString( 150 , 310 , "> " , 0xFFFFFF ) ;
//	DrawBox( 160 , 305 , 300 , 335 , 0x000055 , TRUE) ;
//	if (KeyInputSingleCharString( 170 , 310 , 10 , g_Ranking[9].name , FALSE ) == 1){
//		g_Ranking[9].score = g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
//		SortRanking();		// �����L���O���בւ�
//		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
//		g_GameState = 2;		// �Q�[�����[�h�̕ύX
//	}
//
//}
//
///***********************************************
// * �����L���O���בւ�
// ***********************************************/
//void SortRanking(void)
//{
//	int i, j;
//	RankingData work;
//
//	// �I��@�\�[�g
//	for(i=0; i<9; i++){
//		for(j=i+1; j<10; j++){
//			if(g_Ranking[i].score <= g_Ranking[j].score) {
//				work = g_Ranking[i];
//				g_Ranking[i] = g_Ranking[j];
//				g_Ranking[j] = work;
//			}
//		}
//	}
//
//	// ���ʕt��
//	for(i=0; i<10; i++){
//		g_Ranking[i].no = 1;
//	}
//	// ���_�������ꍇ�́A�������ʂƂ���
//	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
//	for(i=0; i<9; i++) {
//		for(j=i+1; j<10; j++){
//			if(g_Ranking[i].score > g_Ranking[j].score) {
//				g_Ranking[j].no++;
//			}
//		}
//	}
//}
//
///***********************************************
// * �����L���O�f�[�^�̕ۑ�
// ***********************************************/
//int  SaveRanking(void)
//{
//	FILE *fp;
//	#pragma warning(disable:4996)
//
//	// �t�@�C���I�[�v��
//	if  ( ( fp = fopen("dat/rankingdata.txt", "w" ) )  ==  NULL )  {
//		/* �G���[���� */
//		printf( "Ranking Data Error\n" );
//		return -1;
//	}
//
//	// �����L���O�f�[�^���z��f�[�^����������
//	for( int  i = 0 ;  i < 10 ;  i++ ) {
//		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	//�t�@�C���N���[�Y
//	fclose(fp);
//
//	return 0;
//
//}
//
///*************************************
// * �����L���O�f�[�^�ǂݍ���
// *************************************/
//int ReadRanking(void)
//{
//	FILE *fp;
//	#pragma warning(disable:4996)
//
//	//�t�@�C���I�[�v��
//	if((fp = fopen("dat/rankingdata.txt","r"))== NULL){
//		//�G���[����
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
//	for( int i=0; i<10; i++){
//		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
//	}
//	
//	//�t�@�C���N���[�Y
//	fclose(fp);
//
//	return 0;
//}
//
///***********************************************
// * �Q�[���^�C�g���\���i���j���[��ʁj
// ***********************************************/
//void DrawGameTitle(void)
//{
//	//���j���[�J�[�\���ړ�����
//	if ( g_KeyFlg & PAD_INPUT_DOWN ){
//		if ( ++g_MenuNumber > 2 ) g_MenuNumber = 0;
//	}
//	if ( g_KeyFlg & PAD_INPUT_UP ){
//		if ( --g_MenuNumber < 0 ) g_MenuNumber = 2;
//	}
//	
//	// �y�L�[�Ń��j���[�I��
//	if(g_KeyFlg & PAD_INPUT_A) g_GameState = g_MenuNumber + 1;
//
//	//�^�C�g���摜�\��
//	DrawGraph( 0 , 0 , g_TitleImage, FALSE );
//
//	//���j���[�J�[�\���i�O�p�`�j�̕\��
//	g_MenuY = g_MenuNumber * 52;
//	DrawTriangle( 240, 255 + g_MenuY , 260, 270 + g_MenuY , 240, 285 + g_MenuY  , GetColor(255,0,0),TRUE);
//
//}
//
///***********************************************
// * �Q�[����������
// ***********************************************/
//void GameInit(void)
//{
//	// �ϐ��̏����ݒ�
//
//
//	g_GameState = 4;	// �Q�[�����C��������
//}
//
///***********************************************
// * �Q�[�����C��
// ***********************************************/
//void GameMain(void)
//{
//	//�{�[���̕`��
//
//}
//
///***********************************************
// * �Q�[���G���h�`�揈���i�G���h���[���j
// ***********************************************/
//void DrawEnd(void)
//{
//	//�G���h�摜�\��
//	DrawGraph( 0 , 0 , g_EndImage , FALSE ) ;
//
//	//�G���f�B���O�\��
//	if ( ++g_WaitTime < 600 ) g_PosY = 300 - g_WaitTime / 2;
//
//	SetFontSize(24);
//	DrawString(100, 170+g_PosY, "�^�C�g���@�@�@Game�@Title", 0xFFFFFF);
//	DrawString(100, 200+g_PosY, "�o�[�W�����@�@1.0", 0xFFFFFF);
//	DrawString(100, 230+g_PosY, "�ŏI�X�V���@�@201x�Nxx��xx��", 0xFFFFFF);
//	DrawString(100, 260+g_PosY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
//	DrawString(100, 290+g_PosY, "�@�@�@�@�@�@�@�w�w�w�@�w�w", 0xFFFFFF);
//	DrawString(100, 310+g_PosY, "�f�ޗ��p", 0xFFFFFF);
//	DrawString(100, 340+g_PosY, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
//	DrawString(100, 365+g_PosY, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);
//
//	//�^�C���̉��Z�������I��
//	if (++g_WaitTime > 900) g_GameState = 99;
//}
//
///***********************************************
// * �{�[���̕`�揈��
// ***********************************************/
