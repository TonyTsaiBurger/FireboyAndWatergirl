#include <stdio.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#pragma comment(lib,"winmm.lib")


//����˵�����ͼƬ�ļ�
IMAGE imag_bk, imag_playbutton, imag_more, imag_set, imag_tip, imag_back, imag_music, temp_img,imag_author;
void LoadMenuRes()
{
	loadimage(&imag_bk, _T("resoure\\start.png"));
	loadimage(&imag_playbutton, _T("resoure\\play.png"), 220, 220, true);
	loadimage(&imag_more, _T("resoure\\more.png"), 60, 60, true);
	loadimage(&imag_set, _T("resoure\\set.png"), 50, 50, true);
	loadimage(&imag_author, _T("resoure\\a2.png"), 800, 434, true);//������Ϣ����
	loadimage(&imag_tip, _T("resoure\\a.png"), 800, 434, true);//���ý���
	loadimage(&imag_back, _T("resoure\\back.png"), 160, 160, true);//���ذ�ť
	loadimage(&imag_music, _T("resoure\\music.png"), 160, 160, true);//���ְ�ť
	loadimage(&temp_img, TEXT("resoure\\start.png"));//��ʱͼƬҲҪ����
}



//������Ϸ����ͼƬ�ļ�
IMAGE game_bk, temp_game;
IMAGE imag_fireboy_front, imag_fireboy_left, imag_fireboy_right, imag_watergirl_front, imag_watergirl_left, imag_watergirl_right;
IMAGE imag_fire_stone,imag_ice_stone,imag_box;
IMAGE imag_yellow_lever_left, imag_yellow_lever_right, imag_yellow_barricade, imag_purple_button, imag_purple_barricade;
IMAGE imag_door_open;

void LoadGameRes()
{
	//����ͼ
	loadimage(&game_bk, _T("resoure\\background.png"));//show_the_main_point     background
	//������������ͼ
	loadimage(&imag_fireboy_front, _T("resoure\\fire_boy_front.png"), 80, 64, true);
	loadimage(&imag_fireboy_left, _T("resoure\\fire_boy_to_left.png"), 80, 64, true);
	loadimage(&imag_fireboy_right, _T("resoure\\fire_boy_to_right.png"), 80, 64, true);
	//������������ͼ
	loadimage(&imag_watergirl_front, _T("resoure\\ice_girl_front.png"), 80, 64,true);
	loadimage(&imag_watergirl_left, _T("resoure\\ice_girl_to_left.png"),80,64,true);
	loadimage(&imag_watergirl_right, _T("resoure\\ice_girl_to_right.png"),80,64, true);
	//��ʯͼ
	loadimage(&imag_fire_stone, _T("resoure\\fire_stone.png"), 80, 64, true);
	loadimage(&imag_ice_stone, _T("resoure\\ice_stone.png"), 80, 64, true);
	//����ͼ
	loadimage(&imag_box, _T("resoure\\box.png"), 80, 64, true);
	//��ɫ����
	loadimage(&imag_yellow_lever_right, _T("resoure\\yellow_lever_right.png"), 80, 64, true);
	loadimage(&imag_yellow_lever_left, _T("resoure\\yellow_lever_left.png"), 80, 64, true);
	loadimage(&imag_yellow_barricade, _T("resoure\\yellow_barricade.png"), 80, 64, true);
	//��ɫ����
	loadimage(&imag_purple_button, _T("resoure\\purple_button.png"), 80, 64, true);
	loadimage(&imag_purple_barricade, _T("resoure\\purple_barricade.png"), 80, 64, true);
	//�ſ���
	loadimage(&imag_door_open, _T("resoure\\door_open.png"), 80, 64, true);
	//��ʱͼƬ
	loadimage(&temp_game, TEXT("resoure\\show_the_main_point.png"));//��ʱͼƬҲҪ����
}


//������Ϸʧ�ܽ���ͼƬ�ļ�
IMAGE imag_gameover, imag_menubutton, imag_retrybutton;

void LoadGameoverMenuRes()
{	
	loadimage(&imag_gameover, _T("resoure\\loseend.png"));			//��Ϸʧ�ܽ���
	loadimage(&imag_menubutton, _T("resoure\\menu_button.png"));	//�˵���ť
	loadimage(&imag_retrybutton, _T("resoure\\retry_button.png"));	//���԰�ť
}

//������Ϸʤ������ͼƬ�ļ�
IMAGE imag_wined, imag_wined2, imag_continuebutton;

void LoadGameWinMenuRes()
{
	loadimage(&imag_wined, _T("resoure\\winend.png"));						//��Ϸʤ�����棨��ȡ���б�ʯ��
	loadimage(&imag_wined2, _T("resoure\\winend2.png"));					//��Ϸʤ�����棨û�л�ȡ���б�ʯ��
	loadimage(&imag_continuebutton, _T("resoure\\continue_button.png"));	//������ť
}




//����͸���Ȼ�ͼ
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// ������ͼ��ʵ�ʳ���
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// �������ұ߽�
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// �������±߽�
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// ��������߽�
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// �������ϱ߽�

	// ������ͼ��ʼλ��
	dst += dst_width * y + x;
	// ʵ��͸����ͼ
	for (int iy = 0; iy < iheight; ++iy)
	{
		for (int i = 0; i < iwidth; ++i)
		{
			int sa = ((src[i] & 0xff000000) >> 24);//��ȡ������ֵ
			if (sa != 0)//��������ȫ͸���Ͳ�����
				if (sa == 255)//������ȫ��͸����ֱ�ӿ���
					dst[i] = src[i];
				else//������Ҫ��������ϼ����ͼ��߽�Ž��л��
					dst[i] = ((((src[i] & 0xff0000) >> 16) + ((dst[i] & 0xff0000) >> 16) * (255 - sa) / 255) << 16) | ((((src[i] & 0xff00) >> 8) + ((dst[i] & 0xff00) >> 8) * (255 - sa) / 255) << 8) | ((src[i] & 0xff) + (dst[i] & 0xff) * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}