//#include"DxLib.h"
//typedef enum MENU_MODE {
//	GAME_TITLE,
//	GAME_MAIN,
//	GAME_RANKING,
//	GAME_END,
//	INPUT_RANKING,
//	END = 99
//};
//int g_OldKey;
//int g_NowKey;
//int g_KeyFlg;
//
//int g_MenuNumber = 0;
//int g_MenuY;
//
//int g_TitleImage;
//int g_RankingImage;
//int g_EndImage;
//
//int x = 0;
//int g_WaitTime = 0;
//int g_PosY;
//
//int g_Score = 3500;
//
//int g_GameState = GAME_TITLE;
//
//struct RankingData {
//	int no;
//	char name[11];
//	long score;
//};
//
//struct RankingData g_Ranking[10];
//void DrawGameTitle(void);
//void DrawGameMain(void);
//void DrawEnd(void);
//
//void DrawRanking(void);
//void InputRanking(void);
//void SortRanking(void);
//int SaveRanking(void);
//int ReadRanking(void);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmbLine, int nCmdShow)
//{
//	ChangeWindowMode(TRUE);
//
//	if (DxLib_Init() == -1)return -1;
//
//	if ((g_TitleImage = LoadGraph("images/title.bmp")) == -1)return -1;
//	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;
//	if ((g_EndImage = LoadGraph("images/end.bmp")) == -1)return -1;
//
//	if (ReadRanking() == -1)return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	while (ProcessMessage() == 0 && g_GameState != END){
//		
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();
//
//		switch (g_GameState) {
//		case GAME_TITLE:
//			DrawGameTitle();
//			break;
//		case GAME_MAIN:
//			DrawGameMain();
//			break;
//		case GAME_RANKING:
//			DrawRanking();
//			break;
//		case GAME_END:
//			DrawEnd();
//			break;
//		}
//		ScreenFlip();
//	}
//	DxLib_End();
//	return 0;
//}
//void SortRanking(void)
//{
//	RankingData work;
//			//�I��@�\�[�g
//			for (int i = 0; i < 9; i++) {
//				for (int j = i + 1; j < 10; j++) {
//					if (g_Ranking[i].score <= g_Ranking[j].score) {
//						work = g_Ranking[i];
//						g_Ranking[i] = g_Ranking[j];
//						g_Ranking[j] = work;
//					}
//				}
//			}
//			//���ʕt��
//			for (int i = 0; i < 10; i++) {
//				g_Ranking[i].no = 1;
//			}
//			//���_�������ꍇ�́A�������ʂƂ���
//			//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
//			for (int i = 0; i < 9; i++) {
//				for (int j = i + 1; j < 10; j++) {
//					if (g_Ranking[i].score > g_Ranking[j].score) {
//						g_Ranking[j].no++;
//					}
//				}
//			}
//		}
//	
//	void DrawRanking(void) {
//	        //�X�y�[�X�L�[�Ń��j���[�ɖ߂�
//		if (g_KeyFlg & PAD_INPUT_M)g_GameState = GAME_TITLE;
//			//�����L���O�摜����
//			DrawGraph(0, 0, g_RankingImage, FALSE);
//			//�����L���O�ꗗ��\��
//			SetFontSize(30);
//			for (int i = 0; i < 10; i++) {
//				DrawFormatString(80, 170 + i * 25, 0x000000, "%2d   %11s    %10d",g_Ranking[i].no,g_Ranking[i].name,g_Ranking[i].score);
//			}
//			//�����̕\���i�_�Łj
//			if (++g_WaitTime < 30) {
//				SetFontSize(24);
//				DrawString(150, 450, "-- Press[SPACE]Key --", 0xff0000);
//			}
//			else if (g_WaitTime > 60) {
//				g_WaitTime = 0;
//			}
//		}
//	
//	void InputRanking(void) {
//			//�����L���O�摜�\��
//			DrawGraph(0, 0, g_RankingImage, FALSE);
//			SetFontSize(20);
//			DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0x000000);
//			DrawString(160, 270, "���O���p���œ��͂��Ă�������", 0x000000);
//		
//			//���O�̓���
//			DrawString(150, 310, ">", 0x000000);
//			DrawBox(160, 305, 300, 335, 0x000000, TRUE);
//			if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9]. name, FALSE) == 1) {
//				g_Ranking[9].score = g_Score;//�����L���O�f�[�^��10�ԖڂɃX�R�A��o�^
//				SortRanking();//�����L���O���בւ�
//				SaveRanking();//�����L���O�f�[�^�̕ۑ�
//				g_GameState = GAME_RANKING;//GAME���[�h�̕ύX
//			}
//		}
//	
//	//�����L���O�f�[�^�̕ۑ�
//	int SaveRanking(void) {
//		FILE* fp;
//	#pragma warning(disable:4996)
//		//�t�@�C���I�[�v��
//		if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
//			/*�G���[����*/
//			printf("Ranking Data Error\n");
//			return -1;
//		}
//		//�����L���O�f�[�^���z��f�[�^����������
//		for (int i = 0; i < 10; i++) {
//			fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//		}
//		//�t�@�C���N���[�Y
//		fclose(fp);
//		return 0;
//	}
//	
//	//�����L���O�f�[�^�ǂݍ���
//	int ReadRanking(void) {
//		FILE* fp;
//	#pragma warning(disable:4996)
//	
//		//�t�@�C���I�[�v��
//		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
//			//�G���[����
//			printf("Ranking Data Error\n");
//			return -1;
//			//�����L���O�f�[�^���z��f�[�^����������
//			for (int i = 0; i < 10; i++) {
//				fscanf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//			}
//			//�t�@�C���N���[�Y
//			fclose(fp);
//			return 0;
//		}
//	}
//	
//	//GAMETITLE�\���i���j���[��ʁj
//	void DrawGameTitle(void) {
//		//���j���[�J�[�\���ړ�����
//		if (g_KeyFlg & PAD_INPUT_DOWN) {
//			if (++g_MenuNumber > 2)g_MenuNumber = 0;
//		}
//		if (g_KeyFlg & PAD_INPUT_UP) {
//			if (--g_MenuNumber < 0)g_MenuNumber = 2;
//		}
//		//Z�L�[�Ń��j���[�I��
//		if (g_KeyFlg & PAD_INPUT_A)g_GameState = g_MenuNumber + 1;
//		//�^�C�g���摜�\��
//		DrawGraph(0, 0, g_TitleImage, FALSE);
//		//���j���[�J�[�\���i�O�p�`�j�̕\��
//		g_MenuY = g_MenuNumber * 52;
//		DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
//	}
//	
//	//�Q�[�����C��
//	void DrawGameMain(void) {
//		//�����L���O����
//		InputRanking();
//	}
//	
//	void DrawEnd(void) {
//		if (++x >= 255)x = 255;
//			//�G���h�摜�\��
//			DrawGraph(0, 0, g_EndImage, FALSE);
//			//�����T�C�Y��ݒ�
//			SetFontSize(24);
//			//�A���t�@�u�����h�̐ݒ������
//			SetDrawBlendMode(DX_BLENDMODE_ALPHA, x);
//			//�G���f�B���O�\��
//		
//			DrawString(110, 170 + g_PosY, "�^�C�g���@�@�Z�Z�Zgame", 0x000000);
//			DrawString(110, 200 + g_PosY, "�o�[�W�����@2.0", 0x000000);
//			DrawString(110, 230 + g_PosY, "�ŏI�X�V���@2018�N07��01��", 0x000000);
//			DrawString(110, 260 + g_PosY, "����ҁ@�@�@���ۓd�q�r�W�l�X���w�Z", 0x000000);
//			DrawString(110, 290 + g_PosY, "�@�@�@�@�@  ���ہ@���Y", 0x000000);
//			DrawString(110, 310 + g_PosY, "�f�ޗ��p", 0x000000);
//			DrawString(110, 340 + g_PosY, "BGM         ������", 0x000000);
//			DrawString(110, 365 + g_PosY, "SE          �����뉀", 0x000000);
//			
//			//�A���t�@�u�����h�̐ݒ����������
//			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//			//�^�C���̉��Z�������I��
//			if (++g_WaitTime > 900)g_GameState = END;
//		}