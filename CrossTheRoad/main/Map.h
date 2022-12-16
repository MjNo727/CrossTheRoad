#ifndef _Map_H_
#define _Map_H_
#include "Library.h"
#include "People.h"
#include "Lane.h"

class Map {
private:
	People player;
	vector<Lane> lanes;

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
	void initialRender();
	
	bool checkCollision();
	bool checkWin();

	friend class GAME;
};
#endif