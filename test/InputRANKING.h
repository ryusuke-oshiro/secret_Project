#pragma once
class InputRANKING {
private:
	
	int flg;
	int ascii;
	char moji;

	int cursor_X, cursor_Y;
public:
	InputRANKING();
	void InputRanking();
};

extern InputRANKING inputranking;
extern InputRANKING Alfabet[3][10];