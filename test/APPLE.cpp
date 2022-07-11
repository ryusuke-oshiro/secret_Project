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
	w = 0;
	h = 0;
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
	int select = GetRand(6) + 1;
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
	else if (select <= 5) {
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
			g_apple[i].x = i * 72 + 25;		//‚±‚Ìi‚ðƒ‰ƒ“ƒ_ƒ€GetRand(1`7)-1‚É‚·‚é
			g_apple[i].y = 20;
			SelectApple(i);
			g_apple[i].img = Apple_Img[g_apple[i].type];
			/*g_apple[i] = g_apple00;*/
			/*g_apple[i].type = GetRand(2);
			g_apple[i].img = Apple_Img[g_apple[i].type];*/
			/*g_apple[i].x = GetRand(4) * 105 + 40;*/
			/*g_apple[i].speed = g_apple[i].type * 2;*/
			//¬Œ÷
			return TRUE;
		}
	}

	//Ž¸”s
	return FALSE;
}

void APPLE::AppleControl() {
	for (int i = 0; i < Apple_MAX; i++) {
		if (g_apple[i].flg == TRUE) {

			//“G‚Ì•\Ž¦
			DrawRotaGraph(g_apple[i].x, g_apple[i].y, 1.0f, 0, g_apple[i].img, TRUE, FALSE);

			if (g_player.flg == FALSE)continue;

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

			//‚Ü‚Á‚·‚®‰º‚ÉˆÚ“®
			/*g_apple[i].y += g_apple[i].speed + g_player.speed - GameInit.getPLAYER_SPEED() + 1;*/

			//‰æ–Ê‚ð‚Í‚Ýo‚µ‚½‚çÁ‹Ž
			if (g_apple[i].y > SCREEN_HEIGHT + g_apple[i].h) {
				g_apple[i].flg = FALSE;
			}

			//“G‹@‚ð’Ç‚¢‰z‚µ‚½‚çƒJƒEƒ“ƒg‚·‚é
			/*if (g_apple[i].y > g_player.y && g_apple[i].point == 1) {
				g_apple[i].point = 0;
				if (g_apple[i].type == 0)AppleCount1++;
				if (g_apple[i].type == 1)AppleCount2++;
				if (g_apple[i].type == 2)AppleCount3++;
			}*/
			//“–‚½‚è”»’è
			if (g_player.HitBoxPlayer(&g_player, &g_apple[i]) == TRUE) {
				if (g_apple[i].type == 0) { 
					AppleCount1++;
					/*g_Score += g_apple[i].point;*/
				}
				if (g_apple[i].type == 1) { 
					AppleCount2++; 
				}
				if (g_apple[i].type == 2){
					AppleCount3++;
				}
				g_player.flg = FALSE;
				g_player.speed = 5;
				g_player.count = 0;
				g_player.hp -= 100;
				g_apple[i].flg = FALSE;
				if (g_player.hp <= 0) {
					g_GameState = 6;
					StopSoundMem(g_MusicBGM);
				}
			}
		}
	}

	//‘–s‹——£‚²‚Æ‚É“GoŒ»ƒpƒ^[ƒ“‚ð§Œä‚·‚é
	if (g_Mileage / 10 % 50 == 0) {
		CreateApple();
	}
}

