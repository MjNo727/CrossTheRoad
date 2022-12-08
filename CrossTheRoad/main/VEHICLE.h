#ifndef Vehicle_H
#define VEHICLE_H

#include "Obstacle.h"

class Vehicle : public Obstacle
{
public:
	Vehicle();
	Vehicle(int x);
	int isWhat();
	void sound();

};

#endif