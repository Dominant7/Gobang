#pragma once
#include "Checkerboard.h"

/*��Ϸ���ڿ��*/
#define WINDOWS_WIDTH 850
/*��Ϸ���ڸ߶�*/
#define WINDOWS_HEIGHT 850
/*�����߿�*/
#define LINE_THICKNESS 5
/*������ʾ���ؿ��*/
#define BOARD_SIZE_ORIGIN 700

/*��ʾ��ӭ����*/
void ShowWelcome();
/*ѡ����������*/
void ChooseBoard();
/*������Ϸʱѡ���Ⱥ��֣�0Ϊ�������֣�1Ϊ�������*/
void ChooseOrder();
/*ˢ��������ʾ*/
void RefreshBoard(Checkerboard* Bd);
/*���ƺ�alphaͨ����ͼƬ*/
void drawAlpha(int  picture_x, int picture_y, IMAGE* picture);
/*��Ϸ�������*/
void DrawGameOver(LPCTSTR WinWord);