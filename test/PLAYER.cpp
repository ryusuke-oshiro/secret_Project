#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"PLAYER.h"
#include"APPLE.h"
#include"Common.h"

PLAYER g_player;

PLAYER::PLAYER() {
	flg = TRUE;
	tenmetu = 0;
	x = 0.0;
	y = 0;
	w = 0;
	h = 0;
	angle = 0.0;
	count = 0;
	speed = 0.0;
	hp = 0;
	fuel = 0;
	bari = 0;
	baricnt = 0;
	bariup = 0;
}

void PLAYER::InitPlayer() {
	//�v���C���[�̏����ݒ�
	flg = TRUE;
	tenmetu = FALSE;
	x = 320; //320
	y = 380;
	w = 50; //63
	h = 67;
	angle = 0.0;
	count = 0;
	speed = 0.0;
	hp = 1000;
	fuel = 20000;
	bari = 3;
	bariup = 10;
}

void PLAYER::PlayerControl() {
	////�㉺���E�ړ�
	//if (g_player.flg == TRUE) {
	//	if (g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
	//	if (g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	//}

	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
	if (g_player.x < 32)g_player.x = 32;
	if (g_player.x > 460)g_player.x = 460;

	//�ő呬�x�̐ݒ�
	if (g_player.speed < -5) {
		g_player.speed -= -0.5;
	}
	if (g_player.speed > 5) {
		g_player.speed += 0.5;
	}

	//�����ړ�
	if (input.ThumbLX < -17500) {	//������
		if (g_player.speed > -3 && g_player.speed <= 0) {	//speed�� 0 �` -2.9 ��-0.1����
			g_player.speed -= 0.1;
		}
		if (g_player.speed > -4 && g_player.speed <= -3) {	//speed�� -3 �` -3.9 ��-0.2����
			g_player.speed -= 0.2;
		}
		if (g_player.speed >= -5 && g_player.speed <= -4) {	//speed�� -4 �` -5 ��-0.4����
			g_player.speed -= 0.4;
		}
		g_Car_Nowangle = g_Car_left;						//�����͂���������player�����Ɍ�����
	}
	else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {	//�����͂��痣������
		if (g_player.speed < 0) {								//�������}�C�i�X�������瑫���Ă���
			g_player.speed += 0.4;	
			if (g_player.speed > 0) {							//����speed��0�ɂȂ�����~�߂�							
				g_player.speed = 0;
			}
		}
		else if (g_player.speed > 0) {							//�������v���X������������Ă���
			g_player.speed -= 0.4;
			if (g_player.speed < 0) {							//����speed��0�ɂȂ�����~�߂�
				g_player.speed = 0;
			}
		}
	}


	if (input.ThumbLX > 17500) {	//�E����
		if (g_player.speed < 3 && g_player.speed >= 0) {	//speed��0�`2.9��+0.1����
			g_player.speed += 0.1;
		}
		if (g_player.speed < 4 && g_player.speed >= 3) {	//speed��3�`3.9��+0.2����
			g_player.speed += 0.2;
		}
		if (g_player.speed <= 5 && g_player.speed >= 4) {	//speed��4�`5��+0.4����
			g_player.speed += 0.4;
		}
		g_Car_Nowangle = g_Car_right;						//�E���͂���������player���E�Ɍ�����
	}
	else if (input.ThumbLX < 17500 && input.ThumbLX > 128) {	//�E���͂��痣������
		if (g_player.speed < 0) {								//�������}�C�i�X�������瑫���Ă���
			g_player.speed += 0.4;
			if (g_player.speed > 0) {							//����speed��0�ɂȂ�����~�߂�							
				g_player.speed = 0;
			}
		}
		else if (g_player.speed > 0) {							//�������v���X������������Ă���
			g_player.speed -= 0.4;
			if (g_player.speed < 0) {							//����speed��0�ɂȂ�����~�߂�
				g_player.speed = 0;
			}
		}
	}

	//�v���C���[�̕\��
	//if (input.ThumbLX < -17500) {		//������
 //           if (g_player.speed > -10) {
 //               g_player.speed -= 0.5;
 //           }
 //           g_player.x += g_player.speed;
 //       }
 //       else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {		//�������Ƃ�
 //           if (g_player.speed > 0) {			//�h�����h�����������̐�
 //               g_player.speed -= 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //           else if (g_player.speed < 0) {	//�h�����h�����������̎�
 //               g_player.speed += 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //       }
 //       if (input.ThumbLX > 17500) {		//�E����
 //           if (g_player.speed < 10) {
 //               g_player.speed += 0.5;
 //           }
 //           g_player.x += g_player.speed;
 //       }
 //       else if (input.ThumbLX < 17500 && input.ThumbLX>128) {	//�������Ƃ�

 //           if (g_player.speed > 0) {			//�h�����h�����������̎�
 //               g_player.speed -= 0.5;
 //               g_player.x -= g_player.speed;
 //           }
 //           else if (g_player.speed < 0) {	//�h�����h�����������̎�
 //               g_player.speed += 0.5;
 //               g_player.x += g_player.speed;
 //           }
 //       }
	/*if (input.ThumbLX < 128) {
			g_player.x -= g_player.speed;
			
	}
	if (input.ThumbLX > 128) {
			g_player.x += g_player.speed;
			g_Car_Nowangle = g_Car_right;
		}*/
	g_player.x += g_player.speed;
	
	if (g_player.flg == TRUE) {		//TRUE�̊ԁA�\��
		DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car_Nowangle, TRUE, FALSE);
	}
	
	
	if (g_player.tenmetu == TRUE) {		//TRUE�̊ԁA�_��
		if (g_player.count == 0) { 
			g_player.flg = ~g_player.flg; 
		}
		++g_player.count;
		if (g_player.count % 20 == 0) {
			g_player.flg = ~g_player.flg;
		}
		if (g_player.count >= 120) {
			g_player.tenmetu = FALSE;
			g_player.flg = TRUE;
			g_player.count = 0;
		}
	}


	DrawRotaGraph(520, 110, 0.9f, 0, Apple_Img[0], TRUE, FALSE);
	DrawRotaGraph(570, 110, 0.9f, 0, Apple_Img[1], TRUE, FALSE);
	DrawRotaGraph(620, 110, 0.9f, 0, Apple_Img[2], TRUE, FALSE);

	DrawFormatString(510, 140, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", AppleCount3);

	StartTime = GetNowCount()-Time;
	
	DrawFormatString(510, 200, 0xFFFFFF, "%02d", 30-StartTime/1000);
	
	if (StartTime >= 30000) {		//��������30�b��������GameState=6 -> �����L���O���͂ցI
		g_GameState = 6;
		StopSoundMem(g_MusicBGM);
	}
}

