#include "RANKING.h"
#include "common.h"

RANKING ranking;
/***********************************************
 * ランキング並べ替え
 ***********************************************/
void RANKING::SortRanking(void) {
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (data[i].score <= data[j].score) {
				work = data[i];
				data[i] = data[j];
				data[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANKING_DATA; i++) {
		data[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (data[i].score > data[j].score) {
				data[j].no++;
			}
		}
	}
}

/***********************************************
 * ランキングデータの保存
 ***********************************************/
int RANKING::SaveRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%2d %10s %10d\n", data[i].no, data[i].name, data[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;

}

/*************************************
 * ランキングデータ読み込み
 *************************************/
int RANKING::ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%2d %10s %10d", &data[i].no, data[i].name, &data[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

int RANKING::getScore(int n) {
	return data[n].score;
}
void RANKING::setScore(int n) {
	data[4].score = n;
}

int RANKING::getNomber(int n) {
	return data[n].no;
}

char* RANKING::getName(int n) {
	return data[n].name;
}