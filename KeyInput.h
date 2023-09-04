#pragma once
#ifndef __KEYINPUT_H_
#define __KEYINPUT_H_

#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>

 enum GAMEINPUT
{
	NOINPUT = 0x0,
	UPINPUT = 0x1,
	DOWNINPUT = 0x2,
	LEFTINPUT = 0x4,
	RIGHTINPUT = 0x10
};
extern int input1;
extern int input2;

//获取输入
void GetInput();

#endif // !__KEYINPUT_H
