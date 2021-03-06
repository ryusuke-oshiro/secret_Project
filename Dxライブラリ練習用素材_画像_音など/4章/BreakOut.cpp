///********************************************************************
//**	第４章　ゲームプログラミングの基本
//**	　ブロック崩しゲームの作成(2018)
//********************************************************************/
//#include "DxLib.h"
//
///***********************************************
// * 変数の宣言
// ***********************************************/
//int	g_OldKey;				// 前回の入力キー
//int	g_NowKey;				// 今回の入力キー
//int	g_KeyFlg;				// 入力キー情報
//
//int	g_MenuNumber = 0;		// メニューカーソル位置
//int g_MenuY;				// メニューカーソルのＹ座標
//
//int	g_TitleImage;			// 画像用変数
//int	g_RankingImage;			// 画像用変数
//int	g_EndImage;				// 画像用変数
//
//int	g_WaitTime = 0;			// 待ち時間
//int g_PosY;					// スクロール時のＹ座標
//
//int	g_Score = 0;			// スコア
//
//int	g_GameState = 0;		// ゲームステータス
//
//
//
//// ランキングデータ（構造体）
//struct	RankingData {
//	int		no;
//	char	name[11];
//	long	score;
//};
//// ランキングデータ変数宣言
//struct	RankingData		g_Ranking[10];
//
///***********************************************
// * 関数のプロトタイプ宣言
// ***********************************************/
//void GameInit(void);		//ゲーム初期化処理
//void GameMain(void);		//ゲームメイン処理
//
//void DrawGameTitle(void);	//ゲームタイトル処理
//void DrawEnd(void);			//ゲームエンド処理
//
//void DrawRanking(void);		//ランキング描画
//void InputRanking(void);	//ランキング入力
//void SortRanking(void);		//ランキング並べ替え
//int  SaveRanking(void);		//ランキングデータの保存
//int  ReadRanking(void);		//ランキングデータ読み込み
//
//
//
///***********************************************
// * プログラムの開始
// ***********************************************/
//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
//										 LPSTR lpCmdLine, int nCmdShow )
//{
//
//	// タイトルを test に変更
//	SetMainWindowText("ブロック崩し");
//
//	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
//
//	if ( DxLib_Init() == -1 ) return -1;	// DXライブラリの初期化処理
//	
//	//タイトル画像データの読み込み
//	if((g_TitleImage = LoadGraph("images/Title.bmp")) == -1) return -1;
//	//ランキング画像データの読み込み
//	if((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
//	//エンド画像データの読み込み
//	if((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
//
//	if  ( ReadRanking() == -1  )  return  -1;    //ランキングデータの読み込み
//	
//	SetDrawScreen( DX_SCREEN_BACK );	// 描画先画面を裏にする
//	
//	SetFontSize( 20 );		// 文字サイズを設定
//
//	// ゲームループ
//	while ( ProcessMessage() == 0 && g_GameState != 99){
//
//		// 入力キー取得
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// 画面の初期化
//
//		switch (g_GameState){
//			case 0:
//				DrawGameTitle();	//ゲームタイトル処理
//				break;
//			case 1:
//				GameInit();		//ゲーム初期処理
//				break;
//			case 2:
//				DrawRanking();	//ランキング描画処理
//				break;
//			case 3:
//				DrawEnd();		//エンド画面描画処理
//				break;
//			case 4:
//				GameMain();		//ゲームメイン処理
//				break;
//		}
//
//		ScreenFlip();			// 裏画面の内容を表画面に反映
//
//	}
//
//	DxLib_End();	// DXライブラリ使用の終了処理
//	
//	return 0;	// ソフトの終了
//}
//
///***********************************************
// * ランキング描画処理
// ***********************************************/
//void DrawRanking(void)
//{
//	// スペースキーでメニューに戻る
//	if(g_KeyFlg & PAD_INPUT_M) g_GameState = 0;
//
//	//ランキング画像表示
//	DrawGraph( 0 , 0 , g_RankingImage , FALSE ) ;
//
//	// ランキング一覧を表示
//	SetFontSize(30);
//	for( int i=0; i<10; i++ ){
//		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
//							 g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	// 文字の表示(点滅)
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
// * ランキング入力処理
// ***********************************************/
//void InputRanking(void)
//{
//	//ランキング画像表示
//	DrawGraph( 0 , 0 , g_RankingImage, FALSE );
//
//	// フォントサイズの設定
//	SetFontSize(20);
//
//	// 名前入力指示文字列の描画
//	DrawString( 150 , 240 , "ランキングに登録します" , 0xFFFFFF ) ;
//	DrawString( 150 , 270 , "名前を英字で入力してください" , 0xFFFFFF ) ;
//
//	// 名前の入力
//	DrawString( 150 , 310 , "> " , 0xFFFFFF ) ;
//	DrawBox( 160 , 305 , 300 , 335 , 0x000055 , TRUE) ;
//	if (KeyInputSingleCharString( 170 , 310 , 10 , g_Ranking[9].name , FALSE ) == 1){
//		g_Ranking[9].score = g_Score;	// ランキングデータの１０番目にスコアを登録
//		SortRanking();		// ランキング並べ替え
//		SaveRanking();		// ランキングデータの保存
//		g_GameState = 2;		// ゲームモードの変更
//	}
//
//}
//
///***********************************************
// * ランキング並べ替え
// ***********************************************/
//void SortRanking(void)
//{
//	int i, j;
//	RankingData work;
//
//	// 選択法ソート
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
//	// 順位付け
//	for(i=0; i<10; i++){
//		g_Ranking[i].no = 1;
//	}
//	// 得点が同じ場合は、同じ順位とする
//	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
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
// * ランキングデータの保存
// ***********************************************/
//int  SaveRanking(void)
//{
//	FILE *fp;
//	#pragma warning(disable:4996)
//
//	// ファイルオープン
//	if  ( ( fp = fopen("dat/rankingdata.txt", "w" ) )  ==  NULL )  {
//		/* エラー処理 */
//		printf( "Ranking Data Error\n" );
//		return -1;
//	}
//
//	// ランキングデータ分配列データを書き込む
//	for( int  i = 0 ;  i < 10 ;  i++ ) {
//		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	//ファイルクローズ
//	fclose(fp);
//
//	return 0;
//
//}
//
///*************************************
// * ランキングデータ読み込み
// *************************************/
//int ReadRanking(void)
//{
//	FILE *fp;
//	#pragma warning(disable:4996)
//
//	//ファイルオープン
//	if((fp = fopen("dat/rankingdata.txt","r"))== NULL){
//		//エラー処理
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	//ランキングデータ配分列データを読み込む
//	for( int i=0; i<10; i++){
//		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
//	}
//	
//	//ファイルクローズ
//	fclose(fp);
//
//	return 0;
//}
//
///***********************************************
// * ゲームタイトル表示（メニュー画面）
// ***********************************************/
//void DrawGameTitle(void)
//{
//	//メニューカーソル移動処理
//	if ( g_KeyFlg & PAD_INPUT_DOWN ){
//		if ( ++g_MenuNumber > 2 ) g_MenuNumber = 0;
//	}
//	if ( g_KeyFlg & PAD_INPUT_UP ){
//		if ( --g_MenuNumber < 0 ) g_MenuNumber = 2;
//	}
//	
//	// Ｚキーでメニュー選択
//	if(g_KeyFlg & PAD_INPUT_A) g_GameState = g_MenuNumber + 1;
//
//	//タイトル画像表示
//	DrawGraph( 0 , 0 , g_TitleImage, FALSE );
//
//	//メニューカーソル（三角形）の表示
//	g_MenuY = g_MenuNumber * 52;
//	DrawTriangle( 240, 255 + g_MenuY , 260, 270 + g_MenuY , 240, 285 + g_MenuY  , GetColor(255,0,0),TRUE);
//
//}
//
///***********************************************
// * ゲーム初期処理
// ***********************************************/
//void GameInit(void)
//{
//	// 変数の初期設定
//
//
//	g_GameState = 4;	// ゲームメイン処理へ
//}
//
///***********************************************
// * ゲームメイン
// ***********************************************/
//void GameMain(void)
//{
//	//ボールの描画
//
//}
//
///***********************************************
// * ゲームエンド描画処理（エンドロール）
// ***********************************************/
//void DrawEnd(void)
//{
//	//エンド画像表示
//	DrawGraph( 0 , 0 , g_EndImage , FALSE ) ;
//
//	//エンディング表示
//	if ( ++g_WaitTime < 600 ) g_PosY = 300 - g_WaitTime / 2;
//
//	SetFontSize(24);
//	DrawString(100, 170+g_PosY, "タイトル　　　Game　Title", 0xFFFFFF);
//	DrawString(100, 200+g_PosY, "バージョン　　1.0", 0xFFFFFF);
//	DrawString(100, 230+g_PosY, "最終更新日　　201x年xx月xx日", 0xFFFFFF);
//	DrawString(100, 260+g_PosY, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
//	DrawString(100, 290+g_PosY, "　　　　　　　ＸＸＸ　ＸＸ", 0xFFFFFF);
//	DrawString(100, 310+g_PosY, "素材利用", 0xFFFFFF);
//	DrawString(100, 340+g_PosY, "　BGM　　　 　ＸＸＸＸ", 0xFFFFFF);
//	DrawString(100, 365+g_PosY, "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0xFFFFFF);
//
//	//タイムの加算処理＆終了
//	if (++g_WaitTime > 900) g_GameState = 99;
//}
//
///***********************************************
// * ボールの描画処理
// ***********************************************/
