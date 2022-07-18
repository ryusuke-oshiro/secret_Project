#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
#include"POSE.h"
#include"RANKING.h"
#include"Common.h"

PLAYER g_player;

PLAYER::PLAYER() {
	flg = TRUE;
	tenmetu = 0;
	x = 0.0;
	y = 0;
	w = 0;
	h = 0;
	angle = 0.0;
	count = 0;
	speed = 0.0;
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
	x = 320; //320
	y = 380;
	w = 50; //63
	h = 67;
	angle = 0.0;
	count = 0;
	speed = 0.0;
	hp = 1000;
	fuel = 20000;
	bari = 3;
	bariup = 10;
}

void PLAYER::PlayerControl() {

	//慣性移動
	if (input.ThumbLX < -17500) {	//左入力
		if (g_player.speed > -3) {	//speedが 0 ～ -2.9 は-0.1ずつ
			g_player.speed -= 0.1;
		}
		if (g_player.speed > -4) {	//speedが -3 ～ -3.9 は-0.2ずつ
			g_player.speed -= 0.2;
		}
		if (g_player.speed >= -5) {	//speedが -4 ～ -5 は-0.3ずつ
			g_player.speed -= 0.3;
		}
		if (g_player.speed < -5) {							//最大速度の設定
			g_player.speed -= 0.6;
		}
		if (g_player.speed < -7) {
			g_player.speed = -7;
		}
		g_Car_Nowangle = g_Car_left;						//左入力が入ったらplayerを左に向ける
	}

	if (input.ThumbLX > 17500) {	//右入力
		if (g_player.speed < 3) {	//speedが0～2.9は+0.1ずつ
			g_player.speed += 0.1;
		}
		if (g_player.speed < 4) {	//speedが3～3.9は+0.2ずつ
			g_player.speed += 0.2;
		}
		if (g_player.speed <= 5) {	//speedが4～5は+0.3ずつ
			g_player.speed += 0.3;
		}
		if (g_player.speed > 5) {							//最大速度の設定
			g_player.speed += 0.6;
		}
		if (g_player.speed > 7) {
			g_player.speed = 7;
		}
		g_Car_Nowangle = g_Car_right;						//右入力が入ったらplayerを右に向ける
	}


	if (input.ThumbLX >= -17500 && input.ThumbLX <= 17500) {	//離した時
		if (g_player.speed < 0) {								//加速がマイナスだったら足していく
			g_player.speed += 0.7;	
			if (g_player.speed > 0) {							//もしspeedが0になったら止める							
				g_player.speed = 0;
			}
		}
		else if (g_player.speed > 0) {							//加速がプラスだったら引いていく
			g_player.speed -= 0.7;
			if (g_player.speed < 0) {							//もしspeedが0になったら止める
				g_player.speed = 0;
			}
		}
	}

	g_player.x += g_player.speed;

	//画面をはみ出さないようにする
	if (g_player.x < 32) {
		g_player.x = 32;
		g_player.speed = 0;
	}

	if (g_player.x > 460) {
		g_player.x = 460;
		g_player.speed = 0;
	}

	if (g_player.flg == TRUE) {		//TRUEの間、表示
		DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
	}
	
	
	if (g_player.tenmetu == TRUE) {		//TRUEの間、点滅
		if (g_player.count == 0) { 
			g_player.flg = ~g_player.flg; 
		}
		++g_player.count;
		if (g_player.count % 20 == 0) {
			g_player.flg = ~g_player.flg;
		}
		if (g_player.count >= 120) {
			g_player.tenmetu = FALSE;
			g_player.flg = TRUE;
			g_player.count = 0;
		}
	}

	/*DrawString*/

	DrawRotaGraph(515, 320, 0.9f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(565, 320, 0.9f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(615, 320, 0.9f, 0, Apple_Img[2], TRUE, FALSE);
	SetFontSize(20);
	DrawFormatString(505, 350, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(555, 350, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(605, 350, 0xFFFFFF, "%03d", AppleCount3);
	
	if (input.Buttons[XINPUT_BUTTON_START] == 0) {
		g_KeyFLG = TRUE;
	}
	if (input.Buttons[XINPUT_BUTTON_START] == 1 && g_KeyFLG==TRUE) {
		g_KeyFLG = FALSE;
		g_GameState = 7;
	}

	StartTime = GetNowCount()-Time;
	StartTime = 3 - StartTime / 1000 + pose.PoseTime;	//制限時間調整
	
	SetFontSize(36);
	DrawFormatString(550, 240, 0xFFFFFF, "%02d", StartTime);
	
	if (StartTime <= 0) {
		StopSoundMem(g_MusicBGM);		//制限時間30秒たったらGameState=6 -> ランキング入力へ！
		g_KeyFLG = TRUE;
		if (g_Score >= ranking.getScore(4)) {
			g_GameState = 6;

		}else {
			g_GameState = 2;
		}
		
	}
}

int PLAYER::HitBoxPlayer(PLAYER* p, APPLE* e)
{
	//x,yは中心座標とする
	int sx1 = p->x - (p->w / 2);
	int sy1 = p->y - (p->h / 2);
	int sx2 = sx1 + p->w;
	int sy2 = sy1 + p->h;
     DrawBox(sx1, sy1, sx2, sy2, 0xffffff, FALSE);
	int dx1 = e->x - (e->w / 2);
	int dy1 = e->y - (e->h / 2);
	int dx2 = dx1 + e->w;
	int dy2 = dy1 + e->h;
	DrawBox(dx1, dy1, dx2, dy2, 0xffffff, FALSE);

	//矩形が重なっていれば当たり
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		return TRUE;
	}
	return FALSE;
}
