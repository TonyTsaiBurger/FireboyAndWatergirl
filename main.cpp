#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"


#define WIDTH 800
#define HIGHT 600


int main()
{
	initgraph(WIDTH, HIGHT, EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 800x600 像素

	//播放一次
	//mciSendString(L"close  bkmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐
	//mciSendString(L"open .\\fl\\background.mp3 alias bkmusic", NULL, 0, NULL);//重新打开读取音乐文件
	//mciSendString(L"play bkmusic ", NULL, 0, NULL);//播放音乐文件

	//默认打开播放BGM
	//vs多字节集就不要L，.代表的是当前文件位置，alias后面是自定义的别称
	mciSendString(L"open resoure\\background1.mp3 alias bkmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);

	//载入开始菜单页面
	StartMenu();

	
	
	

	//在命令行控制台按任意键退出
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}

//#include <stdio.h>
//#include <graphics.h>
//#include <conio.h>
//#include<time.h>
//clock_t Start_time;
//clock_t End_time;
//int time_1;
//int min, second;
//int main() {
//	initgraph(200, 200, SHOWCONSOLE);//init 初始化  graph 图像窗口  SHOWCONSOLE 显示控制台
//	setbkcolor(RGB(225, 115, 100));//设置背景颜色
//	BeginBatchDraw();	//双缓冲绘图，防止屏闪
//
//	Start_time = clock();
//	while (1) {
//		/*cleardevice();*/
//		End_time = clock();
//		time_1 = (int)((End_time - Start_time) / CLOCKS_PER_SEC);
//		min = time_1 / 60;
//		second = time_1 % 60;
//		settextstyle(60, 0, _T("微软雅黑"));
//		setcolor(YELLOW);//
//		TCHAR str[255];
//		_stprintf_s(str, _T("%0d:%0d"),min,second );		// 高版本 VC 推荐使用 _stprintf_s 函数
//
//		outtextxy(10, 10, str);
//
//
//		EndBatchDraw();//双缓冲绘图
//	}
//	return 0;
//}

