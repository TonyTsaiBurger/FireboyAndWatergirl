#pragma once
#ifndef __MUSIC_H_
#define __MUSIC_H_

#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"

void CloseMusic();
void BGMStart();
void BGMStop();
void GetDiamonds();
void DieMusic();
void LiftMusic();


void LoseMusic();		//ʧ����Ч
void CloseLoseMusic();	//�ر�ʧ����Ч
void WinMusic();		//ʤ����Ч
void CloseWinMusic();	//�ر�ʤ����Ч

#endif // !__MUSIC_H_
