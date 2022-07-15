#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
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
	////上下左右移動
	//if (g_player.flg == TRUE) {
	//	if (g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
	//	if (g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	//}

	//画面をはみ出さないようにする
	if (g_player.x < 32)g_player.x = 32;
	if (g_player.x > 460)g_player.x = 460;

	//最大速度の設定
	if (g_player.speed < -5) {
		g_player.speed -= -0.5;
	}
	if (g_player.speed > 5) {
		g_player.speed += 0.5;
	}

	//慣性移動
	if (input.ThumbLX < -17500) {	//左入力
		if (g_player.speed > -3 && g_player.speed <= 0) {	//speedが 0 ～ -2.9 は-0.1ずつ
			g_player.speed -= 0.1;
		}
		if (g_player.speed > -4 && g_player.speed <= -3) {	//speedが -3 ～ -3.9 は-0.2ずつ
			g_player.speed -= 0.2;
		}
		if (g_player.speed >= -5 && g_player.speed <= -4) {	//speedが -4 ～ -5 は-0.4ずつ
			g_player.speed -= 0.4;
		}
		g_Car_Nowangle = g_Car_left;						//左入力が入ったらplayerを左に向ける
	}
	else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {	//左入力から離した時
		if (g_player.speed < 0) {								//加速がマイナスだったら足していく
			g_player.speed += 0.4;	
			if (g_player.speed > 0) {							//もしspeedが0になったら止める							
				g_player.speed = 0;
			}
		}
		else if (g_player.speed > 0) {							//加速がプラスだったら引いていく
			g_player.speed -= 0.4;
			if (g_player.speed < 0) {							//もしspeedが0になったら止める
				g_player.speed = 0;
			}
		}
	}


	if (input.ThumbLX > 17500) {	//右入力
		if (g_player.speed < 3 && g_player.speed >= 0) {	//speedが0～2.9は+0.1ずつ
			g_player.speed += 0.1;
		}
		if (g_player.speed < 4 && g_player.speed >= 3) {	//speedが3～3.9は+0.2ずつ
			g_player.speed += 0.2;
		}
		if (g_player.speed <= 5 && g_player.speed >= 4) {	//speedが4～5は+0.4ずつ
			g_player.speed += 0.4;
		}
		g_Car_Nowangle = g_Car_right;						//右入力が入ったらplayerを右に向ける
	}
	else if (input.ThumbLX < 17500 && input.ThumbLX > 128) {	//右入力から離した時
		if (g_player.speed < 0) {								//加速がマイナスだったら足していく
			g_player.speed += 0.4;
			if (g_player.speed > 0) {							//もしspeedが0になったら止める							
				g_player.speed = 0;
			}
		}
		else if (g_player.speed > 0) {							//加速がプラスだったら引いていく
			g_player.speed -= 0.4;
			if (g_player.speed < 0) {							//もしspeedが0になったら止める
				g_player.speed = 0;
			}
		}
	}

	//プレイヤーの表示
	//if (input.ThumbLX < -17500) {		//左入力
 //           if (g_player.speed > -10) {
 //               g_player.speed -= 0.5;
 //           }
 //           g_player.x += g_player.speed;
 //       }
 //       else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {		//離したとき
 //           if (g_player.speed > 0) {			//”離す”かつ加速が正の数
 //               g_player.speed -= 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //           else if (g_player.speed < 0) {	//”離す”かつ加速が負の時
 //               g_player.speed += 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //       }
 //       if (input.ThumbLX > 17500) {		//右入力
 //           if (g_player.speed < 10) {
 //               g_player.speed += 0.5;
 //           }
 //           g_player.x += g_player.speed;
 //       }
 //       else if (input.ThumbLX < 17500 && input.ThumbLX>128) {	//離したとき

 //           if (g_player.speed > 0) {			//”離す”かつ加速が正の時
 //               g_player.speed -= 0.5;
 //               g_player.x -= g_player.speed;
 //           }
 //           else if (g_player.speed < 0) {	//”離す”かつ加速が負の時
 //               g_player.speed += 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //       }
	/*if (input.ThumbLX < 128) {
			g_player.x -= g_player.speed;
			
	}
	if (input.ThumbLX > 128) {
			g_player.x += g_player.speed;
			g_Car_Nowangle = g_Car_right;
		}*/
	g_player.x += g_player.speed;
	
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

