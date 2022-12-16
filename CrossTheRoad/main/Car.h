#pragma once
<<<<<<< Updated upstream
#include "Obstacle.h"

//Starting x position for the Car is -6

class Car : public Obstacle
{
public:
    Car();
    Car(int x);
    int isForm();
    //void sound();

};
=======

#include "Vehicle.h"

class Car : public Vehicle
{
private:

public:
	Car();
	Car(int x);
	int isWhat();
	void sound();
};


#endif
>>>>>>> Stashed changes
