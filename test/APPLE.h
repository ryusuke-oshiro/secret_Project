#pragma once
#include"DxLib.h"
#include"Common.h"

class APPLE {
public:
	int flg;	//使用フラグ
	int type;	//タイプ
	int img;	//画像
	int x, y, w, h;	//座標x,y 幅 w 高さ h
	int speed;	//移動速度
	int point;	//スコア加算
public:
	APPLE();
	void InitApple();
	void SelectApple(int x);
	int CreateApple();
	void AppleControl();
	
};
extern APPLE apple;
extern APPLE g_apple[Apple_MAX];
//extern APPLE g_item[ITEM_MAX];



//リンゴの構造体
//struct APPLE {
//	int flg;	//使用フラグ
//	int type;	//タイプ
//	int img;	//画像
//	int x, y, w, h;	//座標x,y 幅 w 高さ h
//	int speed;	//移動速度
//	int point;	//スコア加算
//};
//
////リンゴ
//extern struct APPLE g_apple[Apple_MAX];
//extern struct APPLE g_apple00 = { TRUE,0,0,0,-50,63,120,0,1 };
//extern struct APPLE g_appleCn = { TRUE,4,0,0,-50,18,18,0,1 };
//extern struct APPLE g_item[ITEM_MAX];
//extern struct APPLE g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };
//
//int CreateApple();
//void AppleControl();
