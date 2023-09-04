#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#pragma comment(lib,"winmm.lib")


//载入菜单界面图片文件
IMAGE imag_bk, imag_playbutton, imag_more, imag_set, imag_tip, imag_back, imag_music, temp_img,imag_author;
void LoadMenuRes()
{
	loadimage(&imag_bk, _T("resoure\\start.png"));
	loadimage(&imag_playbutton, _T("resoure\\play.png"), 220, 220, true);
	loadimage(&imag_more, _T("resoure\\more.png"), 60, 60, true);
	loadimage(&imag_set, _T("resoure\\set.png"), 50, 50, true);
	loadimage(&imag_author, _T("resoure\\a2.png"), 800, 434, true);//作者信息界面
	loadimage(&imag_tip, _T("resoure\\a.png"), 800, 434, true);//设置界面
	loadimage(&imag_back, _T("resoure\\back.png"), 160, 160, true);//返回按钮
	loadimage(&imag_music, _T("resoure\\music.png"), 160, 160, true);//音乐按钮
	loadimage(&temp_img, TEXT("resoure\\start.png"));//临时图片也要加载
}



//载入游戏界面图片文件
IMAGE game_bk, temp_game;
IMAGE imag_fireboy_front, imag_fireboy_left, imag_fireboy_right, imag_watergirl_front, imag_watergirl_left, imag_watergirl_right;
IMAGE imag_fire_stone,imag_ice_stone,imag_box;
IMAGE imag_yellow_lever_left, imag_yellow_lever_right, imag_yellow_barricade, imag_purple_button, imag_purple_barricade;
IMAGE imag_door_open;

void LoadGameRes()
{
	//背景图
	loadimage(&game_bk, _T("resoure\\background.png"));//show_the_main_point     background
	//火娃三个动作图
	loadimage(&imag_fireboy_front, _T("resoure\\fire_boy_front.png"), 80, 64, true);
	loadimage(&imag_fireboy_left, _T("resoure\\fire_boy_to_left.png"), 80, 64, true);
	loadimage(&imag_fireboy_right, _T("resoure\\fire_boy_to_right.png"), 80, 64, true);
	//冰娃三个动作图
	loadimage(&imag_watergirl_front, _T("resoure\\ice_girl_front.png"), 80, 64,true);
	loadimage(&imag_watergirl_left, _T("resoure\\ice_girl_to_left.png"),80,64,true);
	loadimage(&imag_watergirl_right, _T("resoure\\ice_girl_to_right.png"),80,64, true);
	//钻石图
	loadimage(&imag_fire_stone, _T("resoure\\fire_stone.png"), 80, 64, true);
	loadimage(&imag_ice_stone, _T("resoure\\ice_stone.png"), 80, 64, true);
	//箱子图
	loadimage(&imag_box, _T("resoure\\box.png"), 80, 64, true);
	//黄色机关
	loadimage(&imag_yellow_lever_right, _T("resoure\\yellow_lever_right.png"), 80, 64, true);
	loadimage(&imag_yellow_lever_left, _T("resoure\\yellow_lever_left.png"), 80, 64, true);
	loadimage(&imag_yellow_barricade, _T("resoure\\yellow_barricade.png"), 80, 64, true);
	//紫色机关
	loadimage(&imag_purple_button, _T("resoure\\purple_button.png"), 80, 64, true);
	loadimage(&imag_purple_barricade, _T("resoure\\purple_barricade.png"), 80, 64, true);
	//门开启
	loadimage(&imag_door_open, _T("resoure\\door_open.png"), 80, 64, true);
	//临时图片
	loadimage(&temp_game, TEXT("resoure\\show_the_main_point.png"));//临时图片也要加载
}


//载入游戏失败界面图片文件
IMAGE imag_gameover, imag_menubutton, imag_retrybutton;

void LoadGameoverMenuRes()
{	
	loadimage(&imag_gameover, _T("resoure\\loseend.png"));			//游戏失败界面
	loadimage(&imag_menubutton, _T("resoure\\menu_button.png"));	//菜单按钮
	loadimage(&imag_retrybutton, _T("resoure\\retry_button.png"));	//重试按钮
}

//载入游戏胜利界面图片文件
IMAGE imag_wined, imag_wined2, imag_continuebutton;

void LoadGameWinMenuRes()
{
	loadimage(&imag_wined, _T("resoure\\winend.png"));						//游戏胜利界面（获取所有宝石）
	loadimage(&imag_wined2, _T("resoure\\winend2.png"));					//游戏胜利界面（没有获取所有宝石）
	loadimage(&imag_continuebutton, _T("resoure\\continue_button.png"));	//继续按钮
}




//根据透明度绘图
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;
	// 实现透明贴图
	for (int iy = 0; iy < iheight; ++iy)
	{
		for (int i = 0; i < iwidth; ++i)
		{
			int sa = ((src[i] & 0xff000000) >> 24);//获取阿尔法值
			if (sa != 0)//假如是完全透明就不处理
				if (sa == 255)//假如完全不透明则直接拷贝
					dst[i] = src[i];
				else//真正需要阿尔法混合计算的图像边界才进行混合
					dst[i] = ((((src[i] & 0xff0000) >> 16) + ((dst[i] & 0xff0000) >> 16) * (255 - sa) / 255) << 16) | ((((src[i] & 0xff00) >> 8) + ((dst[i] & 0xff00) >> 8) * (255 - sa) / 255) << 8) | ((src[i] & 0xff) + (dst[i] & 0xff) * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}