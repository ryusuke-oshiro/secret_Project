�ｿ/***********************************************************
**    隨ｬ5遶縲繝溘ル繧ｲ繝ｼ繝繧偵▽縺上ｋ�茨ｼ抵ｼ
**縲縲縲縲縲縲縲繝ｬ繝ｼ繧ｹ��∩縺代ご繝ｼ
************************************************************/
#include"DxLib.h"
#include"Common.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define RANKING_DATA 5
#include"PLAYER.h"
#include"APPLE.h"
#include"Common.h"
#include"Title.h"


Title title;


/******************************************************
*螟画焚螳｣險
*******************************************************/
int g_OldKey;	//蜑榊屓縺ｮ蜈･蜉帙く繝ｼ
int g_NowKey;	//莉雁屓縺ｮ蜈･蜉帙く繝ｼ
int g_KeyFlg;	//蜈･蜉帙く繝ｼ諠�ｱ

int g_GameState = 0;	//繧ｲ繝ｼ繝繝｢繝ｼ繝

//int g_TitleImage;		//逕ｻ蜒冗畑螟画焚
//int g_Menu, g_Cone;		//繝｡繝九Η繝ｼ逕ｻ蜒丞､画焚

int g_Score = 0;		//繧ｹ繧ｳ繧｢

int g_RankingImage;		//逕ｻ蜒冗畑螟画焚


int g_WaitTime = 0;

int Time = 0;     //待ち時間
int StartTime;
int RefreshTime;

int g_EndImage;        //エンド画面


int g_Mileage;          //襍ｰ陦瑚ｷ晞屬

int Apple_Img[4]; //繝ｪ繝ｳ繧ｴ謠冗判螟画焚
int g_Item[2];    //繧｢繧､繝�Β逕ｻ蜒丞､画焚
int g_Teki[3];    //繧ｭ繝｣繝ｩ逕ｻ蜒丞､画焚

int g_StageImage;//繧ｹ繝��繧ｸ逕ｻ蜒

int AppleCount1, AppleCount2, AppleCount3, AppleCount4; //繝ｪ繝ｳ繧ｴ繧ｫ繧ｦ繝ｳ繝

int g_Car_left, g_Car_right, g_Car_Nowangle, g_Barrier;	//繧ｭ繝｣繝ｩ逕ｻ蜒丞､画焚

//int g_TitleBGM;
int g_MusicBGM;	//繧ｹ繝��繧ｸ髻ｳ貅
int g_GameOverSE;
//int g_SE1;
//int g_SE2;

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
int color_white;
double Fps = 0.0;


//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ�域ｧ矩菴難ｼ
struct RankingData {
	int no;
	char name[11];
	long score;
};
//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ螟画焚螳｣險
struct RankingData g_Ranking[RANKING_DATA];


/***************************************************
*髢｢謨ｰ縺ｮ繝励Ο繝医ち繧､繝怜ｮ｣險
****************************************************/
void GameInit(void);	//繧ｲ繝ｼ繝蛻晄悄蛹門�逅
void GameMain(void);	//繧ｲ繝ｼ繝繝｡繧､繝ｳ蜃ｦ逅

/*void DrawGameTitle(void);*/  //繧ｿ繧､繝医Ν謠冗判蜃ｦ逅
void DrawGameOver(void);//繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�逕ｻ髱｢謠冗判蜃ｦ逅
void DrawEnd(void);//繧ｲ繝ｼ繝繧ｨ繝ｳ繝画緒逕ｻ蜃ｦ逅
void DrawHelp(void);//繧ｲ繝ｼ繝繝倥Ν繝玲緒逕ｻ蜃ｦ逅

void DrawRanking(void);//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ謠冗判蜃ｦ逅
void InputRanking(void);//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ蜈･蜉

int LoadImages(); //逕ｻ蜒剰ｪｭ縺ｿ霎ｼ縺ｿ

void SortRanking(void);	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ荳ｦ縺ｳ譖ｿ縺
int SaveRanking(void);	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ縺ｮ菫晏ｭ
int ReadRanking(void);	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ隱ｭ縺ｿ霎ｼ縺ｿ

void DrawBackGround();		//閭梧勹逕ｻ蜒上せ繧ｯ繝ｭ繝ｼ繝ｫ蜃ｦ逅


int LoadSounds();	//ステージ


void SetColor();
void FpsTimeFanction();

