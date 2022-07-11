//#include<stdio.h>
//#include "DxLib.h"
//#include"Ball.h"
//#include"Bar.h"
//#include"DrawGame.h"
//#include"Rank.h"
//#include"Block.h"
//
//#define _USE_MATH_DEFINES
//#include<math.h>
//#define HEIGHT 10
//#define WIDTH 16
//#define STAGE 5
//
//BALL ball;
//
//BALL::BALL() {
//	g_BallX = 320;
//	g_BallY = 440 - 5;
//}
//
//void BALL::DrawBall()
//{
//	DrawCircle(g_BallX, g_BallY, 4, 0xFFD700, TRUE);
//}
//
//void BALL::ChangeAngle() {
//	float rad = ball.g_BallAngle * (float)M_PI * 2;
//	g_MoveX = (int)(g_Speed * cosf(rad));
//	g_MoveY = (int)(g_Speed * sinf(rad));
//}
//
//void BALL::MoveBall() {
//
//	/*ボールの移動*/
//	if (g_BallFlg != 2) {
//		g_BallX += g_MoveX;
//		g_BallY += g_MoveY;
//	}
//	else {
//		g_BallX = bar.g_BarX + 30;
//		g_BallY = bar.g_BarY - 6;
//	}
//
//	/*壁・天井での反射*/
//	if (g_BallX < 4 || g_BallX > 640 - 4) {		//横の壁
//		if (g_BallX < 4) {
//			g_BallX = 4;
//		}
//		else {
//			g_BallX = 640 - 4;
//		}
//
//		g_BallAngle = (1 - g_BallAngle) + 0.5f;
//		if (g_BallAngle > 1)g_BallAngle -= 1.0f;
//		ChangeAngle();
//	}
//
//	if (g_BallY < 8) {				//上の壁
//		g_BallAngle = (1 - g_BallAngle);
//		ChangeAngle();
//	}
//	/*画面下を超えたらゲームオーバー*/
//	if (g_BallY > 480 + 4)dg.g_GameState = 5;
//
//	if (g_BallY > 480 + 4) {
//		g_BallFlg = 2;
//		if (--g_RestBall < 0) {
//			if (block.g_Score >= g_Ranking[9].score) {
//				dg.g_GameState = 7; //ランキング入力処理へ
//			}
//			else {
//				dg.g_GameState = 5; //ゲームオーバー処理へ
//			}
//		}
//	}
//}
//
//void BALL::HitBlock()
//{
//	//ボールとブロックの当たり判定
//	int x = ball.g_BallX / 40;
//	int y = (ball.g_BallY - 80) / 16;
//
//	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && g_Block[y][x].flg != 0) {
//		g_Block[y][x].flg = 0;
//
//		g_Block[y][x].flg = 0;
//
//		ball.g_BallAngle = (1 - ball.g_BallAngle);
//		ball.ChangeAngle();
//		block.g_Score += g_Block[y][x].score;
//		if (block.CheckBlock() == 0)dg.g_GameState = 6;
//	}
//}