#pragma once
#ifndef __DRAWALPHA_H_
#define __DRAWALPHA_H_

//该文件用于加载所有图片，并且有DrawAlpha函数

#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
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

void LoadMenuRes();				//载入菜单界面图片文件
void LoadGameRes();				//载入游戏界面图片文件
void LoadGameoverMenuRes();		//载入游戏失败界面图片文件
void LoadGameWinMenuRes();		//载入游戏胜利界面图片文件

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);//根据透明度绘图

#endif // !__DRAWALPHA_H_
