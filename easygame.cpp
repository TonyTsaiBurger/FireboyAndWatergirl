#include "DrawAll.h"
#include "Judge.h"
#include <time.h>
#include "gamemenu.h"


int EdgePoint1_x = 30; int EdgePoint1_y = 520;		//���½Ǳ߽�����
int EdgePoint2_x = 30; int EdgePoint2_y = 22;		//���ϽǱ߽�����
int EdgePoint32_x = 672; int EdgePoint32_y = 484;	//���½Ǳ߽�����
int EdgePoint3_x = 720; int EdgePoint3_y = 460;		//���½Ǳ߽�����
int EdgePoint4_x = 720; int EdgePoint4_y = 22;		//���ϽǱ߽�����

int EdgePointLeft = 0;			//����߽��
int EdgePointRight = 720;		//���ұ߽��
int EdgePointUp = 0;			//���ϱ߽��
int EdgePointDown = 508;		//���±߽��




//��ʱ����
void Delay(int ms)
{
	static clock_t oldclock = clock();		// ��̬��������¼��һ�� tick

	oldclock += ms * CLOCKS_PER_SEC / 1000;	// ���� tick

	if (clock() > oldclock)					// ����Ѿ���ʱ��������ʱ
		oldclock = clock();
	else
		while (clock() < oldclock)			// ��ʱ
			Sleep(1);						// �ͷ� CPU ����Ȩ������ CPU ռ����
}



void DealInput()
{
	//ÿһ�ε���ײ���
	FirstJudge();
	SecondJudge();
	ThirdJudge();
	FourthJudge();
	FifthJudge();

	FirstJudge2(); 
	SecondJudge2();
	ThirdJudge2();
	FourthJudge2();
	FifthJudge2();

	

	//���޲���
	/*if ((input1 & UPINPUT) && (WaterGirl.y - WaterGirl.velocityY >= EdgePointUp)) {

		WaterGirl.y -= WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & LEFTINPUT) && (WaterGirl.x - WaterGirl.velocityX >= EdgePointLeft)) {
		WaterGirl.x -= WaterGirl.velocityX;
		DrawWatergirlLeft();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & RIGHTINPUT) && (WaterGirl.x + WaterGirl.velocityX <= EdgePointRight)) {
		if (WaterGirl.x >= 664 && WaterGirl.y == 508) {
			WaterGirl.x = 664;
		}
		WaterGirl.x += WaterGirl.velocityX;
		DrawWatergirlRight();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & DOWNINPUT) && (WaterGirl.y + WaterGirl.velocityY <= EdgePointDown)) {
		WaterGirl.y += WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}*/
	if ((input1 & UPINPUT) && (WaterGirl.y - WaterGirl.velocityY >= EdgePointUp)) {
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & LEFTINPUT) && (WaterGirl.x - WaterGirl.velocityX >= EdgePointLeft)) {
		if (WaterGirl.x <= 88 && WaterGirl.y == 346) {		//�ڶ������
			WaterGirl.x = 88;
		}
		if (WaterGirl.x <= 656 && WaterGirl.y == 192) {		//��������ݵ����Ĳ�
			WaterGirl.x = 656;
		}
		if (WaterGirl.x <= 110 + 35 && WaterGirl.y == 166) {	//���Ĳ������ӵ������
			WaterGirl.x = 110 + 35;
		}
		if (WaterGirl.x <= 100 && WaterGirl.y == 132) {	//���Ĳ���������
			WaterGirl.x = 100;
		}
		WaterGirl.x -= WaterGirl.velocityX;
		DrawWatergirlLeft();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & RIGHTINPUT) && (WaterGirl.x + WaterGirl.velocityX <= EdgePointRight)) {
		if (WaterGirl.x >= 664 && WaterGirl.y == 508) {		//��һ���ұ�ǽ��
			WaterGirl.x = 664;
		}
		if (WaterGirl.x >= 648 && WaterGirl.y == 266) {		//���������
			WaterGirl.x = 648;
		}
		WaterGirl.x += WaterGirl.velocityX;
		DrawWatergirlRight();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}
	if ((input1 & DOWNINPUT) && (WaterGirl.y + WaterGirl.velocityY <= EdgePointDown)) {
		WaterGirl.y += WaterGirl.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", WaterGirl.x, WaterGirl.y);
	}



	//���޲���
	if ((input2 & UPINPUT) && (FireBoy.y - FireBoy.velocityY >= EdgePointUp)) {
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & LEFTINPUT) && (FireBoy.x - FireBoy.velocityX >= EdgePointLeft)) {
		if (FireBoy.x <= 88 && FireBoy.y == 346) {		//�ڶ������
			FireBoy.x = 88;
		}
		if (FireBoy.x <= 656 && FireBoy.y == 192) {		//��������ݵ����Ĳ�
			FireBoy.x = 656;
		}
		if (FireBoy.x <= 110 + 35 && FireBoy.y == 166) {	//���Ĳ������ӵ������
			FireBoy.x = 110 + 35;
		}
		if (FireBoy.x <= 100 && FireBoy.y == 132) {	//���Ĳ���������
			FireBoy.x = 100;
		}
		FireBoy.x -= FireBoy.velocityX;
		DrawFireboyLeft();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & RIGHTINPUT) && (FireBoy.x + FireBoy.velocityX <= EdgePointRight)) {
		if (FireBoy.x >= 664 && FireBoy.y == 508) {		//��һ���ұ�ǽ��
			FireBoy.x = 664;
		}
		if (FireBoy.x >= 648 && FireBoy.y == 266) {		//���������
			FireBoy.x = 648;
		}
		FireBoy.x += FireBoy.velocityX;
		DrawFireboyRight();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	if ((input2 & DOWNINPUT) && (FireBoy.y + FireBoy.velocityY <= EdgePointDown)) {
		FireBoy.y += FireBoy.velocityY;
		DrawGame();
		putimage(0, 0, &temp_game);
		printf("����(%d,%d)\n", FireBoy.x, FireBoy.y);
	}
	input1 = NOINPUT;
	input2 = NOINPUT;
	
}


