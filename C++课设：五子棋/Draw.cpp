#include "Draw.h"
#include "Checkerboard.h"
#include <graphics.h>
#include <stdlib.h>
#include <mmsystem.h> //必须放在最后面，我也不知道为什么......

#pragma comment(lib,"winmm.lib")

void ShowWelcome()
{
	IMAGE* Back = new IMAGE;
	initgraph(WINDOWS_WIDTH,WINDOWS_HEIGHT);
	loadimage(Back, _T(".\\images\\Backing850_850.png"));
	putimage(0, 0, Back, SRCCOPY);
	mciSendString(_T("open .\\sound\\WelcomeBGM.mp3 alias welcomeBGM"), 0, 0, 0);
	mciSendString(_T("play welcomeBGM"), 0, 0, 0);
	setbkmode(TRANSPARENT);
//	FlushBatchDraw();
//	EndBatchDraw();
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 5);
	settextcolor(RGB(0, 0, 0));
	settextstyle(70, 0, L"楷体");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*单人游戏按钮*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"单人游戏";
	int x_buf1 = (300 - textwidth(button1)) / 2;//计算居中偏移距离
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*双人游戏按钮*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"双人游戏";
	int x_buf2 = (300 - textwidth(button2)) / 2;//计算居中偏移距离
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
	/*其他的怪话*/
	const wchar_t welcome_str[] = L"一款五子棋软件";
	const wchar_t choose_str[] = L"请选择游玩模式";
	settextstyle(80, 0, L"黑体");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"黑体");
	int x_bufc = (850 - textwidth(choose_str)) / 2;
	int y_bufc = (150 - textheight(choose_str)) / 2;
	outtextxy(0 + x_bufc, 400 + y_bufc, choose_str);
	delete(Back);
}

void ChooseOrder() 
{
	IMAGE* Back = new IMAGE;
	loadimage(Back, _T(".\\images\\Backing850_850.png"));
	putimage(0, 0, Back, SRCCOPY);
	setbkmode(TRANSPARENT);
	//	FlushBatchDraw();
	//	EndBatchDraw();
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 5);
	settextcolor(RGB(0, 0, 0));
	settextstyle(70, 0, L"楷体");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*执黑按钮*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"执黑先行";
	int x_buf1 = (300 - textwidth(button1)) / 2;//计算居中偏移距离
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*执白按钮*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"执白后行";
	int x_buf2 = (300 - textwidth(button2)) / 2;//计算居中偏移距离
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
	/*其他的怪话*/
	const wchar_t welcome_str[] = L"一款五子棋软件";
	const wchar_t choose_str[] = L"请选择执棋";
	settextstyle(80, 0, L"黑体");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"黑体");
	int x_bufc = (850 - textwidth(choose_str)) / 2;
	int y_bufc = (150 - textheight(choose_str)) / 2;
	outtextxy(0 + x_bufc, 400 + y_bufc, choose_str);
	delete(Back);
}

void ChooseBoard()
{
	IMAGE* Back = new IMAGE;
	loadimage(Back, _T(".\\images\\Backing850_850.png"));
	putimage(0, 0, Back, SRCCOPY);
	setbkmode(TRANSPARENT);
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 5);
	settextcolor(RGB(0, 0, 0));
	settextstyle(70, 0, L"楷体");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*小号棋盘按钮*/
	fillroundrect(35, 670, 185, 770, 60, 40);
	const wchar_t* button1 = L"小";
	int x_buf1 = (150 - textwidth(button1)) / 2;//计算居中偏移距离
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*大号棋盘按钮*/
	fillroundrect(665, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"大";
	int x_buf2 = (150 - textwidth(button2)) / 2;//计算居中偏移距离
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(665 + x_buf2, 670 + y_buf2, button2);
	/*中号棋盘按钮*/
	fillroundrect(WINDOWS_WIDTH / 2 - 75, 670, WINDOWS_WIDTH / 2 + 75, 770, 60, 40);
	const wchar_t button3[] = L"中";
	int x_buf3 = (150 - textwidth(button3)) / 2;//计算居中偏移距离
	int y_buf3 = (100 - textheight(button3)) / 2;
	outtextxy(WINDOWS_WIDTH / 2 - 75 + x_buf3, 670 + y_buf3, button3);
	/*其他的怪话*/
	const wchar_t welcome_str[] = L"一款五子棋软件";
	const wchar_t choose_str[] = L"请选择棋盘大小";
	settextstyle(80, 0, L"黑体");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"黑体");
	int x_bufc = (850 - textwidth(choose_str)) / 2;
	int y_bufc = (150 - textheight(choose_str)) / 2;
	outtextxy(0 + x_bufc, 400 + y_bufc, choose_str);
	delete(Back);
}


