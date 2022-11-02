#include "Controller.h"
#include "mainhead.h"
#include "Game.h"

void Controller::Move(Chess_Pos Pos)
{
	Checkerboard* Bd;
	Bd = GAME.GetBoard();
	Bd->PlaceChess(&Pos, CType);
}

void Controller::Move()
{
}

void Controller::ChangeChessType(ChessType cType)
{
	CType = cType;
}

int Controller::GetType()
{
	return Type;
}

Chess_Pos ComputerPlayer::ChoosePos()
{
	int MaxScore = 0;
	int size = GAME.GetBoard()->GetSize();
	Checkerboard* Bd = GAME.GetBoard();
	Chess_Pos TempPos, MaxScorePos = { size / 2,size / 2 };
	// 评分向量数组清零
	//memset(ScoreBoard, 0, size * size);
	for (TempPos.x = 0; TempPos.x < size; TempPos.x++)
	{
		for (TempPos.y = 0; TempPos.y < size; TempPos.y++)
		{
			ScoreBoard[TempPos.x * size + TempPos.y] = CalcScore(TempPos);
			if (MaxScore < ScoreBoard[TempPos.x * size + TempPos.y])
			{
				MaxScore = ScoreBoard[TempPos.x * size + TempPos.y];
				MaxScorePos = TempPos;
			}
		}
	}
	return MaxScorePos;
}

void ComputerPlayer::NewScore()
{
	delete(ScoreBoard);
	ScoreBoard = new int(MAX_BOARD_SIZE * MAX_BOARD_SIZE);
}

int ComputerPlayer::CalcScore(Chess_Pos Pos)
{
	Chess_Pos temp;
	int count, chessnum;
	Checkerboard* Board = GAME.GetBoard();
	int size = Board->GetSize();
	/*总分数*/
	int score = 0;
	/*被堵的端数*/
	int StuckNum;
	/*位置有棋则0分*/
	if (Board->TestPlace(&Pos)!= NO_CHESS)
	{
		return 0;
	}
	/*左上右下方向*/
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS||temp.x>=size||temp.y>=size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0 || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 1);
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x >= size || temp.y >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0 || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 0);
	/*左下右上方向*/
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y - count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x >= size || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y - count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0 || temp.y >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 1);
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y - count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x >= size || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		temp.y = Pos.y - count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0 || temp.y >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 0);
	/*横向*/
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.y >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 1);
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.y >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.y = Pos.y + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.y < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 0);
	/*纵向*/
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		if (Board->TestPlace(&temp) == CType)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 1);
	for (count = 1, chessnum = 0, StuckNum = 0; count <= 4; count++)
	{
		temp.x = Pos.x + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x >= size)
			{
				StuckNum++;
			}
			break;
		}
	}
	for (count = -1; count >= -4; count--)
	{
		temp.x = Pos.x + count;
		if (Board->TestPlace(&temp) != CType && Board->TestPlace(&temp) != NO_CHESS)
		{
			chessnum++;
		}
		else
		{
			if (Board->TestPlace(&temp) != NO_CHESS || temp.x < 0)
			{
				StuckNum++;
			}
			break;
		}
	}
	score += ShapeScore(chessnum, StuckNum, 0);
	return score;
}

int ComputerPlayer::ShapeScore(int ChessNum, int StuckNum, bool OwnChess)
{
	if (OwnChess)
	{
		switch (ChessNum)
		{
		case 0:
			return 0;
		case 1:
			switch (StuckNum)
			{
			case 0:
				return 10;
			case 1:
				return 5;
			case 2:
				return 0;
			}
		case 2:
			switch (StuckNum)
			{
			case 0:
				return 50;
			case 1:
				return 25;
			case 2:
				return 0;
			}
		case 3:
			switch (StuckNum)
			{
			case 0:
				return 1000;
			case 1:
				return 55;
			case 2:
				return 0;
			}
		default:
			return 9999;
		}
	}
	else
	{
		switch (ChessNum)
		{
		case 0:
			return 0;
		case 1:
			switch (StuckNum)
			{
			case 0:
				return 10;
			case 1:
				return 0;
			case 2:
				return 0;
			}
		case 2:
			switch (StuckNum)
			{
			case 0:
				return 40;
			case 1:
				return 30;
			case 2:
				return 0;
			}
		case 3:
			switch (StuckNum)
			{
			case 0:
				return 200;
			case 1:
				return 60;
			case 2:
				return 0;
			}
		default:
			return 2000;
		}
	}
}