/****************************************************
*繝励Ο繧ｰ繝ｩ繝縺ｮ髢句ｧ
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{
	XINPUT_STATE input;
	SetMainWindowText("Drive&Avoid");		//�ｽ^�ｽC�ｽg�ｽ�ｽ�ｽ�ｽﾝ抵ｿｽ

	ChangeWindowMode(TRUE);					//�ｽE�ｽB�ｽ�ｽ�ｽh�ｽE�ｽ�ｽ�ｽ[�ｽh�ｽﾅ起�ｽ�ｽ

	if (DxLib_Init() == -1)return -1;		//DX�ｽ�ｽ�ｽC�ｽu�ｽ�ｽ�ｽ�ｽ�ｽﾌ擾ｿｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ



	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;


	SetDrawScreen(DX_SCREEN_BACK);			//描画先画面を裏にする
	SetColor();


	if (LoadImages() == -1)return -1;		//�ｽ鞫懶ｿｽﾇみ搾ｿｽ�ｽﾝ関撰ｿｽ�ｽ�ｽ�ｽﾄび出�ｽ�ｽ

	if (LoadSounds() == -1)return -1;		//�ｽT�ｽE�ｽ�ｽ�ｽh�ｽﾇみ搾ｿｽ�ｽﾝ関撰ｿｽ�ｽ�ｽ�ｽﾄび出�ｽ�ｽ

	if (ReadRanking() == -1) return -1;		//�ｽ�ｽ�ｽ�ｽ�ｽL�ｽ�ｽ�ｽO�ｽf�ｽ[�ｽ^�ｽﾌ読み搾ｿｽ�ｽ�ｽ

	//�ｽQ�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽ[�ｽv
	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {

		RefreshTime = GetNowCount();
		//入力キー取得

		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;


		ClearDrawScreen();			//画面の初期化
		FpsTimeFanction();


		switch (g_GameState) {
		case 0:
			title.DrawGameTitle();		//�ｽQ�ｽ[�ｽ�ｽ�ｽ^�ｽC�ｽg�ｽ�ｽ�ｽ`�ｽ謠茨ｿｽ�ｽ
			break;
		case 1:
			GameInit();				//�ｽQ�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ
			break;
		case 2:
			DrawRanking();			//�ｽ�ｽ�ｽ�ｽ�ｽL�ｽ�ｽ�ｽO�ｽ`�ｽ謠茨ｿｽ�ｽ
			break;
		case 3:
			DrawHelp();				//�ｽQ�ｽ[�ｽ�ｽ�ｽw�ｽ�ｽ�ｽv�ｽ`�ｽ謠茨ｿｽ�ｽ
			break;
		case 4:
			DrawEnd();				//�ｽQ�ｽ[�ｽ�ｽ�ｽG�ｽ�ｽ�ｽh�ｽ`�ｽ謠茨ｿｽ�ｽ
			break;
		case 5:
			GameMain();				//�ｽQ�ｽ[�ｽ�ｽ�ｽ�ｽ�ｽC�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ
			break;
		case 6:
			DrawGameOver();			//�ｽQ�ｽ[�ｽ�ｽ�ｽI�ｽ[�ｽo�ｽ[�ｽ`�ｽ謠茨ｿｽ�ｽ
			break;
		case 7:
			InputRanking();			//�ｽ�ｽ�ｽ�ｽ�ｽL�ｽ�ｽ�ｽO�ｽ�ｽ�ｽﾍ擾ｿｽ�ｽ�ｽ
			break;
		}

		ScreenFlip();	//裏画面の内容を表画面に反映
		while (GetNowCount() - RefreshTime < 17);

	}
	DxLib_End();	//DX�ｽ�ｽ�ｽC�ｽu�ｽ�ｽ�ｽ�ｽ�ｽg�ｽp�ｽﾌ終�ｽ�ｽ�ｽ�ｽ�ｽ�ｽ

	return 0;	//�ｽ\�ｽt�ｽg�ｽﾌ終�ｽ�ｽ
}



void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //白色ハンドルを取得
	return;
}

/*********************************************
*繧ｲ繝ｼ繝繧ｿ繧､繝医Ν陦ｨ遉ｺ�医Γ繝九Η繝ｼ逕ｻ髱｢�
**********************************************/
//void DrawGameTitle(void)
//{
//	static int MenuNo = 0;
//
//	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_BACK, FALSE);
//
//	//繝｡繝九Η繝ｼ繧ｫ繝ｼ繧ｽ繝ｫ遘ｻ蜍募�逅
//	if (g_KeyFlg & PAD_INPUT_DOWN) {
//		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
//		if (++MenuNo > 3)MenuNo = 0;
//	}
//	if (g_KeyFlg & PAD_INPUT_UP) {
//		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
//		if (--MenuNo < 0)MenuNo = 3;
//	}
//	//Z繧ｭ繝ｼ縺ｧ繝｡繝九Η繝ｼ驕ｸ謚
//	if (g_KeyFlg & PAD_INPUT_A) {
//		StopSoundMem(g_TitleBGM);
//		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
//		g_GameState = MenuNo + 1;
//	}
//	//繧ｿ繧､繝医Ν逕ｻ蜒剰｡ｨ遉ｺ
//	DrawGraph(0, 0, g_TitleImage, FALSE);
//
//	//繝｡繝九Η繝ｼ
//	DrawGraph(120, 200, g_Menu, TRUE);
//
//	//繝｡繝九Η繝ｼ繧ｫ繝ｼ繧ｽ繝ｫ
//	DrawRotaGraph(90, 220 + MenuNo * 40, 0.7f, M_PI / 2, g_Cone, TRUE);
//
//}
/********************************************
*繧ｲ繝ｼ繝蛻晄悄蛹門�逅
*********************************************/
void GameInit(void)
{
	//繧ｹ繧ｳ繧｢縺ｮ蛻晄悄蛹
	g_Score = 0;

	//襍ｰ陦瑚ｷ晞屬繧貞�譛溷喧
	g_Mileage = 0;
	g_player.InitPlayer();
	apple.InitApple();


	Time = GetNowCount();
	
	//ゲームメイン処理へ
	g_GameState = 5;


}
/*******************************************
*繧ｲ繝ｼ繝繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ謠冗判蜃ｦ逅
********************************************/
void DrawRanking(void)
{
	//繧ｹ繝壹�繧ｹ繧ｭ繝ｼ縺ｧ繝｡繝九Η繝ｼ縺ｫ謌ｻ繧
	if (g_KeyFlg & PAD_INPUT_M) g_GameState = 0;


	//ランキング画像処理 

	DrawGraph(0, 0, g_RankingImage, FALSE);

	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ荳隕ｧ繧定｡ｨ遉ｺ
	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	DrawString(100, 450, "----繧ｹ繝壹�繧ｹ繧ｭ繝ｼ繧呈款縺励※繧ｿ繧､繝医Ν縺ｸ謌ｻ繧 ----", 0xffffff, 0);

}
/*******************************************
*繧ｲ繝ｼ繝繝倥Ν繝玲緒逕ｻ蜃ｦ逅
********************************************/
void DrawHelp(void)
{
	// 繧ｹ繝壹�繧ｹ繧ｭ繝ｼ縺ｧ繝｡繝九Η繝ｼ縺ｫ謌ｻ繧
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;

	//繧ｿ繧､繝医Ν逕ｻ蜒剰｡ｨ遉ｺ
	DrawGraph(0, 0, title.g_TitleImage, FALSE);
	SetFontSize(16);
	DrawString(20, 120, "繝倥Ν繝礼判髱｢", 0xffffff, 0);

	DrawString(20, 160, "縺薙ｌ縺ｯ髫懷ｮｳ迚ｩ繧帝∩縺代↑縺後ｉ", 0xffffff, 0);
	DrawString(20, 180, "襍ｰ繧顔ｶ壹￠繧九ご繝ｼ繝縺ｧ縺", 0xffffff, 0);
	DrawString(20, 200, "辯�侭縺悟ｰｽ縺阪ｋ縺矩囿螳ｳ迚ｩ縺ｫ", 0xffffff, 0);
	DrawString(20, 220, "謨ｰ蝗槫ｽ薙◆繧九→繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�縺ｧ縺", 0xffffff, 0);
	DrawString(20, 250, "繧｢繧､繝�Β荳隕ｧ", 0xffffff, 0);
	DrawGraph(20, 260, g_Item[0], TRUE);
	DrawString(20, 315, "蜿悶ｋ縺ｨ辯�侭縺悟屓蠕ｩ縺吶ｋ繧", 0xffffff, 0);
	DrawGraph(20, 335, g_Item[1], TRUE);
	DrawString(20, 385, "繝繝｡繝ｼ繧ｸ繧貞女縺代※縺�ｋ縺ｨ縺阪↓蜿悶ｋ縺ｨ閠蝉ｹ�屓蠕ｩ", 0xffffff, 0);
	DrawString(20, 405, "閠蝉ｹ�′貂帙▲縺ｦ縺�↑縺九▲縺溘ｉ辯�侭縺悟ｰ代＠蝗槫ｾｩ縺吶ｋ繧", 0xffffff, 0);
	DrawString(20, 450, "---- 繧ｹ繝壹�繧ｹ繧ｭ繝ｼ繧呈款縺励※繧ｿ繧､繝医Ν縺ｸ謌ｻ繧 ----", 0xffffff, 0);
}
/*******************************************
*繧ｲ繝ｼ繝繧ｨ繝ｳ繝画緒逕ｻ蜃ｦ逅
********************************************/
void DrawEnd(void)
{
	//繧ｨ繝ｳ繝臥判蜒剰｡ｨ遉ｺ
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for Playing", 0xffffff, 0);

	//繧ｿ繧､繝縺ｮ蜉邂怜�逅�ｼ�ｵゆｺ�ｼ茨ｼ鍋ｧ貞ｾ鯉ｼ
	if (++g_WaitTime > 180)g_GameState = 99;
}
/******************************************
*繧ｲ繝ｼ繝繝｡繧､繝ｳ
******************************************/
void GameMain(void)
{
		PlaySoundMem(g_MusicBGM, DX_PLAYTYPE_LOOP, FALSE);

		DrawBackGround();

		apple.AppleControl();

		/*ItemControl();*/

		g_player.PlayerControl();


	

	//繧ｹ繝壹�繧ｹ繧ｭ繝ｼ縺ｧ繝｡繝九Η繝ｼ縺ｫ謌ｻ繧
	//if (g_KeyFlg & PAD_INPUT_M)g_GameState = 6;

	//SetFontSize(16);
	//DrawString(20, 20, "繧ｲ繝ｼ繝繝｡繧､繝ｳ", 0xffffff, 0);
	//DrawString(150, 450, "---- 繧ｹ繝壹�繧ｹ繧ｭ繝ｼ繧呈款縺励※繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�縺ｸ ----", 0xffffff, 0);
}


