#include "Game.h"
#include "mainhead.h"
#include <iostream>
#include "Draw.h"
#include <stdlib.h>
#include "ClickTest.h"
using namespace std;

Game GAME;
/*Êó±ê×´Ì¬*/
MOUSEMSG MOUSE;

int main()
{
	while (1)
	{
		Checkerboard* Bd = new Checkerboard(MAX_BOARD_SIZE);
		ShowWelcome();
		ClickWelcome(Bd);
		ChooseBoard();
		GameInit(Bd, ClickBoard());
		RefreshBoard(Bd);
		GAME.Start();
		if (ClickRestart())
		{
			delete(Bd);
			
			continue;
		}
		else
		{
			break;
		}
	}
}

void GameInit(Checkerboard* Bd, int BoardSize)
{
	*Bd = Checkerboard(BoardSize);
}