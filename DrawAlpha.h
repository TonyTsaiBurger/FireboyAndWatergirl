#pragma once
#ifndef __DRAWALPHA_H_
#define __DRAWALPHA_H_

//���ļ����ڼ�������ͼƬ��������DrawAlpha����

#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#pragma comment(lib,"winmm.lib")

extern IMAGE imag_bk, imag_playbutton, imag_more, imag_set, imag_tip, imag_back, imag_music, temp_img,imag_author;
extern IMAGE game_bk, temp_game;
extern IMAGE imag_fireboy_front, imag_fireboy_left, imag_fireboy_right, imag_watergirl_front, imag_watergirl_left, imag_watergirl_right;
extern IMAGE imag_fire_stone, imag_ice_stone,imag_box;
extern IMAGE imag_yellow_lever_left, imag_yellow_lever_right, imag_yellow_barricade, imag_purple_button, imag_purple_barricade;
extern IMAGE imag_door_open;
extern IMAGE imag_gameover, imag_menubutton, imag_retrybutton;
extern IMAGE imag_wined, imag_wined2, imag_continuebutton;

void LoadMenuRes();				//����˵�����ͼƬ�ļ�
void LoadGameRes();				//������Ϸ����ͼƬ�ļ�
void LoadGameoverMenuRes();		//������Ϸʧ�ܽ���ͼƬ�ļ�
void LoadGameWinMenuRes();		//������Ϸʤ������ͼƬ�ļ�

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);//����͸���Ȼ�ͼ

#endif // !__DRAWALPHA_H_
