#pragma once
#include "Library.h"
class Obstacle {
protected:
	vector<string>shape;
	int mX;
	bool form; // Animal = 0 di tu phai qua trai, Vehicle = 1 di tu trai qua phai
public:
	Obstacle();
	Obstacle(int x, bool form);
	void renderShape(int y);
	bool checkOut();
	bool checkSpawn();
	virtual int isForm() = 0;
	virtual void sound() = 0;
	friend class Map;
	friend class People;
	friend class Game;
	friend class Lane;
};