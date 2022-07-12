#pragma once

class Title {
public:
	int g_TitleImage;
	int g_TitleBGM;
	int g_SE1;
	int g_SE2;
	int g_Menu, g_Cone;
public:
	void DrawGameTitle();
};

extern Title title;