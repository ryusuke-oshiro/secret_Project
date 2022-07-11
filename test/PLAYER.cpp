#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
#include"Common.h"

PLAYER g_player;

PLAYER::PLAYER() {
	flg = 0;
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	angle = 0.0;
	count = 0;
	speed = 0;
	hp = 0;
	fuel = 0;
	bari = 0;
	baricnt = 0;
	bariup = 0;
}

void PLAYER::InitPlayer() {
	//プレイヤーの初期設定
	flg = TRUE;
	x = 320;
	y = 380;
	w = 63;
	h = 120;
	angle = 0.0;
	count = 0;
	speed = 5;
	hp = 1000;
	fuel = 20000;
	bari = 3;
	bariup = 10;
}

void PLAYER::PlayerControl() {
	//上下左右移動
	if (g_player.flg == TRUE) {
		if (g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
		if (g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	}

	//画面をはみ出さないようにする
	if (g_player.x < 32)g_player.x = 32;
	if (g_player.x > SCREEN_WIDTH - 180)g_player.x = SCREEN_WIDTH - 180;


	//プレイヤーの表示
	if (g_player.flg == TRUE) {
		if (g_NowKey & PAD_INPUT_LEFT) {
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, -M_PI / 18, g_Car_left, TRUE, FALSE);
			g_Car_Nowangle = g_Car_left;
		}
		else if (g_NowKey & PAD_INPUT_RIGHT) {
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 18, g_Car_right, TRUE, FALSE);
			g_Car_Nowangle = g_Car_right;
		}
		else {
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
		}
		//if (g_KeyFlg & PAD_INPUT_C && g_player.bari > 0 && g_player.baricnt <= 0) {	//バリア？
		//	g_player.bari--;
		//	g_player.baricnt = 1000;
		//}
	
	}
	else {		//player.flgがFALSE(リンゴにあたって)になった時
		DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 8 * (++g_player.count / 5), g_Car_Nowangle, TRUE, FALSE);
		if (g_player.count >= 80)g_player.flg = TRUE;
	}


	DrawRotaGraph(513, 200, 1.0f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(563, 200, 1.0f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(613, 205, 0.7f, 0, Apple_Img[2], TRUE, FALSE);


	/*DrawFormatString(510, 140, 0xFFFFFF, "%03d", RedAppleScore);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", GreenAppleScore);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", YellowAppleScore);*/

}


int PLAYER::HitBoxPlayer(PLAYER* p, APPLE* e)
{
	//x,yは中心座標とする
	int sx1 = p->x - (p->w / 2);
	int sy1 = p->y - (p->h / 2);
	int sx2 = sx1 + p->w;
	int sy2 = sy1 + p->h;

	int dx1 = e->x - (e->w / 2);
	int dy1 = e->y - (e->h / 2);
	int dx2 = dx1 + e->w;
	int dy2 = dy1 + e->h;

	//矩形が重なっていれば当たり
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		return TRUE;
	}
	return FALSE;
}


//
//void PlayerControl::MovePlayer() {
//
//    //左右移動
//    if (player.flg == TRUE) {
//        if (input.ThumbLX < -17500) {		//左入力
//            if (player.speed > -10) {
//                player.speed -= 0.5;
//            }
//            player.x += player.speed;
//        }
//        else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {		//離したとき
//            if (player.speed > 0) {			//”離す”かつ加速が正の数
//                player.speed -= 0.5;
//                player.x += player.speed;
//            }
//            else if (player.speed < 0) {	//”離す”かつ加速が負の時
//                player.speed += 0.5;
//                player.x += player.speed;
//            }
//        }
//        if (input.ThumbLX > 17500) {		//右入力
//            if (player.speed < 10) {
//                player.speed += 0.5;
//            }
//            player.x += player.speed;
//        }
//        else if (input.ThumbLX < 17500 && input.ThumbLX>128) {	//離したとき
//
//            if (player.speed > 0) {			//”離す”かつ加速が正の時
//                player.speed -= 0.5;
//                player.x -= player.speed;
//            }
//            else if (player.speed < 0) {	//”離す”かつ加速が負の時
//                player.speed += 0.5;
//                player.x += player.speed;
//            }
//        }
//    }
//
//    //画面をはみ出さないようにする
//    if (player.x < 32)player.x = 32;
//    if (player.x >460)player.x = 460;
//}

