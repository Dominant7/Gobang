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
	/*当前胜利情况*/
	Win WinState = GO_ON;
	/*点击对应坐标*/
	Chess_Pos Pos;
	/*停止播放欢迎音乐*/
	mciSendString(_T("close welcomeBGM"), 0, 0, 0);
	mciSendString(_T("oepn .\\sound\\place_chess_succeed.wav alias place_succeed_sound"), 0, 0, 0);
	mciSendString(_T("oepn .\\sound\\place_chess_failed.mp3 alias place_failed_sound"), 0, 0, 0);
	if (GAME.GetMode() == MULTI)
	{
		while (1)
		{
			//黑下棋
			PlayChess(Pos);
			BlackCtrl->Move(Pos);
			WinState = JudgeGame(Pos);
			RefreshBoard(GAME.Board);
			if (WinState)
			{
				break;
			}
			//白下棋
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
		if (BlackCtrl->GetType() == 1)//人类执黑
		{
			while (1)
			{
				//黑下棋
				PlayChess(Pos);
				BlackCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
				//白下棋
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
		else //电脑执黑
		{
			while (1)
			{
				//黑下棋
				Pos=ComCtrl->ChoosePos();
				ComCtrl->Move(Pos);
				WinState = JudgeGame(Pos);
				RefreshBoard(GAME.Board);
				if (WinState)
				{
					break;
				}
				//白下棋
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
		DrawGameOver(_T("游戏结束，黑棋胜利！"));
	}
	else if (WinState == WHITE_WIN)
	{
		DrawGameOver(_T("游戏结束，白棋胜利！"));
	}
	else if(WinState==STALE_MATE)
	{
		DrawGameOver(_T("游戏结束，平局！"));
	}
}

Win Game::JudgeGame(Chess_Pos Pos)
{
	Chess_Pos temp;
	ChessType type;
	int count, chessnum;
	/*左上右下方向*/
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
	/*左下右上方向*/
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
	/*横向*/
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
	/*纵向*/
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