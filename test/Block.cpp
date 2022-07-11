//#include<stdio.h>
//#include "DxLib.h"
//#include"Block.h"
//#include"Ball.h"
//
//BLOCK g_Block[HEIGHT][WIDTH];
//BLOCK block;
//
//BLOCK::BLOCK()
//{
//	g_Stage = 0;
//	g_Score = 0;
//}
//
//void BLOCK::InitBlock()
//{
//	//ブロック配列の初期化
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			if (g_BlockData[g_Stage][i][j] != 0) {
//				g_Block[i][j].flg = 1;
//				g_Block[i][j].x = j * 40;
//				g_Block[i][j].y = i * 16 + 80;
//				g_Block[i][j].w = 40;
//				g_Block[i][j].h = 8;
//				g_Block[i][j].image = g_BlockData[g_Stage][i][j];
//				g_Block[i][j].score = g_Block[i][j].image * 10;
//				ball.g_BallFlg = 2;
//			}
//		}
//	}
//}
//
//void BLOCK::DrawBlock()
//{
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			if (g_Block[i][j].flg == 1) {
//				DrawGraph(g_Block[i][j].x, g_Block[i][j].y, g_BlockImage[g_Block[i][j].image], TRUE);
//			}
//		}
//	}
//}
//
//int BLOCK::CheckBlock()
//{
//
//	//ブロック配列の初期化
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			if (g_Block[i][j].flg == 1)	return -1;
//		}
//	}
//	return 0;
//}
//
//void BLOCK::DrawScore() {
//
//	DrawFormatString(20, 20, 0xFFFFFF, "SCORE:%06d", g_Score);
//	SetFontSize(10);
//	DrawFormatString(600, 460, 0xFFD700, "● x%d", ball.g_RestBall);
//}