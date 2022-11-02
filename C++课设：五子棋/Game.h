#pragma once
#include "Checkerboard.h"
#include "Controller.h"

/*胜利状态，依次为未分胜负，黑胜，白胜，平局*/
enum Win { GO_ON, BLACK_WIN, WHITE_WIN, STALE_MATE };
/*游玩模式，依次为单人，双人*/
enum PlayMode { SINGLE, MULTI };


/*游戏规则裁定*/
class Game
{
public:
	Game(Controller* BCtrl, Controller* WCtrl, Checkerboard* Bd, PlayMode Mode, ComputerPlayer* CCtrl = NULL, ChessType CType = WHITE_CHESS);
	Game();
	/*游戏开始*/
	void Start();
	/*判断游戏是否结束，返回对应的胜利状态*/
	Win JudgeGame(Chess_Pos Pos);
	/*游戏模式*/
	PlayMode GetMode();
	/*返回所用棋盘*/
	Checkerboard* GetBoard();
	/*将游戏模式选择函数设为友元*/
	friend void SinglePlay(Checkerboard* Bd);
	friend void MultiPlay(Checkerboard* Bd);
private:
	/*执白棋者*/
	Controller* WhiteCtrl;
	/*执黑棋者*/
	Controller* BlackCtrl;
	/*电脑棋手（如有必要）*/
	ComputerPlayer* ComCtrl;
	/*所用棋盘*/
	Checkerboard* Board;
	/*游玩模式*/
	PlayMode Md;
};

/*当前游戏设置类变量指针*/
extern Game GAME;
