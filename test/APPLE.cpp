#include"DxLib.h"

#include"Common.h"
#include"PLAYER.h"
#include"APPLE.h"

APPLE apple;
APPLE g_apple[Apple_MAX];

APPLE::APPLE() {
	flg = FALSE;
	type = 0;
	img = 0;
	x = 0;
	y = 0;
	w = 35;
	h = 35;
	speed = 0;
	point = 0;
}

void APPLE::InitApple() {
	for (int i = 0; i < Apple_MAX; i++) {
		g_apple[i].flg = FALSE;
		g_apple[i].type = 0;
		g_apple[i].img = 0;
		g_apple[i].x = 0;
		g_apple[i].y = 0;
		g_apple[i].w = 50;
		g_apple[i].h = 50;
		g_apple[i].speed = 0;
		g_apple[i].point = 0;
	}
}

void APPLE::SelectApple(int x) {
	int i = x;
	int select = GetRand(9) + 1;
	if (select <= 6) {
		g_apple[i].type=0;
		g_apple[i].speed=2;
		g_apple[i].point=150;
	}
	else if (select <= 8) {
		g_apple[i].type = 1;
		g_apple[i].speed = 5;
		g_apple[i].point=300;
	}
	else if (select <= 9) {
		g_apple[i].type = 2;
		g_apple[i].speed = 10;
		g_apple[i].point=500;
	}
	else {
		g_apple[i].type = 3;
		g_apple[i].speed = 1;
		g_apple[i].point= -1000;
	}

}

 
int APPLE::CreateApple() {
	for (int i = 0; i < Apple_MAX; i++) {
		if (g_apple[i].flg == FALSE) {
			
			g_apple[i].flg = TRUE;
			g_apple[i].x = GetRand(6) * 72 + 25;		//このiをランダムGetRand1～7(-1)にする
			g_apple[i].y = 20;
			SelectApple(i);
			g_apple[i].img = Apple_Img[g_apple[i].type];
			//成功
			return TRUE;
		}
	}

	//失敗
	return FALSE;
}

void APPLE::AppleControl() {
	//リンゴの合計スコア
	AppleScore();
	for (int i = 0; i < Apple_MAX; i++) {
		if (g_apple[i].flg == TRUE) {

			//敵の表示
			DrawRotaGraph(g_apple[i].x, g_apple[i].y, 1.0f, 0, g_apple[i].img, TRUE, FALSE);

			/*if (g_player.flg == FALSE)continue;*/

			switch (g_apple[i].type) {
			case 0:g_apple[i].y += g_apple[i].speed;
				break;
			case 1:g_apple[i].y += g_apple[i].speed;
				break;
			case 2:g_apple[i].y += g_apple[i].speed;
				break;
			case 3:g_apple[i].y += g_apple[i].speed;
				break;
			}

			//画面をはみ出したら消去
			if (g_apple[i].y > SCREEN_HEIGHT + g_apple[i].h) {
				g_apple[i].flg = FALSE;
			}

			//当たり判定
			if (g_player.HitBoxPlayer(&g_player, &g_apple[i]) == TRUE && g_player.tenmetu == FALSE) {
				if (g_apple[i].type == 0) { 
					AppleCount1++;
					g_Score += g_apple[i].point;
				}
				if (g_apple[i].type == 1) { 
					AppleCount2++; 
					g_Score += g_apple[i].point;
				}
				if (g_apple[i].type == 2){
					AppleCount3++;
					g_Score += g_apple[i].point;
				}
				if (g_apple[i].type == 3) {
					g_Score += g_apple[i].point;
					g_player.tenmetu = TRUE;
				}	
				g_apple[i].flg = FALSE;			//リンゴを消す
			}
		}
	}

	//走行距離ごとに敵出現パターンを制御する
	if (g_Mileage / 10 % 50 == 0) {
		CreateApple();
	}
	
}

void APPLE::AppleScore() {
	if (g_Score < 0) {
		g_Score = 0;
	}
	DrawFormatString(520, 100, 0xffffff,"%05d", g_Score);
}