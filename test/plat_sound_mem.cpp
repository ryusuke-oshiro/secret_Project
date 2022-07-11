//#include "DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//
//    ChangeWindowMode(TRUE);
//    if (DxLib_Init() == -1) return -1;
//
//    int TitleSound;
//
//    TitleSound = LoadSoundMem("sounds/sougen-d.mp3");
//
//    ChangeVolumeSoundMem(255 * 20 / 100, TitleSound);
//
//    PlaySoundMem(TitleSound, DX_PLAYTYPE_BACK);
//
//    while (CheckSoundMem(TitleSound) == 1) {
//        if (ProcessMessage() == -1)   break;
//
//        if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
//            StopSoundMem(TitleSound);
//        }
//    }
//
//    DxLib_End();
//
//    return 0;
//}