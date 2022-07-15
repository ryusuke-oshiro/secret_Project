#include"POSE.h"
#include"Common.h"
#include"DxLib.h"


POSE pose;

POSE::POSE() {
	PoseTime = 0;
	PoseCount = 0;
}

void POSE::DrawPose() {
	if (++PoseCount > 60) {
		++PoseTime;
		PoseCount = 0;
	}

}