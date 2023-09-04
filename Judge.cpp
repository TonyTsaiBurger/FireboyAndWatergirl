#include "DrawAll.h"
#include "KeyInput.h"
#include "easygame.h"

//火娃动作
//火娃跳跃（小空间）
void FireBoyMinJump()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		DrawGame();
		putall();
	}
}
//火娃右跳跃（小空间）
void FireBoyMinJumpAndRightMove()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		FireBoy.x += 3;
		DrawFireboyRight();
		putall();
	}
}
//火娃右跳跃（小空间）
void FireBoyMinJumpAndLeftMove()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		FireBoy.x -= 3;
		DrawFireboyLeft();
		putall();
	}
}

//火娃跳跃不掉落（大空间）
void FireBoyBigJump()
{
	FireBoy.y -= 80;
	DrawGame();
	putall();
}
//火娃跳跃掉落（大空间）
void FireBoyBigDown()
{
	for (int i = 0; i < 16; i++) {
		FireBoy.y += 5;
		DrawGame();
		putall();
	}
}

//火娃中跳跃
void FireBoyMidJump()
{
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		DrawGame();
		putall();
	}
}
//火娃向右跳跃
void FireBoyMidJumpAndRightMove()
{	
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		FireBoy.x += 7;
		DrawFireboyRight();
		putall();
	}
}
//火娃向左跳跃
void FireBoyMidJumpAndLeftMove()
{
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		FireBoy.x -= 7;
		DrawFireboyLeft();
		putall();
	}
}


//冰娃动作
//冰娃跳跃（小空间）
void WaterGirlMinJump()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		DrawGame();
		putall();
	}
}
//冰娃右跳跃（小空间）
void WaterGirlMinJumpAndRightMove()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		WaterGirl.x += 3;
		DrawWatergirlRight();
		putall();
	}
}
//冰娃右跳跃（小空间）
void WaterGirlMinJumpAndLeftMove()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		WaterGirl.x -= 3;
		DrawWatergirlLeft();
		putall();
	}
}

//冰娃跳跃不掉落（大空间）
void WaterGirlBigJump()
{
	WaterGirl.y -= 80;
	DrawGame();
	putall();
}
//冰娃跳跃掉落（大空间）
void WaterGirlBigDown()
{
	for (int i = 0; i < 16; i++) {
		WaterGirl.y += 5;
		DrawGame();
		putall();
	}
}

//冰娃中跳跃
void WaterGirlMidJump()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		DrawGame();
		putall();
	}
}
//冰娃向右跳跃
void WaterGirlMidJumpAndRightMove()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		WaterGirl.x += 7;
		DrawWatergirlRight();
		putall();
	}
}
//冰娃向左跳跃
void WaterGirlMidJumpAndLeftMove()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		WaterGirl.x -= 7;
		DrawWatergirlLeft();
		putall();
	}
}





//每层的检测
//火娃
//第一层碰撞检测
void FirstJudge()
{
	//在第一层左边的范围		隔板头到隔板末
	if ((FireBoy.x >= 0 && FireBoy.x <= 236) && (FireBoy.y >= 484 && FireBoy.y <= 508)) {
		if (input2 & UPINPUT) {
			FireBoyMinJump();
			if (input2 & RIGHTINPUT) {
				FireBoyMinJumpAndRightMove();
			}
			if (input2 & LEFTINPUT) {
				FireBoyMinJumpAndLeftMove();
			}
		}
	}
	if ((FireBoy.x > 235 && FireBoy.x <= 282) && (FireBoy.y == 508)) {  //小一层隔板末到火水前的前
		if (input2 & UPINPUT) {
			FireBoyBigJump();
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 11; i++) {
					FireBoy.x -= 3;
					FireBoy.y = 426;
					DrawFireboyLeft();
					putall();
				}
			}
			else
			{
				//282  //不在范围内则掉落
				FireBoyBigDown();
			}
		}
	}
	if ((FireBoy.x > 282 && FireBoy.x <= 318) && (FireBoy.y == 508)) {  //小一层火水前的前到火水前
		if (input2 & UPINPUT) {
			FireBoyMidJump();
		}
	}
	if ((FireBoy.x >= 232 && FireBoy.x <= 234) && (FireBoy.y == 426))	//小二层隔板末，边缘自动掉落
	{
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 4;
			DrawGame();
			putall();
		}
		FireBoy.y += 2;
		DrawGame();
		putall();
	}
	if ((FireBoy.x >= 0 && FireBoy.x < 198) && (FireBoy.y == 426))		//小二层隔板头到隔板末
	{
		if (input2 & UPINPUT) {
			FireBoyMinJump();
		}
	}
	//冰水和火水的判定
	if ((FireBoy.x > 318 && FireBoy.x <= 440) && FireBoy.y >= 508) { //火水前到火水后
		if ((FireBoy.x > 318 && FireBoy.x < 420) && FireBoy.y >= 508) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x > 318 && FireBoy.x < 340) {
			FireBoy.y = 508;
		}
		if (FireBoy.x >= 340 && FireBoy.x < 416) {  //在火水中
			FireBoy.y = 516;
		}
		if (FireBoy.x >= 416 && FireBoy.x <= 422) {  //快出火水
			FireBoy.y = 508;
		}
		if (FireBoy.x >= 372 && FireBoy.x <= 402) {  //吃到宝石
			GetDiamonds();
			FireBoy.diamonds = 1;
		}
		else if (FireBoy.x >= 402 && FireBoy.x <= 412)
		{
			CloseMusic();
		}
	}
	if ((FireBoy.x > 440 && FireBoy.x <= 598) && FireBoy.y >= 508) {  //冰水前到冰水后
		if ((FireBoy.x > 460 && FireBoy.x < 578) && FireBoy.y >= 508) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x > 440 && FireBoy.x < 492) {
			FireBoy.y = 508;
		}
		if (FireBoy.x > 492 && FireBoy.x <= 570) {  //在冰水中
			DieMusic();
			FireBoy.y = 516;
			FireBoy.status = 1;
		}
		else if (FireBoy.x >= 570 && FireBoy.x <= 580)
		{
			CloseMusic();
		}
		if (FireBoy.x > 570 && FireBoy.x <= 598) {  //快出冰水
			FireBoy.y = 508;
		}
	}
	if ((FireBoy.x > 598 && FireBoy.x <= 720) && FireBoy.y == 508) {  //冰水后  准备跳跃
		if (FireBoy.x == 664 && FireBoy.y == 508) {  //碰到第一层墙壁
			FireBoy.x = 664;
		}
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				/*FireBoy.y -= 60;*/
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 12; i++) {
					FireBoy.y -= 5;
					FireBoy.x += 3;
					DrawFireboyRight();
					putall();
				}
			}
			if (input2 & LEFTINPUT) {
				FireBoyMidJumpAndLeftMove();
			}
		}
	}
	if (FireBoy.x <= 690 && FireBoy.y == 448) {		//滑落墙壁1
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 5;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
	}
	if ((FireBoy.x > 690 && FireBoy.x <= 720) && FireBoy.y == 448) {		//跳跃到第二层
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 12; i++) {  //632,388   448
					FireBoy.y -= 5;
					FireBoy.x -= 6;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	if (FireBoy.x >= 630 && FireBoy.y == 388) {		//滑落墙壁2
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 5;
			FireBoy.x += 4;
			DrawFireboyRight();
			putall();
		}
	}
}


