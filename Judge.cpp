#include "DrawAll.h"
#include "KeyInput.h"
#include "easygame.h"

//���޶���
//������Ծ��С�ռ䣩
void FireBoyMinJump()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		DrawGame();
		putall();
	}
}
//��������Ծ��С�ռ䣩
void FireBoyMinJumpAndRightMove()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		FireBoy.x += 3;
		DrawFireboyRight();
		putall();
	}
}
//��������Ծ��С�ռ䣩
void FireBoyMinJumpAndLeftMove()
{
	FireBoy.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		FireBoy.y += 2;
		FireBoy.x -= 3;
		DrawFireboyLeft();
		putall();
	}
}

//������Ծ�����䣨��ռ䣩
void FireBoyBigJump()
{
	FireBoy.y -= 80;
	DrawGame();
	putall();
}
//������Ծ���䣨��ռ䣩
void FireBoyBigDown()
{
	for (int i = 0; i < 16; i++) {
		FireBoy.y += 5;
		DrawGame();
		putall();
	}
}

//��������Ծ
void FireBoyMidJump()
{
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		DrawGame();
		putall();
	}
}
//����������Ծ
void FireBoyMidJumpAndRightMove()
{	
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		FireBoy.x += 7;
		DrawFireboyRight();
		putall();
	}
}
//����������Ծ
void FireBoyMidJumpAndLeftMove()
{
	FireBoy.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		FireBoy.y += 4;
		FireBoy.x -= 7;
		DrawFireboyLeft();
		putall();
	}
}


//���޶���
//������Ծ��С�ռ䣩
void WaterGirlMinJump()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		DrawGame();
		putall();
	}
}
//��������Ծ��С�ռ䣩
void WaterGirlMinJumpAndRightMove()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		WaterGirl.x += 3;
		DrawWatergirlRight();
		putall();
	}
}
//��������Ծ��С�ռ䣩
void WaterGirlMinJumpAndLeftMove()
{
	WaterGirl.y -= 20;
	DrawGame();
	putall();
	for (int i = 0; i < 10; i++) {
		WaterGirl.y += 2;
		WaterGirl.x -= 3;
		DrawWatergirlLeft();
		putall();
	}
}

//������Ծ�����䣨��ռ䣩
void WaterGirlBigJump()
{
	WaterGirl.y -= 80;
	DrawGame();
	putall();
}
//������Ծ���䣨��ռ䣩
void WaterGirlBigDown()
{
	for (int i = 0; i < 16; i++) {
		WaterGirl.y += 5;
		DrawGame();
		putall();
	}
}

//��������Ծ
void WaterGirlMidJump()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		DrawGame();
		putall();
	}
}
//����������Ծ
void WaterGirlMidJumpAndRightMove()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		WaterGirl.x += 7;
		DrawWatergirlRight();
		putall();
	}
}
//����������Ծ
void WaterGirlMidJumpAndLeftMove()
{
	WaterGirl.y -= 60;
	DrawGame();
	putall();
	for (int i = 0; i < 15; i++) {
		WaterGirl.y += 4;
		WaterGirl.x -= 7;
		DrawWatergirlLeft();
		putall();
	}
}





//ÿ��ļ��
//����
//��һ����ײ���
void FirstJudge()
{
	//�ڵ�һ����ߵķ�Χ		����ͷ������ĩ
	if ((FireBoy.x >= 0 && FireBoy.x <= 236) && (FireBoy.y >= 484 && FireBoy.y <= 508)) {
		if (input2 & UPINPUT) {
			FireBoyMinJump();
			if (input2 & RIGHTINPUT) {
				FireBoyMinJumpAndRightMove();
			}
			if (input2 & LEFTINPUT) {
				FireBoyMinJumpAndLeftMove();
			}
		}
	}
	if ((FireBoy.x > 235 && FireBoy.x <= 282) && (FireBoy.y == 508)) {  //Сһ�����ĩ����ˮǰ��ǰ
		if (input2 & UPINPUT) {
			FireBoyBigJump();
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 11; i++) {
					FireBoy.x -= 3;
					FireBoy.y = 426;
					DrawFireboyLeft();
					putall();
				}
			}
			else
			{
				//282  //���ڷ�Χ�������
				FireBoyBigDown();
			}
		}
	}
	if ((FireBoy.x > 282 && FireBoy.x <= 318) && (FireBoy.y == 508)) {  //Сһ���ˮǰ��ǰ����ˮǰ
		if (input2 & UPINPUT) {
			FireBoyMidJump();
		}
	}
	if ((FireBoy.x >= 232 && FireBoy.x <= 234) && (FireBoy.y == 426))	//С�������ĩ����Ե�Զ�����
	{
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 4;
			DrawGame();
			putall();
		}
		FireBoy.y += 2;
		DrawGame();
		putall();
	}
	if ((FireBoy.x >= 0 && FireBoy.x < 198) && (FireBoy.y == 426))		//С�������ͷ������ĩ
	{
		if (input2 & UPINPUT) {
			FireBoyMinJump();
		}
	}
	//��ˮ�ͻ�ˮ���ж�
	if ((FireBoy.x > 318 && FireBoy.x <= 440) && FireBoy.y >= 508) { //��ˮǰ����ˮ��
		if ((FireBoy.x > 318 && FireBoy.x < 420) && FireBoy.y >= 508) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x > 318 && FireBoy.x < 340) {
			FireBoy.y = 508;
		}
		if (FireBoy.x >= 340 && FireBoy.x < 416) {  //�ڻ�ˮ��
			FireBoy.y = 516;
		}
		if (FireBoy.x >= 416 && FireBoy.x <= 422) {  //�����ˮ
			FireBoy.y = 508;
		}
		if (FireBoy.x >= 372 && FireBoy.x <= 402) {  //�Ե���ʯ
			GetDiamonds();
			FireBoy.diamonds = 1;
		}
		else if (FireBoy.x >= 402 && FireBoy.x <= 412)
		{
			CloseMusic();
		}
	}
	if ((FireBoy.x > 440 && FireBoy.x <= 598) && FireBoy.y >= 508) {  //��ˮǰ����ˮ��
		if ((FireBoy.x > 460 && FireBoy.x < 578) && FireBoy.y >= 508) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x > 440 && FireBoy.x < 492) {
			FireBoy.y = 508;
		}
		if (FireBoy.x > 492 && FireBoy.x <= 570) {  //�ڱ�ˮ��
			DieMusic();
			FireBoy.y = 516;
			FireBoy.status = 1;
		}
		else if (FireBoy.x >= 570 && FireBoy.x <= 580)
		{
			CloseMusic();
		}
		if (FireBoy.x > 570 && FireBoy.x <= 598) {  //�����ˮ
			FireBoy.y = 508;
		}
	}
	if ((FireBoy.x > 598 && FireBoy.x <= 720) && FireBoy.y == 508) {  //��ˮ��  ׼����Ծ
		if (FireBoy.x == 664 && FireBoy.y == 508) {  //������һ��ǽ��
			FireBoy.x = 664;
		}
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				/*FireBoy.y -= 60;*/
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 12; i++) {
					FireBoy.y -= 5;
					FireBoy.x += 3;
					DrawFireboyRight();
					putall();
				}
			}
			if (input2 & LEFTINPUT) {
				FireBoyMidJumpAndLeftMove();
			}
		}
	}
	if (FireBoy.x <= 690 && FireBoy.y == 448) {		//����ǽ��1
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 5;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
	}
	if ((FireBoy.x > 690 && FireBoy.x <= 720) && FireBoy.y == 448) {		//��Ծ���ڶ���
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 12; i++) {  //632,388   448
					FireBoy.y -= 5;
					FireBoy.x -= 6;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	if (FireBoy.x >= 630 && FireBoy.y == 388) {		//����ǽ��2
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 5;
			FireBoy.x += 4;
			DrawFireboyRight();
			putall();
		}
	}
}