/*******************************************
*繧｢繧､繝�Β縺ｮ蛻ｶ蠕｡
*蠑輔謨ｰ�壹↑縺
*謌ｻ繧雁､�壹↑縺
*********************************************/
//void ItemControl()
//{
//	for (int i = 0; i < ITEM_MAX; i++) {
//		if (g_item[i].flg == TRUE) {
//
//			//繧｢繧､繝�Β縺ｮ陦ｨ遉ｺ
//			DrawRotaGraph(g_item[i].x, g_item[i].y, 1.0f, 0, g_item[i].img, TRUE);
//			if (g_player.flg == FALSE)continue;
//
//			//縺ｾ縺｣縺吶＄荳九↓遘ｻ蜍
//			g_item[i].y += g_item[i].speed + g_player.speed - GameInit.getPLAYER_SPEED();
//
//			//逕ｻ髱｢繧偵�縺ｿ蜃ｺ縺励◆繧画ｶ亥悉
//			if (g_item[i].y > SCREEN_HEIGHT)g_item[i].flg = FALSE;
//
//			//蠖薙◆繧雁愛螳
//			if (g_player.HitBoxPlayer(&g_player, &g_item[i]) == TRUE) {
//				g_item[i].flg = FALSE;
//				if (g_item[i].type == 0)g_player.fuel += g_item[i].point;
//				if (g_item[i].type == 1) {
//					g_player.hp += g_item[i].point;
//					if (g_player.hp > GameInit.getPLAYER_HP())
//						g_player.hp = GameInit.getPLAYER_HP();
//				}
//			}
//		}
//	}
//
//	//襍ｰ陦瑚ｷ晞屬縺斐→縺ｫ謨ｵ蜃ｺ迴ｾ繝代ち繝ｼ繝ｳ繧貞宛蠕｡縺吶ｋ
//	if (g_Mileage / 10 % 500 == 0) {
//		CreateItem();
//	}
//}