int PLAYER::HitBoxPlayer(PLAYER* p, APPLE* e)
{
	//x,y�͒��S���W�Ƃ���
	int sx1 = p->x - (p->w / 2);
	int sy1 = p->y - (p->h / 2);
	int sx2 = sx1 + p->w;
	int sy2 = sy1 + p->h;
     DrawBox(sx1, sy1, sx2, sy2, 0xffffff, FALSE);
	int dx1 = e->x - (e->w / 2);
	int dy1 = e->y - (e->h / 2);
	int dx2 = dx1 + e->w;
	int dy2 = dy1 + e->h;
	DrawBox(dx1, dy1, dx2, dy2, 0xffffff, FALSE);

	//��`���d�Ȃ��Ă���Γ�����
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		return TRUE;
	}
	return FALSE;
}


//
//void PlayerControl::MovePlayer() {
//
//    //���E�ړ�
//    if (player.flg == TRUE) {
//        if (input.ThumbLX < -17500) {		//������
//            if (player.speed > -10) {
//                player.speed -= 0.5;
//            }
//            player.x += player.speed;
//        }
//        else if (input.ThumbLX > -17500 && input.ThumbLX < 128) {		//�������Ƃ�
//            if (player.speed > 0) {			//�h�����h�����������̐�
//                player.speed -= 0.5;
//                player.x += player.speed;
//            }
//            else if (player.speed < 0) {	//�h�����h�����������̎�
//                player.speed += 0.5;
//                player.x += player.speed;
//            }
//        }
//        if (input.ThumbLX > 17500) {		//�E����
//            if (player.speed < 10) {
//                player.speed += 0.5;
//            }
//            player.x += player.speed;
//        }
//        else if (input.ThumbLX < 17500 && input.ThumbLX>128) {	//�������Ƃ�
//
//            if (player.speed > 0) {			//�h�����h�����������̎�
//                player.speed -= 0.5;
//                player.x -= player.speed;
//            }
//            else if (player.speed < 0) {	//�h�����h�����������̎�
//                player.speed += 0.5;
//                player.x += player.speed;
//            }
//        }
//    }
//
//    //��ʂ��͂ݏo���Ȃ��悤�ɂ���
//    if (player.x < 32)player.x = 32;
//    if (player.x >460)player.x = 460;
//}

