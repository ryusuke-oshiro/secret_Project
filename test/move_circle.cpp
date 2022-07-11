//#include "DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//
//    ChangeWindowMode(TRUE);
//    if (DxLib_Init() == -1) return -1;
//
//    int Key;
//    int mx = 320, my = 200;
//
//    SetDrawScreen(DX_SCREEN_BACK);
//
//    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
//        Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//        if (Key & PAD_INPUT_UP)        my -= 3;
//        if (Key & PAD_INPUT_DOWN)      my += 3;
//        if (Key & PAD_INPUT_RIGHT)     mx += 3;
//        if (Key & PAD_INPUT_LEFT)      mx -= 3;
//
//        ClearDrawScreen();
//
//        DrawString(mx, my, "Åú", 0xFF);
//
//        ScreenFlip();
//    }
//
//    DxLib_End();
//    return 0;
//}