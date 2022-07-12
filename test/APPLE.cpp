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
	flg = FALSE;
	type = 0;
	img = 0;
	x = 0;
	y = 0;
	w = 50;
	h = 50;
	speed = 0;
	point = 0;
}

//g_apple00 = { TRUE,0,0,0,-50,63,120,0,1 }

void APPLE::SelectApple(int x) {
	int i = x;
	int select = GetRand(7) + 1;
	if (select <= 2) {
		g_apple[i].type=0;
		g_apple[i].speed=2;
		g_apple[i].point=150;
	}
	else if (select <= 4) {
		g_apple[i].type = 1;
		g_apple[i].speed = 5;
		g_apple[i].point=300;
	}
	else if (select <= 6) {
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
			g_apple[i].x = GetRand(6) * 72 + 25;		//このiをランダムGetRand(1～7)-1にする
			g_apple[i].y = 20;
			SelectApple(i);
			g_apple[i].img = Apple_Img[g_apple[i].type];
			/*g_apple[i] = g_apple00;*/
			/*g_apple[i].type = GetRand(2);
			g_apple[i].img = Apple_Img[g_apple[i].type];*/
			/*g_apple[i].x = GetRand(4) * 105 + 40;*/
			/*g_apple[i].speed = g_apple[i].type * 2;*/
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

			//まっすぐ下に移動
			/*g_apple[i].y += g_apple[i].speed + g_player.speed - GameInit.getPLAYER_SPEED() + 1;*/

			//画面をはみ出したら消去
			if (g_apple[i].y > SCREEN_HEIGHT + g_apple[i].h) {
				g_apple[i].flg = FALSE;
			}

			//敵機を追い越したらカウントする
			/*if (g_apple[i].y > g_player.y && g_apple[i].point == 1) {
				g_apple[i].point = 0;
				if (g_apple[i].type == 0)AppleCount1++;
				if (g_apple[i].type == 1)AppleCount2++;
				if (g_apple[i].type == 2)AppleCount3++;
			}*/
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

	DrawFormatString(561, 200, 0xffffff,"%d", g_Score);
}