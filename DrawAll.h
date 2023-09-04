#pragma once
#ifndef __DRAWALL_H_
#define __DRAWALL_H_

#include "DrawAlpha.h"
#include "Music.h"


typedef struct character {
	int x, y;						//��ɫ����
	int width, height;				//��ɫ��Ⱥ͸߶�
	int velocityX, velocityY;		//��ɫ��X��Y�����ϵ��ٶ�
	int status;						//��ɫ״̬��������ö�����ͱ�ʾ  0��ʾ���� 1��ʾ����
	int diamonds;					//�ռ�����ʯ����
	int speed;						//��ɫ�ƶ��ٶ�
	int boxcontact;					//�����ӵ���ϵ
	IMAGE image;					//��ɫͼ��
} Character;

//��ɫ����ɫ����
typedef struct yellowprop {
	int stauts = 1;
}Prop;

extern Character FireBoy, WaterGirl;
extern Prop purplebutton;

//��ʼ��λ��
void Init();
//��ʼ��λ��
void DrawBackGame();
//Ĭ�ϲ�����״̬
void DrawGame();
//��������
void DrawFireboyLeft();
//��������
void DrawWatergirlLeft();
//��������
void DrawFireboyRight();
//��������
void DrawWatergirlRight();



#endif // !__DRAWALL_H_
