#pragma once
#include "Obstacle.h"

//Starting x position for the Car is -6

class Car : public Obstacle
{
public:
    Car();
    Car(int x);
    int isForm();
    void sound();

};