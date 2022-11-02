#pragma once
#include "Checkerboard.h"

/*检测游戏模式选择的循环*/
void ClickWelcome(Checkerboard* Bd);
/*单人游戏界面*/
void SinglePlay(Checkerboard* Bd);
/*多人游戏界面*/
void MultiPlay(Checkerboard* Bd);
/*检测先后行选择的循环，0为先行，1为后行*/
int ClickOrder(Checkerboard* Bd);
/*棋盘选择界面*/
int ClickBoard();
/*结算页面检测，返回1重开，返回0退出*/
int ClickRestart();
/*下棋点击*/
void PlayChess(Chess_Pos& Pos);