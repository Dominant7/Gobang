#pragma once
#define MAX_BOARD_SIZE 19
#define BIG_BOARD_SIZE 19
#define MIDDLE_BOARD_SIZE 15
#define SMALL_BOARD_SIZE 9
#include <graphics.h>

struct Chess_Pos 
{
	int x;
	int y;
};

enum ChessType { NO_CHESS, BLACK_CHESS, WHITE_CHESS };

/*����*/
class Checkerboard
{
public:
	/*��ʼ������*/
	Checkerboard(int _Size, LPCTSTR WImg = _T(".\\images\\white.png"), LPCTSTR BImg = _T(".\\images\\black.png"), LPCTSTR BkImg = _T(".\\images\\Backing850_850.png"));
	/*ָ��λ����ָ������*/
	void PlaceChess(Chess_Pos* Pos, ChessType Type);
	/*��������λ�÷���ָ��λ��Ϊ���Ӱ��ӻ�����*/
	ChessType TestPlace(Chess_Pos* Pos);
	/*��ȡ����·��*/
	int GetSize();
	/*����������ͼ*/
	void LoadChessImg(LPCTSTR WImg, LPCTSTR BImg);
	/*���ر�����ͼ*/
	void LoadBackImg(LPCTSTR BkImg);
	/*��ȡ������ͼ*/
	void ReadChessImg(LPCTSTR& WImg, LPCTSTR& BImg);
	/*��ȡ������ͼ*/
	void ReadBackImg(LPCTSTR& BkImg);
private:
	/*����·��*/
	int Size;
	/*���̵�ǰ����״��*/
	ChessType BoardData[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
	/*����ͼƬ·��*/
	LPCTSTR BlackChessImg;
	/*����ͼƬ·��*/
	LPCTSTR WhiteChessImg;
	/*����ͼƬ·��*/
	LPCTSTR BackingImg;
};