/******************************************
*繧｢繧､繝�Β縺ｮ逕滓�
*蠑輔謨ｰ�壹↑縺
*謌ｻ繧雁､�啜RUE�壽�蜉溘FALSE�壼､ｱ謨
*******************************************/
//int CreateItem()
//{
//	for (int i = 0; i < ITEM_MAX; i++) {
//		if (g_item[i].flg == FALSE) {
//			g_item[i] = g_item00;
//			g_item[i].type = GetRand(1);
//			g_item[i].img = g_Item[g_item[i].type];
//			g_item[i].x = GetRand(4) * 105 + 40;
//			g_item[i].speed = 1 + g_item[i].type * 3;
//			if (g_item[i].type == 0)g_item[i].point = 500;
//			if (g_item[i].type == 1)g_item[i].point = 50;
//
//			//謌仙粥
//			return TRUE;
//		}
//	}
//
//	//螟ｱ謨
//	return FALSE;
//}


/*******************************************
*繝励Ξ繧､繝､繝ｼ縺ｮ遘ｻ蜍
*蠑墓焚�壹↑縺
* 謌ｻ繧雁､�壹↑縺
********************************************/
//void PlayerControl()
//{
//	//辯�侭縺ｮ豸郁ｲｻ
//	g_player.fuel -= g_player.speed;
//	//繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�蜃ｦ逅�∈
//	if (g_player.fuel <= 0) {
//		g_GameState = 6;
//		StopSoundMem(g_MusicBGM);
//	}
//	//Z繧ｭ繝ｼ縺ｧ蜉騾
//	if (g_KeyFlg & PAD_INPUT_A && g_player.speed < 10)g_player.speed += 1;
//
//	//X繧ｭ繝ｼ縺ｧ貂幃
//	if (g_KeyFlg & PAD_INPUT_B && g_player.speed > 1)g_player.speed -= 1;
//
//	//荳贋ｸ句ｷｦ蜿ｳ遘ｻ蜍
//	if (g_player.flg == TRUE) {
//		if (g_NowKey & PAD_INPUT_UP)g_player.y -= g_player.speed;
//		if (g_NowKey & PAD_INPUT_DOWN)g_player.y += g_player.speed;
//		if (g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
//		if (g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
//	}
//
//	//逕ｻ髱｢繧偵�縺ｿ蜃ｺ縺輔↑縺�ｈ縺�↓縺吶ｋ
//	if (g_player.x < 32)g_player.x = 32;
//	if (g_player.x > SCREEN_WIDTH - 180)g_player.x = SCREEN_WIDTH - 180;
//	if (g_player.y < 60)g_player.y = 60;
//	if (g_player.y > SCREEN_HEIGHT - 60)g_player.y = SCREEN_HEIGHT - 60;
//
//	//繝励Ξ繧､繝､繝ｼ縺ｮ陦ｨ遉ｺ
//	if (g_player.flg == TRUE) {
//		if (g_NowKey & PAD_INPUT_LEFT) {
//			DrawRotaGraph(g_player.x, g_player.y, 1.0f, -M_PI / 18, g_Car, TRUE, FALSE);
//		}
//		else if (g_NowKey & PAD_INPUT_RIGHT) {
//			DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 18, g_Car, TRUE, FALSE);
//		}
//		else {
//			DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Car, TRUE, FALSE);
//		}
//
//		if (g_KeyFlg & PAD_INPUT_C && g_player.bari > 0 && g_player.baricnt <= 0) {
//			g_player.bari--;
//			g_player.baricnt = 1000;
//		}
//		if (g_player.baricnt > 0) {
//			g_player.baricnt -= g_player.speed;
//			DrawRotaGraph(g_player.x, g_player.y, 1.0f, 0, g_Barrier, TRUE, FALSE);
//		}
//
//	}
//	else {
//		DrawRotaGraph(g_player.x, g_player.y, 1.0f, M_PI / 8 * (++g_player.count / 5), g_Car, TRUE, FALSE);
//		if (g_player.count >= 80)g_player.flg = TRUE;
//	}
//	//謨ｵ繧偵ｈ縺代◆謨ｰ繧定｡ｨ遉ｺ
//	SetFontSize(16);
//	DrawFormatString(510, 20, 0x000000, "繝上う繧ｹ繧ｳ繧｢");
//	DrawFormatString(560, 40, 0xFFFFFF, "%08d", g_Ranking[0].score);
//	DrawFormatString(510, 80, 0x000000, "驕ｿ縺代◆謨ｰ");
//	DrawRotaGraph(523, 120, 0.3f, 0, g_Teki[0], TRUE, FALSE);
//	DrawRotaGraph(573, 120, 0.3f, 0, g_Teki[1], TRUE, FALSE);
//	DrawRotaGraph(623, 120, 0.3f, 0, g_Teki[2], TRUE, FALSE);
//
//	DrawFormatString(510, 140, 0xFFFFFF, "%03d", g_EnemyCount1);
//	DrawFormatString(560, 140, 0xFFFFFF, "%03d", g_EnemyCount2);
//	DrawFormatString(610, 140, 0xFFFFFF, "%03d", g_EnemyCount3);
//	DrawFormatString(510, 200, 0x000000, "襍ｰ陦瑚ｷ晞屬");
//	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
//	DrawFormatString(510, 240, 0x000000, "繧ｹ繝斐�繝");
//	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);
//
//	//繝舌Μ繧｢縺ｮ陦ｨ遉ｺ
//	for (int i = 0; i < g_player.bari; i++) {
//		DrawRotaGraph(520 + i * 25, 340, 0.2f, 0, g_Barrier, TRUE, FALSE);
//	}
//
//	//辯�侭繧ｲ繝ｼ繧ｸ縺ｮ陦ｨ遉ｺ
//	int F_X = 510; int F_Y = 390; int F_W = 100; int F_H = 20;
//	DrawString(F_X, F_Y, "FUEL METER", 0x000000, 0);
//	//蜀��縺ｮ繧ｲ繝ｼ繧ｸ
//	DrawBox(F_X, F_Y + 20, F_X + (int)(g_player.fuel * F_W / PLAYER_FUEL), F_Y + 20 + F_H, 0x0066cc, TRUE);
//	//螟門�縺ｮ繧ｲ繝ｼ繧ｸ譫
//	DrawBox(F_X, F_Y + 20, F_X + F_W, F_Y + 20 + F_H, 0x000000, FALSE);
//
//	//菴灘鴨繧ｲ繝ｼ繧ｸ縺ｮ陦ｨ遉ｺ
//	int X = 510; int Y = 430; int W = 100; int H = 20;
//	DrawString(X, Y, "PLAYER HP", 0x000000, 0);
//	//蜀��繧ｲ繝ｼ繧ｸ
//	DrawBox(X, Y + 20, X + (int)(g_player.hp * W / PLAYER_HP), Y + 20 + H, 0xff0000, TRUE);
//	//螟門�縺ｮ繧ｲ繝ｼ繧ｸ譫
//	DrawBox(X, Y + 20, X + W, Y + 20 + H, 0x000000, FALSE);
//
//}
/*****************************************
*謨ｵ讖溘�逕滓�
*蠑輔謨ｰ:縺ｪ縺
*謌ｻ繧雁､:TRUE;謌仙粥縲FALSE:螟ｱ謨
******************************************/
//int CreateEnemy()
//{
//	for (int i = 0; i < Apple_MAX; i++) {
//		if (g_enemy[i].flg == FALSE) {
//			g_enemy[i] = g_enemy00;
//			g_enemy[i].type = GetRand(2);
//			g_enemy[i].img = g_Teki[g_enemy[i].type];
//			g_enemy[i].x = GetRand(4) * 105 + 40;
//			g_enemy[i].speed = g_enemy[i].type * 2;
//			//謌仙粥
//			return TRUE;
//		}
//	}
//
//	//螟ｱ謨
//	return FALSE;
//}

