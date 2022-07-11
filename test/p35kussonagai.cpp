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
//			//選択法ソート
//			for (int i = 0; i < 9; i++) {
//				for (int j = i + 1; j < 10; j++) {
//					if (g_Ranking[i].score <= g_Ranking[j].score) {
//						work = g_Ranking[i];
//						g_Ranking[i] = g_Ranking[j];
//						g_Ranking[j] = work;
//					}
//				}
//			}
//			//順位付け
//			for (int i = 0; i < 10; i++) {
//				g_Ranking[i].no = 1;
//			}
//			//得点が同じ場合は、同じ順位とする
//			//同順位があった場合の次の順位はデータ個数が加算された順位とする
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
//	        //スペースキーでメニューに戻る
//		if (g_KeyFlg & PAD_INPUT_M)g_GameState = GAME_TITLE;
//			//ランキング画像処理
//			DrawGraph(0, 0, g_RankingImage, FALSE);
//			//ランキング一覧を表示
//			SetFontSize(30);
//			for (int i = 0; i < 10; i++) {
//				DrawFormatString(80, 170 + i * 25, 0x000000, "%2d   %11s    %10d",g_Ranking[i].no,g_Ranking[i].name,g_Ranking[i].score);
//			}
//			//文字の表示（点滅）
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
//			//ランキング画像表示
//			DrawGraph(0, 0, g_RankingImage, FALSE);
//			SetFontSize(20);
//			DrawString(150, 240, "ランキングに登録します", 0x000000);
//			DrawString(160, 270, "名前を英字で入力してください", 0x000000);
//		
//			//名前の入力
//			DrawString(150, 310, ">", 0x000000);
//			DrawBox(160, 305, 300, 335, 0x000000, TRUE);
//			if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9]. name, FALSE) == 1) {
//				g_Ranking[9].score = g_Score;//ランキングデータの10番目にスコアを登録
//				SortRanking();//ランキング並べ替え
//				SaveRanking();//ランキングデータの保存
//				g_GameState = GAME_RANKING;//GAMEモードの変更
//			}
//		}
//	
//	//ランキングデータの保存
//	int SaveRanking(void) {
//		FILE* fp;
//	#pragma warning(disable:4996)
//		//ファイルオープン
//		if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
//			/*エラー処理*/
//			printf("Ranking Data Error\n");
//			return -1;
//		}
//		//ランキングデータ分配列データを書き込む
//		for (int i = 0; i < 10; i++) {
//			fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//		}
//		//ファイルクローズ
//		fclose(fp);
//		return 0;
//	}
//	
//	//ランキングデータ読み込み
//	int ReadRanking(void) {
//		FILE* fp;
//	#pragma warning(disable:4996)
//	
//		//ファイルオープン
//		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
//			//エラー処理
//			printf("Ranking Data Error\n");
//			return -1;
//			//ランキングデータ分配列データを書き込む
//			for (int i = 0; i < 10; i++) {
//				fscanf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//			}
//			//ファイルクローズ
//			fclose(fp);
//			return 0;
//		}
//	}
//	
//	//GAMETITLE表示（メニュー画面）
//	void DrawGameTitle(void) {
//		//メニューカーソル移動処理
//		if (g_KeyFlg & PAD_INPUT_DOWN) {
//			if (++g_MenuNumber > 2)g_MenuNumber = 0;
//		}
//		if (g_KeyFlg & PAD_INPUT_UP) {
//			if (--g_MenuNumber < 0)g_MenuNumber = 2;
//		}
//		//Zキーでメニュー選択
//		if (g_KeyFlg & PAD_INPUT_A)g_GameState = g_MenuNumber + 1;
//		//タイトル画像表示
//		DrawGraph(0, 0, g_TitleImage, FALSE);
//		//メニューカーソル（三角形）の表示
//		g_MenuY = g_MenuNumber * 52;
//		DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
//	}
//	
//	//ゲームメイン
//	void DrawGameMain(void) {
//		//ランキング入力
//		InputRanking();
//	}
//	
//	void DrawEnd(void) {
//		if (++x >= 255)x = 255;
//			//エンド画像表示
//			DrawGraph(0, 0, g_EndImage, FALSE);
//			//文字サイズを設定
//			SetFontSize(24);
//			//アルファブレンドの設定をする
//			SetDrawBlendMode(DX_BLENDMODE_ALPHA, x);
//			//エンディング表示
//		
//			DrawString(110, 170 + g_PosY, "タイトル　　〇〇〇game", 0x000000);
//			DrawString(110, 200 + g_PosY, "バージョン　2.0", 0x000000);
//			DrawString(110, 230 + g_PosY, "最終更新日　2018年07月01日", 0x000000);
//			DrawString(110, 260 + g_PosY, "製作者　　　国際電子ビジネス専門学校", 0x000000);
//			DrawString(110, 290 + g_PosY, "　　　　　  国際　太郎", 0x000000);
//			DrawString(110, 310 + g_PosY, "素材利用", 0x000000);
//			DrawString(110, 340 + g_PosY, "BGM         魔王魂", 0x000000);
//			DrawString(110, 365 + g_PosY, "SE          煉獄庭園", 0x000000);
//			
//			//アルファブレンドの設定を解除する
//			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//			//タイムの加算処理＆終了
//			if (++g_WaitTime > 900)g_GameState = END;
//		}