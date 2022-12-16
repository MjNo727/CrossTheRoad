#pragma once
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