/***********************************************************
**    第5章　ミニゲームをつくる（２）
**　　　　　　　レース＆避けゲー
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
*変数宣言
*******************************************************/
XINPUT_STATE input;
int g_KeyFLG = TRUE;	//入力キー情報


int g_OldKey;
int g_NowKey;
int g_KeyFlg;

int g_GameState = 0;	//ゲームモード

/*int g_TitleImage;*/		//画像用変数
int g_Menu, g_Cone;		//メニュー画像変数

int g_Score = 0;		//スコア

int g_RankingImage;		//画像用変数

int g_WaitTime = 0;

int g_WaitCount = 0;

int Time = 0;     //待ち時間
int StartTime;
int RefreshTime;

int g_EndImage;        //エンド画面

int g_Mileage;          //走行距離

int Apple_Img[4]; //リンゴ描画変数
int g_Item[2];    //アイテム画像変数
int g_Teki[3];    //キャラ画像変数

int g_StageImage;//ステージ画像

int AppleCount1, AppleCount2, AppleCount3, AppleCount4; //リンゴカウント

int g_Car_left, g_Car_right, g_Car_Nowangle, g_Barrier;	//キャラ画像変数

int g_TitleBGM;
int g_MusicBGM;	//ステージ音源
int g_GameOverSE;
int g_SE1;
int g_SE2;

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
int color_white;
double Fps = 0.0;

int x;
int x_flg = TRUE;

//ランキングデータ（構造体）
struct RankingData {
	int no;
	char name[11];
	long score;
};
//ランキングデータ変数宣言
struct RankingData g_Ranking[RANKING_DATA];

/***************************************************
*関数のプロトタイプ宣言
****************************************************/
void GameInit(void);	//ゲーム初期化処理
void GameMain(void);	//ゲームメイン処理

void DrawGameTitle(void);//タイトル描画処理
void DrawGameOver(void);//ゲームオーバー画面描画処理
void DrawEnd(void);//ゲームエンド描画処理
void DrawHelp(void);//ゲームヘルプ描画処理

void DrawRanking(void);//ランキング描画処理
void InputRanking(void);//ランキング入力

int LoadImages(); //画像読み込み

void SortRanking(void);	//ランキング並び替え
int SaveRanking(void);	//ランキングデータの保存
int ReadRanking(void);	//ランキングデータ読み込み

void DrawBackGround();		//背景画像スクロール処理

int LoadSounds();	//ステージ

int LoadSounds();	//ステージ

void SetColor();
void FpsTimeFanction();

/****************************************************
*プログラムの開始
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{

	SetMainWindowText("Drive&Avoid");		//タイトルを設定

	ChangeWindowMode(TRUE);					//ウィンドウモードで起動

	if (DxLib_Init() == -1)return -1;		//DXライブラリの初期化処理



	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);			//描画先画面を裏にする
	SetColor();

	if (LoadImages() == -1)return -1;		//画像読み込み関数を呼び出し

	if (LoadSounds() == -1)return -1;		//サウンド読み込み関数を呼び出し

	if (ReadRanking() == -1) return -1;		//ランキングデータの読み込み

	//ゲームループ
	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
		RefreshTime = GetNowCount();
		//入力キー取得
		/*g_OldKey = g_NewKey;*/
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		

		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();			//画面の初期化
		FpsTimeFanction();

		switch (g_GameState) {
		case 0:
			title.DrawGameTitle();		//ゲームタイトル描画処理
			break;
		case 1:
			GameInit();				//ゲーム初期処理
			break;
		case 2:
			DrawRanking();			//ランキング描画処理
			break;
		case 3:
			DrawHelp();				//ゲームヘルプ描画処理
			break;
		case 4:
			DrawEnd();				//ゲームエンド描画処理
			break;
		case 5:
			GameMain();				//ゲームメイン処理
			break;
		case 6:
			DrawGameOver();			//ゲームオーバー描画処理
			break;
		case 7:
			InputRanking();			//ランキング入力処理
			break;
		}
		ScreenFlip();	//裏画面の内容を表画面に反映
		while (GetNowCount() - RefreshTime < 17);
	}
	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;	//ソフトの終了
}


