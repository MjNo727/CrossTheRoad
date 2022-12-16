#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Library.h"
#include "Obstacle.h"

#define DOWN_MAP 34
#define LEFT_MAP 4
#define RIGHT_MAP 113
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)

class People {
private:
	int x, y; // position
	int height = 3;
	int width = 5;

	vector<string> people;			// player
	vector<string> blank;
	bool checkDead;
public:
	People();
	People(int x, int y);


	void createPeople();
	void createBlank();
	int getHeight();
	int getWidth();
	int getX();
	int getY();
	void Up();
	void Down();
	void Left();
	void Right();
	vector<string>getPeople();
	vector<string>getBlank();
	void setCheckDead();
	bool getCheckDead();

	bool checkCollision(Obstacle& obstacle);

	friend class Map;
};

#endif


