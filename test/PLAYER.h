#pragma once
#include"Common.h"
#include"APPLE.h"

class PLAYER {
public:
	int flg;	//�g�p�t���O
	int x, y;	//���Wx,y
	int w, h;	//��w,����h
	double angle;//�@�̂̌���
	int count;	//�^�C�~���O�p
	int speed;	//�ړ����x
	int hp;		//�̗�
	int fuel;	//�R��
	int bari;	//�o���A��
	int baricnt;	//�o���A�p������
	int bariup;	//�o���A�񐔁i���s�����A�b�v�j
public:
	PLAYER();
	void InitPlayer();
	void PlayerControl();
	int HitBoxPlayer(PLAYER* p, APPLE* e);
};

extern PLAYER g_player;

//���@�̍\����
//struct PLAYER {
//	int flg;	//�g�p�t���O
//	int x, y;	//���Wx,y
//	int w, h;	//��w,����h
//	double angle;//�@�̂̌���
//	int count;	//�^�C�~���O�p
//	int speed;	//�ړ����x
//	int hp;		//�̗�
//	int fuel;	//�R��
//	int bari;	//�o���A��
//	int baricnt;	//�o���A�p������
//	int bariup;	//�o���A�񐔁i���s�����A�b�v�j
//};
////���@
//struct PLAYER g_player;
//
//void PlayerControl();
//int HitBoxPlayer(PLAYER* p, APPLE* e);


//class Player {
//public:
//	int flg;	//�g�p�t���O
//	int x, y;	//���Wx,y
//	int w, h;	//��w,����h
//	double angle;//�@�̂̌���
//	int count;	//�^�C�~���O�p
//	int speed;	//�ړ����x
//	int hp;		//�̗�
//	int fuel;	//�R��
//	int bari;	//�o���A��
//	int baricnt;	//�o���A�p������
//	int bariup;	//�o���A�񐔁i���s�����A�b�v�j
//	
//public:
//	Player();
//	void DrawPlayer();
//};
//
//extern Player player;