//第二层碰撞检测
void SecondJudge()
{
	//毒水的判定
	if ((FireBoy.x >= 354 && FireBoy.x < 630) && (FireBoy.y >= 388 && FireBoy.y <= 396)) { //毒水前到斜角前
		if ((FireBoy.x >= 354 && FireBoy.x < 600) && (FireBoy.y >= 388 && FireBoy.y <= 396)) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 354 && FireBoy.x <= 460) {	//毒水后
			FireBoy.y = 388;
		}
		if (FireBoy.x > 460 && FireBoy.x <= 546) {  //在毒水中
			FireBoy.y = 396;
			FireBoy.status = 1;
			DieMusic();
		}
		else if (FireBoy.x <= 460 && FireBoy.y >= 450)
		{
			CloseMusic();
		}
		if (FireBoy.x > 546 && FireBoy.x < 630) {  //毒水前
			FireBoy.y = 388;
		}
	}
	//第二层斜坡处上升与滑落
	if ((FireBoy.x <= 354 && FireBoy.x >= 350) && FireBoy.y == 388) {		//第二层斜坡处上升
		for (int i = 0; i < 20; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 346;
		DrawFireboyLeft();
		putall();
	}
	if (FireBoy.x > 314 && FireBoy.y == 346) {		//第二层斜坡处滑落
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 388;
		DrawFireboyRight();
		putall();
	}
	//黄色机关处
	if ((FireBoy.x >= 86 && FireBoy.x <= 314) && FireBoy.y == 346) {    //开关前后
		if (FireBoy.x >= 110 && FireBoy.x <= 300) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		//if ((FireBoy.x >= 150 && FireBoy.x <= 166) && FireBoy.y == 346) { //踩到机关播放音乐
		//	LiftMusic();
		//}
		//else
		//{
		//	CloseMusic();			//否则关闭音乐
		//}
		if (FireBoy.x >= 86 && FireBoy.x <= 96) {					//跳上升降梯子
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					for (int i = 0; i < 12; i++) {
						FireBoy.y -= 3;
						FireBoy.x -= 2;
						DrawFireboyLeft();
						putall();
					}
				}
			}
		}
	}
	if (FireBoy.x >= 70 && FireBoy.y == 310) {			//升降梯边缘滑落
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 3;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
	}
	if ((FireBoy.x >= 0 && FireBoy.x <= 55) && FireBoy.y == 310) {			//升降梯跳到第三层
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {		//从y310 到  y246
				for (int i = 0; i < 16; i++) {
					FireBoy.y -= 4;
					FireBoy.x += 2;
					DrawFireboyRight();
					putall();
				}
				FireBoy.y = 246;
				DrawFireboyRight();
				putall();
			}
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 15; i++) {

					FireBoy.x -= 2;
					if (FireBoy.x <= 0) {
						FireBoy.x = 0;
					}
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	if (FireBoy.x <= 68 && FireBoy.y == 246) {			//第三层滑落
		for (int i = 0; i < 16; i++) {
			FireBoy.y += 4;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
	}
}

//第三层碰撞检测
void ThirdJudge()
{
	//第三层斜坡前
	if ((FireBoy.x > 68 && FireBoy.x <= 374) && FireBoy.y == 246) {
		if (FireBoy.x >= 88 && FireBoy.x <= 374) {
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 96 && FireBoy.x <= 126) {  //吃到宝石
			FireBoy.diamonds = 2;
			GetDiamonds();
		}
		else if (FireBoy.x >= 126 && FireBoy.x <= 136)
		{
			CloseMusic();
		}
		//if (FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) {		//紫色按钮
		//	drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//下降到692,270，上升到692,212
		//}
		//else
		//{
		//	drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//底层按钮
		//	drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//下降到692,270，上升到692,212
		//}
	}

	//第三层斜坡处滑落与上升
	if (FireBoy.x > 374 && FireBoy.y == 246) {		//第三层斜坡处滑落
		for (int i = 0; i < 10; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 266;
		DrawFireboyRight();
		putall();
	}
	if (FireBoy.x < 394 && FireBoy.y == 266) {		//第三层斜坡处上升
		for (int i = 0; i < 10; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 246;
		DrawFireboyLeft();
		putall();
	}


	//第三层斜坡处到升降梯前的前，空间较大位置
	if ((FireBoy.x >= 394 && FireBoy.x <= 550) && FireBoy.y == 266) {
		if (FireBoy.x >= 404 && FireBoy.x <= 550) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
	}

	//较大空间后位置到升降梯前
	if ((FireBoy.x >= 550 && FireBoy.x <= 648) && FireBoy.y == 266) {
		if (FireBoy.x >= 570 && FireBoy.x <= 600) {		//不能跳上电梯的位置
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 620 && FireBoy.x < 638) {		//能跳上电梯的位置
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					for (int i = 0; i < 16; i++) {
						FireBoy.y -= 1;
						FireBoy.x += 2;
						DrawFireboyRight();
						putall();
					}
					FireBoy.y = 250;
					DrawFireboyRight();
					putall();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
	}
	//在电梯滑落
	if (FireBoy.x <= 656 && FireBoy.y == 250) {
		for (int i = 0; i < 16; i++) {
			FireBoy.y += 1;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 266;
		DrawFireboyLeft();
		putall();
	}
	//在电梯上的操作
	if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 250) {
		if (FireBoy.x > 670 && FireBoy.x <= 720) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
					if (FireBoy.x >= 720) {
						FireBoy.x = 720;
					}
					DrawFireboyRight();
					putall();

				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
	}
	//电梯控制
	if (purplebutton.stauts == 2) {  //当有人离开按钮
		if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 250) {
			FireBoy.y = 192;
			DrawGame();
			putall();
		}
	}
	else if (purplebutton.stauts == 1)
	{
		if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 192) {
			FireBoy.y = 250;
			DrawGame();
			putall();
		}
	}

	//第三层电梯升到最高准备跳跃
	if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 192) {			//y192  到y166   
		if (FireBoy.x > 670 && FireBoy.x <= 720) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
					if (FireBoy.x >= 720) {
						FireBoy.x = 720;
						DrawFireboyRight();
						putall();
					}
				}
				if (input2 & LEFTINPUT) {
					FireBoy.y -= 40;
					DrawGame();
					putall();
					for (int i = 0; i < 7; i++) {
						FireBoy.y += 2;
						FireBoy.x -= 8;
						DrawFireboyLeft();
						putall();
					}
					FireBoy.y = 166;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	//第四层右边掉落检测
	if (FireBoy.x >= 654 && FireBoy.y == 166) {
		for (int i = 0; i < 13; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 192;
		DrawFireboyRight();
		putall();
	}
}

//第四层碰撞检测
void FourthJudge()
{
	//第四层滑坡前操作
	if ((FireBoy.x > 536 && FireBoy.x < 654) && FireBoy.y == 166) {
		if (FireBoy.x > 536 && FireBoy.x < 610) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
	}

	//第四层上滑坡
	if ((FireBoy.x <= 536 && FireBoy.x >= 530) && FireBoy.y == 166) {  //y166 到y126
		for (int i = 0; i < 20; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 126;
		DrawFireboyLeft();
		putall();
	}
	//第四层下滑坡
	if ((FireBoy.x >= 490 && FireBoy.x <= 496) && FireBoy.y == 126) {  //y166 到y126
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 166;
		DrawFireboyRight();
		putall();
	}

	//第四层上完滑坡后到前面掉落处
	if ((FireBoy.x > 352 && FireBoy.x <= 470) && FireBoy.y == 126) {
		if (FireBoy.x - 35 < 400) {
			FireBoy.boxcontact = 1;
			drawAlpha(&temp_game, FireBoy.x - 35, 128, &imag_box);
			putall();
		}
	}
	//第四层推箱子掉落
	if (FireBoy.x <= 352 && FireBoy.y == 126) {				//y126 到y166
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			DrawFireboyLeft();
			drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
			putall();
		}
		FireBoy.y = 166;
		DrawFireboyLeft();
		drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
		putall();
	}
	//推箱子到最左边过程
	if (FireBoy.x >= 145 && FireBoy.x <= 352 && FireBoy.y == 166) {				//y126 到y166
		if (FireBoy.boxcontact == 1) {
			drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
			putall();
		}
	}
	if (FireBoy.x <= 145 && FireBoy.y == 166) {			//推到最左了
		drawAlpha(&temp_game, 110, 168, &imag_box);
		putall();
		FireBoy.boxcontact = 2;
		DrawFireboyLeft();
		putall();
	}

	//第四层跳到箱子上
	if ((FireBoy.x >= 143 && FireBoy.x <= 160) && FireBoy.y == 166) {
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				FireBoy.y -= 60;
				DrawGame();
				putall();
				for (int i = 0; i < 15; i++) {
					FireBoy.y += 4;
					FireBoy.x += 7;
					if (FireBoy.x >= 184) {
						FireBoy.x = 184;
					}
					DrawFireboyRight();
					putall();
				}
			}
			if (input2 & LEFTINPUT) {									//y166 到y132
				FireBoy.y -= 60;
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 13; i++) {
					FireBoy.y += 2;
					FireBoy.x -= 2;
					if (FireBoy.x <= 100) {
						FireBoy.x = 100;
					}
					DrawFireboyLeft();
					putall();
				}
				FireBoy.y = 132;
				DrawFireboyLeft();
				putall();
			}
		}
	}
	//从箱子上掉落
	if (FireBoy.x >= 128 && FireBoy.y == 132) {
		for (int i = 0; i < 17; i++) {
			FireBoy.y += 2;
			FireBoy.x += 1;
			DrawFireboyRight();
			putall();
		}
	}
	//从箱子上跳跃到下一层
	if ((FireBoy.x >= 98 && FireBoy.x < 128) && FireBoy.y == 132) {
		if (FireBoy.x >= 98 && FireBoy.x < 110) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoy.y -= 60;
					for (int i = 0; i < 15; i++) {
						FireBoy.y += 4;
						FireBoy.x += 7;
						if (FireBoy.x >= 184) {
							FireBoy.x = 184;
						}
						FireBoy.y = 166;
						DrawFireboyRight();
						putall();
					}
				}
				if (input2 & LEFTINPUT) {									//y132 到y86
					FireBoy.y -= 60;
					for (int i = 0; i < 7; i++) {
						FireBoy.y += 2;
						FireBoy.x -= 2;
						DrawFireboyLeft();
						putall();
					}
					FireBoy.y = 86;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	//从第五层断层掉落
	if (FireBoy.x >= 96 && FireBoy.y == 86) {					//y86 到y132
		for (int i = 0; i < 23; i++) {
			FireBoy.y += 2;
			FireBoy.x += 1;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 132;
		DrawFireboyRight();
		putall();
	}
	//在第五层断层的操作
	if ((FireBoy.x < 96 && FireBoy.x >= 0) && FireBoy.y == 86) {
		//在冰娃的操作里冰娃吃钻石
		if (FireBoy.x >= 0 && FireBoy.x < 70) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 70 && FireBoy.x < 96) {
			if (input2 & UPINPUT) {
				if (input2 & RIGHTINPUT) {				//y86 到 y26
					/*FireBoy.y -= 80;*/
					for (int i = 0; i < 20; i++) {
						FireBoy.y -= 4;
						DrawFireboyRight();
						putall();
					}
					for (int i = 0; i < 20; i++) {
						FireBoy.y += 1;
						FireBoy.x += 5;
						DrawFireboyRight();
						putall();
					}
					FireBoy.y = 26;
					DrawFireboyRight();
					putall();
				}
			}
		}
	}

}

//第五层碰撞检测
void FifthJudge()
{	//操作控制
	if ((FireBoy.x > 272 && FireBoy.x <= 720) && FireBoy.y == 66) {
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				FireBoyMinJumpAndRightMove();
			}
			if (input2 & LEFTINPUT) {
				FireBoyMinJumpAndLeftMove();
			}
		}
	}
	//火娃吃到宝石
	if ((FireBoy.x >= 180 && FireBoy.x <= 210) && FireBoy.y == 26) {
		GetDiamonds();
		FireBoy.diamonds = 3;
	}
	else if ((FireBoy.x > 210 && FireBoy.x <= 220) && FireBoy.y == 26)
	{
		CloseMusic();
	}
	//第五层左滑落
	if ((FireBoy.x <= 164 && FireBoy.x >= 158) && FireBoy.y == 26) {
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 3;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
	}
	//第五层右滑落1
	if ((FireBoy.x >= 214 && FireBoy.x <= 220) && FireBoy.y == 26) {			//y26 到 y44       x214  x236
		for (int i = 0; i < 9; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyRight();
		putall();
	}
	//第五层右上升1
	if ((FireBoy.x >= 230 && FireBoy.x <= 236) && FireBoy.y == 44) {			//y26 到 y44       x214  x236
		for (int i = 0; i < 9; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 26;
		DrawFireboyLeft();
		putall();
	}
	//第五层右滑落2
	if ((FireBoy.x >= 254 && FireBoy.x <= 260) && FireBoy.y == 44) {			//y44 到 y66       x287  x254
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyRight();
		putall();
	}
	//第五层右上升2
	if ((FireBoy.x <= 272 && FireBoy.x >= 266) && FireBoy.y == 66) {			//y44 到 y66       x272  x250
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyLeft();
		putall();
	}

	//第五层右上升3
	if ((FireBoy.x >= 490 && FireBoy.x <= 496) && FireBoy.y == 66) {		//y66 到 y44       x490  x512
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyRight();
		putall();
	}
	//第五层右滑落3
	if ((FireBoy.x <= 512 && FireBoy.x >= 508) && FireBoy.y == 44) {		//y44 到 y66       x490  x512
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyLeft();
		putall();
	}
	//第五层右滑落4
	if ((FireBoy.x >= 574 && FireBoy.x <= 580) && FireBoy.y == 44) {		//y44 到 y66       x574  x592
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyRight();
		putall();
	}
	//第五层右上升4
	if ((FireBoy.x <= 592 && FireBoy.x >= 586) && FireBoy.y == 66) {		//y66 到 y44       x574  x592
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyLeft();
		putall();
	}
}



















//冰娃
//第一层碰撞检测
void FirstJudge2()
{
	//在第一层左边的范围		隔板头到隔板末
	if ((WaterGirl.x >= 0 && WaterGirl.x <= 236) && (WaterGirl.y >= 484 && WaterGirl.y <= 508)) {
		if (input1 & UPINPUT) {
			WaterGirlMinJump();
			if (input1 & RIGHTINPUT) {
				WaterGirlMinJumpAndRightMove();
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMinJumpAndLeftMove();
			}
		}
	}
	if ((WaterGirl.x > 235 && WaterGirl.x <= 282) && (WaterGirl.y == 508)) {  //小一层隔板末到火水前的前
		if (input1 & UPINPUT) {
			WaterGirlBigJump();
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 11; i++) {
					WaterGirl.x -= 3;
					WaterGirl.y = 426;
					DrawWatergirlLeft();
					putall();
				}
			}
			else
			{
				//282  //不在范围内则掉落
				WaterGirlBigDown();
			}
		}
	}
	if ((WaterGirl.x > 282 && WaterGirl.x <= 318) && (WaterGirl.y == 508)) {  //小一层火水前的前到火水前
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
		}
	}
	if ((WaterGirl.x >= 232 && WaterGirl.x <= 234) && (WaterGirl.y == 426))	//小二层隔板末，边缘自动掉落
	{
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 4;
			DrawGame();
			putall();
		}
		WaterGirl.y += 2;
		DrawGame();
		putall();
	}
	if ((WaterGirl.x >= 0 && WaterGirl.x < 198) && (WaterGirl.y == 426))		//小二层隔板头到隔板末
	{
		if (input1 & UPINPUT) {
			WaterGirlMinJump();
		}
	}
	//冰水和火水的判定
	if ((WaterGirl.x > 318 && WaterGirl.x <= 440) && WaterGirl.y >= 508) { //火水前到火水后
		if ((WaterGirl.x > 318 && WaterGirl.x < 420) && WaterGirl.y >= 508) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x > 318 && WaterGirl.x < 340) {
			WaterGirl.y = 508;
		}
		if (WaterGirl.x >= 340 && WaterGirl.x < 416) {  //在火水中
			WaterGirl.y = 516;
			DieMusic();
			WaterGirl.status = 1;
		}
		else if (WaterGirl.x >= 416 && WaterGirl.x <= 426)
		{
			CloseMusic();
		}
		if (WaterGirl.x >= 416 && WaterGirl.x <= 422) {  //快出火水
			WaterGirl.y = 508;
		}

	}
	if ((WaterGirl.x > 440 && WaterGirl.x <= 598) && WaterGirl.y >= 508) {  //冰水前到冰水后
		if ((WaterGirl.x > 460 && WaterGirl.x < 578) && WaterGirl.y >= 508) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x > 440 && WaterGirl.x < 492) {
			WaterGirl.y = 508;
		}
		if (WaterGirl.x > 492 && WaterGirl.x <= 570) {  //在冰水中
			WaterGirl.y = 516;
		}
		if (WaterGirl.x >= 532 && WaterGirl.x <= 562) {  //吃到宝石
			GetDiamonds();
			WaterGirl.diamonds = 1;
		}
		else if (WaterGirl.x >= 562 && WaterGirl.x <= 572)
		{
			CloseMusic();
		}
		if (WaterGirl.x > 570 && WaterGirl.x <= 598) {  //快出冰水
			WaterGirl.y = 508;
		}
	}
	if ((WaterGirl.x > 598 && WaterGirl.x <= 720) && WaterGirl.y == 508) {  //冰水后  准备跳跃
		if (WaterGirl.x == 664 && WaterGirl.y == 508) {  //碰到第一层墙壁
			WaterGirl.x = 664;
		}
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				for (int i = 0; i < 12; i++) {
					WaterGirl.y -= 5;
					WaterGirl.x += 3;
					DrawWatergirlRight();
					putall();
				}
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMidJumpAndLeftMove();
			}
		}
	}
	if (WaterGirl.x <= 690 && WaterGirl.y == 448) {		//滑落墙壁1
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 5;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
	}
	if ((WaterGirl.x > 690 && WaterGirl.x <= 720) && WaterGirl.y == 448) {		//跳跃到第二层
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 12; i++) {  //632,388   448
					WaterGirl.y -= 5;
					WaterGirl.x -= 6;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	if (WaterGirl.x >= 630 && WaterGirl.y == 388) {		//滑落墙壁2
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 5;
			WaterGirl.x += 4;
			DrawWatergirlRight();
			putall();
		}
	}
}

