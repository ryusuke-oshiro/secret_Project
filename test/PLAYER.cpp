#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
#include"Common.h"

PLAYER g_player;

PLAYER::PLAYER() {
	flg = 0;
	tenmetu = 0;
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
	tenmetu = FALSE;
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
	////上下左右移動
	//if (g_player.flg == TRUE) {
	//	if (g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
	//	if (g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	//}

	//画面をはみ出さないようにする
	if (g_player.x < 32)g_player.x = 32;
	if (g_player.x > SCREEN_WIDTH - 180)g_player.x = SCREEN_WIDTH - 180;


	//プレイヤーの表示
	if (g_player.flg == TRUE) {
		if (g_NowKey & PAD_INPUT_LEFT) {
			g_player.x -= g_player.speed;
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, -M_PI / 18, g_Car_left, TRUE, FALSE);
			g_Car_Nowangle = g_Car_left;
		}
		else if (g_NowKey & PAD_INPUT_RIGHT) {
			g_player.x += g_player.speed;
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 18, g_Car_right, TRUE, FALSE);
			g_Car_Nowangle = g_Car_right;
		}
		else {
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
		}
	
	}
	else {		//player.flg = FALSE->表示状態		player.tenmetu = TRUE->非表示状態
		g_player.count = ++g_player.count;
		if (g_player.tenmetu==TRUE) {
			PlayerTenmetuON();										//非表示
			if (g_player.count % 20 == 0)g_player.tenmetu = FALSE; 
		}
		if (g_player.tenmetu == FALSE) {
			PlayerTenmetuOFF();										//表示
			if (g_player.count % 20 == 0)g_player.tenmetu = TRUE;
		}
		if (g_player.count >= 120) {
			g_player.flg = TRUE; g_player.count = 0;
		}
	}

	DrawRotaGraph(520, 110, 0.9f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(570, 110, 0.9f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(620, 110, 0.9f, 0, Apple_Img[2], TRUE, FALSE);

	DrawFormatString(510, 140, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", AppleCount3);

	StartTime = GetNowCount()-Time;
	
	DrawFormatString(510, 200, 0xFFFFFF, "%02d", 30-StartTime/1000);
	
	if (StartTime >= 30000) {		//制限時間30秒たったらGameState=6 -> ランキング入力へ！
		g_GameState = 6;
		StopSoundMem(g_MusicBGM);
	}
	

}

void PLAYER::PlayerTenmetuON() {
		if (g_NowKey & PAD_INPUT_LEFT) {
			g_player.x -= g_player.speed;
			g_Car_Nowangle = g_Car_left;
		}
		if (g_NowKey & PAD_INPUT_RIGHT) {
			g_player.x += g_player.speed;
			g_Car_Nowangle = g_Car_right;
		}
}

void PLAYER::PlayerTenmetuOFF() {
		if (g_NowKey & PAD_INPUT_LEFT) {
			g_player.x -= g_player.speed;
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, -M_PI / 18, g_Car_left, TRUE, FALSE);
			g_Car_Nowangle = g_Car_left;
		}
		else if (g_NowKey & PAD_INPUT_RIGHT) {
			g_player.x += g_player.speed;
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 18, g_Car_right, TRUE, FALSE);
			g_Car_Nowangle = g_Car_right;
		}
		else {
			DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
		}
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

