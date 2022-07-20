#pragma once
#include"Common.h"
#include"APPLE.h"

class PLAYER {
public:
	int flg;	//使用フラグ
	int tenmetu; //点滅フラグ
	double x;
	int y;	//座標x,y
	int w, h;	//幅w,高さh
	double angle;//機体の向き
	int count;	//タイミング用
	double speed;	//移動速度
public:
	PLAYER();
	void InitPlayer();
	void PlayerControl();
	int HitBoxPlayer(PLAYER* p, APPLE* e);
};

extern PLAYER g_player;