void RefreshBoard(Checkerboard* Bd)
{
	/*当前棋盘大小*/
	int size = Bd->GetSize();
	/*计算可整除的大小*/
	int BOARD_SIZE = BOARD_SIZE_ORIGIN - BOARD_SIZE_ORIGIN % (size - 1);
	/*棋子边长*/
	int ChessSize = (BOARD_SIZE / (size - 1)) * 9 / 10;
	/*加载背景*/
	LPCTSTR BkImgPos;
	Bd->ReadBackImg(BkImgPos);
	loadimage(0, BkImgPos);
	/*绘制棋盘网格*/
	setlinecolor(RGB(50, 50, 50));
	setlinestyle(PS_SOLID, 1);
	/*竖线*/
	for (int i = 0; i < size; i++)
	{
		line((WINDOWS_WIDTH - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), (WINDOWS_HEIGHT - BOARD_SIZE) / 2, (WINDOWS_WIDTH - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), WINDOWS_HEIGHT - (WINDOWS_HEIGHT - BOARD_SIZE) / 2);
	}
	/*横线*/
	for (int i = 0; i < size; i++)
	{
		line((WINDOWS_WIDTH - BOARD_SIZE) / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), WINDOWS_WIDTH - (WINDOWS_WIDTH - BOARD_SIZE) / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)));
	}
	/*当前检测的位置*/
	Chess_Pos CheckPos = { 0,0 };
	ChessType type;
	/*加载棋子图片*/
	LPCTSTR BImgPos = NULL, WImgPos = NULL;
	Bd->ReadChessImg(WImgPos, BImgPos);
	IMAGE* BChess = new IMAGE;
	IMAGE* WChess = new IMAGE;
	Sleep(100);
	loadimage(BChess, BImgPos, ChessSize, ChessSize, true);
	loadimage(WChess, WImgPos, ChessSize, ChessSize, true);
	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(0, 0, 0));
	setfillstyle(BS_SOLID);
	for (; CheckPos.y < size; CheckPos.y++)
	{
		for (CheckPos.x = 0; CheckPos.x < size; CheckPos.x++)
		{
			type = Bd->TestPlace(&CheckPos);
			if (type == BLACK_CHESS)
			{
				drawAlpha((WINDOWS_WIDTH - BOARD_SIZE) / 2 + CheckPos.x * (BOARD_SIZE / (size - 1)) - ChessSize / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + CheckPos.y * (BOARD_SIZE / (size - 1)) - ChessSize / 2, BChess);
			}
			else if (type == WHITE_CHESS)
			{
				drawAlpha((WINDOWS_WIDTH - BOARD_SIZE) / 2 + CheckPos.x * (BOARD_SIZE / (size - 1)) - ChessSize / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + CheckPos.y * (BOARD_SIZE / (size - 1)) - ChessSize / 2, WChess);
			}
			else if (type == NO_CHESS)
			{
				fillcircle((WINDOWS_WIDTH - BOARD_SIZE) / 2 + CheckPos.x * (BOARD_SIZE / (size - 1)), (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + CheckPos.y * (BOARD_SIZE / (size - 1)), 3);
			}
		}
	}
	delete(BChess);
	delete(WChess);
}

void drawAlpha(int  picture_x, int picture_y, IMAGE* picture)
{

	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}

void DrawGameOver(LPCTSTR WinWord)
{
	setbkmode(TRANSPARENT);
	setlinecolor(RGB(0, 0, 0));
	setlinestyle(PS_SOLID, 5);
	settextcolor(RGB(0, 0, 0));
	settextstyle(70, 0, L"楷体");
	setfillcolor(RGB(158, 155, 126));
	setfillstyle(BS_SOLID);
	/*结算菜单*/
	fillroundrect(75, 300, 775, 400, 60, 40);
	/*输出结算的话*/
	int x_buf = (700 - textwidth(WinWord)) / 2;//计算居中偏移距离
	int y_buf = (100 - textheight(WinWord)) / 2;
	outtextxy(75 + x_buf, 300 + y_buf, WinWord);
	/*执黑按钮*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"再来一局";
	int x_buf1 = (300 - textwidth(button1)) / 2;//计算居中偏移距离
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*执白按钮*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"不响丸辣";
	int x_buf2 = (300 - textwidth(button2)) / 2;//计算居中偏移距离
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
}
