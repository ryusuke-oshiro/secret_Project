#pragma once
#include"DxLib.h"

struct	RankingData {
    int		no;
    char	name[11];
    long	score;
};


class RANKING {
private:
    FILE* fp;
    RankingData data[10];

public:
    void SortRanking(void);		//ランキング並べ替え
    int  SaveRanking(void);		//ランキングデータの保存
    int  ReadRanking(void);		//ランキングデータ読み込み
    int getScore(int n);
    void setScore(int n);
    int getNomber(int n);
    char* getName(int n);
    int getName2(int c,int n);
    void setName(int c,int n);
};

extern RANKING ranking;