//��ʱ��
TCHAR str[255];
clock_t Start_time;
clock_t End_time;
int time_1;
int min, second;

//����ʱ��͵�ͼ
void putall()
{
	putimage(0, 0, &temp_game);
	outtextxy(364, -2, str);
}

//��Ϸ����
void GameMenu()
{
	
	Start_time = clock();
	Init();		//��ʼ������
	DrawGame();	//������Ϸ����
	putimage(0, 0, &temp_game);
	
	while (1) {
		//��ʱ��
		End_time = clock();
		time_1 = (int)((End_time - Start_time) / CLOCKS_PER_SEC);
		min = time_1 / 60;
		second = time_1 % 60;
		if (min < 10 && second >= 10) {
			_stprintf_s(str, _T("0%d:%d"), min, second);
		}
		else if (min >= 10 && second < 10)
		{
			_stprintf_s(str, _T("%d:0%d"), min, second);
		}
		else if (min < 10 && second < 10)
		{
			_stprintf_s(str, _T("0%d:0%d"), min, second);
		}
		//_stprintf_s(str, _T("%d:%d"), min, second);		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
		setbkmode(TRANSPARENT);             //���屳��͸��
		settextstyle(38, 0, _T("΢���ź�"));
		setcolor(YELLOW);
		cleardevice();
		putall();
		


		GetInput();
		DealInput();
		if (WaterGirl.status == 1 || FireBoy.status == 1) {		//��һ��������������Ϸʧ��
			LoseMusic();
			GameOverMenu();
		}
		else
		{
			CloseLoseMusic();
		}
		if (WaterGirl.status == 2 && FireBoy.status == 2) {			//��Ϸʤ��
			WinMusic();
			if (WaterGirl.diamonds == 4 && FireBoy.diamonds == 3) {	//�����˵�������ǰ��ȫ����ʯ�ռ����
				GameWinMenu();
			}
			else
			{
				GameWinMenu2();									//û�л�ȡ������ʯ
			}
		}
		else
		{
			CloseWinMusic();
		}
	}
	
}