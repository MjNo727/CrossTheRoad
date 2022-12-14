#ifndef _Map_H_
#define _Map_H_
#include "Library.h"
#include "People.h"


class Map {
private:
	People player;


public:
	Map();
	void printMapBorder();
	void printMap();
	void fillInsideMap();
	int drawFromPosition(int x, int y, vector<string>shape, int w, int h);
	void drawPlayer();
	void resetPlayer();
	void updatePosPlayer(char key);
	bool checkEndMap();

	void initializeMap();

	bool checkWin();

	friend class GAME;
};
#endif