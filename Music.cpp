#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"

void CloseMusic()
{
	mciSendString(L"close  diamondsmusic", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
	mciSendString(L"close  diemusic", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
	mciSendString(L"close  liftmusic", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
}
	
//�������ֿ���
void BGMStart() 
{
	mciSendString(L"open resoure\\background1.mp3 alias bkmusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
}
//�رձ�������
void BGMStop()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
}
//��ȡ��ʯ��Ч
void GetDiamonds()
{
	
	mciSendString(L"open resoure\\GetDiamonds.mp3 alias diamondsmusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play diamondsmusic", NULL, 0, NULL);
}
//������Ч
void DieMusic()
{
	mciSendString(L"open resoure\\Die.mp3 alias diemusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play diemusic", NULL, 0, NULL);	
}
//������Ч
void LiftMusic()
{
	mciSendString(L"open resoure\\Lift.mp3 alias liftmusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play liftmusic", NULL, 0, NULL);
}

//ʧ����Ч
void LoseMusic()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
	mciSendString(L"open resoure\\lose.mp3 alias losemusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play losemusic", NULL, 0, NULL);
}
//�ر�ʧ����Ч
void CloseLoseMusic()
{
	mciSendString(L"close  losemusic", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
}

//ʤ����Ч
void WinMusic()
{
	mciSendString(L"close  bkmusic ", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
	mciSendString(L"open resoure\\win.mp3 alias winmusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play winmusic", NULL, 0, NULL);
}
//�ر�ʤ����Ч
void CloseWinMusic()
{
	mciSendString(L"close  winmusic", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
}