//第二层碰撞检测
void SecondJudge2()
{
	//毒水的判定
	if ((WaterGirl.x >= 354 && WaterGirl.x < 630) && (WaterGirl.y >= 388 && WaterGirl.y <= 396)) { //毒水前到斜角前
		if ((WaterGirl.x >= 354 && WaterGirl.x < 600) && (WaterGirl.y >= 388 && WaterGirl.y <= 396)) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 354 && WaterGirl.x <= 460) {	//毒水后
			WaterGirl.y = 388;
		}
		if (WaterGirl.x > 460 && WaterGirl.x <= 546) {  //在毒水中
			WaterGirl.y = 396;
			WaterGirl.status = 1;
			DieMusic();
		}
		else if (WaterGirl.x <= 460 && WaterGirl.x >= 450)
		{
			CloseMusic();
		}
		if (WaterGirl.x > 546 && WaterGirl.x < 630) {  //毒水前
			WaterGirl.y = 388;
		}
	}
	//第二层斜坡处上升与滑落
	if ((WaterGirl.x <= 354 && WaterGirl.x >= 350) && WaterGirl.y == 388) {		//第二层斜坡处上升
		for (int i = 0; i < 20; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 346;
		DrawWatergirlLeft();
		putall();
	}
	if (WaterGirl.x > 314 && WaterGirl.y == 346) {		//第二层斜坡处滑落
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 388;
		DrawWatergirlRight();
		putall();
	}
	//黄色机关处
	if ((WaterGirl.x >= 86 && WaterGirl.x <= 314) && WaterGirl.y == 346) {    //开关前后
		if (WaterGirl.x >= 110 && WaterGirl.x <= 300) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		//if ((WaterGirl.x >= 150 && WaterGirl.x <= 166) && WaterGirl.y == 346) { //踩到机关播放音乐
		//	LiftMusic();
		//}
		//else
		//{
		//	CloseMusic();			//否则关闭音乐
		//}
		if (WaterGirl.x >= 86 && WaterGirl.x <= 96) {					//跳上升降梯子
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					for (int i = 0; i < 12; i++) {
						WaterGirl.y -= 3;
						WaterGirl.x -= 2;
						DrawWatergirlLeft();
						putall();
					}
				}
			}
		}
	}
	if (WaterGirl.x >= 70 && WaterGirl.y == 310) {			//升降梯边缘滑落
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 3;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
	}
	if ((WaterGirl.x >= 0 && WaterGirl.x <= 55) && WaterGirl.y == 310) {			//升降梯跳到第三层
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {		//从y310 到  y246
				for (int i = 0; i < 16; i++) {
					WaterGirl.y -= 4;
					WaterGirl.x += 2;
					DrawWatergirlRight();
					putall();
				}
				WaterGirl.y = 246;
				DrawWatergirlRight();
				putall();
			}
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 15; i++) {

					WaterGirl.x -= 2;
					if (WaterGirl.x <= 0) {
						WaterGirl.x = 0;
					}
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	if (WaterGirl.x <= 68 && WaterGirl.y == 246) {			//第三层滑落
		for (int i = 0; i < 16; i++) {
			WaterGirl.y += 4;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
	}
}

//第三层碰撞检测
void ThirdJudge2()
{
	//第三层斜坡前
	if ((WaterGirl.x > 68 && WaterGirl.x <= 374) && WaterGirl.y == 246) {
		if (WaterGirl.x >= 88 && WaterGirl.x <= 374) {
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		//if (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246) {		//紫色按钮
		//	drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//下降到692,270，上升到692,212
		//}
		//else
		//{
		//	drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//底层按钮
		//	drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//下降到692,270，上升到692,212
		//}
	}


	//第三层斜坡处滑落与上升
	if (WaterGirl.x > 374 && WaterGirl.y == 246) {		//第三层斜坡处滑落
		for (int i = 0; i < 10; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 266;
		DrawWatergirlRight();
		putall();
	}
	if (WaterGirl.x < 394 && WaterGirl.y == 266) {		//第三层斜坡处上升
		for (int i = 0; i < 10; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 246;
		DrawWatergirlLeft();
		putall();
	}


	//第三层斜坡处到升降梯前的前，空间较大位置
	if ((WaterGirl.x >= 394 && WaterGirl.x <= 550) && WaterGirl.y == 266) {
		if (WaterGirl.x >= 404 && WaterGirl.x <= 550) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 424 && WaterGirl.x <= 454) {  //吃到宝石
			WaterGirl.diamonds = 2;
			GetDiamonds();
		}
		else if (WaterGirl.x >= 454 && WaterGirl.x <= 464)
		{
			CloseMusic();
		}
	}

	//较大空间后位置到升降梯前
	if ((WaterGirl.x >= 550 && WaterGirl.x <= 648) && WaterGirl.y == 266) {
		if (WaterGirl.x >= 570 && WaterGirl.x <= 600) {		//不能跳上电梯的位置
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 620 && WaterGirl.x < 638) {		//能跳上电梯的位置
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					for (int i = 0; i < 16; i++) {
						WaterGirl.y -= 1;
						WaterGirl.x += 2;
						DrawWatergirlRight();
						putall();
					}
					WaterGirl.y = 250;
					DrawWatergirlRight();
					putall();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
	}
	//在电梯滑落
	if (WaterGirl.x <= 656 && WaterGirl.y == 250) {
		for (int i = 0; i < 16; i++) {
			WaterGirl.y += 1;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 266;
		DrawWatergirlLeft();
		putall();
	}
	//在电梯上的操作
	if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 250) {
		if (WaterGirl.x > 670 && WaterGirl.x <= 720) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
					if (WaterGirl.x >= 720) {
						WaterGirl.x = 720;
					}
					DrawWatergirlRight();
					putall();

				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
	}
	//电梯控制
	if (purplebutton.stauts == 2) {  //当有人离开按钮
		if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 250) {
			WaterGirl.y = 192;
			DrawGame();
			putall();
		}
	}
	else if (purplebutton.stauts == 1)
	{
		if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 192) {
			WaterGirl.y = 250;
			DrawGame();
			putall();
		}
	}

	//第三层电梯升到最高准备跳跃
	if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 192) {			//y192  到y166   
		if (WaterGirl.x > 670 && WaterGirl.x <= 720) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
					if (WaterGirl.x >= 720) {
						WaterGirl.x = 720;
						DrawWatergirlRight();
						putall();
					}
				}
				if (input1 & LEFTINPUT) {
					WaterGirl.y -= 40;
					DrawGame();
					putall();
					for (int i = 0; i < 7; i++) {
						WaterGirl.y += 2;
						WaterGirl.x -= 8;
						DrawWatergirlLeft();
						putall();
					}
					WaterGirl.y = 166;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	//第四层右边掉落检测
	if (WaterGirl.x >= 654 && WaterGirl.y == 166) {
		for (int i = 0; i < 13; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 192;
		DrawWatergirlRight();
		putall();
	}
}

//第四层碰撞检测
void FourthJudge2()
{
	//第四层滑坡前操作
	if ((WaterGirl.x > 536 && WaterGirl.x < 654) && WaterGirl.y == 166) {
		if (WaterGirl.x > 536 && WaterGirl.x < 610) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
	}

	//第四层上滑坡
	if ((WaterGirl.x <= 536 && WaterGirl.x >= 530) && WaterGirl.y == 166) {  //y166 到y126
		for (int i = 0; i < 20; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 126;
		DrawWatergirlLeft();
		putall();
	}
	//第四层下滑坡
	if ((WaterGirl.x >= 490 && WaterGirl.x <= 496) && WaterGirl.y == 126) {  //y166 到y126
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 166;
		DrawWatergirlRight();
		putall();
	}

	//第四层上完滑坡后到前面掉落处
	if ((WaterGirl.x > 352 && WaterGirl.x <= 470) && WaterGirl.y == 126) {
		if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
			if (WaterGirl.x - 35 < 400) {
				WaterGirl.boxcontact = 1;
				drawAlpha(&temp_game, WaterGirl.x - 35, 128, &imag_box);
				putall();
			}
		}
	}
	//第四层推箱子掉落
	if (WaterGirl.x <= 352 && WaterGirl.y == 126) {				//y126 到y166
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
				DrawWatergirlLeft();
				drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
				putall();
			}
		}
		WaterGirl.y = 166;
		if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
			DrawWatergirlLeft();
			drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
			putall();
		}
	}
	//推箱子到最左边过程
	if (WaterGirl.x >= 145 && WaterGirl.x <= 352 && WaterGirl.y == 166) {				//y126 到y166
		if (WaterGirl.boxcontact == 1) {
			drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
			putall();
		}
	}
	if (WaterGirl.x <= 145 && WaterGirl.y == 166) {			//推到最左了
		drawAlpha(&temp_game, 110, 168, &imag_box);
		putall();
		WaterGirl.boxcontact = 2;
		DrawWatergirlLeft();
		putall();
	}

	//第四层跳到箱子上
	if ((WaterGirl.x >= 143 && WaterGirl.x <= 160) && WaterGirl.y == 166) {
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				WaterGirl.y -= 60;
				DrawGame();
				putall();
				for (int i = 0; i < 15; i++) {
					WaterGirl.y += 4;
					WaterGirl.x += 7;
					if (WaterGirl.x >= 184) {
						WaterGirl.x = 184;
					}
					DrawWatergirlRight();
					putall();
				}
			}
			if (input1 & LEFTINPUT) {									//y166 到y132
				WaterGirl.y -= 60;
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 13; i++) {
					WaterGirl.y += 2;
					WaterGirl.x -= 2;
					if (WaterGirl.x <= 100) {
						WaterGirl.x = 100;
					}
					DrawWatergirlLeft();
					putall();
				}
				WaterGirl.y = 132;
				DrawWatergirlLeft();
				putall();
			}
		}
	}
	//从箱子上掉落
	if (WaterGirl.x >= 128 && WaterGirl.y == 132) {
		for (int i = 0; i < 17; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 1;
			DrawWatergirlRight();
			putall();
		}
	}
	//从箱子上跳跃到下一层
	if ((WaterGirl.x >= 98 && WaterGirl.x < 128) && WaterGirl.y == 132) {
		if (WaterGirl.x >= 98 && WaterGirl.x < 110) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirl.y -= 60;
					for (int i = 0; i < 15; i++) {
						WaterGirl.y += 4;
						WaterGirl.x += 7;
						if (WaterGirl.x >= 184) {
							WaterGirl.x = 184;
						}
						WaterGirl.y = 166;
						DrawWatergirlRight();
						putall();
					}
				}
				if (input1 & LEFTINPUT) {									//y132 到y86
					WaterGirl.y -= 60;
					for (int i = 0; i < 7; i++) {
						WaterGirl.y += 2;
						WaterGirl.x -= 2;
						DrawWatergirlLeft();
						putall();
					}
					WaterGirl.y = 86;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	//从第五层断层掉落
	if (WaterGirl.x >= 96 && WaterGirl.y == 86) {					//y86 到y132
		for (int i = 0; i < 23; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 1;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 132;
		DrawWatergirlRight();
		putall();
	}
	//在第五层断层的操作
	if ((WaterGirl.x < 96 && WaterGirl.x >= 0) && WaterGirl.y == 86) {
		//在冰娃的操作里冰娃吃钻石
		if (WaterGirl.x >= 10 && WaterGirl.x <= 26) {
			WaterGirl.diamonds = 3;
			GetDiamonds();
		}
		else if (WaterGirl.x > 36 && WaterGirl.x <= 46)
		{
			CloseMusic();
		}
		if (WaterGirl.x >= 0 && WaterGirl.x < 70) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 70 && WaterGirl.x < 96) {
			if (input1 & UPINPUT) {
				if (input1 & RIGHTINPUT) {				//y86 到 y26
					/*WaterGirl.y -= 80;*/
					for (int i = 0; i < 20; i++) {
						WaterGirl.y -= 4;
						DrawWatergirlRight();
						putall();
					}
					for (int i = 0; i < 20; i++) {
						WaterGirl.y += 1;
						WaterGirl.x += 5;
						DrawWatergirlRight();
						putall();
					}
					WaterGirl.y = 26;
					DrawWatergirlRight();
					putall();
				}
			}
		}

	}
}