//�ڶ�����ײ���
void SecondJudge()
{
	//��ˮ���ж�
	if ((FireBoy.x >= 354 && FireBoy.x < 630) && (FireBoy.y >= 388 && FireBoy.y <= 396)) { //��ˮǰ��б��ǰ
		if ((FireBoy.x >= 354 && FireBoy.x < 600) && (FireBoy.y >= 388 && FireBoy.y <= 396)) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 354 && FireBoy.x <= 460) {	//��ˮ��
			FireBoy.y = 388;
		}
		if (FireBoy.x > 460 && FireBoy.x <= 546) {  //�ڶ�ˮ��
			FireBoy.y = 396;
			FireBoy.status = 1;
			DieMusic();
		}
		else if (FireBoy.x <= 460 && FireBoy.y >= 450)
		{
			CloseMusic();
		}
		if (FireBoy.x > 546 && FireBoy.x < 630) {  //��ˮǰ
			FireBoy.y = 388;
		}
	}
	//�ڶ���б�´������뻬��
	if ((FireBoy.x <= 354 && FireBoy.x >= 350) && FireBoy.y == 388) {		//�ڶ���б�´�����
		for (int i = 0; i < 20; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 346;
		DrawFireboyLeft();
		putall();
	}
	if (FireBoy.x > 314 && FireBoy.y == 346) {		//�ڶ���б�´�����
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 388;
		DrawFireboyRight();
		putall();
	}
	//��ɫ���ش�
	if ((FireBoy.x >= 86 && FireBoy.x <= 314) && FireBoy.y == 346) {    //����ǰ��
		if (FireBoy.x >= 110 && FireBoy.x <= 300) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
		//if ((FireBoy.x >= 150 && FireBoy.x <= 166) && FireBoy.y == 346) { //�ȵ����ز�������
		//	LiftMusic();
		//}
		//else
		//{
		//	CloseMusic();			//����ر�����
		//}
		if (FireBoy.x >= 86 && FireBoy.x <= 96) {					//������������
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					for (int i = 0; i < 12; i++) {
						FireBoy.y -= 3;
						FireBoy.x -= 2;
						DrawFireboyLeft();
						putall();
					}
				}
			}
		}
	}
	if (FireBoy.x >= 70 && FireBoy.y == 310) {			//�����ݱ�Ե����
		for (int i = 0; i < 12; i++) {
			FireBoy.y += 3;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
	}
	if ((FireBoy.x >= 0 && FireBoy.x <= 55) && FireBoy.y == 310) {			//����������������
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {		//��y310 ��  y246
				for (int i = 0; i < 16; i++) {
					FireBoy.y -= 4;
					FireBoy.x += 2;
					DrawFireboyRight();
					putall();
				}
				FireBoy.y = 246;
				DrawFireboyRight();
				putall();
			}
			if (input2 & LEFTINPUT) {
				for (int i = 0; i < 15; i++) {

					FireBoy.x -= 2;
					if (FireBoy.x <= 0) {
						FireBoy.x = 0;
					}
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	if (FireBoy.x <= 68 && FireBoy.y == 246) {			//�����㻬��
		for (int i = 0; i < 16; i++) {
			FireBoy.y += 4;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
	}
}

//��������ײ���
void ThirdJudge()
{
	//������б��ǰ
	if ((FireBoy.x > 68 && FireBoy.x <= 374) && FireBoy.y == 246) {
		if (FireBoy.x >= 88 && FireBoy.x <= 374) {
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 96 && FireBoy.x <= 126) {  //�Ե���ʯ
			FireBoy.diamonds = 2;
			GetDiamonds();
		}
		else if (FireBoy.x >= 126 && FireBoy.x <= 136)
		{
			CloseMusic();
		}
		//if (FireBoy.x >= 174 && FireBoy.x <= 208 && FireBoy.y == 246) {		//��ɫ��ť
		//	drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//�½���692,270��������692,212
		//}
		//else
		//{
		//	drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//�ײ㰴ť
		//	drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//�½���692,270��������692,212
		//}
	}

	//������б�´�����������
	if (FireBoy.x > 374 && FireBoy.y == 246) {		//������б�´�����
		for (int i = 0; i < 10; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 266;
		DrawFireboyRight();
		putall();
	}
	if (FireBoy.x < 394 && FireBoy.y == 266) {		//������б�´�����
		for (int i = 0; i < 10; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 246;
		DrawFireboyLeft();
		putall();
	}


	//������б�´���������ǰ��ǰ���ռ�ϴ�λ��
	if ((FireBoy.x >= 394 && FireBoy.x <= 550) && FireBoy.y == 266) {
		if (FireBoy.x >= 404 && FireBoy.x <= 550) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
	}

	//�ϴ�ռ��λ�õ�������ǰ
	if ((FireBoy.x >= 550 && FireBoy.x <= 648) && FireBoy.y == 266) {
		if (FireBoy.x >= 570 && FireBoy.x <= 600) {		//�������ϵ��ݵ�λ��
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 620 && FireBoy.x < 638) {		//�����ϵ��ݵ�λ��
			if (input2 & UPINPUT) {
				FireBoyMinJump();
				if (input2 & RIGHTINPUT) {
					for (int i = 0; i < 16; i++) {
						FireBoy.y -= 1;
						FireBoy.x += 2;
						DrawFireboyRight();
						putall();
					}
					FireBoy.y = 250;
					DrawFireboyRight();
					putall();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
	}
	//�ڵ��ݻ���
	if (FireBoy.x <= 656 && FireBoy.y == 250) {
		for (int i = 0; i < 16; i++) {
			FireBoy.y += 1;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 266;
		DrawFireboyLeft();
		putall();
	}
	//�ڵ����ϵĲ���
	if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 250) {
		if (FireBoy.x > 670 && FireBoy.x <= 720) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
					if (FireBoy.x >= 720) {
						FireBoy.x = 720;
					}
					DrawFireboyRight();
					putall();

				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
	}
	//���ݿ���
	if (purplebutton.stauts == 2) {  //�������뿪��ť
		if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 250) {
			FireBoy.y = 192;
			DrawGame();
			putall();
		}
	}
	else if (purplebutton.stauts == 1)
	{
		if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 192) {
			FireBoy.y = 250;
			DrawGame();
			putall();
		}
	}

	//����������������׼����Ծ
	if ((FireBoy.x > 656 && FireBoy.x <= 720) && FireBoy.y == 192) {			//y192  ��y166   
		if (FireBoy.x > 670 && FireBoy.x <= 720) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
					if (FireBoy.x >= 720) {
						FireBoy.x = 720;
						DrawFireboyRight();
						putall();
					}
				}
				if (input2 & LEFTINPUT) {
					FireBoy.y -= 40;
					DrawGame();
					putall();
					for (int i = 0; i < 7; i++) {
						FireBoy.y += 2;
						FireBoy.x -= 8;
						DrawFireboyLeft();
						putall();
					}
					FireBoy.y = 166;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	//���Ĳ��ұߵ�����
	if (FireBoy.x >= 654 && FireBoy.y == 166) {
		for (int i = 0; i < 13; i++) {
			FireBoy.y += 2;
			FireBoy.x += 2;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 192;
		DrawFireboyRight();
		putall();
	}
}

//���Ĳ���ײ���
void FourthJudge()
{
	//���Ĳ㻬��ǰ����
	if ((FireBoy.x > 536 && FireBoy.x < 654) && FireBoy.y == 166) {
		if (FireBoy.x > 536 && FireBoy.x < 610) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMidJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMidJumpAndLeftMove();
				}
			}
		}
	}

	//���Ĳ��ϻ���
	if ((FireBoy.x <= 536 && FireBoy.x >= 530) && FireBoy.y == 166) {  //y166 ��y126
		for (int i = 0; i < 20; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 126;
		DrawFireboyLeft();
		putall();
	}
	//���Ĳ��»���
	if ((FireBoy.x >= 490 && FireBoy.x <= 496) && FireBoy.y == 126) {  //y166 ��y126
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 166;
		DrawFireboyRight();
		putall();
	}

	//���Ĳ����껬�º�ǰ����䴦
	if ((FireBoy.x > 352 && FireBoy.x <= 470) && FireBoy.y == 126) {
		if (FireBoy.x - 35 < 400) {
			FireBoy.boxcontact = 1;
			drawAlpha(&temp_game, FireBoy.x - 35, 128, &imag_box);
			putall();
		}
	}
	//���Ĳ������ӵ���
	if (FireBoy.x <= 352 && FireBoy.y == 126) {				//y126 ��y166
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 2;
			DrawFireboyLeft();
			drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
			putall();
		}
		FireBoy.y = 166;
		DrawFireboyLeft();
		drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
		putall();
	}
	//�����ӵ�����߹���
	if (FireBoy.x >= 145 && FireBoy.x <= 352 && FireBoy.y == 166) {				//y126 ��y166
		if (FireBoy.boxcontact == 1) {
			drawAlpha(&temp_game, FireBoy.x - 35, FireBoy.y + 2, &imag_box);
			putall();
		}
	}
	if (FireBoy.x <= 145 && FireBoy.y == 166) {			//�Ƶ�������
		drawAlpha(&temp_game, 110, 168, &imag_box);
		putall();
		FireBoy.boxcontact = 2;
		DrawFireboyLeft();
		putall();
	}

	//���Ĳ�����������
	if ((FireBoy.x >= 143 && FireBoy.x <= 160) && FireBoy.y == 166) {
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				FireBoy.y -= 60;
				DrawGame();
				putall();
				for (int i = 0; i < 15; i++) {
					FireBoy.y += 4;
					FireBoy.x += 7;
					if (FireBoy.x >= 184) {
						FireBoy.x = 184;
					}
					DrawFireboyRight();
					putall();
				}
			}
			if (input2 & LEFTINPUT) {									//y166 ��y132
				FireBoy.y -= 60;
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 13; i++) {
					FireBoy.y += 2;
					FireBoy.x -= 2;
					if (FireBoy.x <= 100) {
						FireBoy.x = 100;
					}
					DrawFireboyLeft();
					putall();
				}
				FireBoy.y = 132;
				DrawFireboyLeft();
				putall();
			}
		}
	}
	//�������ϵ���
	if (FireBoy.x >= 128 && FireBoy.y == 132) {
		for (int i = 0; i < 17; i++) {
			FireBoy.y += 2;
			FireBoy.x += 1;
			DrawFireboyRight();
			putall();
		}
	}
	//����������Ծ����һ��
	if ((FireBoy.x >= 98 && FireBoy.x < 128) && FireBoy.y == 132) {
		if (FireBoy.x >= 98 && FireBoy.x < 110) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoy.y -= 60;
					for (int i = 0; i < 15; i++) {
						FireBoy.y += 4;
						FireBoy.x += 7;
						if (FireBoy.x >= 184) {
							FireBoy.x = 184;
						}
						FireBoy.y = 166;
						DrawFireboyRight();
						putall();
					}
				}
				if (input2 & LEFTINPUT) {									//y132 ��y86
					FireBoy.y -= 60;
					for (int i = 0; i < 7; i++) {
						FireBoy.y += 2;
						FireBoy.x -= 2;
						DrawFireboyLeft();
						putall();
					}
					FireBoy.y = 86;
					DrawFireboyLeft();
					putall();
				}
			}
		}
	}
	//�ӵ����ϲ����
	if (FireBoy.x >= 96 && FireBoy.y == 86) {					//y86 ��y132
		for (int i = 0; i < 23; i++) {
			FireBoy.y += 2;
			FireBoy.x += 1;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 132;
		DrawFireboyRight();
		putall();
	}
	//�ڵ����ϲ�Ĳ���
	if ((FireBoy.x < 96 && FireBoy.x >= 0) && FireBoy.y == 86) {
		//�ڱ��޵Ĳ�������޳���ʯ
		if (FireBoy.x >= 0 && FireBoy.x < 70) {
			if (input2 & UPINPUT) {
				FireBoyMidJump();
				if (input2 & RIGHTINPUT) {
					FireBoyMinJumpAndRightMove();
				}
				if (input2 & LEFTINPUT) {
					FireBoyMinJumpAndLeftMove();
				}
			}
		}
		if (FireBoy.x >= 70 && FireBoy.x < 96) {
			if (input2 & UPINPUT) {
				if (input2 & RIGHTINPUT) {				//y86 �� y26
					/*FireBoy.y -= 80;*/
					for (int i = 0; i < 20; i++) {
						FireBoy.y -= 4;
						DrawFireboyRight();
						putall();
					}
					for (int i = 0; i < 20; i++) {
						FireBoy.y += 1;
						FireBoy.x += 5;
						DrawFireboyRight();
						putall();
					}
					FireBoy.y = 26;
					DrawFireboyRight();
					putall();
				}
			}
		}
	}

}

//�������ײ���
void FifthJudge()
{	//��������
	if ((FireBoy.x > 272 && FireBoy.x <= 720) && FireBoy.y == 66) {
		if (input2 & UPINPUT) {
			FireBoyMidJump();
			if (input2 & RIGHTINPUT) {
				FireBoyMinJumpAndRightMove();
			}
			if (input2 & LEFTINPUT) {
				FireBoyMinJumpAndLeftMove();
			}
		}
	}
	//���޳Ե���ʯ
	if ((FireBoy.x >= 180 && FireBoy.x <= 210) && FireBoy.y == 26) {
		GetDiamonds();
		FireBoy.diamonds = 3;
	}
	else if ((FireBoy.x > 210 && FireBoy.x <= 220) && FireBoy.y == 26)
	{
		CloseMusic();
	}
	//���������
	if ((FireBoy.x <= 164 && FireBoy.x >= 158) && FireBoy.y == 26) {
		for (int i = 0; i < 20; i++) {
			FireBoy.y += 3;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
	}
	//������һ���1
	if ((FireBoy.x >= 214 && FireBoy.x <= 220) && FireBoy.y == 26) {			//y26 �� y44       x214  x236
		for (int i = 0; i < 9; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyRight();
		putall();
	}
	//�����������1
	if ((FireBoy.x >= 230 && FireBoy.x <= 236) && FireBoy.y == 44) {			//y26 �� y44       x214  x236
		for (int i = 0; i < 9; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 26;
		DrawFireboyLeft();
		putall();
	}
	//������һ���2
	if ((FireBoy.x >= 254 && FireBoy.x <= 260) && FireBoy.y == 44) {			//y44 �� y66       x287  x254
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyRight();
		putall();
	}
	//�����������2
	if ((FireBoy.x <= 272 && FireBoy.x >= 266) && FireBoy.y == 66) {			//y44 �� y66       x272  x250
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 2;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyLeft();
		putall();
	}

	//�����������3
	if ((FireBoy.x >= 490 && FireBoy.x <= 496) && FireBoy.y == 66) {		//y66 �� y44       x490  x512
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyRight();
		putall();
	}
	//������һ���3
	if ((FireBoy.x <= 512 && FireBoy.x >= 508) && FireBoy.y == 44) {		//y44 �� y66       x490  x512
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyLeft();
		putall();
	}
	//������һ���4
	if ((FireBoy.x >= 574 && FireBoy.x <= 580) && FireBoy.y == 44) {		//y44 �� y66       x574  x592
		for (int i = 0; i < 11; i++) {
			FireBoy.y += 2;
			FireBoy.x += 3;
			DrawFireboyRight();
			putall();
		}
		FireBoy.y = 66;
		DrawFireboyRight();
		putall();
	}
	//�����������4
	if ((FireBoy.x <= 592 && FireBoy.x >= 586) && FireBoy.y == 66) {		//y66 �� y44       x574  x592
		for (int i = 0; i < 11; i++) {
			FireBoy.y -= 2;
			FireBoy.x -= 3;
			DrawFireboyLeft();
			putall();
		}
		FireBoy.y = 44;
		DrawFireboyLeft();
		putall();
	}
}



















//����
//��һ����ײ���
void FirstJudge2()
{
	//�ڵ�һ����ߵķ�Χ		����ͷ������ĩ
	if ((WaterGirl.x >= 0 && WaterGirl.x <= 236) && (WaterGirl.y >= 484 && WaterGirl.y <= 508)) {
		if (input1 & UPINPUT) {
			WaterGirlMinJump();
			if (input1 & RIGHTINPUT) {
				WaterGirlMinJumpAndRightMove();
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMinJumpAndLeftMove();
			}
		}
	}
	if ((WaterGirl.x > 235 && WaterGirl.x <= 282) && (WaterGirl.y == 508)) {  //Сһ�����ĩ����ˮǰ��ǰ
		if (input1 & UPINPUT) {
			WaterGirlBigJump();
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 11; i++) {
					WaterGirl.x -= 3;
					WaterGirl.y = 426;
					DrawWatergirlLeft();
					putall();
				}
			}
			else
			{
				//282  //���ڷ�Χ�������
				WaterGirlBigDown();
			}
		}
	}
	if ((WaterGirl.x > 282 && WaterGirl.x <= 318) && (WaterGirl.y == 508)) {  //Сһ���ˮǰ��ǰ����ˮǰ
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
		}
	}
	if ((WaterGirl.x >= 232 && WaterGirl.x <= 234) && (WaterGirl.y == 426))	//С�������ĩ����Ե�Զ�����
	{
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 4;
			DrawGame();
			putall();
		}
		WaterGirl.y += 2;
		DrawGame();
		putall();
	}
	if ((WaterGirl.x >= 0 && WaterGirl.x < 198) && (WaterGirl.y == 426))		//С�������ͷ������ĩ
	{
		if (input1 & UPINPUT) {
			WaterGirlMinJump();
		}
	}
	//��ˮ�ͻ�ˮ���ж�
	if ((WaterGirl.x > 318 && WaterGirl.x <= 440) && WaterGirl.y >= 508) { //��ˮǰ����ˮ��
		if ((WaterGirl.x > 318 && WaterGirl.x < 420) && WaterGirl.y >= 508) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x > 318 && WaterGirl.x < 340) {
			WaterGirl.y = 508;
		}
		if (WaterGirl.x >= 340 && WaterGirl.x < 416) {  //�ڻ�ˮ��
			WaterGirl.y = 516;
			DieMusic();
			WaterGirl.status = 1;
		}
		else if (WaterGirl.x >= 416 && WaterGirl.x <= 426)
		{
			CloseMusic();
		}
		if (WaterGirl.x >= 416 && WaterGirl.x <= 422) {  //�����ˮ
			WaterGirl.y = 508;
		}

	}
	if ((WaterGirl.x > 440 && WaterGirl.x <= 598) && WaterGirl.y >= 508) {  //��ˮǰ����ˮ��
		if ((WaterGirl.x > 460 && WaterGirl.x < 578) && WaterGirl.y >= 508) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x > 440 && WaterGirl.x < 492) {
			WaterGirl.y = 508;
		}
		if (WaterGirl.x > 492 && WaterGirl.x <= 570) {  //�ڱ�ˮ��
			WaterGirl.y = 516;
		}
		if (WaterGirl.x >= 532 && WaterGirl.x <= 562) {  //�Ե���ʯ
			GetDiamonds();
			WaterGirl.diamonds = 1;
		}
		else if (WaterGirl.x >= 562 && WaterGirl.x <= 572)
		{
			CloseMusic();
		}
		if (WaterGirl.x > 570 && WaterGirl.x <= 598) {  //�����ˮ
			WaterGirl.y = 508;
		}
	}
	if ((WaterGirl.x > 598 && WaterGirl.x <= 720) && WaterGirl.y == 508) {  //��ˮ��  ׼����Ծ
		if (WaterGirl.x == 664 && WaterGirl.y == 508) {  //������һ��ǽ��
			WaterGirl.x = 664;
		}
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				for (int i = 0; i < 12; i++) {
					WaterGirl.y -= 5;
					WaterGirl.x += 3;
					DrawWatergirlRight();
					putall();
				}
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMidJumpAndLeftMove();
			}
		}
	}
	if (WaterGirl.x <= 690 && WaterGirl.y == 448) {		//����ǽ��1
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 5;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
	}
	if ((WaterGirl.x > 690 && WaterGirl.x <= 720) && WaterGirl.y == 448) {		//��Ծ���ڶ���
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 12; i++) {  //632,388   448
					WaterGirl.y -= 5;
					WaterGirl.x -= 6;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	if (WaterGirl.x >= 630 && WaterGirl.y == 388) {		//����ǽ��2
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 5;
			WaterGirl.x += 4;
			DrawWatergirlRight();
			putall();
		}
	}
}

