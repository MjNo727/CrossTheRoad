#pragma once
#include "Library.h"
class Obstacle {
protected:
	vector<string>shape;
	int mX;
	bool form; // Animal = 1, Vehicle = 0
public:
	Obstacle();
	Obstacle(int x, bool form);
	void renderShape(int y);
	bool checkOut();
	bool checkSpawn();
	virtual int isForm() = 0;
	virtual void sound() = 0;
	friend class MAP;
	friend class People;
	friend class Game;
};