#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include "DrawAlpha.h"
#include "easygame.h"
#pragma comment(lib,"winmm.lib")

void LoadMenuRes();//载入菜单界面图片文件
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);//根据透明度绘图
void DrawMainMenu();//构建主菜单界面
void StartMenu();//载入开始菜单页面
void TipMenu();//载入提示菜单
void SetMenu();//载入设置菜单

void GameOverMenu();//游戏失败界面


int x1 = 394; int y1 = 510;		//PLAY坐标
int x2 = 80; int y2 = 550;		//问号坐标
int x3 = 724; int y3 = 546;		//设置坐标
int x4 = 392; int y4 = 340;		//返回坐标
int x5 = 392; int y5 = 200;		//音乐坐标

int x6 = 266; int y6 = 346;		//返回菜单按钮坐标
int x7 = 526; int y7 = 344;		//重新游戏按钮坐标

int x8 = 400; int y8 = 366;		//继续游戏按钮坐标

//各个按钮的范围
int r1[] = { x1 - 84, y1 - 36, x1 + 84, y1 + 36, 10, 10 };
int r2[] = { x2 - 26, y2 - 26, x2 + 26, y2 + 26, 0, 0 };
int r3[] = { x3 - 26, y3 - 26, x3 + 26, y3 + 26, 0, 0 };
int r4[] = { x4 - 64, y4 - 26, x4 + 64, y4 + 26, 30, 30 };
int r5[] = { x5 - 54, y5 - 54, x5 + 54, y5 + 54, 0, 0 };

int r6[] = { x6 - 60, y6 - 22, x6 + 60, y6 + 22, 0, 0 };	//返回菜单按钮
int r7[] = { x7 - 60, y7 - 22, x7 + 60, y7 + 22, 0, 0 };	//重新游戏按钮

int r8[] = { x8 - 82, y8 - 20, x8 + 82, y8 + 20, 0, 0 };	//继续游戏按钮




//构建主菜单界面
void DrawMainMenu()
{
	LoadMenuRes();
	drawAlpha(&temp_img, 0, 0, &imag_bk);
	drawAlpha(&temp_img, 290, 400, &imag_playbutton);
	drawAlpha(&temp_img, 50, 520, &imag_more);
	drawAlpha(&temp_img, 700, 520, &imag_set);
}

//提示菜单界面
void DrawTipMenu()
{
	DrawMainMenu();
	drawAlpha(&temp_img, 0, 0, &imag_author);
	drawAlpha(&temp_img, 312, 260, &imag_back);
}
//设置菜单界面
void DrawSetMenu()
{
	DrawMainMenu();
	drawAlpha(&temp_img, 0, 0, &imag_tip);
	drawAlpha(&temp_img, 312, 260, &imag_back);
}

void StartMenu()
{
	//载入开始菜单页面
	DrawMainMenu();
	putimage(0, 0, &temp_img);

	////辅助构建
	//putimage(50, 520, &imag_more);
	//putimage(700, 520, &imag_set);
	//putimage(312, 124, &imag_music);
	//roundrect(r1[0], r1[1], r1[2], r1[3], r1[4], r1[5]);
	//roundrect(r2[0], r2[1], r2[2], r2[3], r2[4], r2[5]);
	//roundrect(r3[0], r3[1], r3[2], r3[3], r3[4], r3[5]);
	//roundrect(r4[0], r4[1], r4[2], r4[3], r4[4], r4[5]);
	//roundrect(r5[0], r5[1], r5[2], r5[3], r5[4], r5[5]);
	

	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		
		if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3]) {
			if (m1.message == WM_LBUTTONDOWN)//当左键按下PLAY时进行的操作
			{
				//进入游戏界面
				cleardevice();
				GameMenu();
			}
		}else if (m1.x > r2[0] && m1.x < r2[2] && m1.y>r2[1] && m1.y < r2[3]) {
			if (m1.message == WM_LBUTTONDOWN)//当左键按下问号时进行的操作
			{
				//弹出提示框
				cleardevice();
				TipMenu();
			}
		}else if (m1.x > r3[0] && m1.x < r3[2] && m1.y>r3[1] && m1.y < r3[3]) {
			if (m1.message == WM_LBUTTONDOWN)//当左键按下设置时进行的操作
			{
				//弹出设置框
				cleardevice();
				SetMenu();
			}
		}
	}
}

