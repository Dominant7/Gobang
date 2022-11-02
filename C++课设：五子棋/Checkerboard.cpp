#include "Checkerboard.h"
#include <wchar.h>

Checkerboard::Checkerboard(int _Size, LPCTSTR WImg, LPCTSTR BImg, LPCTSTR BkImg)
{
	Size = _Size;
	memset(BoardData, 0, MAX_BOARD_SIZE * MAX_BOARD_SIZE * sizeof(ChessType));
	LoadChessImg(WImg, BImg);
	LoadBackImg(BkImg);
}

void Checkerboard::PlaceChess(Chess_Pos* Pos, ChessType Type)
{
	BoardData[Pos->x][Pos->y] = Type;
}

ChessType Checkerboard::TestPlace(Chess_Pos* Pos)
{
	if (Pos->x >= 0 && Pos->x <= Size - 1 && Pos->y >= 0 && Pos->y <= Size - 1)
	{
		return BoardData[Pos->x][Pos->y];
	}
	else
	{
		return NO_CHESS;
	}
}

int Checkerboard::GetSize()
{
	return Size;
}

void Checkerboard::LoadChessImg(LPCTSTR WImg,LPCTSTR BImg)
{
	WhiteChessImg = WImg;
	BlackChessImg = BImg;
}

void Checkerboard::LoadBackImg(LPCTSTR BkImg)
{
	BackingImg = BkImg;
}

void Checkerboard::ReadChessImg(LPCTSTR& WImg, LPCTSTR& BImg)
{
	WImg = WhiteChessImg;
	BImg = BlackChessImg;
}

void Checkerboard::ReadBackImg(LPCTSTR& BkImg)
{
	BkImg = BackingImg;
}