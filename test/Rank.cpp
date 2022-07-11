//#include<stdio.h>
//#include "DxLib.h"
//#include"DrawGame.h"
//#include"Rank.h"
//#include"Block.h"
//
//
//RANK rank;
//RANK g_Ranking[10];
//RANK work;
//
//void RANK::DrawRanking()
//{
//	// スペースキーでメニューに戻る
//	if (dg.g_KeyFlg & PAD_INPUT_M) dg.g_GameState = 0;
//
//	//ランキング画像表示
//	DrawGraph(0, 0, dg.g_RankingImage, FALSE);
//
//	// ランキング一覧を表示
//	SetFontSize(30);
//	for (int i = 0; i < 10; i++) {
//		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d   %10s     %10d",
//			g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	// 文字の表示(点滅)
//	if (++dg.g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);
//	}
//	else if (dg.g_WaitTime > 60) {
//		dg.g_WaitTime = 0;
//	}
//
//}
//
//void RANK::InputRanking()
//{
//	//ランキング画像表示
//	DrawGraph(0, 0, dg.g_RankingImage, FALSE);
//
//	// フォントサイズの設定
//	SetFontSize(20);
//
//	// 名前入力指示文字列の描画
//	DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
//	DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);
//
//	// 名前の入力
//	DrawString(150, 310, "> ", 0xFFFFFF);
//	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
//	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9].name, FALSE) == 1) {
//		g_Ranking[9].score = block.g_Score;	// ランキングデータの１０番目にスコアを登録
//		SortRanking();		// ランキング並べ替え
//		SaveRanking();		// ランキングデータの保存
//		dg.g_GameState = 2;		// ゲームモードの変更
//	}
//
//}
//
//int  RANK::ReadRanking()
//{
//	FILE* fp;
//#pragma warning(disable:4996)
//
//	//ファイルオープン
//	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
//		//エラー処理
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	//ランキングデータ配分列データを読み込む
//	for (int i = 0; i < 10; i++) {
//		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
//	}
//
//	//ファイルクローズ
//	fclose(fp);
//
//	return 0;
//}
//
//int  RANK::SaveRanking()
//{
//	FILE* fp;
//#pragma warning(disable:4996)
//
//	// ファイルオープン
//	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
//		/* エラー処理 */
//		printf("Ranking Data Error\n");
//		return -1;
//	}
//
//	// ランキングデータ分配列データを書き込む
//	for (int i = 0; i < 10; i++) {
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
//void RANK::SortRanking()
//{
//	int i, j;
//
//
//
//	// 選択法ソート
//	for (i = 0; i < 9; i++) {
//		for (j = i + 1; j < 10; j++) {
//			if (g_Ranking[i].score <= g_Ranking[j].score) {
//				work = g_Ranking[i];
//				g_Ranking[i] = g_Ranking[j];
//				g_Ranking[j] = work;
//			}
//		}
//	}
//
//	// 順位付け
//	for (i = 0; i < 10; i++) {
//		g_Ranking[i].no = 1;
//	}
//	// 得点が同じ場合は、同じ順位とする
//	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
//	for (i = 0; i < 9; i++) {
//		for (j = i + 1; j < 10; j++) {
//			if (g_Ranking[i].score > g_Ranking[j].score) {
//				g_Ranking[j].no++;
//			}
//		}
//	}
//}