#pragma once
#ifndef __GAMEMENU_H
#define __GAMEMEUN_H

#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include "DrawAlpha.h"
#include "easygame.h"
#pragma comment(lib,"winmm.lib")


void DrawMainMenu();//�������˵�����
void StartMenu();//���뿪ʼ�˵�ҳ��
void TipMenu();//������ʾ�˵�
void SetMenu();//�������ò˵�

void GameOverMenu();//��Ϸ�����˵�
void GameWinMenu();//��Ϸʤ�����棨��ȡ���б�ʯ��
void GameWinMenu2();//��Ϸʤ�����棨û�л�ȡ���б�ʯ��


#endif // !__GAMEMENU_H