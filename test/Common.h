#pragma once
#include<DxLib.h>
#define Apple_MAX  10
#define ITEM_MAX  3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define RANKING_DATA 5

extern XINPUT_STATE input;
extern int g_KeyFLG;
extern int ButtonFLG;

extern int g_KeyFlg;
extern int g_NowKey;

extern int g_SE1;
extern int g_SE2;
extern int g_SE3;

extern int Time;

extern int g_WaitCount;

extern int g_WaitTime;

extern int StartTime;

extern int g_MusicBGM;
extern int g_SE1;
extern int g_SE2;
extern int g_Cone;

extern int g_Mileage;

extern int g_GameState;

extern int AppleCount1, AppleCount2, AppleCount3;

extern int g_Car_left,g_Car_right,g_Car_Nowangle;

extern int Apple_Img[4];

extern int g_Score;

extern void DrawBackGround();