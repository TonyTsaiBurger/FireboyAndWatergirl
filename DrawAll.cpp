#include "DrawAlpha.h"
#include <time.h>

//��ɫ
typedef struct character {
	int x, y;						//��ɫ����
	int width, height;				//��ɫ��Ⱥ͸߶�
	int velocityX, velocityY;		//��ɫ��X��Y�����ϵ��ٶ�
	int status;						//��ɫ״̬��������ö�����ͱ�ʾ
	int diamonds;					//�ռ�����ʯ����
	int speed;						//��ɫ�ƶ��ٶ�
	int boxcontact;					//�����ӵ���ϵ
	IMAGE image;					//��ɫͼ��
} Character;

//��ɫ����
typedef struct yellowprop {
	int stauts = 1;
}Prop;

Character FireBoy, WaterGirl;
Prop yellowlever;
Prop purplebutton;

//��ʼ��λ��
void Init()
{
	//���޳�ʼ��
	FireBoy.x = 38;									//38,508       //��������λ��Ϊ150��126
	FireBoy.y = 508;
	FireBoy.width = 80;
	FireBoy.height = 64;
	FireBoy.velocityX = 2;
	FireBoy.velocityY = 2;
	FireBoy.boxcontact = 0;
	FireBoy.status = 0;
	FireBoy.diamonds = 0;
	//���޳�ʼ��
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

//������ͼ
void DrawBackGame()
{
	LoadGameRes();
	drawAlpha(&temp_game, 0, 0, &game_bk);
	if (FireBoy.diamonds == 0 && WaterGirl.diamonds == 0) {
		//��һ�����
		drawAlpha(&temp_game, 382, 508, &imag_fire_stone);
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 0) {
		//��һ�����
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 0 && WaterGirl.diamonds == 1) {
		//��һ�����
		drawAlpha(&temp_game, 382, 508, &imag_fire_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 1) {
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 1) {
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 1 && WaterGirl.diamonds == 2) {
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 2) {
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 2) {
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 3) {
		//��������ʯ
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 3) {
		//��������ʯ
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}

	if (FireBoy.diamonds == 1 && WaterGirl.diamonds==0) {
		//��һ�����
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 106, 246, &imag_fire_stone);
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 2 && WaterGirl.diamonds == 0) {
		//��һ�����
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 190, 26, &imag_fire_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}
	if (FireBoy.diamonds == 3 && WaterGirl.diamonds == 0) {
		//��һ�����
		drawAlpha(&temp_game, 542, 508, &imag_ice_stone);
		//�ڶ�����ʯ
		drawAlpha(&temp_game, 434, 264, &imag_ice_stone);
		//��������ʯ
		drawAlpha(&temp_game, 16, 86, &imag_ice_stone);
		drawAlpha(&temp_game, 414, 66, &imag_ice_stone);
	}

	//����
	if (FireBoy.boxcontact == 0 && WaterGirl.boxcontact == 0) {
		drawAlpha(&temp_game, 400, 128, &imag_box);
	}
	if (FireBoy.boxcontact == 2 || WaterGirl.boxcontact == 2) {
		drawAlpha(&temp_game, 110, 168, &imag_box);
	}


	//��ɫ����
	if ((FireBoy.x >= 152 && FireBoy.x <= 153 && FireBoy.y == 346) || (WaterGirl.x >= 152 && WaterGirl.x <= 153 && WaterGirl.y == 346)) {
		yellowlever.stauts = -yellowlever.stauts;
	}
	if (yellowlever.stauts > 0) {
		drawAlpha(&temp_game, 152, 354, &imag_yellow_lever_right);
		drawAlpha(&temp_game, 32, 270, &imag_yellow_barricade);  //�½���32,328,������ ������32,270

	}
	if (yellowlever.stauts < 0)
	{
		drawAlpha(&temp_game, 152, 354, &imag_yellow_lever_left);
		drawAlpha(&temp_game, 32, 328, &imag_yellow_barricade);  //�½���32,328,������ ������32,270
	}

	//��ɫ����
	if (((FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) || (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246)) || ((FireBoy.x >= 574 && FireBoy.x <= 608 && FireBoy.y == 166) || (WaterGirl.x >= 574 && WaterGirl.x <= 608 && WaterGirl.y == 166))) {
		if ((FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) || (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246)) {
			drawAlpha(&temp_game, 592, 166, &imag_purple_button);	//�ϲ㰴ť
			drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//�½���692,270��������692,212
			purplebutton.stauts = 1;
		}
		else if ((FireBoy.x >= 574 && FireBoy.x <= 608 && FireBoy.y == 166) || (WaterGirl.x >= 574 && WaterGirl.x <= 608 && WaterGirl.y == 166))
		{
			drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//�ײ㰴ť
			drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//�½���692,270��������692,212
			purplebutton.stauts = 1;
		}
	}
	else
	{
		drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//�ײ㰴ť
		drawAlpha(&temp_game, 592, 166, &imag_purple_button);	//�ϲ㰴ť
		drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//�½���692,270��������692,212
		purplebutton.stauts = 2;
	}

	//���޵�����ǰ
	if ((FireBoy.x >= 600 && FireBoy.x <= 640) && FireBoy.y == 66) {
		FireBoy.status = 2;			//���û��޳ɹ�״̬
		drawAlpha(&temp_game, 620, 66, &imag_door_open);
	}
	//ˮ�޵�����ǰ
	if ((WaterGirl.x >= 660 && WaterGirl.x <= 700) && WaterGirl.y == 66) {	
		WaterGirl.status = 2;		//����ˮ�޳ɹ�״̬
		drawAlpha(&temp_game, 680, 66, &imag_door_open);
	}

	//����
	/*drawAlpha(&temp_game, 0, 0, &imag_fireboy_front);*/
}


//Ĭ�ϲ�����״̬
void DrawGame()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_front);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_front);
}
//��������
void DrawFireboyLeft()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_left);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_left);
}
//��������
void DrawWatergirlLeft()
{
	DrawBackGame();
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_left);
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_left);
}
//��������
void DrawFireboyRight()
{
	DrawBackGame();
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_right);
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_right);
}
//��������
void DrawWatergirlRight()
{
	DrawBackGame();
	drawAlpha(&temp_game, WaterGirl.x, WaterGirl.y, &imag_watergirl_right);
	drawAlpha(&temp_game, FireBoy.x, FireBoy.y, &imag_fireboy_right);
}