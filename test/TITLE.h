#pragma once
class TITLE {
public:
	int x;
	int x_flg;
	int g_TitleImage;
	int g_TitleBGM;
public:
	TITLE();
	void DrawGameTitle();
};
extern TITLE title;