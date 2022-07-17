#include "RANKING.h"
#include "common.h"

RANKING ranking;
/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void RANKING::SortRanking(void) {
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (data[i].score <= data[j].score) {
				work = data[i];
				data[i] = data[j];
				data[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		data[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (data[i].score > data[j].score) {
				data[j].no++;
			}
		}
	}
}

/***********************************************
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
int RANKING::SaveRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%2d %10s %10d\n", data[i].no, data[i].name, data[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;

}

/*************************************
 * �����L���O�f�[�^�ǂݍ���
 *************************************/
int RANKING::ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%2d %10s %10d", &data[i].no, data[i].name, &data[i].score);
	}

	//�t�@�C���N���[�Y
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