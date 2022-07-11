#pragma once
#include"Common.h"
#include"APPLE.h"

class PLAYER {
public:
	int flg;	//使用フラグ
	int x, y;	//座標x,y
	int w, h;	//幅w,高さh
	double angle;//機体の向き
	int count;	//タイミング用
	int speed;	//移動速度
	int hp;		//体力
	int fuel;	//燃料
	int bari;	//バリア回数
	int baricnt;	//バリア継続時間
	int bariup;	//バリア回数（走行距離アップ）
public:
	PLAYER();
	void InitPlayer();
	void PlayerControl();
	int HitBoxPlayer(PLAYER* p, APPLE* e);
};

extern PLAYER g_player;

//自機の構造体
//struct PLAYER {
//	int flg;	//使用フラグ
//	int x, y;	//座標x,y
//	int w, h;	//幅w,高さh
//	double angle;//機体の向き
//	int count;	//タイミング用
//	int speed;	//移動速度
//	int hp;		//体力
//	int fuel;	//燃料
//	int bari;	//バリア回数
//	int baricnt;	//バリア継続時間
//	int bariup;	//バリア回数（走行距離アップ）
//};
////自機
//struct PLAYER g_player;
//
//void PlayerControl();
//int HitBoxPlayer(PLAYER* p, APPLE* e);


//class Player {
//public:
//	int flg;	//使用フラグ
//	int x, y;	//座標x,y
//	int w, h;	//幅w,高さh
//	double angle;//機体の向き
//	int count;	//タイミング用
//	int speed;	//移動速度
//	int hp;		//体力
//	int fuel;	//燃料
//	int bari;	//バリア回数
//	int baricnt;	//バリア継続時間
//	int bariup;	//バリア回数（走行距離アップ）
//	
//public:
//	Player();
//	void DrawPlayer();
//};
//
//extern Player player;