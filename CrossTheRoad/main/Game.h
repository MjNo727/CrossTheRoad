#ifndef _GAME_H_
#define _GAME_H_

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)

#include "Library.h"
#include "Map.h"
#include "People.h"

class Game {
private:
	//Map map;
	//CPeople player;
	//CVehicle vehicle;
	

public:
	//Game();
	void ResizeConsole(int width, int height);
	void FixConsoleWindow();

	void fillMenu();


	void menu();
	void xxx(int x, int y);
	//void newGame();
	//void loadGame();
	//void saveGame();
};

void GoToXY(int x, int y);
void NoCursorType();
void CursorType();
void TxtColor(int color);
void clrscr(); // clear screen

#endif