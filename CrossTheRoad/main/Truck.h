#pragma once
<<<<<<< Updated upstream
#include "Obstacle.h"

//Starting x position for the Truck is -6

class Truck : public Obstacle
{
public:
    Truck();
    Truck(int x);
    int isForm();
    //void sound();

};
=======

#include "Vehicle.h"

class Truck : public Vehicle
{
private:

public:
	Truck();
	Truck(int x);
	int isWhat();
	void sound();
};


#endif
>>>>>>> Stashed changes