/*****************************************
*繧ｨ繝阪Α繝ｼ縺ｮ遘ｻ蜍
*蠑輔謨ｰ:縺ｪ縺
*謌ｻ繧雁､:縺ｪ縺
*******************************************/
//void EnemyControl()
//{
//	for (int i = 0; i < Apple_MAX; i++) {
//		if (g_enemy[i].flg == TRUE) {
//
//			//謨ｵ縺ｮ陦ｨ遉ｺ
//			DrawRotaGraph(g_enemy[i].x, g_enemy[i].y, 1.0f, 0, g_enemy[i].img, TRUE, FALSE);
//
//			if (g_player.flg == FALSE)continue;
//
//			//縺ｾ縺｣縺吶＄荳九↓遘ｻ蜍
//			g_enemy[i].y += g_enemy[i].speed + g_player.speed - PLAYER_SPEED + 1;
//
//			//逕ｻ髱｢繧偵�縺ｿ蜃ｺ縺励◆繧画ｶ亥悉
//			if (g_enemy[i].y > SCREEN_HEIGHT + g_enemy[i].h)
//				g_enemy[i].flg = FALSE;
//
//			//謨ｵ讖溘ｒ霑ｽ縺�ｶ翫＠縺溘ｉ繧ｫ繧ｦ繝ｳ繝医☆繧
//			if (g_enemy[i].y > g_player.y && g_enemy[i].point == 1) {
//				g_enemy[i].point = 0;
//				if (g_enemy[i].type == 0)g_EnemyCount1++;
//				if (g_enemy[i].type == 1)g_EnemyCount2++;
//				if (g_enemy[i].type == 2)g_EnemyCount3++;
//			}
//			//蠖薙◆繧雁愛螳
//			if (HitBoxPlayer(&g_player, &g_enemy[i]) == TRUE && g_player.baricnt <= 0) {
//				g_player.flg = FALSE;
//				g_player.speed = PLAYER_SPEED;
//				g_player.count = 0;
//				g_player.hp -= 100;
//				g_enemy[i].flg = FALSE;
//				if (g_player.hp <= 0) {
//					g_GameState = 6;
//					StopSoundMem(g_MusicBGM);
//				}
//			}
//		}
//	}
//
//	//襍ｰ陦瑚ｷ晞屬縺斐→縺ｫ謨ｵ蜃ｺ迴ｾ繝代ち繝ｼ繝ｳ繧貞宛蠕｡縺吶ｋ
//	if (g_Mileage / 10 % 50 == 0) {
//		CreateEnemy();
//	}
//}

