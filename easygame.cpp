#include "DrawAll.h"
#include "Judge.h"
#include <time.h>
#include "gamemenu.h"


int EdgePoint1_x = 30; int EdgePoint1_y = 520;		//左下角边界坐标
int EdgePoint2_x = 30; int EdgePoint2_y = 22;		//左上角边界坐标
int EdgePoint32_x = 672; int EdgePoint32_y = 484;	//右下角边界坐标
int EdgePoint3_x = 720; int EdgePoint3_y = 460;		//右下角边界坐标
int EdgePoint4_x = 720; int EdgePoint4_y = 22;		//右上角边界坐标

int EdgePointLeft = 0;			//最左边界点
int EdgePointRight = 720;		//最右边界点
int EdgePointUp = 0;			//最上边界点
int EdgePointDown = 508;		//最下边界点




//延时函数
void Delay(int ms)
{
	static clock_t oldclock = clock();		// 静态变量，记录上一次 tick

	oldclock += ms * CLOCKS_PER_SEC / 1000;	// 更新 tick

	if (clock() > oldclock)					// 如果已经超时，无需延时
		oldclock = clock();
	else
		while (clock() < oldclock)			// 延时
			Sleep(1);						// 释放 CPU 控制权，降低 CPU 占用率
}



void DealInput()
{
	//每一次的碰撞检测
	FirstJudge();
	SecondJudge();
	ThirdJudge();
	FourthJudge();
	FifthJudge();

	FirstJudge2(); 
	SecondJudge2();
	ThirdJudge2();
	FourthJudge2();
	FifthJudge2();

	

	//冰娃操作
	/*if ((input1 & UPINPUT) && (WaterGirl.y - WaterGirl.velocityY >= EdgePointUp)) {

		WaterGirl.y -= WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & LEFTINPUT) && (WaterGirl.x - WaterGirl.velocityX >= EdgePointLeft)) {
		WaterGirl.x -= WaterGirl.velocityX;
		DrawWatergirlLeft();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & RIGHTINPUT) && (WaterGirl.x + WaterGirl.velocityX <= EdgePointRight)) {
		if (WaterGirl.x >= 664 && WaterGirl.y == 508) {
			WaterGirl.x = 664;
		}
		WaterGirl.x += WaterGirl.velocityX;
		DrawWatergirlRight();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & DOWNINPUT) && (WaterGirl.y + WaterGirl.velocityY <= EdgePointDown)) {
		WaterGirl.y += WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}*/
	if ((input1 & UPINPUT) && (WaterGirl.y - WaterGirl.velocityY >= EdgePointUp)) {
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & LEFTINPUT) && (WaterGirl.x - WaterGirl.velocityX >= EdgePointLeft)) {
		if (WaterGirl.x <= 88 && WaterGirl.y == 346) {		//第二层电梯
			WaterGirl.x = 88;
		}
		if (WaterGirl.x <= 656 && WaterGirl.y == 192) {		//第三层电梯到第四层
			WaterGirl.x = 656;
		}
		if (WaterGirl.x <= 110 + 35 && WaterGirl.y == 166) {	//第四层推箱子到最左边
			WaterGirl.x = 110 + 35;
		}
		if (WaterGirl.x <= 100 && WaterGirl.y == 132) {	//第四层推箱子上
			WaterGirl.x = 100;
		}
		WaterGirl.x -= WaterGirl.velocityX;
		DrawWatergirlLeft();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & RIGHTINPUT) && (WaterGirl.x + WaterGirl.velocityX <= EdgePointRight)) {
		if (WaterGirl.x >= 664 && WaterGirl.y == 508) {		//第一层右边墙壁
			WaterGirl.x = 664;
		}
		if (WaterGirl.x >= 648 && WaterGirl.y == 266) {		//第三层电梯
			WaterGirl.x = 648;
		}
		WaterGirl.x += WaterGirl.velocityX;
		DrawWatergirlRight();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & DOWNINPUT) && (WaterGirl.y + WaterGirl.velocityY <= EdgePointDown)) {
		WaterGirl.y += WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("冰娃(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}



	//火娃操作
	if ((input2 & UPINPUT) && (FireBoy.y - FireBoy.velocityY >= EdgePointUp)) {
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("火娃(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & LEFTINPUT) && (FireBoy.x - FireBoy.velocityX >= EdgePointLeft)) {
		if (FireBoy.x <= 88 && FireBoy.y == 346) {		//第二层电梯
			FireBoy.x = 88;
		}
		if (FireBoy.x <= 656 && FireBoy.y == 192) {		//第三层电梯到第四层
			FireBoy.x = 656;
		}
		if (FireBoy.x <= 110 + 35 && FireBoy.y == 166) {	//第四层推箱子到最左边
			FireBoy.x = 110 + 35;
		}
		if (FireBoy.x <= 100 && FireBoy.y == 132) {	//第四层推箱子上
			FireBoy.x = 100;
		}
		FireBoy.x -= FireBoy.velocityX;
		DrawFireboyLeft();
		putimage(0, 0, &temp_game);
		printf("火娃(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & RIGHTINPUT) && (FireBoy.x + FireBoy.velocityX <= EdgePointRight)) {
		if (FireBoy.x >= 664 && FireBoy.y == 508) {		//第一层右边墙壁
			FireBoy.x = 664;
		}
		if (FireBoy.x >= 648 && FireBoy.y == 266) {		//第三层电梯
			FireBoy.x = 648;
		}
		FireBoy.x += FireBoy.velocityX;
		DrawFireboyRight();
		putimage(0, 0, &temp_game);
		printf("火娃(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & DOWNINPUT) && (FireBoy.y + FireBoy.velocityY <= EdgePointDown)) {
		FireBoy.y += FireBoy.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("火娃(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	input1 = NOINPUT;
	input2 = NOINPUT;
	
}


//计时器
TCHAR str[255];
clock_t Start_time;
clock_t End_time;
int time_1;
int min, second;

//画出时间和地图
void putall()
{
	putimage(0, 0, &temp_game);
	outtextxy(364, -2, str);
}

//游戏界面
void GameMenu()
{
	
	Start_time = clock();
	Init();		//初始化人物
	DrawGame();	//画出游戏界面
	putimage(0, 0, &temp_game);
	
	while (1) {
		//计时器
		End_time = clock();
		time_1 = (int)((End_time - Start_time) / CLOCKS_PER_SEC);
		min = time_1 / 60;
		second = time_1 % 60;
		if (min < 10 && second >= 10) {
			_stprintf_s(str, _T("0%d:%d"), min, second);
		}
		else if (min >= 10 && second < 10)
		{
			_stprintf_s(str, _T("%d:0%d"), min, second);
		}
		else if (min < 10 && second < 10)
		{
			_stprintf_s(str, _T("0%d:0%d"), min, second);
		}
		//_stprintf_s(str, _T("%d:%d"), min, second);		// 高版本 VC 推荐使用 _stprintf_s 函数
		setbkmode(TRANSPARENT);             //字体背景透明
		settextstyle(38, 0, _T("微软雅黑"));
		setcolor(YELLOW);
		cleardevice();
		putall();
		


		GetInput();
		DealInput();
		if (WaterGirl.status == 1 || FireBoy.status == 1) {		//有一个掉入陷阱中游戏失败
			LoseMusic();
			GameOverMenu();
		}
		else
		{
			CloseLoseMusic();
		}
		if (WaterGirl.status == 2 && FireBoy.status == 2) {			//游戏胜利
			WinMusic();
			if (WaterGirl.diamonds == 4 && FireBoy.diamonds == 3) {	//两个人到到达门前且全部宝石收集完毕
				GameWinMenu();
			}
			else
			{
				GameWinMenu2();									//没有获取所有钻石
			}
		}
		else
		{
			CloseWinMusic();
		}
	}
	
}