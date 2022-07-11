//#include "DxLib.h"
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine, int nCmdShow)
//{
//	DATEDATA Date;
//
//	ChangeWindowMode(TRUE);
//
//
//	if (DxLib_Init() == -1)
//		return -1;
//
//	int PosX = 350;
//	int PosY = 200;
//	int NumberImage[10];
//	LoadDivGraph("images/number.bmp", 10, 10, 1, 20, 30, NumberImage);
//	
//	int TitleSound;
//	TitleSound = LoadSoundMem("sounds/life_01_mezamasi.mp3");
//	
//	while (1) {
//
//		SetDrawScreen(DX_SCREEN_BACK);
//
//		ClearDrawScreen();
//
//		GetDateTime(&Date);
//
//		int color;
//		color = GetColor(0, 0, 255);
//		
//		if (Date.Sec%10 == 0) {										//ifï∂Ç≈ÉTÉEÉìÉh
//			ChangeVolumeSoundMem(255 * 20 / 100, TitleSound);
//			PlaySoundMem(TitleSound, DX_PLAYTYPE_BACK);
//		}
//		DrawFormatString(PosX + 20, PosY + 5, color, "ïb");			//Å`ïbÇÃï\é¶
//		DrawGraph(PosX, PosY, NumberImage[Date.Sec % 10], TRUE);
//				Date.Sec /= 10;
//				
//		DrawGraph(PosX - 20, PosY, NumberImage[Date.Sec % 10], TRUE);
//		
//		DrawFormatString(PosX - 40, PosY + 5, color, "ï™");			//Å`ï™ÇÃï\é¶
//		DrawGraph(PosX - 60, PosY, NumberImage[Date.Min % 10], TRUE);
//		        Date.Min /= 10;
//		DrawGraph(PosX - 80, PosY, NumberImage[Date.Min % 10], TRUE);
//		
//		
//		DrawFormatString(PosX - 100, PosY + 5, color, "éû");		//Å`éûÇÃï\é¶
//		DrawGraph(PosX - 120, PosY, NumberImage[Date.Hour % 10], TRUE);
//				Date.Hour /= 10;
//		DrawGraph(PosX - 140, PosY, NumberImage[Date.Hour % 10], TRUE);
//		
//		ScreenFlip();
//
//		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
//			break;
//		}
//
//
//	}
//
//	DxLib_End();
//
//	return 0;
//}