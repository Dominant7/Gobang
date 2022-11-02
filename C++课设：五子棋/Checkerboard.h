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

/*棋盘*/
class Checkerboard
{
public:
	/*初始化棋盘*/
	Checkerboard(int _Size, LPCTSTR WImg = _T(".\\images\\white.png"), LPCTSTR BImg = _T(".\\images\\black.png"), LPCTSTR BkImg = _T(".\\images\\Backing850_850.png"));
	/*指定位置落指定的子*/
	void PlaceChess(Chess_Pos* Pos, ChessType Type);
	/*输入棋盘位置返回指定位置为黑子白子或无子*/
	ChessType TestPlace(Chess_Pos* Pos);
	/*获取棋盘路数*/
	int GetSize();
	/*加载棋子贴图*/
	void LoadChessImg(LPCTSTR WImg, LPCTSTR BImg);
	/*加载背景贴图*/
	void LoadBackImg(LPCTSTR BkImg);
	/*读取棋子贴图*/
	void ReadChessImg(LPCTSTR& WImg, LPCTSTR& BImg);
	/*读取背景贴图*/
	void ReadBackImg(LPCTSTR& BkImg);
private:
	/*棋盘路数*/
	int Size;
	/*棋盘当前棋子状况*/
	ChessType BoardData[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
	/*黑子图片路径*/
	LPCTSTR BlackChessImg;
	/*白子图片路径*/
	LPCTSTR WhiteChessImg;
	/*背景图片路径*/
	LPCTSTR BackingImg;
};

