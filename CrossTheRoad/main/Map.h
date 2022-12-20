#ifndef _Map_H_
#define _Map_H_
#include "Library.h"
#include "People.h"
#include "Lane.h"
#include "Level.h"

class Map {
private:
	People player;
	vector<Lane> lanes;
	Level level;

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


	int renderMAP(int frameTime);
	bool checkCollision();

	void initializeMap();
	void initialRender();
	void generateMap(int frameTime);


	void saveGame(string name, bool mode);
	bool loadGame(string name, bool& mode);
	void levelUp();
	bool checkMaxLevel();
	bool checkWin();


	friend class Game;
};
#endif