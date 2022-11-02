#include "Draw.h"
#include "Checkerboard.h"
#include <graphics.h>
#include <stdlib.h>
#include <mmsystem.h> //�����������棬��Ҳ��֪��Ϊʲô......

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
	settextstyle(70, 0, L"����");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*������Ϸ��ť*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"������Ϸ";
	int x_buf1 = (300 - textwidth(button1)) / 2;//�������ƫ�ƾ���
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*˫����Ϸ��ť*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"˫����Ϸ";
	int x_buf2 = (300 - textwidth(button2)) / 2;//�������ƫ�ƾ���
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
	/*�����Ĺֻ�*/
	const wchar_t welcome_str[] = L"һ�����������";
	const wchar_t choose_str[] = L"��ѡ������ģʽ";
	settextstyle(80, 0, L"����");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"����");
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
	settextstyle(70, 0, L"����");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*ִ�ڰ�ť*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"ִ������";
	int x_buf1 = (300 - textwidth(button1)) / 2;//�������ƫ�ƾ���
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*ִ�װ�ť*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"ִ�׺���";
	int x_buf2 = (300 - textwidth(button2)) / 2;//�������ƫ�ƾ���
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
	/*�����Ĺֻ�*/
	const wchar_t welcome_str[] = L"һ�����������";
	const wchar_t choose_str[] = L"��ѡ��ִ��";
	settextstyle(80, 0, L"����");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"����");
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
	settextstyle(70, 0, L"����");
	setfillcolor(RGB(204, 158, 51));
	setfillstyle(BS_SOLID);
	/*С�����̰�ť*/
	fillroundrect(35, 670, 185, 770, 60, 40);
	const wchar_t* button1 = L"С";
	int x_buf1 = (150 - textwidth(button1)) / 2;//�������ƫ�ƾ���
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*������̰�ť*/
	fillroundrect(665, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"��";
	int x_buf2 = (150 - textwidth(button2)) / 2;//�������ƫ�ƾ���
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(665 + x_buf2, 670 + y_buf2, button2);
	/*�к����̰�ť*/
	fillroundrect(WINDOWS_WIDTH / 2 - 75, 670, WINDOWS_WIDTH / 2 + 75, 770, 60, 40);
	const wchar_t button3[] = L"��";
	int x_buf3 = (150 - textwidth(button3)) / 2;//�������ƫ�ƾ���
	int y_buf3 = (100 - textheight(button3)) / 2;
	outtextxy(WINDOWS_WIDTH / 2 - 75 + x_buf3, 670 + y_buf3, button3);
	/*�����Ĺֻ�*/
	const wchar_t welcome_str[] = L"һ�����������";
	const wchar_t choose_str[] = L"��ѡ�����̴�С";
	settextstyle(80, 0, L"����");
	int x_bufw = (850 - textwidth(welcome_str)) / 2;
	int y_bufw = (200 - textheight(welcome_str)) / 2;
	outtextxy(0 + x_bufw, 100 + y_bufw, welcome_str);
	settextstyle(70, 0, L"����");
	int x_bufc = (850 - textwidth(choose_str)) / 2;
	int y_bufc = (150 - textheight(choose_str)) / 2;
	outtextxy(0 + x_bufc, 400 + y_bufc, choose_str);
	delete(Back);
}


void RefreshBoard(Checkerboard* Bd)
{
	/*��ǰ���̴�С*/
	int size = Bd->GetSize();
	/*����������Ĵ�С*/
	int BOARD_SIZE = BOARD_SIZE_ORIGIN - BOARD_SIZE_ORIGIN % (size - 1);
	/*���ӱ߳�*/
	int ChessSize = (BOARD_SIZE / (size - 1)) * 9 / 10;
	/*���ر���*/
	LPCTSTR BkImgPos;
	Bd->ReadBackImg(BkImgPos);
	loadimage(0, BkImgPos);
	/*������������*/
	setlinecolor(RGB(50, 50, 50));
	setlinestyle(PS_SOLID, 1);
	/*����*/
	for (int i = 0; i < size; i++)
	{
		line((WINDOWS_WIDTH - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), (WINDOWS_HEIGHT - BOARD_SIZE) / 2, (WINDOWS_WIDTH - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), WINDOWS_HEIGHT - (WINDOWS_HEIGHT - BOARD_SIZE) / 2);
	}
	/*����*/
	for (int i = 0; i < size; i++)
	{
		line((WINDOWS_WIDTH - BOARD_SIZE) / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)), WINDOWS_WIDTH - (WINDOWS_WIDTH - BOARD_SIZE) / 2, (WINDOWS_HEIGHT - BOARD_SIZE) / 2 + i * (BOARD_SIZE / (size - 1)));
	}
	/*��ǰ����λ��*/
	Chess_Pos CheckPos = { 0,0 };
	ChessType type;
	/*��������ͼƬ*/
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

	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
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
	settextstyle(70, 0, L"����");
	setfillcolor(RGB(158, 155, 126));
	setfillstyle(BS_SOLID);
	/*����˵�*/
	fillroundrect(75, 300, 775, 400, 60, 40);
	/*�������Ļ�*/
	int x_buf = (700 - textwidth(WinWord)) / 2;//�������ƫ�ƾ���
	int y_buf = (100 - textheight(WinWord)) / 2;
	outtextxy(75 + x_buf, 300 + y_buf, WinWord);
	/*ִ�ڰ�ť*/
	fillroundrect(35, 670, 335, 770, 60, 40);
	const wchar_t* button1 = L"����һ��";
	int x_buf1 = (300 - textwidth(button1)) / 2;//�������ƫ�ƾ���
	int y_buf1 = (100 - textheight(button1)) / 2;
	outtextxy(35 + x_buf1, 670 + y_buf1, button1);
	/*ִ�װ�ť*/
	fillroundrect(515, 670, 815, 770, 60, 40);
	const wchar_t button2[] = L"��������";
	int x_buf2 = (300 - textwidth(button2)) / 2;//�������ƫ�ƾ���
	int y_buf2 = (100 - textheight(button2)) / 2;
	outtextxy(515 + x_buf2, 670 + y_buf2, button2);
}
