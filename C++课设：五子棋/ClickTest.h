#pragma once
#include "Checkerboard.h"

/*�����Ϸģʽѡ���ѭ��*/
void ClickWelcome(Checkerboard* Bd);
/*������Ϸ����*/
void SinglePlay(Checkerboard* Bd);
/*������Ϸ����*/
void MultiPlay(Checkerboard* Bd);
/*����Ⱥ���ѡ���ѭ����0Ϊ���У�1Ϊ����*/
int ClickOrder(Checkerboard* Bd);
/*����ѡ�����*/
int ClickBoard();
/*����ҳ���⣬����1�ؿ�������0�˳�*/
int ClickRestart();
/*������*/
void PlayChess(Chess_Pos& Pos);