void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //白色ハンドルを取得
	return;
}
///*********************************************
//*ゲームタイトル表示（メニュー画面）
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
//	//メニューカーソル移動処理
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
//	//Zキーでメニュー選択
//	if (input.Buttons[12] == 1) {
//		StopSoundMem(g_TitleBGM);
//		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
//		g_GameState = MenuNo + 1;
//	}
//	//タイトル画像表示
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//メニューカーソル
//	DrawRotaGraph(150 + x, 240 + MenuNo * 50, 0.7f, M_PI / 2, g_Cone, TRUE);
//
//}
/********************************************
*ゲーム初期化処理
*********************************************/
void GameInit(void)
{
	//スコアの初期化
	g_Score = 0;

	//走行距離を初期化
	g_Mileage = 0;
	g_player.InitPlayer();
	apple.InitApple();

	Time = GetNowCount();
	

	//ゲームメイン処理へ
	g_GameState = 5;

	//音源の初期設定


	//エネミーの初期設定
	/*for (int i = 0; i < Apple_MAX; i++) {
		g_apple[i].flg = FALSE;
	}*/

}
/*******************************************
*ゲームランキング描画処理
********************************************/
void DrawRanking(void)
{
	//スペースキーでメニューに戻る
	if (g_KeyFlg & PAD_INPUT_M) g_GameState = 0;

	//ランキング画像処理 
	//ランキング画像処理
	DrawGraph(0, 0, g_RankingImage, FALSE);

	//ランキング一覧を表示
	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	DrawString(100, 450, "----スペースキーを押してタイトルへ戻る ----", 0xffffff, 0);

}
/*******************************************
*ゲームヘルプ描画処理
********************************************/
void DrawHelp(void)
{
	// スペースキーでメニューに戻る
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;

	//タイトル画像表示
	DrawGraph(0, 0, title.g_TitleImage, FALSE);
	SetFontSize(16);
	DrawString(20, 120, "ヘルプ画面", 0xffffff, 0);

	DrawString(20, 160, "これは障害物を避けながら", 0xffffff, 0);
	DrawString(20, 180, "走り続けるゲームです", 0xffffff, 0);
	DrawString(20, 200, "燃料が尽きるか障害物に", 0xffffff, 0);
	DrawString(20, 220, "数回当たるとゲームオーバーです", 0xffffff, 0);
	DrawString(20, 250, "アイテム一覧", 0xffffff, 0);
	DrawGraph(20, 260, g_Item[0], TRUE);
	DrawString(20, 315, "取ると燃料が回復するよ", 0xffffff, 0);
	DrawGraph(20, 335, g_Item[1], TRUE);
	DrawString(20, 385, "ダメージを受けているときに取ると耐久回復", 0xffffff, 0);
	DrawString(20, 405, "耐久が減っていなかったら燃料が少し回復するよ", 0xffffff, 0);
	DrawString(20, 450, "---- スペースキーを押してタイトルへ戻る ----", 0xffffff, 0);
}
/*******************************************
*ゲームエンド描画処理
********************************************/
void DrawEnd(void)
{
	//エンド画像表示
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//タイムの加算処理＆終了（３秒後）
	if (++g_WaitTime > 180)g_GameState = 99;
}
/******************************************
*ゲームメイン
******************************************/
void GameMain(void)
{
		PlaySoundMem(g_MusicBGM, DX_PLAYTYPE_LOOP, FALSE);

		DrawBackGround();

		apple.AppleControl();

		g_player.PlayerControl();


	

	//スペースキーでメニューに戻る
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 6;

	SetFontSize(16);
	DrawString(20, 20, "ゲームメイン", 0xffffff, 0);
	DrawString(150, 450, "---- スペースキーを押してゲームオーバーへ ----", 0xffffff, 0);
}



/******************************************
*背景画像スクロール処理
*引　数：なし
*戻り値：なし
********************************************/
void DrawBackGround()
{
	

	DrawGraph(0, 0, g_StageImage, FALSE);		//画像：横490+150(スコア表示分)=640:縦480

	
}

