#pragma once
#ifndef __DRAWALL_H_
#define __DRAWALL_H_

#include "DrawAlpha.h"
#include "Music.h"


typedef struct character {
	int x, y;						//角色坐标
	int width, height;				//角色宽度和高度
	int velocityX, velocityY;		//角色在X和Y方向上的速度
	int status;						//角色状态，可以用枚举类型表示  0表示或者 1表示死亡
	int diamonds;					//收集的钻石数量
	int speed;						//角色移动速度
	int boxcontact;					//与箱子的联系
	IMAGE image;					//角色图像
} Character;

//黄色或紫色机关
typedef struct yellowprop {
	int stauts = 1;
}Prop;

extern Character FireBoy, WaterGirl;
extern Prop purplebutton;

//初始化位置
void Init();
//初始化位置
void DrawBackGame();
//默认不动的状态
void DrawGame();
//火娃左走
void DrawFireboyLeft();
//冰娃左走
void DrawWatergirlLeft();
//火娃右走
void DrawFireboyRight();
//冰娃右走
void DrawWatergirlRight();



#endif // !__DRAWALL_H_