/******************************************
*閾ｪ讖溘→謨ｵ讖溘�蠖薙◆繧雁愛螳
*蠑輔謨ｰ:PLAYER縲繝昴う繝ｳ繧ｿ
*謌ｻ繧雁､:TRUE:蠖薙◆繧:FALSE:縺ｪ縺
*******************************************/
//int HitBoxPlayer(PLAYER* p, APPLE* e)
//{
//	//x,y縺ｯ荳ｭ蠢�ｺｧ讓吶→縺吶ｋ
//	int sx1 = p->x - (p->w / 2);
//	int sy1 = p->y - (p->h / 2);
//	int sx2 = sx1 + p->w;
//	int sy2 = sy1 + p->h;
//
//	int dx1 = e->x - (e->w / 2);
//	int dy1 = e->y - (e->h / 2);
//	int dx2 = dx1 + e->w;
//	int dy2 = dy1 + e->h;
//
//	//遏ｩ蠖｢縺碁㍾縺ｪ縺｣縺ｦ縺�ｌ縺ｰ蠖薙◆繧
//	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
//		return TRUE;
//	}
//	return FALSE;
//}
/******************************************
*閭梧勹逕ｻ蜒上せ繧ｯ繝ｭ繝ｼ繝ｫ蜃ｦ逅
*蠑輔謨ｰ�壹↑縺
*謌ｻ繧雁､�壹↑縺
********************************************/
void DrawBackGround()
{
	////g_Mileage += 5;

	//g_Mileage += g_player.speed;

	////繧ｹ繝��繧ｸ逕ｻ蜒剰｡ｨ遉ｺ

	////謠冗判蜿ｯ閭ｽ繧ｨ繝ｪ繧｢繧定ｨｭ螳
	//SetDrawArea(0, 0, 500, 480);

	DrawGraph(0, 0, g_StageImage, FALSE);		//逕ｻ蜒擾ｼ壽ｨｪ490+150(繧ｹ繧ｳ繧｢陦ｨ遉ｺ蛻)=640:邵ｦ480

	//DrawGraph(0, g_Mileage % 480 - 480, g_StageImage, FALSE);

	//DrawGraph(0, g_Mileage % 480, g_StageImage, FALSE);

	////繧ｨ繝ｪ繧｢繧呈綾縺
	//SetDrawArea(0, 0, 640, 480);

	////繧ｹ繧ｳ繧｢遲芽｡ｨ遉ｺ鬆伜沺
	//DrawBox(500, 0, 640, 480, 0x009900, TRUE);
}

