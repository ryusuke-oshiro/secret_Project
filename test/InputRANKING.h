#pragma once
class InputRANKING {
public:
	int count;
	int upper;
	int rower;
	int number;
	char moji;
	int cursor_X, cursor_Y;
public:
	InputRANKING();
	void InputRanking();
};

extern InputRANKING inputranking;
extern InputRANKING Alfabet[5][13];