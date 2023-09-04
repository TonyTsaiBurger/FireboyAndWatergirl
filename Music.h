#pragma once
#ifndef __MUSIC_H_
#define __MUSIC_H_

#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"

void CloseMusic();
void BGMStart();
void BGMStop();
void GetDiamonds();
void DieMusic();
void LiftMusic();


void LoseMusic();		//失败音效
void CloseLoseMusic();	//关闭失败音效
void WinMusic();		//胜利音效
void CloseWinMusic();	//关闭胜利音效

#endif // !__MUSIC_H_
