#pragma once
class POSE {
public:
	int PoseTime;
	int PoseCount;
public:
	POSE();
	void initPose();
	void DrawPose();
};
extern POSE pose;