//�ڶ�����ײ���
void SecondJudge2()
{
	//��ˮ���ж�
	if ((WaterGirl.x >= 354 && WaterGirl.x < 630) && (WaterGirl.y >= 388 && WaterGirl.y <= 396)) { //��ˮǰ��б��ǰ
		if ((WaterGirl.x >= 354 && WaterGirl.x < 600) && (WaterGirl.y >= 388 && WaterGirl.y <= 396)) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 354 && WaterGirl.x <= 460) {	//��ˮ��
			WaterGirl.y = 388;
		}
		if (WaterGirl.x > 460 && WaterGirl.x <= 546) {  //�ڶ�ˮ��
			WaterGirl.y = 396;
			WaterGirl.status = 1;
			DieMusic();
		}
		else if (WaterGirl.x <= 460 && WaterGirl.x >= 450)
		{
			CloseMusic();
		}
		if (WaterGirl.x > 546 && WaterGirl.x < 630) {  //��ˮǰ
			WaterGirl.y = 388;
		}
	}
	//�ڶ���б�´������뻬��
	if ((WaterGirl.x <= 354 && WaterGirl.x >= 350) && WaterGirl.y == 388) {		//�ڶ���б�´�����
		for (int i = 0; i < 20; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 346;
		DrawWatergirlLeft();
		putall();
	}
	if (WaterGirl.x > 314 && WaterGirl.y == 346) {		//�ڶ���б�´�����
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 388;
		DrawWatergirlRight();
		putall();
	}
	//��ɫ���ش�
	if ((WaterGirl.x >= 86 && WaterGirl.x <= 314) && WaterGirl.y == 346) {    //����ǰ��
		if (WaterGirl.x >= 110 && WaterGirl.x <= 300) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		//if ((WaterGirl.x >= 150 && WaterGirl.x <= 166) && WaterGirl.y == 346) { //�ȵ����ز�������
		//	LiftMusic();
		//}
		//else
		//{
		//	CloseMusic();			//����ر�����
		//}
		if (WaterGirl.x >= 86 && WaterGirl.x <= 96) {					//������������
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					for (int i = 0; i < 12; i++) {
						WaterGirl.y -= 3;
						WaterGirl.x -= 2;
						DrawWatergirlLeft();
						putall();
					}
				}
			}
		}
	}
	if (WaterGirl.x >= 70 && WaterGirl.y == 310) {			//�����ݱ�Ե����
		for (int i = 0; i < 12; i++) {
			WaterGirl.y += 3;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
	}
	if ((WaterGirl.x >= 0 && WaterGirl.x <= 55) && WaterGirl.y == 310) {			//����������������
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {		//��y310 ��  y246
				for (int i = 0; i < 16; i++) {
					WaterGirl.y -= 4;
					WaterGirl.x += 2;
					DrawWatergirlRight();
					putall();
				}
				WaterGirl.y = 246;
				DrawWatergirlRight();
				putall();
			}
			if (input1 & LEFTINPUT) {
				for (int i = 0; i < 15; i++) {

					WaterGirl.x -= 2;
					if (WaterGirl.x <= 0) {
						WaterGirl.x = 0;
					}
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	if (WaterGirl.x <= 68 && WaterGirl.y == 246) {			//�����㻬��
		for (int i = 0; i < 16; i++) {
			WaterGirl.y += 4;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
	}
}

//��������ײ���
void ThirdJudge2()
{
	//������б��ǰ
	if ((WaterGirl.x > 68 && WaterGirl.x <= 374) && WaterGirl.y == 246) {
		if (WaterGirl.x >= 88 && WaterGirl.x <= 374) {
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		//if (WaterGirl.x >= 174 && WaterGirl.x <= 208 && WaterGirl.y == 246) {		//��ɫ��ť
		//	drawAlpha(&temp_game, 692, 270, &imag_purple_barricade);//�½���692,270��������692,212
		//}
		//else
		//{
		//	drawAlpha(&temp_game, 190, 246, &imag_purple_button);	//�ײ㰴ť
		//	drawAlpha(&temp_game, 692, 212, &imag_purple_barricade);//�½���692,270��������692,212
		//}
	}


	//������б�´�����������
	if (WaterGirl.x > 374 && WaterGirl.y == 246) {		//������б�´�����
		for (int i = 0; i < 10; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 266;
		DrawWatergirlRight();
		putall();
	}
	if (WaterGirl.x < 394 && WaterGirl.y == 266) {		//������б�´�����
		for (int i = 0; i < 10; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 246;
		DrawWatergirlLeft();
		putall();
	}


	//������б�´���������ǰ��ǰ���ռ�ϴ�λ��
	if ((WaterGirl.x >= 394 && WaterGirl.x <= 550) && WaterGirl.y == 266) {
		if (WaterGirl.x >= 404 && WaterGirl.x <= 550) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 424 && WaterGirl.x <= 454) {  //�Ե���ʯ
			WaterGirl.diamonds = 2;
			GetDiamonds();
		}
		else if (WaterGirl.x >= 454 && WaterGirl.x <= 464)
		{
			CloseMusic();
		}
	}

	//�ϴ�ռ��λ�õ�������ǰ
	if ((WaterGirl.x >= 550 && WaterGirl.x <= 648) && WaterGirl.y == 266) {
		if (WaterGirl.x >= 570 && WaterGirl.x <= 600) {		//�������ϵ��ݵ�λ��
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 620 && WaterGirl.x < 638) {		//�����ϵ��ݵ�λ��
			if (input1 & UPINPUT) {
				WaterGirlMinJump();
				if (input1 & RIGHTINPUT) {
					for (int i = 0; i < 16; i++) {
						WaterGirl.y -= 1;
						WaterGirl.x += 2;
						DrawWatergirlRight();
						putall();
					}
					WaterGirl.y = 250;
					DrawWatergirlRight();
					putall();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
	}
	//�ڵ��ݻ���
	if (WaterGirl.x <= 656 && WaterGirl.y == 250) {
		for (int i = 0; i < 16; i++) {
			WaterGirl.y += 1;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 266;
		DrawWatergirlLeft();
		putall();
	}
	//�ڵ����ϵĲ���
	if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 250) {
		if (WaterGirl.x > 670 && WaterGirl.x <= 720) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
					if (WaterGirl.x >= 720) {
						WaterGirl.x = 720;
					}
					DrawWatergirlRight();
					putall();

				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
	}
	//���ݿ���
	if (purplebutton.stauts == 2) {  //�������뿪��ť
		if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 250) {
			WaterGirl.y = 192;
			DrawGame();
			putall();
		}
	}
	else if (purplebutton.stauts == 1)
	{
		if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 192) {
			WaterGirl.y = 250;
			DrawGame();
			putall();
		}
	}

	//����������������׼����Ծ
	if ((WaterGirl.x > 656 && WaterGirl.x <= 720) && WaterGirl.y == 192) {			//y192  ��y166   
		if (WaterGirl.x > 670 && WaterGirl.x <= 720) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
					if (WaterGirl.x >= 720) {
						WaterGirl.x = 720;
						DrawWatergirlRight();
						putall();
					}
				}
				if (input1 & LEFTINPUT) {
					WaterGirl.y -= 40;
					DrawGame();
					putall();
					for (int i = 0; i < 7; i++) {
						WaterGirl.y += 2;
						WaterGirl.x -= 8;
						DrawWatergirlLeft();
						putall();
					}
					WaterGirl.y = 166;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	//���Ĳ��ұߵ�����
	if (WaterGirl.x >= 654 && WaterGirl.y == 166) {
		for (int i = 0; i < 13; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 2;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 192;
		DrawWatergirlRight();
		putall();
	}
}

//���Ĳ���ײ���
void FourthJudge2()
{
	//���Ĳ㻬��ǰ����
	if ((WaterGirl.x > 536 && WaterGirl.x < 654) && WaterGirl.y == 166) {
		if (WaterGirl.x > 536 && WaterGirl.x < 610) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMidJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMidJumpAndLeftMove();
				}
			}
		}
	}

	//���Ĳ��ϻ���
	if ((WaterGirl.x <= 536 && WaterGirl.x >= 530) && WaterGirl.y == 166) {  //y166 ��y126
		for (int i = 0; i < 20; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 126;
		DrawWatergirlLeft();
		putall();
	}
	//���Ĳ��»���
	if ((WaterGirl.x >= 490 && WaterGirl.x <= 496) && WaterGirl.y == 126) {  //y166 ��y126
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 166;
		DrawWatergirlRight();
		putall();
	}

	//���Ĳ����껬�º�ǰ����䴦
	if ((WaterGirl.x > 352 && WaterGirl.x <= 470) && WaterGirl.y == 126) {
		if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
			if (WaterGirl.x - 35 < 400) {
				WaterGirl.boxcontact = 1;
				drawAlpha(&temp_game, WaterGirl.x - 35, 128, &imag_box);
				putall();
			}
		}
	}
	//���Ĳ������ӵ���
	if (WaterGirl.x <= 352 && WaterGirl.y == 126) {				//y126 ��y166
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 2;
			if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
				DrawWatergirlLeft();
				drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
				putall();
			}
		}
		WaterGirl.y = 166;
		if (FireBoy.boxcontact != 1 && FireBoy.boxcontact != 2) {
			DrawWatergirlLeft();
			drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
			putall();
		}
	}
	//�����ӵ�����߹���
	if (WaterGirl.x >= 145 && WaterGirl.x <= 352 && WaterGirl.y == 166) {				//y126 ��y166
		if (WaterGirl.boxcontact == 1) {
			drawAlpha(&temp_game, WaterGirl.x - 35, WaterGirl.y + 2, &imag_box);
			putall();
		}
	}
	if (WaterGirl.x <= 145 && WaterGirl.y == 166) {			//�Ƶ�������
		drawAlpha(&temp_game, 110, 168, &imag_box);
		putall();
		WaterGirl.boxcontact = 2;
		DrawWatergirlLeft();
		putall();
	}

	//���Ĳ�����������
	if ((WaterGirl.x >= 143 && WaterGirl.x <= 160) && WaterGirl.y == 166) {
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				WaterGirl.y -= 60;
				DrawGame();
				putall();
				for (int i = 0; i < 15; i++) {
					WaterGirl.y += 4;
					WaterGirl.x += 7;
					if (WaterGirl.x >= 184) {
						WaterGirl.x = 184;
					}
					DrawWatergirlRight();
					putall();
				}
			}
			if (input1 & LEFTINPUT) {									//y166 ��y132
				WaterGirl.y -= 60;
				/*DrawGame();
				putall();*/
				for (int i = 0; i < 13; i++) {
					WaterGirl.y += 2;
					WaterGirl.x -= 2;
					if (WaterGirl.x <= 100) {
						WaterGirl.x = 100;
					}
					DrawWatergirlLeft();
					putall();
				}
				WaterGirl.y = 132;
				DrawWatergirlLeft();
				putall();
			}
		}
	}
	//�������ϵ���
	if (WaterGirl.x >= 128 && WaterGirl.y == 132) {
		for (int i = 0; i < 17; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 1;
			DrawWatergirlRight();
			putall();
		}
	}
	//����������Ծ����һ��
	if ((WaterGirl.x >= 98 && WaterGirl.x < 128) && WaterGirl.y == 132) {
		if (WaterGirl.x >= 98 && WaterGirl.x < 110) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirl.y -= 60;
					for (int i = 0; i < 15; i++) {
						WaterGirl.y += 4;
						WaterGirl.x += 7;
						if (WaterGirl.x >= 184) {
							WaterGirl.x = 184;
						}
						WaterGirl.y = 166;
						DrawWatergirlRight();
						putall();
					}
				}
				if (input1 & LEFTINPUT) {									//y132 ��y86
					WaterGirl.y -= 60;
					for (int i = 0; i < 7; i++) {
						WaterGirl.y += 2;
						WaterGirl.x -= 2;
						DrawWatergirlLeft();
						putall();
					}
					WaterGirl.y = 86;
					DrawWatergirlLeft();
					putall();
				}
			}
		}
	}
	//�ӵ����ϲ����
	if (WaterGirl.x >= 96 && WaterGirl.y == 86) {					//y86 ��y132
		for (int i = 0; i < 23; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 1;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 132;
		DrawWatergirlRight();
		putall();
	}
	//�ڵ����ϲ�Ĳ���
	if ((WaterGirl.x < 96 && WaterGirl.x >= 0) && WaterGirl.y == 86) {
		//�ڱ��޵Ĳ�������޳���ʯ
		if (WaterGirl.x >= 10 && WaterGirl.x <= 26) {
			WaterGirl.diamonds = 3;
			GetDiamonds();
		}
		else if (WaterGirl.x > 36 && WaterGirl.x <= 46)
		{
			CloseMusic();
		}
		if (WaterGirl.x >= 0 && WaterGirl.x < 70) {
			if (input1 & UPINPUT) {
				WaterGirlMidJump();
				if (input1 & RIGHTINPUT) {
					WaterGirlMinJumpAndRightMove();
				}
				if (input1 & LEFTINPUT) {
					WaterGirlMinJumpAndLeftMove();
				}
			}
		}
		if (WaterGirl.x >= 70 && WaterGirl.x < 96) {
			if (input1 & UPINPUT) {
				if (input1 & RIGHTINPUT) {				//y86 �� y26
					/*WaterGirl.y -= 80;*/
					for (int i = 0; i < 20; i++) {
						WaterGirl.y -= 4;
						DrawWatergirlRight();
						putall();
					}
					for (int i = 0; i < 20; i++) {
						WaterGirl.y += 1;
						WaterGirl.x += 5;
						DrawWatergirlRight();
						putall();
					}
					WaterGirl.y = 26;
					DrawWatergirlRight();
					putall();
				}
			}
		}

	}
}

