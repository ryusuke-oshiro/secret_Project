#pragma once
#include"DxLib.h"
#include"Common.h"

class APPLE {
public:
	int flg;	//�g�p�t���O
	int type;	//�^�C�v
	int img;	//�摜
	int x, y, w, h;	//���Wx,y �� w ���� h
	int speed;	//�ړ����x
	int point;	//�X�R�A���Z
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



//�����S�̍\����
//struct APPLE {
//	int flg;	//�g�p�t���O
//	int type;	//�^�C�v
//	int img;	//�摜
//	int x, y, w, h;	//���Wx,y �� w ���� h
//	int speed;	//�ړ����x
//	int point;	//�X�R�A���Z
//};
//
////�����S
//extern struct APPLE g_apple[Apple_MAX];
//extern struct APPLE g_apple00 = { TRUE,0,0,0,-50,63,120,0,1 };
//extern struct APPLE g_appleCn = { TRUE,4,0,0,-50,18,18,0,1 };
//extern struct APPLE g_item[ITEM_MAX];
//extern struct APPLE g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };
//
//int CreateApple();
//void AppleControl();
