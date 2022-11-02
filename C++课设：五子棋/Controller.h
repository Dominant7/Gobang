#pragma once
#include "Checkerboard.h"

/*控制下棋操作的对象，如玩家，电脑等*/
class Controller
{
public:
	/*玩家下棋*/
	void Move(Chess_Pos Pos);
	/*电脑下棋*/
	void Move();
	/*更改执棋类型*/
	void ChangeChessType(ChessType cType);
	/*获取对象类型*/
	int GetType();
protected:
	/*控制对象类型，0为未设置，1为人类，2为电脑*/
	int Type = 0;
	/*对象执棋，使用ChessType作为区分*/
	ChessType CType;
};

class HumanPlayer : public Controller
{
public:
	HumanPlayer()
	{
		Type = 1;
	}
};

class ComputerPlayer :public Controller
{
public:
	ComputerPlayer()
	{
		Type = 0;
	}
	Chess_Pos ChoosePos();
	void NewScore();
	int CalcScore(Chess_Pos Pos);
private:
	int* ScoreBoard = NULL;
	/*输入棋形参数判断分值，ChessNum为同类棋个数，StuckNum为阻塞数，OwnChess为1表示自己的棋，0为对手的棋*/
	int ShapeScore(int ChessNum, int StuckNum, bool OwnChess);
};