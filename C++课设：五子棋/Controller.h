#pragma once
#include "Checkerboard.h"

/*������������Ķ�������ң����Ե�*/
class Controller
{
public:
	/*�������*/
	void Move(Chess_Pos Pos);
	/*��������*/
	void Move();
	/*����ִ������*/
	void ChangeChessType(ChessType cType);
	/*��ȡ��������*/
	int GetType();
protected:
	/*���ƶ������ͣ�0Ϊδ���ã�1Ϊ���࣬2Ϊ����*/
	int Type = 0;
	/*����ִ�壬ʹ��ChessType��Ϊ����*/
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
	/*�������β����жϷ�ֵ��ChessNumΪͬ���������StuckNumΪ��������OwnChessΪ1��ʾ�Լ����壬0Ϊ���ֵ���*/
	int ShapeScore(int ChessNum, int StuckNum, bool OwnChess);
};