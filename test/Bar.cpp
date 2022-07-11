//#include<stdio.h>
//#include "DxLib.h"
//#include"Bar.h"
//#include"Ball.h"
//
//BAR bar;
//
//BAR::BAR()
//{
//	g_BarX = 290;
//	g_BarY = 440;
//}
//
//void BAR::DrawBar()
//{
//	DrawBox(g_BarX, g_BarY, g_BarX + 60, g_BarY + 8, 0xFFD700, TRUE);
//}
//
//void BAR::MoveBar()
//{
//	//マウスから座標を読み取る
//	GetMousePoint(&g_MouseX, &g_MouseY);
//
//	bar.g_BarX = g_MouseX;
//	if (bar.g_BarX < 0) {
//		bar.g_BarX = 0;
//	}
//	else if (bar.g_BarX > 640 - 60) {
//		bar.g_BarX = 580;
//	}
//	//マウス左クリックでゲームスタート
//	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && ball.g_BallFlg == 2) {
//		ball.g_BallFlg = 0;
//		//スピードとアングルによる移動量計算
//		ball.g_Speed = 5;
//		ball.g_BallAngle = 0.625f;
//		ball.ChangeAngle();
//	}
//}
//
//void BAR::HitBar()
//{
//	int mx0, mx1, my0, my1, sx0, sx1, sy0, sy1;
//
//	//座標位置の事前計算
//	mx0 = ball.g_BallX - 4;
//	mx1 = ball.g_BallX + 4;
//	my0 = ball.g_BallY - 4;
//	my1 = ball.g_BallY + 4;
//	sx0 = bar.g_BarX;
//	sx1 = bar.g_BarX + 60;
//	sy0 = bar.g_BarY;
//	sy1 = bar.g_BarY + 8;
//	//ボールとバーの当たり判定
//	if (sx0 <= mx1 && sx1 >= mx0 && sy0 <= my1 && sy1 >= my0) {
//		if (ball.g_BallFlg == 0) {
//			ball.g_BallAngle = (0.3f / 60) * (mx1 - sx0) + 0.6f;
//			ball.ChangeAngle();
//			ball.g_BallFlg = 1;
//		}
//	}
//	else {
//		if (ball.g_BallFlg != 2)ball.g_BallFlg = 0;
//	}
//}