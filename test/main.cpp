///********************************************************************
//**	第４章　ゲームプログラミングの基本
//**	　ブロック崩しゲームの作成(2018)
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
// * 変数の宣言
// ***********************************************/
//int	g_OldKey;				// 前回の入力キー
//int	g_NowKey;				// 今回の入力キー
////int	g_KeyFlg;				// 入力キー情報
//
////int	g_MenuNumber = 0;		// メニューカーソル位置
///*int g_MenuY;*/				// メニューカーソルのＹ座標
//
////int	g_TitleImage;			// 画像用変数
////int	g_RankingImage;			// 画像用変数
////int	g_EndImage;				// 画像用変数
//
////int	g_WaitTime = 0;			// 待ち時間
///*int g_PosY;*/					// スクロール時のＹ座標
//
////int	g_Score = 0;			// スコア
////
////int	g_GameState = 0;		// ゲームステータス
//
//
///*int g_BallX, g_BallY;*/				//ボールの座標
//
////int g_MoveX, g_MoveY;				//ボールの移動量
////
////int g_Speed;				//ボールのスピード
///*float g_BallAngle;*/			//ボールの角度
//
////int g_BarX;					//バーの座標
////int g_BarY;
//
////int g_MouseX, g_MouseY;		//マウスの座標
//
///*int g_BallFlg;*/				//ボールの状態（0...移動中　1...バー接触）
//
////int g_BlockImage[8]; //ブロック画像用変数
//
////int g_RestBall;		//残りボール処理
//
///*int g_Stage = 0;*/	//ステージ用変数
//
////  数字の色は　黒(0)　赤(1)　緑(2)　 黄色(3)　　青(4)　ピンク(5)　水色(6)　　白(7)
////  ＜注意＞黒はブロックなし
//
////int	g_BlockData[STAGE][HEIGHT][WIDTH] = {	// ブロック配列
////	{	// 0ｽﾃｰｼﾞ
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
////	{	// 1ｽﾃｰｼﾞ
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
////	{	// 2ｽﾃｰｼﾞ
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
////	{	// 3ｽﾃｰｼﾞ
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
////	{	// 4ｽﾃｰｼﾞ
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
//// ランキングデータ（構造体）
////struct	RankingData {
////	int		no;
////	char	name[11];
////	long	score;
////};
//// ランキングデータ変数宣言
////struct	RankingData		g_Ranking[10];
//
////ブロックデータ（構造体の定義）
////struct ObjectBlock {
////	int flg;
////	int x, y;
////	int w, h;
////	int mx, my;
////	int image;
////	int score;
////};
//////ブロックデータの宣言
////struct ObjectBlock g_Block[HEIGHT][WIDTH];
//
///***********************************************
// * 関数のプロトタイプ宣言
// ***********************************************/
//void GameInit(void);//ゲーム初期化処理
//void GameMain(void);//ゲームメイン処理
//
////void DrawGameTitle(void);	//ゲームタイトル処理
////void DrawEnd(void);			//ゲームエンド処理
//
///*void DrawBall(void);*/		//ボールの描画
///*void DrawBar(void);*///バーの描画処理
///*void MoveBall(void);*/		//ボールの移動
///*void DrawRanking(void);	*/	//ランキング描画
////void InputRanking(void);	//ランキング入力
////void SortRanking(void);		//ランキング並べ替え
////int  SaveRanking(void);		//ランキングデータの保存
////int  ReadRanking(void);		//ランキングデータ読み込み
////void DrawGameOver(void);  //ゲームオーバー描画処理
////void DrawGameClear(void);//ゲームクリア描画処理
///*void ChangeAngle(void);*///角度変更処理
///*void InitBlock(void);*///ブロック初期処理
////void MoveBar(void);//バーの移動処理
////void HitBar(void);//ボールとバーの当たり判定
///*void HitBlock(void);*///ボールとブロックの当たり判定
///*void DrawBlock(void);*///ボール描画処理
///*void DrawScore(void);*///スコア描画処理
///*int CheckBlock(void);*///ブロックチェック処理
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
//	if((dg.g_TitleImage = LoadGraph("images/Title.bmp")) == -1) return -1;
//	//ランキング画像データの読み込み
//	if((dg.g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
//	//エンド画像データの読み込み
//	if((dg.g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
//
//	if  ( rank.ReadRanking() == -1  )  return  -1;    //ランキングデータの読み込み
//	
//	SetDrawScreen( DX_SCREEN_BACK );	// 描画先画面を裏にする
//	
//	SetFontSize( 20 );		// 文字サイズを設定
//
//	//ブロック画像データの読み込み
//	if (LoadDivGraph("images/block.bmp", 8, 8, 1, 40, 8, block.g_BlockImage) == -1)return -1;
//
//	// ゲームループ
//	while ( ProcessMessage() == 0 && dg.g_GameState != 99){
//
//		// 入力キー取得
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
//		dg.g_KeyFlg = g_NowKey & ~g_OldKey;
//
//		ClearDrawScreen();		// 画面の初期化
//
//		switch (dg.g_GameState){
//			case 0:
//				dg.DrawGameTitle();	//ゲームタイトル処理
//				break;
//			case 1:
//				GameInit();		//ゲーム初期処理
//				break;
//			case 2:
//				rank.DrawRanking();	//ランキング描画処理
//				break;
//			case 3:
//				dg.DrawEnd();		//エンド画面描画処理
//				break;
//			case 4:
//				GameMain();		//ゲームメイン処理
//				break;
//			case 5:
//				dg.DrawGameOver(); //ゲームオーバー描画処理
//				break;
//			case 6:
//				dg.DrawGameClear();//ゲームクリア描画処理
//				break;
//			case 7:
//				rank.InputRanking(); //ランキング入力処理
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
// * ゲーム初期処理
// ***********************************************/
//
//void GameInit(void)
//{
//	/*変数の初期設定*/
//	/*ball.g_BallX = 320;
//	ball.g_BallY = 440 - 5;*/
//	/*bar.g_BarX = 290;
//	bar.g_BarY = 440;*/
//	ball.g_MoveX = 1;
//	ball.g_MoveY = -2;
//	dg.g_GameState = 4;	// ゲームメイン処理へ
//	ball.g_RestBall = 2;		//残りボールの設定
//	block.InitBlock();
//}
//
//
///***********************************************
// * ゲームメイン
// ***********************************************/
//void GameMain(void)
//{
//
//	bar.MoveBar();//バーの移動処理
//	ball.MoveBall();//ボールの移動
//	bar.HitBar();//ボールとバーの当たり判定
//	ball.HitBlock();//ボールとブロックの当たり判定
//	ball.DrawBall();
//	bar.DrawBar();//バーの描画
//	block.DrawBlock();//ブロックを描画する
//	block.DrawScore();//スコアを描画する
//}
//
///***********************************************
// * ランキング描画処理
// ***********************************************/
////void DrawRanking(void)
////{
////	// スペースキーでメニューに戻る
////	if(g_KeyFlg & PAD_INPUT_M) g_GameState = 0;
////
////	//ランキング画像表示
////	DrawGraph( 0 , 0 , g_RankingImage , FALSE ) ;
////
////	// ランキング一覧を表示
////	SetFontSize(30);
////	for( int i=0; i<10; i++ ){
////		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
////							 g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
////	}
////
////	// 文字の表示(点滅)
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
// * ランキング入力処理
// ***********************************************/
////void InputRanking(void)
////{
////	//ランキング画像表示
////	DrawGraph( 0 , 0 , g_RankingImage, FALSE );
////
////	// フォントサイズの設定
////	SetFontSize(20);
////
////	// 名前入力指示文字列の描画
////	DrawString( 150 , 240 , "ランキングに登録します" , 0xFFFFFF ) ;
////	DrawString( 150 , 270 , "名前を英字で入力してください" , 0xFFFFFF ) ;
////
////	// 名前の入力
////	DrawString( 150 , 310 , "> " , 0xFFFFFF ) ;
////	DrawBox( 160 , 305 , 300 , 335 , 0x000055 , TRUE) ;
////	if (KeyInputSingleCharString( 170 , 310 , 10 , g_Ranking[9].name , FALSE ) == 1){
////		g_Ranking[9].score = g_Score;	// ランキングデータの１０番目にスコアを登録
////		SortRanking();		// ランキング並べ替え
////		SaveRanking();		// ランキングデータの保存
////		g_GameState = 2;		// ゲームモードの変更
////	}
////
////}
//
///***********************************************
// * ランキング並べ替え
// ***********************************************/
////void SortRanking(void)
////{
////	int i, j;
////	RankingData work;
////
////	// 選択法ソート
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
////	// 順位付け
////	for(i=0; i<10; i++){
////		g_Ranking[i].no = 1;
////	}
////	// 得点が同じ場合は、同じ順位とする
////	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
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
// * ランキングデータの保存
// ***********************************************/
////int  SaveRanking(void)
////{
////	FILE *fp;
////	#pragma warning(disable:4996)
////
////	// ファイルオープン
////	if  ( ( fp = fopen("dat/rankingdata.txt", "w" ) )  ==  NULL )  {
////		/* エラー処理 */
////		printf( "Ranking Data Error\n" );
////		return -1;
////	}
////
////	// ランキングデータ分配列データを書き込む
////	for( int  i = 0 ;  i < 10 ;  i++ ) {
////		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
////	}
////
////	//ファイルクローズ
////	fclose(fp);
////
////	return 0;
////
////}
//
///*************************************
// * ランキングデータ読み込み
// *************************************/
////int ReadRanking(void)
////{
////	FILE *fp;
////	#pragma warning(disable:4996)
////
////	//ファイルオープン
////	if((fp = fopen("dat/rankingdata.txt","r"))== NULL){
////		//エラー処理
////		printf("Ranking Data Error\n");
////		return -1;
////	}
////
////	//ランキングデータ配分列データを読み込む
////	for( int i=0; i<10; i++){
////		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
////	}
////	
////	//ファイルクローズ
////	fclose(fp);
////
////	return 0;
////}
//
///***********************************************
// * ゲームタイトル表示（メニュー画面）
// ***********************************************/
////void DrawGameTitle(void)
////{
////	//メニューカーソル移動処理
////	if ( g_KeyFlg & PAD_INPUT_DOWN ){
////		if ( ++g_MenuNumber > 2 ) g_MenuNumber = 0;
////	}
////	if ( g_KeyFlg & PAD_INPUT_UP ){
////		if ( --g_MenuNumber < 0 ) g_MenuNumber = 2;
////	}
////	
////	// Ｚキーでメニュー選択
////	if(g_KeyFlg & PAD_INPUT_A) g_GameState = g_MenuNumber + 1;
////
////	//タイトル画像表示
////	DrawGraph( 0 , 0 , g_TitleImage, FALSE );
////
////	//メニューカーソル（三角形）の表示
////	g_MenuY = g_MenuNumber * 52;
////	DrawTriangle( 240, 255 + g_MenuY , 260, 270 + g_MenuY , 240, 285 + g_MenuY  , GetColor(255,0,0),TRUE);
////
////}
//
/////***********************************************
//// * ゲーム初期処理
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
////	///*変数の初期設定*/
////	//ball.g_BallX = 320;
////	//ball.g_BallY = 440 - 5;
////	g_MoveX = 1;
////	g_MoveY = -2;
////	g_BarX = 290;
////	g_BarY = 440;
////	g_GameState = 4;	// ゲームメイン処理へ
////	g_RestBall = 2;		//残りボールの設定
////	InitBlock();
////}
////
////
/////***********************************************
//// * ゲームメイン
//// ***********************************************/
////void GameMain(void)
////{
////
////	MoveBar();//バーの移動処理
////	MoveBall();//ボールの移動
////	HitBar();//ボールとバーの当たり判定
////	HitBlock();//ボールとブロックの当たり判定
////	
////	
////	ball.DrawBall();
////	
////	DrawBar();//バーの描画
////	DrawBlock();//ブロックを描画する
////	DrawScore();//スコアを描画する
////}
//
///***********************************************
// * ゲームエンド描画処理（エンドロール）
// ***********************************************/
////void DrawEnd(void)
////{
////	//エンド画像表示
////	DrawGraph( 0 , 0 , g_EndImage , FALSE ) ;
////
////	//エンディング表示
////	if ( ++g_WaitTime < 600 ) g_PosY = 300 - g_WaitTime / 2;
////
////	SetFontSize(24);
////	DrawString(100, 170+g_PosY, "タイトル　　　Game　Title", 0xFFFFFF);
////	DrawString(100, 200+g_PosY, "バージョン　　1.0", 0xFFFFFF);
////	DrawString(100, 230+g_PosY, "最終更新日　　201x年xx月xx日", 0xFFFFFF);
////	DrawString(100, 260+g_PosY, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
////	DrawString(100, 290+g_PosY, "　　　　　　　ＸＸＸ　ＸＸ", 0xFFFFFF);
////	DrawString(100, 310+g_PosY, "素材利用", 0xFFFFFF);
////	DrawString(100, 340+g_PosY, "　BGM　　　 　ＸＸＸＸ", 0xFFFFFF);
////	DrawString(100, 365+g_PosY, "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0xFFFFFF);
////
////	//タイムの加算処理＆終了
////	if (++g_WaitTime > 900) g_GameState = 99;
////}
//
///***********************************************
// * ボールの描画処理
// ***********************************************/
////void DrawBall(void) {
////	DrawCircle(g_BallX, g_BallY, 4, 0xFFD700, TRUE);
////}
//
///***********************************************
//*バーの描画処理
//************************************************/
////void DrawBar(void) {
////	//バーの描画
////	DrawBox(g_BarX, g_BarY, g_BarX + 60, g_BarY + 8, 0xFFD700, TRUE);
////}
//
///**********************************************
//*ボールとバーの当たり判定
//***********************************************/
////void HitBar(void) {
////	
////	int mx0, mx1, my0, my1, sx0, sx1, sy0, sy1;
////
////	//座標位置の事前計算
////	mx0 = ball.g_BallX - 4;
////	mx1 = ball.g_BallX + 4;
////	my0 = ball.g_BallY - 4;
////	my1 = ball.g_BallY + 4;
////	sx0 = bar.g_BarX;
////	sx1 = bar.g_BarX + 60;
////	sy0 = bar.g_BarY;
////	sy1 = bar.g_BarY + 8;
////	//ボールとバーの当たり判定
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
//*ボールとブロックの当たり判定
//****************************************************************/
////void HitBlock(void) {
////	
////	//ボールとブロックの当たり判定
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
// *ボールの移動処理
// **********************************************/
////void MoveBall(void) {
////	
////	/*ボールの移動*/
////	if (ball.g_BallFlg != 2) {
////		ball.g_BallX += ball.g_MoveX;
////		ball.g_BallY += ball.g_MoveY;
////	}
////	else {
////		ball.g_BallX = bar.g_BarX + 30;
////		ball.g_BallY = bar.g_BarY - 6;
////	}
////
////	/*壁・天井での反射*/
////	if (ball.g_BallX < 4 || ball.g_BallX > 640 - 4) {		//横の壁
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
////	if (ball.g_BallY < 8) {				//上の壁
////		ball.g_BallAngle = (1 - ball.g_BallAngle);
////		ball.ChangeAngle();
////	}
////	/*画面下を超えたらゲームオーバー*/
////	if (ball.g_BallY > 480 + 4)dg.g_GameState = 5;
////
////	if (ball.g_BallY > 480 + 4) {
////		ball.g_BallFlg = 2;
////		if (--ball.g_RestBall < 0) {
////			if (score.g_Score >= g_Ranking[9].score) {
////				dg.g_GameState = 7; //ランキング入力処理へ
////			}
////			else {
////				dg.g_GameState = 5; //ゲームオーバー処理へ
////			}
////		}
////	}
////}
///************************************************
//*バー移動処理
//*************************************************/
////void MoveBar(void) {
////	//マウスから座標を読み取る
////	GetMousePoint(&g_MouseX, &g_MouseY);
////
////	bar.g_BarX = g_MouseX;
////	if (bar.g_BarX < 0) {
////		bar.g_BarX = 0;
////	}else if (bar.g_BarX > 640 - 60) {
////		bar.g_BarX = 580;
////	}
////	//マウス左クリックでゲームスタート
////	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && ball.g_BallFlg == 2) {
////		ball.g_BallFlg = 0;
////		//スピードとアングルによる移動量計算
////		ball.g_Speed = 5;
////		ball.g_BallAngle = 0.625f;
////		ball.ChangeAngle();
////	}
////}
//
///************************************************
//*角度変更処理
//*************************************************/
////void ChangeAngle(void) {
////	float rad = ball.g_BallAngle * (float)M_PI * 2;
////	g_MoveX = (int)(g_Speed * cosf(rad));
////	g_MoveY = (int)(g_Speed * sinf(rad));
////}
//
///************************************************
//*ゲームオーバー画面描画処理
//*************************************************/
////void DrawGameOver(void)
////{
////	//スペースキーでメニューに戻る
////	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
////
////	SetFontSize(48);
////	DrawString(200, 200, "Game Over", GetColor(255, 0, 0));
////
////		//文字の表示(点滅)
////	if (++g_WaitTime < 30) {
////		SetFontSize(24);
////		DrawString(150, 450, "-- Press[SPACE]Key --", GetColor(255, 0, 0));
////	}else if (g_WaitTime > 60) {
////		g_WaitTime = 0;
////	}
////}
///******************************************************************************
//*ブロック初期処理
//*******************************************************************************/
////void InitBlock(void) {
////
////	//ブロック配列の初期化
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
//*ブロック描画処理
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
//*スコア描画処理
//************************************************************************************/
////void DrawScore(void) {
////
////	DrawFormatString(20, 20, 0xFFFFFF, "SCORE:%06d", g_Score);
////	SetFontSize(10);
////	DrawFormatString(600, 460, 0xFFD700, "● x%d", g_RestBall);
////}
///*****************************************
//*ブロックチェック処理
//******************************************/
////int CheckBlock(void) {
////
////	//ブロック配列の初期化
////	for (int i = 0; i < HEIGHT; i++) {
////		for (int j = 0; j < WIDTH; j++) {
////			if (g_Block[i][j].flg == 1)	return -1;
////		}
////	}
////	return 0;
////}
///*****************************************:
//*ゲームクリア画面描画処理
//******************************************/
////void DrawGameClear(void)
////{
////	//スペースキーでNEXTステージへ
////	if (g_KeyFlg & PAD_INPUT_M) {
////		g_GameState = 4;
////		if (++g_Stage > 4)g_Stage = 0;
////		InitBlock();
////	}
////	SetFontSize(48);
////	DrawString(120, 200, "Congratulations", 0x7F00F0);
////	//文字の表示（点滅）
////	if (++g_WaitTime < 30) {
////		SetFontSize(24);
////		DrawString(150, 450, "-- Press[SPACE]Key --", 0xFF0000);
////	}else if(g_WaitTime > 60){
////		g_WaitTime = 0;
////	}
////}