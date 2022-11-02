#pragma once
#include "Checkerboard.h"

/*游戏窗口宽度*/
#define WINDOWS_WIDTH 850
/*游戏窗口高度*/
#define WINDOWS_HEIGHT 850
/*棋盘线宽*/
#define LINE_THICKNESS 5
/*棋盘显示像素宽度*/
#define BOARD_SIZE_ORIGIN 700

/*显示欢迎界面*/
void ShowWelcome();
/*选择棋盘种类*/
void ChooseBoard();
/*单人游戏时选择先后手，0为黑棋先手，1为白棋后手*/
void ChooseOrder();
/*刷新棋盘显示*/
void RefreshBoard(Checkerboard* Bd);
/*绘制含alpha通道的图片*/
void drawAlpha(int  picture_x, int picture_y, IMAGE* picture);
/*游戏结算界面*/
void DrawGameOver(LPCTSTR WinWord);