//提示菜单界面
void TipMenu()
{
	//弹出提示框
	DrawTipMenu();
	putimage(0, 0, &temp_img);

	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r4[0] && m1.x < r4[2] && m1.y>r4[1] && m1.y < r4[3]) {
			if (m1.message == WM_LBUTTONDOWN)//当左键按下问号时进行的操作
			{
				cleardevice();
				StartMenu();
			}
		}
	}
}

//设置菜单界面
void SetMenu()
{
	DrawSetMenu();
	drawAlpha(&temp_img, 312, 120, &imag_music);
	putimage(0, 0, &temp_img);
	int flag = 1;
	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r4[0] && m1.x < r4[2] && m1.y>r4[1] && m1.y < r4[3]) {
			if (m1.message == WM_LBUTTONDOWN)//当左键按下返回时进行的操作
			{
				cleardevice();
				//GameWinMenu2();
				StartMenu();
			}
		}
		else if(m1.x > r5[0] && m1.x < r5[2] && m1.y>r5[1] && m1.y < r5[3]){
			if (m1.message == WM_LBUTTONDOWN)//当左键按下音乐符号时进行的操作
			{
				if (flag == 1) {
					BGMStop();//先关闭之前播放的本音乐
					flag = 0;
				}
				else
				{
					BGMStart();
					flag = 1;
				}
			}
		}
	}
}

//游戏失败界面
void GameOverMenu()
{
	LoadGameoverMenuRes();
	DrawGame();
	drawAlpha(&temp_game, 76, 60, &imag_gameover);
	drawAlpha(&temp_game, 170, 300, &imag_menubutton);
	drawAlpha(&temp_game, 430, 300, &imag_retrybutton);
	putimage(0, 0, &temp_game);
	//辅助构建
	/*roundrect(r6[0], r6[1], r6[2], r6[3], r6[4], r6[5]);
	roundrect(r7[0], r7[1], r7[2], r7[3], r7[4], r7[5]);*/
	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r6[0] && m1.x < r6[2] && m1.y>r6[1] && m1.y < r6[3]) {	//点击返回菜单按钮
			if (m1.message == WM_LBUTTONDOWN)//当左键按下返回开始菜单时进行的操作
			{
				cleardevice();
				Init();
				BGMStart();
				StartMenu();
			}
		}
		else if (m1.x > r7[0] && m1.x < r7[2] && m1.y>r7[1] && m1.y < r7[3]) {	//点击重新游戏按钮
			if (m1.message == WM_LBUTTONDOWN)//当左键按下重新游戏时进行的操作
			{
				cleardevice();
				Init();
				BGMStart();
				GameMenu();
			}
		}
	}
}

//游戏胜利界面（获取所有宝石）
void GameWinMenu() 
{
	LoadGameWinMenuRes();
	DrawGame();
	drawAlpha(&temp_game, 66, 86, &imag_wined);
	drawAlpha(&temp_game, 288, 320, &imag_continuebutton);
	putimage(0, 0, &temp_game);
	//辅助操作
	/*roundrect(r8[0], r8[1], r8[2], r8[3], r8[4], r8[5]);*/
	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r8[0] && m1.x < r8[2] && m1.y>r8[1] && m1.y < r8[3]) {	//按下继续按钮的操作	
			if (m1.message == WM_LBUTTONDOWN)		//当左键按下继续按钮时进行的操作
			{
				cleardevice();
				Init();
				BGMStart();
				StartMenu();
			}
		}
	}
}

//游戏胜利界面（没有获取所有宝石）
void GameWinMenu2()
{
	LoadGameWinMenuRes();
	DrawGame();
	drawAlpha(&temp_game, 66, 86, &imag_wined2);
	drawAlpha(&temp_game, 288, 320, &imag_continuebutton);
	putimage(0, 0, &temp_game);
	//辅助操作
	/*roundrect(r8[0], r8[1], r8[2], r8[3], r8[4], r8[5]);*/
	ExMessage m1;
	while (1)
	{
		m1 = getmessage();//获取鼠标操作
		if (m1.x > r8[0] && m1.x < r8[2] && m1.y>r8[1] && m1.y < r8[3]) {	//按下继续按钮的操作	
			if (m1.message == WM_LBUTTONDOWN)		//当左键按下继续按钮时进行的操作
			{
				cleardevice();
				Init();
				BGMStart();
				StartMenu();
			}
		}
	}
}