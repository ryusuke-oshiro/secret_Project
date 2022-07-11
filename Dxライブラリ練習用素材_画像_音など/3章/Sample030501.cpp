///******************************************************************** 
//** 第３章 ゲームプログラミングの基本 
//** （５）ランキング表示画面の作成 
//********************************************************************/ 
//#include "DxLib.h" 
// 
///*********************************************** 
// * 変数の宣言 
// ***********************************************/ 
//int g_OldKey;  // 前回の入力キー 
//int g_NowKey;  // 今回の入力キー 
//int g_KeyFlg;  // 入力キー情報
//
//int g_RankingImage;//画像用変数
//
//int g_WaitTime = 0;  //待ち時間
//
////ランキングデータ（構造体）
//struct RankingData{
//    int     no;
//    char    name[11];
//    long    score;
//};
////ランキングデータ初期化
//struct RankingData       g_Ranking[10]= {
//    {1,"**********",100000},
//    {2,"**********",50000},
//    {3,"**********",10000},
//    {4,"**********",5000},
//    {5,"**********",1000},
//    {6,"**********",500},
//    {7,"**********",100},
//    {8,"**********",50},
//    {9,"**********",10},
//    {10, "**********", 5},
//};
//void DrawRanking(void);
///*********************************************** 
// * プログラムの開始 
// ***********************************************/ 
//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,  
//     LPSTR lpCmdLine, int nCmdShow ) 
//{ 
// // ウィンドウモードで起動する 
// ChangeWindowMode(TRUE); 
// 
// // DX ライブラリの初期化処理:エラーが起きたら直ちに終了 
// if ( DxLib_Init() == -1 ) return -1; 
//
// //ランキング画像データ読み込み
// if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
// 
// // 描画先画面を裏にする 
// SetDrawScreen( DX_SCREEN_BACK ); 
// 
//
// // ゲームループ 
// while ( ProcessMessage() == 0 ){ 
//  // キー入力取得 
//  g_OldKey = g_NowKey; 
//  g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//  g_KeyFlg = g_NowKey & ~ g_OldKey; 
//   
//  if (g_KeyFlg & PAD_INPUT_M)break;
//
//  // 画面の初期化 
//  ClearDrawScreen(); 
// 
//  DrawRanking();//ランキング描画処理
//
//  // 裏画面の内容を表画面に反映します 
//  ScreenFlip(); 
// } 
// // DX ライブラリ使用の終了処理 
// DxLib_End(); 
// 
// // ソフトの終了 
// return 0; 
//} 
//
//void DrawRanking(void) 
//{
//    //ランキング画像表示
//    DrawGraph(0, 0, g_RankingImage, FALSE);
//
//    //ランキング一覧を表示
//    SetFontSize(30);
//    for (int i = 0; i < 10; i++) {
//        DrawFormatString(80, 170 + i * 25, 0x000000, "%2d %10s %10d", g_Ranking[i].no,g_Ranking[i].name, g_Ranking[i].score);
//    }
//
//    //文字の表示（点滅）
//    if (++g_WaitTime < 30) {
//        SetFontSize(24);
//        DrawString(150, 450, "-- Press[SPACE］Key --", 0xFF0000);
//    }
//    else if (g_WaitTime > 60) {
//        g_WaitTime = 0;
//    }
//}