#include "ClickTest.h"
#include "Checkerboard.h"
#include "mainhead.h"
#include "Controller.h"
#include "Draw.h"
#include "Game.h"

void ClickWelcome(Checkerboard* Bd)
{
	while (1)
	{
		if (MouseHit())
		{
			MOUSE = GetMouseMsg();
			if (MOUSE.x > 35 && MOUSE.x < 335 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN) //�������������Ϸ
			{
				SinglePlay(Bd);
				break;
			}
			else if (MOUSE.x > 515 && MOUSE.x < 815 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN)//������˫����Ϸ
			{
				MultiPlay(Bd);
				break;
			}
		}
	}
}

void SinglePlay(Checkerboard* Bd)
{
	int order;
	ChooseOrder();
	order = ClickOrder(Bd);
	ComputerPlayer* CP = new ComputerPlayer;
	CP->NewScore();
	HumanPlayer* HP = new HumanPlayer;
	if (order == 0)
	{
		GAME = Game(HP, CP, Bd, SINGLE);
	}
	else if (order == 1)
	{
		GAME = Game(CP, HP, Bd, SINGLE);
	}
}

void MultiPlay(Checkerboard* Bd)
{
	HumanPlayer* HP1 = new HumanPlayer;
	HumanPlayer* HP2 = new HumanPlayer;
	GAME = Game(HP1, HP2, Bd, MULTI);
}

int ClickOrder(Checkerboard* Bd)
{
	while (1)
	{
		if (MouseHit())
		{
			MOUSE = GetMouseMsg();
			if (MOUSE.x > 35 && MOUSE.x < 335 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN) //�������ִ������
			{
				return 0;
			}
			else if (MOUSE.x > 515 && MOUSE.x < 815 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN)//������ִ�׺���
			{
				MultiPlay(Bd);
				return 1;
			}
		}
	}
}

int ClickBoard()
{
	while (1)
	{
		if (MouseHit())
		{
			MOUSE = GetMouseMsg();
			if (MOUSE.x > 35 && MOUSE.x < 185 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN) //�������С
			{
				return SMALL_BOARD_SIZE;
			}
			else if (MOUSE.x > WINDOWS_WIDTH / 2 - 75 && MOUSE.x < WINDOWS_WIDTH / 2 + 75 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN) //��������
			{
				return MIDDLE_BOARD_SIZE;
			}
			else if (MOUSE.x > 665 && MOUSE.x < 815 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN)//��������
			{
				return BIG_BOARD_SIZE;
			}
		}
	}
}


int ClickRestart()
{
	while (1)
	{
		if (MouseHit())
		{
			MOUSE = GetMouseMsg();
			if (MOUSE.x > 35 && MOUSE.x < 335 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN) //�����������һ��
			{
				return 1;
				break;
			}
			else if (MOUSE.x > 515 && MOUSE.x < 815 && MOUSE.y>670 && MOUSE.y < 770 && MOUSE.uMsg == WM_LBUTTONDOWN)//�������˳���Ϸ
			{
				exit(0);
				break;
			}
		}
	}
}

void PlayChess(Chess_Pos& Pos)
{
	/*��ǰ���̴�С*/
	int size = GAME.GetBoard()->GetSize();
	/*����������Ĵ�С*/
	int BOARD_SIZE = BOARD_SIZE_ORIGIN - BOARD_SIZE_ORIGIN % (size - 1);
	/*���ӱ߳�*/
	int ChessSize = (BOARD_SIZE / (size - 1)) * 9 / 10;
	/*������������α߳�*/
	int SideLength = (BOARD_SIZE / (size - 1)) / 3;
	/*�հ׳���*/
	int x_buf = (WINDOWS_WIDTH - BOARD_SIZE) / 2, y_buf = (WINDOWS_HEIGHT - BOARD_SIZE) / 2;
	Chess_Pos PosTemp;
	while (1)
	{
		if (MouseHit() && GetMouseMsg().uMsg == WM_LBUTTONDOWN)
		{
			MOUSE = GetMouseMsg();
			if (
				(MOUSE.x >= x_buf - SideLength && MOUSE.x <= WINDOWS_WIDTH - x_buf + SideLength)
				&&
				(MOUSE.y >= y_buf - SideLength && MOUSE.y <= WINDOWS_HEIGHT - y_buf + SideLength)
//				&&
//				(MOUSE.uMsg == WM_LBUTTONDOWN)
				)
			{
				if (
					(MOUSE.x - x_buf + SideLength) % (BOARD_SIZE / (size - 1)) <= 2 * SideLength
					&&
					(MOUSE.y - y_buf + SideLength) % (BOARD_SIZE / (size - 1)) <= 2 * SideLength
					)
				{
					PosTemp.x = (MOUSE.x - x_buf + SideLength) / (BOARD_SIZE / (size - 1));
					PosTemp.y = (MOUSE.y - y_buf + SideLength) / (BOARD_SIZE / (size - 1));
					if (GAME.GetBoard()->TestPlace(&PosTemp) == NO_CHESS)
					{
						Pos = PosTemp;
						mciSendString(_T("play place_succeed_sound"), 0, 0, 0);
						break;
					}
					else
					{
						mciSendString(_T("play place_failed_sound"), 0, 0, 0);
						continue;
					}
				}
				else
				{
					mciSendString(_T("play place_failed_sound"), 0, 0, 0);
				}
			}
		}
	}
}
