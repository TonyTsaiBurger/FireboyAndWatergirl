#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"

void CloseMusic()
{
	mciSendString(L"close  diamondsmusic", NULL, 0, NULL);//先关闭之前播放的本音乐
	mciSendString(L"close  diemusic", NULL, 0, NULL);//先关闭之前播放的本音乐
	mciSendString(L"close  liftmusic", NULL, 0, NULL);//先关闭之前播放的本音乐
}
	
//背景音乐开启
void BGMStart() 
{
	mciSendString(L"open resoure\\background1.mp3 alias bkmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
}
//关闭背景音乐
void BGMStop()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐
}
//获取宝石音效
void GetDiamonds()
{
	
	mciSendString(L"open resoure\\GetDiamonds.mp3 alias diamondsmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play diamondsmusic", NULL, 0, NULL);
}
//死亡音效
void DieMusic()
{
	mciSendString(L"open resoure\\Die.mp3 alias diemusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play diemusic", NULL, 0, NULL);	
}
//电梯音效
void LiftMusic()
{
	mciSendString(L"open resoure\\Lift.mp3 alias liftmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play liftmusic", NULL, 0, NULL);
}

//失败音效
void LoseMusic()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐
	mciSendString(L"open resoure\\lose.mp3 alias losemusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play losemusic", NULL, 0, NULL);
}
//关闭失败音效
void CloseLoseMusic()
{
	mciSendString(L"close  losemusic", NULL, 0, NULL);//先关闭之前播放的本音乐
}

//胜利音效
void WinMusic()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐
	mciSendString(L"open resoure\\win.mp3 alias winmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString(L"play winmusic", NULL, 0, NULL);
}
//关闭胜利音效
void CloseWinMusic()
{
	mciSendString(L"close  winmusic", NULL, 0, NULL);//先关闭之前播放的本音乐
}

