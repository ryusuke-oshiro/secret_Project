#pragma once
class InputRANKING {
public:
	int g_InputRankingImage;
	int g_EnterImage;
	int g_BackSpaceImage;
	int count;
	char moji=0;
	int cursor_X;
	int cursor_Y;
	int NameWarning;
public:
	InputRANKING();
	void InputRanking();
};

extern InputRANKING inputranking;