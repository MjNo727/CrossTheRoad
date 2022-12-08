#pragma once
#include "Library.h"
#define DOWN_MAP 34
#define LEFT_MAP 4
#define RIGHT_MAP 113
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)
class People {
	int mX, mY; //
	bool mState; //dead or alive
	int height;
	int width;
	vector<char, char>people;
	bool checkAlive;
public:

	People();
	People(int mX, int mY);
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
	
};

