#pragma once
#ifndef __JUDGE_H_
#define __JUDGE_H_

#include "DrawAll.h"
#include "KeyInput.h"

//火娃
void FirstJudge();			//第一层碰撞检测
void SecondJudge();			//第二层碰撞检测
void ThirdJudge();			//第三层碰撞检测
void FourthJudge();			//第四层碰撞检测
void FifthJudge();			//第五层碰撞检测

//冰娃
void FirstJudge2();			//第一层碰撞检测
void SecondJudge2();		//第二层碰撞检测
void ThirdJudge2();			//第三层碰撞检测
void FourthJudge2();		//第四层碰撞检测
void FifthJudge2();			//第五层碰撞检测


#endif // !__JUDGE_H_