/***************************************
*ゲームオーバー画面描画処理
****************************************/
void DrawGameOver(void)
{
	PlaySoundMem(g_GameOverSE, DX_PLAYTYPE_BACK, FALSE);
	g_Score = (g_Mileage / 10 * 10) + AppleCount3 * 50 + AppleCount1 * 200;

	//スペースキーでメニューに戻る
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
	DrawString(220, 170, "ゲームオーバー", 0xcc0000);
	SetFontSize(16);
	DrawString(180, 200, "走行距離　　　", 0x000000);
	DrawRotaGraph(230, 230, 0.3f, M_PI / 2, g_Teki[2], TRUE, FALSE);

	DrawRotaGraph(230, 250, 0.3f, M_PI / 2, g_Teki[1], TRUE, FALSE);

	DrawRotaGraph(230, 270, 0.3f, M_PI / 2, g_Teki[0], TRUE, FALSE);

	DrawFormatString(260, 200, 0xFFFFFF, "%6d x  10 = %6d", g_Mileage / 10, g_Mileage / 10 * 10);

	DrawFormatString(260, 222, 0xFFFFFF, "%6d x  50 = %6d", AppleCount3, AppleCount3 * 50);

	DrawFormatString(260, 243, 0xFFFFFF, "%6d x  100 = %6d", AppleCount2, AppleCount2 * 100);

	DrawFormatString(260, 264, 0xFFFFFF, "%6d x  200 = %6d", AppleCount1, AppleCount1 * 200);

	DrawString(310, 290, "スコア", 0x000000);

	DrawFormatString(260, 290, 0xFFFFFF, "          =%6d", g_Score);

	DrawString(150, 450, "---- スペースキーを押してタイトルへ戻る ----", 0xffffff, 0);

}
/****************************************
*ランキング入力処理
****************************************/
void InputRanking(void)
{
	//ランキング画像表示
	DrawGraph(0, 0, g_RankingImage, FALSE);

	// フォントサイズの設定
	SetFontSize(20);

	// 名前入力指示文字列の描画
	DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
	DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

	// 名前の入力
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[RANKING_DATA].name, FALSE) == 1) {
		g_Ranking[RANKING_DATA].score = g_Score;	// ランキングデータの１０番目にスコアを登録
		SortRanking();		// ランキング並べ替え
		SaveRanking();		// ランキングデータの保存
		g_GameState = 2;		// ゲームモードの変更
	}
}
/************************************************:
*ランキング並び替え
***********************************************/
void SortRanking(void) {
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANKING_DATA; i++) {
		g_Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}
/****************************************
*ランキングデータ保存
*****************************************/
int SaveRanking(void) {

	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;

}
/*****************************************
*ランキングデータ読み込み
******************************************/
int ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANKING_DATA; i++) {
		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}
/***************************************
*サウンド読み込み
****************************************/
int LoadSounds()
{
	if ((title.g_TitleBGM = LoadSoundMem("sounds/Initial D - Night Of Fire.mp3")) == -1)return -1;
	//initial D音源
	if ((g_MusicBGM = LoadSoundMem("sounds/Daisuke full ver. (歌詞・和訳付き).mp3")) == -1)return -1;
	if ((g_GameOverSE = LoadSoundMem("sounds/GameOver.mp3")) == -1)return -1;

	//SE1 データ読み込み
	if ((g_SE1 = LoadSoundMem("sounds/SE1.mp3")) == -1)return -1;
	//SE2 データ読み込み
	if ((g_SE2 = LoadSoundMem("sounds/SE2.mp3")) == -1)return -1;


	//SEの音量調整
	ChangeVolumeSoundMem(80, g_SE2);

	ChangeVolumeSoundMem(120, g_SE1);

	return 0;
}
/****************************************
*画像読み込み
*****************************************/
int LoadImages()
{
	//タイトル
	if ((title.g_TitleImage = LoadGraph("images/BackGround_title.png")) == -1)return -1;
	//メニュー
	if ((g_Cone = LoadGraph("images/cone.bmp")) == -1)return -1;
	//リンゴ
	if ((Apple_Img[0] = LoadGraph("images/RedApple.png")) == -1)return -1;
	if ((Apple_Img[1] = LoadGraph("images/GreenApple.png")) == -1)return -1;
	if ((Apple_Img[2] = LoadGraph("images/YellowApple.png")) == -1)return -1;
	if ((Apple_Img[3] = LoadGraph("images/PurpleApple.png")) == -1)return -1;
	//アイテム
	if ((g_Item[0] = LoadGraph("images/gasoline.bmp")) == -1)return -1;
	if ((g_Item[1] = LoadGraph("images/supana.bmp")) == -1)return -1;
	
	//ステージ背景
	if ((g_StageImage = LoadGraph("images/BackGround.png")) == -1)return -1;
	//プレイヤー
	if ((g_Car_left = LoadGraph("images/PlayerA.png")) == -1)return -1;
	if ((g_Car_right = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Car_Nowangle = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Barrier = LoadGraph("images/barrier.png")) == -1)return -1;

	return 0;
}