/***************************************
*繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�逕ｻ髱｢謠冗判蜃ｦ逅
****************************************/
void DrawGameOver(void)
{
	PlaySoundMem(g_GameOverSE, DX_PLAYTYPE_BACK, FALSE);
	g_Score = (g_Mileage / 10 * 10) + AppleCount3 * 50 + AppleCount1 * 200;

	//繧ｹ繝壹�繧ｹ繧ｭ繝ｼ縺ｧ繝｡繝九Η繝ｼ縺ｫ謌ｻ繧
	if (g_KeyFlg & PAD_INPUT_M) {
		if (g_Ranking[RANKING_DATA].score >= g_Score) {
			g_GameState = 0;
		}
		else {
			g_GameState = 7;
		}
	}

	DrawBox(150, 150, 490, 330, 0x009900, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(220, 170, "繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌�", 0xcc0000);
	SetFontSize(16);
	DrawString(180, 200, "襍ｰ陦瑚ｷ晞屬縲縲縲", 0x000000);
	DrawRotaGraph(230, 230, 0.3f, M_PI / 2, g_Teki[2], TRUE, FALSE);

	DrawRotaGraph(230, 250, 0.3f, M_PI / 2, g_Teki[1], TRUE, FALSE);

	DrawRotaGraph(230, 270, 0.3f, M_PI / 2, g_Teki[0], TRUE, FALSE);

	DrawFormatString(260, 200, 0xFFFFFF, "%6d x  10 = %6d", g_Mileage / 10, g_Mileage / 10 * 10);

	DrawFormatString(260, 222, 0xFFFFFF, "%6d x  50 = %6d", AppleCount3, AppleCount3 * 50);

	DrawFormatString(260, 243, 0xFFFFFF, "%6d x  100 = %6d", AppleCount2, AppleCount2 * 100);

	DrawFormatString(260, 264, 0xFFFFFF, "%6d x  200 = %6d", AppleCount1, AppleCount1 * 200);

	DrawString(310, 290, "繧ｹ繧ｳ繧｢", 0x000000);

	DrawFormatString(260, 290, 0xFFFFFF, "          =%6d", g_Score);

	DrawString(150, 450, "---- 繧ｹ繝壹�繧ｹ繧ｭ繝ｼ繧呈款縺励※繧ｿ繧､繝医Ν縺ｸ謌ｻ繧 ----", 0xffffff, 0);

}
/****************************************
*繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ蜈･蜉帛�逅
****************************************/
void InputRanking(void)
{
	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ逕ｻ蜒剰｡ｨ遉ｺ
	DrawGraph(0, 0, g_RankingImage, FALSE);

	// 繝輔か繝ｳ繝医し繧､繧ｺ縺ｮ險ｭ螳
	SetFontSize(20);

	// 蜷榊燕蜈･蜉帶欠遉ｺ譁�ｭ怜�縺ｮ謠冗判
	DrawString(150, 240, "繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ縺ｫ逋ｻ骭ｲ縺励∪縺", 0xFFFFFF);
	DrawString(150, 270, "蜷榊燕繧定恭蟄励〒蜈･蜉帙＠縺ｦ縺上□縺輔＞", 0xFFFFFF);

	// 蜷榊燕縺ｮ蜈･蜉
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[RANKING_DATA].name, FALSE) == 1) {
		g_Ranking[RANKING_DATA].score = g_Score;	// 繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ縺ｮ�托ｼ千分逶ｮ縺ｫ繧ｹ繧ｳ繧｢繧堤匳骭ｲ
		SortRanking();		// 繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ荳ｦ縺ｹ譖ｿ縺
		SaveRanking();		// 繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ縺ｮ菫晏ｭ
		g_GameState = 2;		// 繧ｲ繝ｼ繝繝｢繝ｼ繝峨�螟画峩
	}
}
/************************************************:
*繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ荳ｦ縺ｳ譖ｿ縺
***********************************************/
void SortRanking(void) {
	int i, j;
	RankingData work;

	// 驕ｸ謚樊ｳ輔た繝ｼ繝
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	// 鬆�ｽ堺ｻ倥￠
	for (i = 0; i < RANKING_DATA; i++) {
		g_Ranking[i].no = 1;
	}
	// 蠕礼せ縺悟酔縺伜ｴ蜷医�縲∝酔縺倬�ｽ阪→縺吶ｋ
	// 蜷碁�ｽ阪′縺ゅ▲縺溷ｴ蜷医�谺｡縺ｮ鬆�ｽ阪�繝��繧ｿ蛟区焚縺悟刈邂励＆繧後◆鬆�ｽ阪→縺吶ｋ
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}
/****************************************
*繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ菫晏ｭ
*****************************************/
int SaveRanking(void) {

	FILE* fp;
#pragma warning(disable:4996)

	// 繝輔ぃ繧､繝ｫ繧ｪ繝ｼ繝励Φ
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* 繧ｨ繝ｩ繝ｼ蜃ｦ逅 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// 繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ蛻��蛻励ョ繝ｼ繧ｿ繧呈嶌縺崎ｾｼ繧
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//繝輔ぃ繧､繝ｫ繧ｯ繝ｭ繝ｼ繧ｺ
	fclose(fp);

	return 0;

}
/*****************************************
*繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ隱ｭ縺ｿ霎ｼ縺ｿ
******************************************/
int ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//繝輔ぃ繧､繝ｫ繧ｪ繝ｼ繝励Φ
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//繧ｨ繝ｩ繝ｼ蜃ｦ逅
		printf("Ranking Data Error\n");
		return -1;
	}

	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ繝��繧ｿ驟榊�蛻励ョ繝ｼ繧ｿ繧定ｪｭ縺ｿ霎ｼ繧
	for (int i = 0; i < RANKING_DATA; i++) {
		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	//繝輔ぃ繧､繝ｫ繧ｯ繝ｭ繝ｼ繧ｺ
	fclose(fp);

	return 0;
}
/***************************************
*繧ｵ繧ｦ繝ｳ繝芽ｪｭ縺ｿ霎ｼ縺ｿ
****************************************/
int LoadSounds()
{
	if ((title.g_TitleBGM = LoadSoundMem("sounds/Initial D - Night Of Fire.mp3")) == -1)return -1;
	//initial D髻ｳ貅
	if ((g_MusicBGM = LoadSoundMem("sounds/Daisuke full ver. (豁瑚ｩ槭�蜥瑚ｨｳ莉倥″).mp3")) == -1)return -1;
	if ((g_GameOverSE = LoadSoundMem("sounds/GameOver.mp3")) == -1)return -1;

	//SE1 繝��繧ｿ隱ｭ縺ｿ霎ｼ縺ｿ
	if ((title.g_SE1 = LoadSoundMem("sounds/SE1.mp3")) == -1)return -1;
	//SE2 繝��繧ｿ隱ｭ縺ｿ霎ｼ縺ｿ
	if ((title.g_SE2 = LoadSoundMem("sounds/SE2.mp3")) == -1)return -1;


	//SE縺ｮ髻ｳ驥剰ｪｿ謨ｴ
	ChangeVolumeSoundMem(80, title.g_SE2);

	ChangeVolumeSoundMem(120, title.g_SE1);

	return 0;
}
/****************************************
*逕ｻ蜒剰ｪｭ縺ｿ霎ｼ縺ｿ
*****************************************/
int LoadImages()
{

	//繧ｿ繧､繝医Ν
	if ((title.g_TitleImage = LoadGraph("images/BackGround_a.png")) == -1)return -1;
	//繝｡繝九Η繝ｼ
	if ((title.g_Menu = LoadGraph("images/menu.bmp")) == -1)return -1;
	if ((title.g_Cone = LoadGraph("images/cone.bmp")) == -1)return -1;
	//繝ｪ繝ｳ繧ｴ

	if ((Apple_Img[0] = LoadGraph("images/RedApple.png")) == -1)return -1;
	if ((Apple_Img[1] = LoadGraph("images/GreenApple.png")) == -1)return -1;
	if ((Apple_Img[2] = LoadGraph("images/YellowApple.png")) == -1)return -1;
	if ((Apple_Img[3] = LoadGraph("images/PurpleApple.png")) == -1)return -1;
	//繧｢繧､繝�Β
	if ((g_Item[0] = LoadGraph("images/gasoline.bmp")) == -1)return -1;
	if ((g_Item[1] = LoadGraph("images/supana.bmp")) == -1)return -1;
	//謨ｵ
	/*if (LoadDivGraph("images/RedApple.png", 3, 3, 1, 63, 120, g_Teki) == -1)return -1;*/

	//繝ｩ繝ｳ繧ｭ繝ｳ繧ｰ陦ｨ遉ｺ
	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;

	//繧ｹ繝��繧ｸ閭梧勹
	if ((g_StageImage = LoadGraph("images/BackGround.png")) == -1)return -1;
	//繝励Ξ繧､繝､繝ｼ
	if ((g_Car_left = LoadGraph("images/PlayerA.png")) == -1)return -1;
	if ((g_Car_right = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Car_Nowangle = LoadGraph("images/PlayerA_2.png")) == -1)return -1;
	if ((g_Barrier = LoadGraph("images/barrier.png")) == -1)return -1;

	return 0;
}
