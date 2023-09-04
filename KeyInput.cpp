#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>

//按键输入的枚举列表
enum GAMEINPUT
{
	NOINPUT = 0x0,
	UPINPUT = 0x1,
	DOWNINPUT = 0x2,
	LEFTINPUT = 0x4,
	RIGHTINPUT = 0x10
};
int input1 = NOINPUT;
int input2 = NOINPUT;

//获取输入
void GetInput()
{
	if (GetAsyncKeyState('W') & 0x8000) {
		input1 |= UPINPUT;
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		input1 |= LEFTINPUT;
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		input1 |= RIGHTINPUT;
	}
	/*if (GetAsyncKeyState('S') & 0x8000) {
		input1 |= DOWNINPUT;
	}*/

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		input2 |= UPINPUT;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		input2 |= LEFTINPUT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		input2 |= RIGHTINPUT;
	}
	/*if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		input2 |= DOWNINPUT;
	}*/
}