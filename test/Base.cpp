//#include "DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	XINPUT_STATE g_NowKey;
//	XINPUT_STATE g_OldKey;
//
//	int i;
//	int Color;
//
//	// ＤＸライブラリの初期化
//	if (DxLib_Init() < 0) return -1;
//
//	// 描画先を裏画面にする
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	// メインループ(何かキーが押されたらループを抜ける)
//	while (ProcessMessage() == 0)
//	{
//		// 画面のクリア
//		ClearDrawScreen();
//
//		// 入力状態を取得
//		GetJoypadXInputState(DX_INPUT_PAD1, &g_NowKey);
//
//		g_OldKey = g_NowKey;
//
//		// 画面に XINPUT_STATE の中身を描画
//		Color = GetColor(255, 255, 255);
//		DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
//			g_NowKey.LeftTrigger, g_NowKey.RightTrigger);
//		DrawFormatString(0, 16, Color, "ThumbLX:%d ThumbLY:%d",
//			g_NowKey.ThumbLX, g_NowKey.ThumbLY);
//		DrawFormatString(0, 32, Color, "ThumbRX:%d ThumbRY:%d",
//			g_NowKey.ThumbRX, g_NowKey.ThumbRY);
//		DrawString(0, 64, "Button", Color);
//		for (i = 0; i < 16; i++)
//		{
//			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
//				"%2d:%d", i, g_NowKey.Buttons[i]);
//		}
//
//		// 裏画面の内容を表画面に反映
//		ScreenFlip();
//	}
//
//	// ＤＸライブラリの後始末
//	DxLib_End();
//
//	// ソフトの終了
//	return 0;
//}