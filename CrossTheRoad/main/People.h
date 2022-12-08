#pragma once
#include "Library.h"
#define DOWN_MAP 34
#define LEFT_MAP 4
#define RIGHT_MAP 113
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)
class People {
	int x, y; //
	bool mState; //dead or alive
	int height;
	int width;
	char** person;
	bool checkAlive;
public:

	People();
	People(int x, int y);
	void createPlayer();
	int getHeight();
	int getWidth();
	int getX();
	int getY();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isFinish();
	bool isAlive();
	~People();
};

