#pragma once
#ifndef __GAMEMENU_H
#define __GAMEMEUN_H

#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include "DrawAlpha.h"
#include "easygame.h"
#pragma comment(lib,"winmm.lib")


void DrawMainMenu();//构建主菜单界面
void StartMenu();//载入开始菜单页面
void TipMenu();//载入提示菜单
void SetMenu();//载入设置菜单

void GameOverMenu();//游戏结束菜单
void GameWinMenu();//游戏胜利界面（获取所有宝石）
void GameWinMenu2();//游戏胜利界面（没有获取所有宝石）


#endif // !__GAMEMENU_H