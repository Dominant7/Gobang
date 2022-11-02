#pragma once
#include "Checkerboard.h"
#include "Controller.h"

/*ʤ��״̬������Ϊδ��ʤ������ʤ����ʤ��ƽ��*/
enum Win { GO_ON, BLACK_WIN, WHITE_WIN, STALE_MATE };
/*����ģʽ������Ϊ���ˣ�˫��*/
enum PlayMode { SINGLE, MULTI };


/*��Ϸ����ö�*/
class Game
{
public:
	Game(Controller* BCtrl, Controller* WCtrl, Checkerboard* Bd, PlayMode Mode, ComputerPlayer* CCtrl = NULL, ChessType CType = WHITE_CHESS);
	Game();
	/*��Ϸ��ʼ*/
	void Start();
	/*�ж���Ϸ�Ƿ���������ض�Ӧ��ʤ��״̬*/
	Win JudgeGame(Chess_Pos Pos);
	/*��Ϸģʽ*/
	PlayMode GetMode();
	/*������������*/
	Checkerboard* GetBoard();
	/*����Ϸģʽѡ������Ϊ��Ԫ*/
	friend void SinglePlay(Checkerboard* Bd);
	friend void MultiPlay(Checkerboard* Bd);
private:
	/*ִ������*/
	Controller* WhiteCtrl;
	/*ִ������*/
	Controller* BlackCtrl;
	/*�������֣����б�Ҫ��*/
	ComputerPlayer* ComCtrl;
	/*��������*/
	Checkerboard* Board;
	/*����ģʽ*/
	PlayMode Md;
};

/*��ǰ��Ϸ���������ָ��*/
extern Game GAME;
