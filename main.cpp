#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#pragma comment(lib,"winmm.lib")
#include "gamemenu.h"


#define WIDTH 800
#define HIGHT 600


int main()
{
	initgraph(WIDTH, HIGHT, EX_SHOWCONSOLE);	// ������ͼ���ڣ���СΪ 800x600 ����

	//����һ��
	//mciSendString(L"close  bkmusic ", NULL, 0, NULL);//�ȹر�֮ǰ���ŵı�����
	//mciSendString(L"open .\\fl\\background.mp3 alias bkmusic", NULL, 0, NULL);//���´򿪶�ȡ�����ļ�
	//mciSendString(L"play bkmusic ", NULL, 0, NULL);//���������ļ�

	//Ĭ�ϴ򿪲���BGM
	//vs���ֽڼ��Ͳ�ҪL��.������ǵ�ǰ�ļ�λ�ã�alias�������Զ���ı��
	mciSendString(L"open resoure\\background1.mp3 alias bkmusic", NULL, 0, NULL);//bkmusic���Լ�����ı���
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);

	//���뿪ʼ�˵�ҳ��
	StartMenu();

	
	
	

	//�������п���̨��������˳�
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}

//#include <stdio.h>
//#include <graphics.h>
//#include <conio.h>
//#include<time.h>
//clock_t Start_time;
//clock_t End_time;
//int time_1;
//int min, second;
//int main() {
//	initgraph(200, 200, SHOWCONSOLE);//init ��ʼ��  graph ͼ�񴰿�  SHOWCONSOLE ��ʾ����̨
//	setbkcolor(RGB(225, 115, 100));//���ñ�����ɫ
//	BeginBatchDraw();	//˫�����ͼ����ֹ����
//
//	Start_time = clock();
//	while (1) {
//		/*cleardevice();*/
//		End_time = clock();
//		time_1 = (int)((End_time - Start_time) / CLOCKS_PER_SEC);
//		min = time_1 / 60;
//		second = time_1 % 60;
//		settextstyle(60, 0, _T("΢���ź�"));
//		setcolor(YELLOW);//
//		TCHAR str[255];
//		_stprintf_s(str, _T("%0d:%0d"),min,second );		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
//
//		outtextxy(10, 10, str);
//
//
//		EndBatchDraw();//˫�����ͼ
//	}
//	return 0;
//}

