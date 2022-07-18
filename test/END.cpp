#include"DxLib.h"
#include"Common.h"
#include"END.h"

END end;

END::END() {
	g_EndImage = 0;
}

void END::DrawEnd() {
	//エンド画像表示
	DrawGraph(0, 0, g_EndImage, FALSE);

	//タイムの加算処理＆終了（３秒後）
	if (++g_WaitTime > 180)g_GameState = 99;
}