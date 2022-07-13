#pragma once
#include<DxLib.h>
#define RANKING_DATA 5


class Ranking {
public:
	int g_Ranking;
	int g_RankingImage;
	int no;
	char name;
	long score;
private:
	void SortRanking();	 //�����L���O���ёւ�
	int SaveRanking();	 //�����L���O�f�[�^�̕ۑ�
	int ReadRanking();	 //�����L���O�f�[�^�ǂݍ���
	void DrawRanking();  //�����L���O�`�揈��
	void InputRanking(); //�����L���O����
};

struct RankingData {
	int no;
	char name[11];
	long score;
};
//�����L���O�f�[�^�ϐ��錾
struct RankingData g_Ranking[RANKING_DATA];

extern Ranking ranking;