#pragma once
#include<DxLib.h>
#define Apple_MAX  10
#define ITEM_MAX  3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

extern XINPUT_STATE input;
extern int g_KeyFlg;

extern int g_NowKey;

extern int Time;

extern int StartTime;

extern int g_MusicBGM;

extern int g_Mileage;

extern int g_GameState;

extern int AppleCount1, AppleCount2, AppleCount3;

extern int g_Car_left,g_Car_right,g_Car_Nowangle;

extern int Apple_Img[4];

extern int g_Score;