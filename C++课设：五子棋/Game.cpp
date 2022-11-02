#include "Game.h"
#include "Draw.h"
#include "ClickTest.h"

Game::Game(Controller* BCtrl, Controller* WCtrl, Checkerboard* Bd, PlayMode Mode, ComputerPlayer* CCtrl,ChessType CType)
{
	this->BlackCtrl = BCtrl;
	BCtrl->ChangeChessType(BLACK_CHESS);
	this->WhiteCtrl = WCtrl;
	WCtrl->ChangeChessType(WHITE_CHESS);
	this->Board = Bd;
	this->Md = Mode;
	if (CCtrl != NULL)
	{
		this->ComCtrl = CCtrl;
		CCtrl->ChangeChessType(CType);
	}
}

Game::Game()
{
	BlackCtrl = NULL;
	WhiteCtrl = NULL;
	ComCtrl = NULL;
	Board = NULL;
	Md = SINGLE;
}

void Game::Start()
{
	/*��ǰʤ�����*/
	Win WinState = GO_ON;
	/*�����Ӧ����*/
	Chess_Pos Pos;
	/*ֹͣ���Ż�ӭ����*/
	mciSendString(_T("close welcomeBGM"), 0, 0, 0);
	mciSendString(_T("oepn .\\sound\\place_chess_succeed.wav alias place_succeed_sound"), 0, 0, 0);
	mciSendString(_T("oepn .\\sound\\place_chess_failed.mp3 alias place_failed_sound"), 0, 0, 0);
	if (GAME.GetMode() == MULTI)
	{
		while (1)
		{
			//������
			PlayChess(Pos);
			BlackCtrl->Move(Pos);
			WinState = JudgeGame(Pos);
			RefreshBoard(GAME.Board);
			if (WinState)
			{
				break;
			}
			//������
			PlayChess(Pos);
			WhiteCtrl->Move(Pos);
			WinState = JudgeGame(Pos);
			RefreshBoard(GAME.Board);
			if (WinState)
			{
				break;
			}
		}
	}
	else if (GAME.GetMode() == SINGLE)
	{
		if (BlackCtrl->GetType() == 1)//����ִ��
		{
			while (1)
			{
				//������
				PlayChess(Pos);
				BlackCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
				//������
				Pos = ComCtrl->ChoosePos();
				ComCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
			}
		}
		else //����ִ��
		{
			while (1)
			{
				//������
				Pos=ComCtrl->ChoosePos();
				ComCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
				//������
				PlayChess(Pos);
				WhiteCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
			}
		}
	}
	if (WinState == BLACK_WIN)
	{
		DrawGameOver(_T("��Ϸ����������ʤ����"));
	}
	else if (WinState == WHITE_WIN)
	{
		DrawGameOver(_T("��Ϸ����������ʤ����"));
	}
	else if(WinState==STALE_MATE)
	{
		DrawGameOver(_T("��Ϸ������ƽ�֣�"));
	}
}

Win Game::JudgeGame(Chess_Pos Pos)
{
	Chess_Pos temp;
	ChessType type;
	int count, chessnum;
	/*�������·���*/
	for (count = -4, type = NO_CHESS, chessnum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == type)
		{
			chessnum++;
		}
		else
		{
			chessnum = 1;
			type = Board->TestPlace(&temp);
		}
		if (chessnum == 5)
		{
			switch (type)
			{
			case BLACK_CHESS:
				return BLACK_WIN;
			case WHITE_CHESS:
				return WHITE_WIN;
			default:
				break;
			}
		}
	}
	/*�������Ϸ���*/
	for (count = -4, type = NO_CHESS, chessnum = 0; count <= 4; count++)
	{
		temp.x = Pos.x - count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == type)
		{
			chessnum++;
		}
		else
		{
			chessnum = 1;
			type = Board->TestPlace(&temp);
		}
		if (chessnum == 5)
		{
			switch (type)
			{
			case BLACK_CHESS:
				return BLACK_WIN;
			case WHITE_CHESS:
				return WHITE_WIN;
			default:
				break;
			}
		}
	}
	/*����*/
	for (count = -4, type = NO_CHESS, chessnum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y;
		if (Board->TestPlace(&temp) == type)
		{
			chessnum++;
		}
		else
		{
			chessnum = 1;
			type = Board->TestPlace(&temp);
		}
		if (chessnum == 5)
		{
			switch (type)
			{
			case BLACK_CHESS:
				return BLACK_WIN;
			case WHITE_CHESS:
				return WHITE_WIN;
			default:
				break;
			}
		}
	}
	/*����*/
	for (count = -4, type = NO_CHESS, chessnum = 0; count <= 4; count++)
	{
		temp.x = Pos.x;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == type)
		{
			chessnum++;
		}
		else
		{
			chessnum = 1;
			type = Board->TestPlace(&temp);
		}
		if (chessnum == 5)
		{
			switch (type)
			{
			case BLACK_CHESS:
				return BLACK_WIN;
			case WHITE_CHESS:
				return WHITE_WIN;
			default:
				break;
			}
		}
	}
	return GO_ON;
}

PlayMode Game::GetMode()
{
	return Md;
}

Checkerboard* Game::GetBoard()
{
	return Board;
}