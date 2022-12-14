#ifndef _GAME_H_
#define _GAME_H_

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)

#define LEFT_BORDER 4
#define RIGHT_BORDER 118
#define TOP_BORDER 1
#define BOTTOM_BORDER 36

//
#define HORIZONTAL_PALE_PIECE char(205);
#define VERTICAL_PALE_PIECE char(186);
#define UP_LEFT_CORNER_PALE_PIECE char(201)
#define UP_RIGHT_CORNER_PALE_PIECE char(187)
#define DOWN_LEFT_CORNER_PALE_PIECE char(200)
#define DOWN_RIGHT_CORNER_PALE_PIECE char(188)
#define LANE_LEFT_BORDER -30
#define LANE_RIGHT_BORDER 150

#include "Library.h"
#include "Map.h"
#include "People.h"

class Game {
private:
	Map map;
	bool mode = true; // default: true		true: easy, false: hard
	bool checkMute = false;			// Mute backgound song, default: false
	bool checkLoadGame;
	bool checkPauseGame;	// default: false
	//

public:
	
	void ResizeConsole(int width, int height);
	void FixConsoleWindow();
	void logoCrossyRoad();
	void fillMenu();

	void menu();
	void box(int x, int y);

	void newGame();

	void settings();
};

void GoToXY(int x, int y);
void NoCursorType();
void CursorType();
void TextColor(int color);
void clrscr(); 
std::mt19937::result_type getSeed();
#endif