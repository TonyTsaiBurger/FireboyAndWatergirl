#include "DrawAlpha.h"
#include <time.h>

//角色
typedef struct character {
	int x, y;						//角色坐标
	int width, height;				//角色宽度和高度
	int velocityX, velocityY;		//角色在X和Y方向上的速度
	int status;						//角色状态，可以用枚举类型表示
	int diamonds;					//收集的钻石数量
	int speed;						//角色移动速度
	int boxcontact;					//与箱子的联系
	IMAGE image;					//角色图像
} Character;

//黄色机关
typedef struct yellowprop {
	int stauts = 1;
}Prop;

Character FireBoy, WaterGirl;
Prop yellowlever;
Prop purplebutton;

//初始化位置
void Init()
{
	//火娃初始化
	FireBoy.x = 38;									//38,508       //到推箱子位置为150，126
	FireBoy.y = 508;
	FireBoy.width = 80;
	FireBoy.height = 64;
	FireBoy.velocityX = 2;
	FireBoy.velocityY = 2;
	FireBoy.boxcontact = 0;
	FireBoy.status = 0;
	FireBoy.diamonds = 0;
	//冰娃初始化
	WaterGirl.x = 38;								//38,426
	WaterGirl.y = 426;
	WaterGirl.width = 80;
	WaterGirl.height = 64;
	WaterGirl.velocityX = 2;
	WaterGirl.velocityY = 2;
	WaterGirl.boxcontact = 0;
	WaterGirl.status = 0;
	WaterGirl.diamonds = 0;
}

//画出地图
void DrawBackGame()
{
	LoadGameRes();
	drawAlpha(&temp_game, 0, 0, &game_bk);
	if (FireBoy.diamonds == 0 && WaterGirl.diamonds == 0) {
		//第一层钻号
		drawAlpha(&temp_game, 382, 508, &imag_fire_stone);
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 0) {
		//第一层钻号
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 0 && WaterGirl.diamonds == 1) {
		//第一层钻号
		drawAlpha(&temp_game, 382, 508, &imag_fire_stone);
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 1) {
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 1) {
		//第二层钻石
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 2) {
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 2) {
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 2) {
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 3) {
		//第三层钻石
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 3) {
		//第三层钻石
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}

	if (FireBoy.diamonds == 1 && WaterGirl.diamonds==0) {
		//第一层钻号
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//第二层钻石
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 0) {
		//第一层钻号
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//第二层钻石
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 0) {
		//第一层钻号
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//第二层钻石
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//第三层钻石
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}

	//箱子
	if (FireBoy.boxcontact == 0 && WaterGirl.boxcontact == 0) {
		drawAlpha(&temp_game, 400, 128, &imag_box);
	}
	if (FireBoy.boxcontact == 2 || WaterGirl.boxcontact == 2) {
		drawAlpha(&temp_game, 110, 168, &imag_box);
	}


	//黄色机关
	if ((FireBoy.x >= 152 && FireBoy.x <= 153 && FireBoy.y == 346) || (WaterGirl.x >= 152 && WaterGirl.x <= 153 && WaterGirl.y == 346)) {
		yellowlever.stauts = -yellowlever.stauts;
	}
	if (yellowlever.stauts > 0) {
		drawAlpha(&temp_game, 152, 354, &imag_yellow_lever_right);
		drawAlpha(&temp_game, 32, 270, &imag_yellow_barricade);  //下降到32,328,不到底 上升到32,270

	}
	if (yellowlever.stauts < 0)
	{
		drawAlpha(&temp_game, 152, 354, &imag_yellow_lever_left);
		drawAlpha(&temp_game, 32, 328, &imag_yellow_barricade);  //下降到32,328,不到底 上升到32,270
	}

	//紫色机关
	if (((FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) || (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246)) || ((FireBoy.x >= 574 && FireBoy.x <= 608 && FireBoy.y == 166) || (WaterGirl.x >= 574 && WaterGirl.x <= 608 && WaterGirl.y == 166))) {
		if ((FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) || (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246)) {
			drawAlpha(&temp_game, 592, 166, &imag_purple_button);	//上层按钮
			drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//下降到692,270，上升到692,212
			purplebutton.stauts = 1;
		}
		else if ((FireBoy.x >= 574 && FireBoy.x <= 608 && FireBoy.y == 166) || (WaterGirl.x >= 574 && WaterGirl.x <= 608 && WaterGirl.y == 166))
		{
			drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//底层按钮
			drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//下降到692,270，上升到692,212
			purplebutton.stauts = 1;
		}
	}
	else
	{
		drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//底层按钮
		drawAlpha(&temp_game, 592, 166, &imag_purple_button);	//上层按钮
		drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//下降到692,270，上升到692,212
		purplebutton.stauts = 2;
	}

	//火娃到达门前
	if ((FireBoy.x >= 600 && FireBoy.x <= 640) && FireBoy.y == 66) {
		FireBoy.status = 2;			//设置火娃成功状态
		drawAlpha(&temp_game, 620, 66, &imag_door_open);
	}
	//水娃到达门前
	if ((WaterGirl.x >= 660 && WaterGirl.x <= 700) && WaterGirl.y == 66) {	
		WaterGirl.status = 2;		//设置水娃成功状态
		drawAlpha(&temp_game, 680, 66, &imag_door_open);
	}

	//保安
	/*drawAlpha(&temp_game, 0, 0, &imag_fireboy_front);*/
}


//默认不动的状态
void DrawGame()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_front);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_front);
}
//火娃左走
void DrawFireboyLeft()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_left);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_left);
}
//冰娃左走
void DrawWatergirlLeft()
{
	DrawBackGame();
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_left);
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_left);
}
//火娃右走
void DrawFireboyRight()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_right);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_right);
}
//冰娃右走
void DrawWatergirlRight()
{
	DrawBackGame();
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_right);
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_right);
}