#pragma once
#include"Common.h"
#include"APPLE.h"

class PLAYER {
public:
	int flg;	//�g�p�t���O
	int tenmetu; //�_�Ńt���O
	double x;
	int y;	//���Wx,y
	int w, h;	//��w,����h
	double angle;//�@�̂̌���
	int count;	//�^�C�~���O�p
	double speed;	//�ړ����x
	//int hp;		//�̗�
	//int fuel;	//�R��
	//int bari;	//�o���A��
	//int baricnt;	//�o���A�p������
	//int bariup;	//�o���A�񐔁i���s�����A�b�v�j
public:
	PLAYER();
	void InitPlayer();
	void PlayerControl();
	int HitBoxPlayer(PLAYER* p, APPLE* e);
};

extern PLAYER g_player;