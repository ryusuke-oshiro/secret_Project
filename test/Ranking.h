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
	void SortRanking();	 //ランキング並び替え
	int SaveRanking();	 //ランキングデータの保存
	int ReadRanking();	 //ランキングデータ読み込み
	void DrawRanking();  //ランキング描画処理
	void InputRanking(); //ランキング入力
};

struct RankingData {
	int no;
	char name[11];
	long score;
};
//ランキングデータ変数宣言
struct RankingData g_Ranking[RANKING_DATA];

extern Ranking ranking;