//第五层碰撞检测
void FifthJudge2()
{	//操作控制
	if ((WaterGirl.x > 272 && WaterGirl.x <= 720) && WaterGirl.y == 66) {
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				WaterGirlMinJumpAndRightMove();
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMinJumpAndLeftMove();
			}
		}
	}
	//冰娃吃到钻石
	if ((WaterGirl.x >= 404 && WaterGirl.x <= 434) && WaterGirl.y == 66) {
		GetDiamonds();
		WaterGirl.diamonds = 4;
	}
	else if ((WaterGirl.x >= 434 && WaterGirl.x <= 444) && WaterGirl.y == 66)
	{
		CloseMusic();
	}
	//第五层左滑落
	if ((WaterGirl.x <= 164 && WaterGirl.x >= 158) && WaterGirl.y == 26) {
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 3;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
	}
	//第五层右滑落1
	if ((WaterGirl.x >= 214 && WaterGirl.x <= 220) && WaterGirl.y == 26) {			//y26 到 y44       x214  x236
		for (int i = 0; i < 9; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlRight();
		putall();
	}
	//第五层右上升1
	if ((WaterGirl.x >= 230 && WaterGirl.x <= 236) && WaterGirl.y == 44) {			//y26 到 y44       x214  x236
		for (int i = 0; i < 9; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 26;
		DrawWatergirlLeft();
		putall();
	}
	//第五层右滑落2
	if ((WaterGirl.x >= 254 && WaterGirl.x <= 260) && WaterGirl.y == 44) {			//y44 到 y66       x287  x254
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlRight();
		putall();
	}
	//第五层右上升2
	if ((WaterGirl.x <= 272 && WaterGirl.x >= 266) && WaterGirl.y == 66) {			//y44 到 y66       x272  x250
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlLeft();
		putall();
	}

	//第五层右上升3
	if ((WaterGirl.x >= 490 && WaterGirl.x <= 496) && WaterGirl.y == 66) {		//y66 到 y44       x490  x512
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlRight();
		putall();
	}
	//第五层右滑落3
	if ((WaterGirl.x <= 512 && WaterGirl.x >= 508) && WaterGirl.y == 44) {		//y44 到 y66       x490  x512
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlLeft();
		putall();
	}
	//第五层右滑落4
	if ((WaterGirl.x >= 574 && WaterGirl.x <= 580) && WaterGirl.y == 44) {		//y44 到 y66       x574  x592
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlRight();
		putall();
	}
	//第五层右上升4
	if ((WaterGirl.x <= 592 && WaterGirl.x >= 586) && WaterGirl.y == 66) {		//y66 到 y44       x574  x592
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlLeft();
		putall();
	}
}






