//�������ײ���
void FifthJudge2()
{	//��������
	if ((WaterGirl.x > 272 && WaterGirl.x <= 720) && WaterGirl.y == 66) {
		if (input1 & UPINPUT) {
			WaterGirlMidJump();
			if (input1 & RIGHTINPUT) {
				WaterGirlMinJumpAndRightMove();
			}
			if (input1 & LEFTINPUT) {
				WaterGirlMinJumpAndLeftMove();
			}
		}
	}
	//���޳Ե���ʯ
	if ((WaterGirl.x >= 404 && WaterGirl.x <= 434) && WaterGirl.y == 66) {
		GetDiamonds();
		WaterGirl.diamonds = 4;
	}
	else if ((WaterGirl.x >= 434 && WaterGirl.x <= 444) && WaterGirl.y == 66)
	{
		CloseMusic();
	}
	//���������
	if ((WaterGirl.x <= 164 && WaterGirl.x >= 158) && WaterGirl.y == 26) {
		for (int i = 0; i < 20; i++) {
			WaterGirl.y += 3;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
	}
	//������һ���1
	if ((WaterGirl.x >= 214 && WaterGirl.x <= 220) && WaterGirl.y == 26) {			//y26 �� y44       x214  x236
		for (int i = 0; i < 9; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlRight();
		putall();
	}
	//�����������1
	if ((WaterGirl.x >= 230 && WaterGirl.x <= 236) && WaterGirl.y == 44) {			//y26 �� y44       x214  x236
		for (int i = 0; i < 9; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 26;
		DrawWatergirlLeft();
		putall();
	}
	//������һ���2
	if ((WaterGirl.x >= 254 && WaterGirl.x <= 260) && WaterGirl.y == 44) {			//y44 �� y66       x287  x254
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlRight();
		putall();
	}
	//�����������2
	if ((WaterGirl.x <= 272 && WaterGirl.x >= 266) && WaterGirl.y == 66) {			//y44 �� y66       x272  x250
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 2;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlLeft();
		putall();
	}

	//�����������3
	if ((WaterGirl.x >= 490 && WaterGirl.x <= 496) && WaterGirl.y == 66) {		//y66 �� y44       x490  x512
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlRight();
		putall();
	}
	//������һ���3
	if ((WaterGirl.x <= 512 && WaterGirl.x >= 508) && WaterGirl.y == 44) {		//y44 �� y66       x490  x512
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlLeft();
		putall();
	}
	//������һ���4
	if ((WaterGirl.x >= 574 && WaterGirl.x <= 580) && WaterGirl.y == 44) {		//y44 �� y66       x574  x592
		for (int i = 0; i < 11; i++) {
			WaterGirl.y += 2;
			WaterGirl.x += 3;
			DrawWatergirlRight();
			putall();
		}
		WaterGirl.y = 66;
		DrawWatergirlRight();
		putall();
	}
	//�����������4
	if ((WaterGirl.x <= 592 && WaterGirl.x >= 586) && WaterGirl.y == 66) {		//y66 �� y44       x574  x592
		for (int i = 0; i < 11; i++) {
			WaterGirl.y -= 2;
			WaterGirl.x -= 3;
			DrawWatergirlLeft();
			putall();
		}
		WaterGirl.y = 44;
		DrawWatergirlLeft();
		putall();
	}
}






















